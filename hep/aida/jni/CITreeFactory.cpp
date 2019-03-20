
#include "FreeHepTypes.h"

#include "AIDA/ITreeFactory.h"
#include "AIDA/ITree.h"

#include "ProxyFactory.h"

#include "CITreeFactory.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CITreeFactory
 * Method:    create
 * Signature: ()Lhep/aida/ITree;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITreeFactory_create__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITreeFactory* cref = (ITreeFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITree* tree = cref->create();
    return factory->create(env, *tree);
}

/*
 * Class:     hep_aida_jni_CITreeFactory
 * Method:    create
 * Signature: (Ljava/lang/String;)Lhep/aida/ITree;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITreeFactory_create__Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITreeFactory* cref = (ITreeFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITree* tree = cref->create(name);
    return factory->create(env, *tree);
}

/*
 * Class:     hep_aida_jni_CITreeFactory
 * Method:    create
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Lhep/aida/ITree;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITreeFactory_create__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname, jstring jtype) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string type = env->GetStringUTFChars(jtype, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITreeFactory* cref = (ITreeFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITree* tree = cref->create(name, type);
    return factory->create(env, *tree);
}

/*
 * Class:     hep_aida_jni_CITreeFactory
 * Method:    create
 * Signature: (Ljava/lang/String;Ljava/lang/String;Z)Lhep/aida/ITree;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITreeFactory_create__Ljava_lang_String_2Ljava_lang_String_2Z
  (JNIEnv *env, jobject obj, jstring jname, jstring jtype, jboolean readOnly) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string type = env->GetStringUTFChars(jtype, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITreeFactory* cref = (ITreeFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITree* tree = cref->create(name, type, readOnly);
    return factory->create(env, *tree);
}

/*
 * Class:     hep_aida_jni_CITreeFactory
 * Method:    create
 * Signature: (Ljava/lang/String;Ljava/lang/String;ZZ)Lhep/aida/ITree;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITreeFactory_create__Ljava_lang_String_2Ljava_lang_String_2ZZ
  (JNIEnv *env, jobject obj, jstring jname, jstring jtype, jboolean readOnly, jboolean createNew) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string type = env->GetStringUTFChars(jtype, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITreeFactory* cref = (ITreeFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITree* tree = cref->create(name, type, readOnly, createNew);
    return factory->create(env, *tree);
}

/*
 * Class:     hep_aida_jni_CITreeFactory
 * Method:    create
 * Signature: (Ljava/lang/String;Ljava/lang/String;ZZLjava/lang/String;)Lhep/aida/ITree;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITreeFactory_create__Ljava_lang_String_2Ljava_lang_String_2ZZLjava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname, jstring jtype, jboolean readOnly, jboolean createNew, jstring joptions) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string type = env->GetStringUTFChars(jtype, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy3;
    string options = env->GetStringUTFChars(joptions, &isCopy3);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITreeFactory* cref = (ITreeFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITree* tree = cref->create(name, type, readOnly, createNew, options);
    return factory->create(env, *tree);
}
