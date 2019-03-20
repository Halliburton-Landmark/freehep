#include <jni.h>

#ifndef _Included_hep_aida_jni_CUtil
#define _Included_hep_aida_jni_CUtil
#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT jclass JNICALL Java_hep_aida_jni_convert_to_class
  (JNIEnv *env, std::string type);

JNIEXPORT char* JNICALL Java_hep_aida_jni_convert_to_string
  (JNIEnv *env, jclass clazz);
#ifdef __cplusplus
}
#endif
#endif
