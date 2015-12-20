// Copyright (c) 2013 NaturalMotion.  All Rights Reserved.
// Not to be copied, adapted, modified, used, distributed, sold,
// licensed or commercially exploited in any manner without the
// written consent of NaturalMotion.
//
// All non public elements of this software are the confidential
// information of NaturalMotion and may not be disclosed to any
// person nor used for any purpose not expressly approved by
// NaturalMotion in writing.

#ifndef NM_LIMBSHAREDSTATE_H
#define NM_LIMBSHAREDSTATE_H

#include "NMPlatform/NMVector3.h"
#include "NMPlatform/NMMatrix34.h"

#include "AutoGenerated/NetworkForceInclude.h"


#include "AutoGenerated/Types/LimbHandleData.h"
#include "AutoGenerated/Types/ContactInfo.h"
#include "AutoGenerated/Types/DynamicState.h"

#include "euphoria/erReachLimit.h"
#include "euphoria/erLimbTransforms.h"

#ifndef NM_BEHAVIOUR_LIB_NAMESPACE
#error behaviour library namespace undefined
#endif

// Forward decls for ER classes.
namespace ER
{
  class Module;
  class Limb;
}

namespace NM_BEHAVIOUR_LIB_NAMESPACE
{
  // Forward decls for NM_BEHAVIOUR_LIB_NAMESPACE classes
  class MyNetwork;

//----------------------------------------------------------------------------------------------------------------------
/// These classes are used to store data in the root module for global access by behaviour modules.
//----------------------------------------------------------------------------------------------------------------------
class LimbSharedState
{
public:
  
  void update(
    MyNetwork& myNetwork,
    ER::Limb& limb,
    float timeStep,
    MR::InstanceDebugInterface* MR_OUTPUT_DEBUG_ARG(pDebugDrawInst));

  void initialise(ER::Limb& limb);

  // Data initialised with the euphoria network that remains constant.
  //
  int32_t m_numPartsBeforeBase;
  int32_t m_totalNumParts;
  int32_t m_numPartsInChain;

  // Data that is updated on a frame by frame basis.
  //
  float m_externalSupportAmount;  ///< {4}  1.0f if the limb is deemed to be supported by an external constraint or SK/HK 0.0f otherwise, spine is a special case that takes account of gravity compensation
  DynamicState m_dynamicState;    ///< {64} vel, mass etc of limb as a whole 
  LimbHandleData m_endData;       ///< {48} vel, angular vel etc of the end part
  LimbHandleData m_rootData;      ///< {48} vel, angular vel etc of the root part
  ER::LimbTransform m_rootTM;     ///< {64} Transform of the root
  ER::ReachLimit m_reachLimit;    ///< {16} note from Head.module: "TODO (This is not currently used, possibly re-use for eye cone instead (ticket 12244)"
  /*Position*/ NMP::Vector3 m_basePosition; ///< {16} position of the base joint, the joint from which most motion originates (e.g. the shoulder in the arm)

  bool m_mainPartIsColliding;     ///< {1} Have contact on any part from base to end.
  bool m_limbBarEndIsColliding;   ///< {1} Have contact on any part from root to one before end.
  ContactInfo m_endContact;       ///< {80} Position and normal of contact on end part.

  // Error between IK target and IK solution
  /*Distance*/ float m_IKPositionError;
  /*Angle*/    float m_IKOrientationError;
  /*Angle*/    float m_IKNormalError;
  float m_IKPositionErrorWeight;     // {4}
  float m_IKOrientationErrorWeight;  // {4}
  float m_IKNormalErrorWeight;       // {4}

  // Individual part information
  NMP::Matrix34 m_partTMs[NetworkConstants::rigMaxNumPartsPerLimb];
  NMP::Vector3 m_jointPositions[NetworkConstants::rigMaxNumPartsPerLimb];  
};

class HeadLimbSharedState : public LimbSharedState
{
public:
  void update(
    MyNetwork& myNetwork,
    ER::Limb& limb,
    float timeStep,
    MR::InstanceDebugInterface* MR_OUTPUT_DEBUG_ARG(pDebugDrawInst));

  ER::LimbTransform m_endTM;      ///< {64} Transform of the head
};

class SpineLimbSharedState : public LimbSharedState
{
public:
  void update(
    MyNetwork& myNetwork,
    ER::Limb& limb,
    float timeStep,
    MR::InstanceDebugInterface* MR_OUTPUT_DEBUG_ARG(pDebugDrawInst));

  void updateMainSpineExternalSupportAmount(MyNetwork& myNetwork);

  ER::LimbTransform m_endTM;      ///< {64} Transform of the head
  ContactInfo m_rootContact;      ///< {80} Contact of external object info (pos, normal etc) for the pelvis

};

class ArmAndLegLimbSharedState : public LimbSharedState
{
public:
  void update(
    MyNetwork& myNetwork,
    ER::Limb& limb,
    float timeStep,
    MR::InstanceDebugInterface* MR_OUTPUT_DEBUG_ARG(pDebugDrawInst));

  ER::HandFootTransform m_endTM;                          ///< {64} Transform of the end effector.
  /*Position*/ NMP::Vector3 m_midLimbPartPosition;        ///< {16} The elbow or knee joint position.
  /*Position*/ NMP::Vector3 m_endLimbPartPosition;        ///< {16} The wrist or ankle joint position.
  bool m_isConstrained;                                   ///< {1}
};

class BodyLimbSharedState
{

public:
  void update(
    MyNetwork& myNetwork,
    const ArmAndLegLimbSharedState* armLimbStates,
    const ArmAndLegLimbSharedState* legLimbStates,
    const HeadLimbSharedState* headLimbStates,
    const SpineLimbSharedState* spineLimbStates);

  // Average end effectors.
  ER::HandFootTransform m_averageOfFeetTM;
  ER::HandFootTransform m_averageOfHandsTM;
  ER::HandFootTransform m_averageOfHandsAndFeetTM;

  // Averages of "reference" i.e. "default pose" feet and shoulders wrt world
  // (these are the defaultPoseEndRelativeToRoot values averaged and transformed to world by the current root tm).
  ER::HandFootTransform m_averageOfDefaultPoseFeetTMWorld;
  NMP::Matrix34 m_averageOfDefaultPoseShouldersTMWorld;

  float m_averageOfLegsIKOrientationError;

  // Dynamic state
  DynamicState m_dynamicState;
};

}

#endif // NM_LIMBSHAREDSTATE_H