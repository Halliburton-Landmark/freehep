
#include "FreeHepTypes.h"

#include "AIDA/IFunctionCatalog.h"
#include "AIDA/IFunction.h"

#include "ProxyFactory.h"

#include "CIFunctionCatalog.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIFunctionCatalog
 * Method:    add
 * Signature: (Ljava/lang/String;Lhep/aida/IFunction;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIFunctionCatalog_add__Ljava_lang_String_2Lhep_aida_IFunction_2
  (JNIEnv *env, jobject obj, jstring jname, jobject jfunction) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFunction* function = factory->createIFunction(env, jfunction);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunctionCatalog* cref = (IFunctionCatalog*)ProxyFactory::getCRef(crefID);

    return cref->add(name, function);
}

/*
 * Class:     hep_aida_jni_CIFunctionCatalog
 * Method:    add
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIFunctionCatalog_add__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname, jstring jcodelet) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string codelet = env->GetStringUTFChars(jcodelet, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunctionCatalog* cref = (IFunctionCatalog*)ProxyFactory::getCRef(crefID);

    return cref->add(name, codelet);
}

/*
 * Class:     hep_aida_jni_CIFunctionCatalog
 * Method:    list
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CIFunctionCatalog_list
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunctionCatalog* cref = (IFunctionCatalog*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> result = cref->list();

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jresult = env->NewObjectArray(result.size(), stringClass, NULL);
    for (unsigned int index=0; index<result.size(); index++) {
	    jobject jtmp = env->NewStringUTF(result[index].c_str());
        env->SetObjectArrayElement(jresult, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jresult;
}

/*
 * Class:     hep_aida_jni_CIFunctionCatalog
 * Method:    remove
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFunctionCatalog_remove
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunctionCatalog* cref = (IFunctionCatalog*)ProxyFactory::getCRef(crefID);

    cref->remove(name);
}

/*
 * Class:     hep_aida_jni_CIFunctionCatalog
 * Method:    storeAll
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFunctionCatalog_storeAll
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunctionCatalog* cref = (IFunctionCatalog*)ProxyFactory::getCRef(crefID);

    cref->storeAll(name);
}

/*
 * Class:     hep_aida_jni_CIFunctionCatalog
 * Method:    loadAll
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFunctionCatalog_loadAll
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFunctionCatalog* cref = (IFunctionCatalog*)ProxyFactory::getCRef(crefID);

    cref->loadAll(name);
}
