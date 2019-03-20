
#include "FreeHepTypes.h"

#include "Registry.h"

#include "CProxy.h"

using namespace JAIDA;

JNIEXPORT void JNICALL Java_hep_aida_jni_CProxy_finalize(JNIEnv *env, jobject jobj, jlong ID) {
    Registry::getRegistry()->remove(ID);
}
