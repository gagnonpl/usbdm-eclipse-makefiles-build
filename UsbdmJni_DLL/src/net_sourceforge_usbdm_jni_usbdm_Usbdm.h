/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class net.sourceforge.usbdm.jni.usbdm */

#ifndef _Included_net_sourceforge_usbdm_jni_usbdm
#define _Included_net_sourceforge_usbdm_jni_usbdm
#ifdef __cplusplus
extern "C" {
#endif
#undef net_sourceforge_usbdm_jni_Usbdm_BDM_RC_OK
#define net_sourceforge_usbdm_jni_Usbdm_BDM_RC_OK 0L
/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmInit
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmInit
  (JNIEnv *, jclass);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmExit
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmExit
  (JNIEnv *, jclass);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmGetBDMInformation
 * Signature: (Lnet/sourceforge/usbdm/connections/usbdm/Usbdm/BdmInformation;)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetBDMInformation
  (JNIEnv *, jclass, jobject);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmGetErrorString
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetErrorString
  (JNIEnv *, jclass, jint);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmFindDevices
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmFindDevices
  (JNIEnv *, jclass, jintArray);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmReleaseDevices
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmReleaseDevices
  (JNIEnv *, jclass);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmGetBDMSerialNumber
 * Signature: ([C)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetBDMSerialNumber
  (JNIEnv *, jclass, jbyteArray);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmGetBDMDescription
 * Signature: ([C)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetBDMDescription
  (JNIEnv *, jclass, jbyteArray);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmOpen
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmOpen
  (JNIEnv *, jclass, jint);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmClose
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmClose
  (JNIEnv *, jclass);

/*
 * Class:     Java_net_sourceforge_usbdm_jni_Usbdm
 * Method:    usbdmGetUsbdmApplicationPath
 * Signature: ([C)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetUsbdmApplicationPath
  (JNIEnv *env, jclass, jbyteArray jString);

/*
 * Class:     Java_net_sourceforge_usbdm_jni_Usbdm
 * Method:    usbdmGetUsbdmResourcePath
 * Signature: ([C)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetUsbdmResourcePath
  (JNIEnv *env, jclass, jbyteArray jString);

/*
 * Cnet.sourceforge.usbdm.jni.usbdm_jni_Usbdm
 * Method:    usbdmGetDefaultExtendedOptions
 * Signature: ([C)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetUsbdmDataPath
  (JNIEnv *env, jclass, jbyteArray jString);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmSetExtendedOptions
 * Signature: (Lnet/sourceforge/usbdm/connections/usbdm/Usbdm/BdmInformation;)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetDefaultExtendedOptions
  (JNIEnv *, jclass, jobject);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmGetBDMInformation
 * Signature: (Lnet/sourceforge/usbdm/connections/usbdm/Usbdm/BdmInformation;)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetExtendedOptions
  (JNIEnv *, jclass, jobject);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmGetExtendedOptions
 * Signature: (Lnet/sourceforge/usbdm/connections/usbdm/Usbdm/BdmInformation;)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetExtendedOptions
  (JNIEnv *, jclass, jobject);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmSetTargetType
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetTargetType
  (JNIEnv *, jclass, jint targetType);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmSetTargetVpp
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetTargetVpp
  (JNIEnv *, jclass, jint targetVpp);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmSetTargetVdd
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetTargetVdd
  (JNIEnv *, jclass, jint targetVdd);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmTargetReset
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetReset
  (JNIEnv *, jclass, jint mode);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmTargetConnect
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetConnect
  (JNIEnv *, jclass);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmReadMemory
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmReadMemory
   (JNIEnv *env, jclass, jint memorySpace, jint byteCount, jint address, jbyteArray data);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmWriteMemory
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmWriteMemory
(JNIEnv *env, jclass, jint memorySpace, jint byteCount, jint address, jbyteArray data);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmReadReg
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmReadReg
(JNIEnv *env, jclass, jint space, jint regNo, jintArray regValue);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmReadReg
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_net_sourceforge_usbdm_jni_Usbdm_usbdmWriteReg
(JNIEnv *env, jclass, jint space, jint regNo, jint jRegValue);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmReadStatusReg
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmReadStatusReg(JNIEnv *env, jclass, jintArray jRegValue);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmWriteControlReg
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmWriteControlReg(JNIEnv *env, jclass, jint space, jint regNo, jint jRegValue);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmTargetGo
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetGo(JNIEnv *, jclass);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmTargetStep
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetStep(JNIEnv *, jclass);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmTargetHalt
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmTargetHalt(JNIEnv *, jclass);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    ControlPins
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmControlPins(JNIEnv *env, jclass, jint jValue, jintArray jStatus);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmSetSpeed
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmSetSpeed(JNIEnv *env, jclass, jint jSpeed);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmGetSpeed
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetSpeed(JNIEnv *env, jclass, jintArray jSpeed);

/*
 * Class:     net.sourceforge.usbdm.jni.usbdm
 * Method:    usbdmBDMStatus
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL
Java_net_sourceforge_usbdm_jni_Usbdm_usbdmGetBDMStatus(JNIEnv *env, jclass cls, jobject jStatus);

#ifdef __cplusplus
}
#endif
#endif
