#ifndef _C_CkDsa_W_H
#define _C_CkDsa_W_H
#include "Chilkat_C.h"

HCkDsaW CkDsaW_Create(void);
HCkDsaW CkDsaW_Create2(bool bForMono);
void CkDsaW_Dispose(HCkDsaW handle);
void CkDsaW_getDebugLogFilePath(HCkDsaW cHandle, HCkStringW retval);
void CkDsaW_putDebugLogFilePath(HCkDsaW cHandle, const wchar_t *newVal);
HCkDsaProgressW CkDsaW_getEventCallbackObject(HCkDsaW cHandle);
void CkDsaW_putEventCallbackObject(HCkDsaW cHandle, HCkDsaProgressW newVal);
int CkDsaW_getGroupSize(HCkDsaW cHandle);
void CkDsaW_putGroupSize(HCkDsaW cHandle, int newVal);
void CkDsaW_getHash(HCkDsaW cHandle, HCkByteDataW retval);
void CkDsaW_putHash(HCkDsaW cHandle, HCkByteDataW  newVal);
void CkDsaW_getHexG(HCkDsaW cHandle, HCkStringW retval);
void CkDsaW_getHexP(HCkDsaW cHandle, HCkStringW retval);
void CkDsaW_getHexQ(HCkDsaW cHandle, HCkStringW retval);
void CkDsaW_getHexX(HCkDsaW cHandle, HCkStringW retval);
void CkDsaW_getHexY(HCkDsaW cHandle, HCkStringW retval);
void CkDsaW_getLastErrorHtml(HCkDsaW cHandle, HCkStringW retval);
void CkDsaW_getLastErrorText(HCkDsaW cHandle, HCkStringW retval);
void CkDsaW_getLastErrorXml(HCkDsaW cHandle, HCkStringW retval);
void CkDsaW_getSignature(HCkDsaW cHandle, HCkByteDataW retval);
void CkDsaW_putSignature(HCkDsaW cHandle, HCkByteDataW  newVal);
BOOL CkDsaW_getVerboseLogging(HCkDsaW cHandle);
void CkDsaW_putVerboseLogging(HCkDsaW cHandle, BOOL newVal);
void CkDsaW_getVersion(HCkDsaW cHandle, HCkStringW retval);
BOOL CkDsaW_FromDer(HCkDsaW cHandle, HCkByteDataW derData);
BOOL CkDsaW_FromDerFile(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_FromEncryptedPem(HCkDsaW cHandle, const wchar_t *password, const wchar_t *pemData);
BOOL CkDsaW_FromPem(HCkDsaW cHandle, const wchar_t *pemData);
BOOL CkDsaW_FromPublicDer(HCkDsaW cHandle, HCkByteDataW derData);
BOOL CkDsaW_FromPublicDerFile(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_FromPublicPem(HCkDsaW cHandle, const wchar_t *pemData);
BOOL CkDsaW_FromXml(HCkDsaW cHandle, const wchar_t *xmlKey);
BOOL CkDsaW_GenKey(HCkDsaW cHandle, int numBits);
BOOL CkDsaW_GenKeyFromParamsDer(HCkDsaW cHandle, HCkByteDataW derBytes);
BOOL CkDsaW_GenKeyFromParamsDerFile(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_GenKeyFromParamsPem(HCkDsaW cHandle, const wchar_t *pem);
BOOL CkDsaW_GenKeyFromParamsPemFile(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_GetEncodedHash(HCkDsaW cHandle, const wchar_t *encoding, HCkStringW outStr);
BOOL CkDsaW_GetEncodedSignature(HCkDsaW cHandle, const wchar_t *encoding, HCkStringW outStr);
BOOL CkDsaW_LoadText(HCkDsaW cHandle, const wchar_t *path, HCkStringW outStr);
BOOL CkDsaW_SaveLastError(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_SaveText(HCkDsaW cHandle, const wchar_t *strToSave, const wchar_t *path);
BOOL CkDsaW_SetEncodedHash(HCkDsaW cHandle, const wchar_t *encoding, const wchar_t *encodedHash);
BOOL CkDsaW_SetEncodedSignature(HCkDsaW cHandle, const wchar_t *encoding, const wchar_t *encodedSig);
BOOL CkDsaW_SetKeyExplicit(HCkDsaW cHandle, int groupSizeInBytes, const wchar_t *pHex, const wchar_t *qHex, const wchar_t *gHex, const wchar_t *xHex);
BOOL CkDsaW_SetPubKeyExplicit(HCkDsaW cHandle, int groupSizeInBytes, const wchar_t *pHex, const wchar_t *qHex, const wchar_t *gHex, const wchar_t *yHex);
BOOL CkDsaW_SignHash(HCkDsaW cHandle);
BOOL CkDsaW_ToDer(HCkDsaW cHandle, HCkByteDataW outBytes);
BOOL CkDsaW_ToDerFile(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_ToEncryptedPem(HCkDsaW cHandle, const wchar_t *password, HCkStringW outStr);
BOOL CkDsaW_ToPem(HCkDsaW cHandle, HCkStringW outStr);
BOOL CkDsaW_ToPublicDer(HCkDsaW cHandle, HCkByteDataW outBytes);
BOOL CkDsaW_ToPublicDerFile(HCkDsaW cHandle, const wchar_t *path);
BOOL CkDsaW_ToPublicPem(HCkDsaW cHandle, HCkStringW outStr);
BOOL CkDsaW_ToXml(HCkDsaW cHandle, BOOL bPublicOnly, HCkStringW outStr);
BOOL CkDsaW_UnlockComponent(HCkDsaW cHandle, const wchar_t *unlockCode);
BOOL CkDsaW_Verify(HCkDsaW cHandle);
BOOL CkDsaW_VerifyKey(HCkDsaW cHandle);
const wchar_t *CkDsaW__debugLogFilePath(HCkDsaW cHandle);
const wchar_t *CkDsaW__getEncodedHash(HCkDsaW cHandle, const wchar_t *encoding);
const wchar_t *CkDsaW__getEncodedSignature(HCkDsaW cHandle, const wchar_t *encoding);
const wchar_t *CkDsaW__hexG(HCkDsaW cHandle);
const wchar_t *CkDsaW__hexP(HCkDsaW cHandle);
const wchar_t *CkDsaW__hexQ(HCkDsaW cHandle);
const wchar_t *CkDsaW__hexX(HCkDsaW cHandle);
const wchar_t *CkDsaW__hexY(HCkDsaW cHandle);
const wchar_t *CkDsaW__lastErrorHtml(HCkDsaW cHandle);
const wchar_t *CkDsaW__lastErrorText(HCkDsaW cHandle);
const wchar_t *CkDsaW__lastErrorXml(HCkDsaW cHandle);
const wchar_t *CkDsaW__loadText(HCkDsaW cHandle, const wchar_t *path);
const wchar_t *CkDsaW__toEncryptedPem(HCkDsaW cHandle, const wchar_t *password);
const wchar_t *CkDsaW__toPem(HCkDsaW cHandle);
const wchar_t *CkDsaW__toPublicPem(HCkDsaW cHandle);
const wchar_t *CkDsaW__toXml(HCkDsaW cHandle, BOOL bPublicOnly);
const wchar_t *CkDsaW__version(HCkDsaW cHandle);
#endif