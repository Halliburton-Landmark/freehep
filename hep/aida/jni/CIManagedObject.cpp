
#include "FreeHepTypes.h"

#include "AIDA/IManagedObject.h"

#include "ProxyFactory.h"

#include "CIManagedObject.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIManagedObject
 * Method:    name
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIManagedObject_name
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IManagedObject* cref = (IManagedObject*)ProxyFactory::getCRef(crefID);

    string result = cref->name();
    jstring jresult = env->NewStringUTF(result.c_str());
    return jresult;
}

/*
 * Class:     hep_aida_jni_CIManagedObject
 * Method:    type
 * Signature: ()Ljava/lang/String;
 */
/*
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIManagedObject_type
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IManagedObject* cref = (IManagedObject*)ProxyFactory::getCRef(crefID);

    string result = cref->type();
    jstring jresult = env->NewStringUTF(result.c_str());
    return jresult;
}
*/
