
#include "FreeHepTypes.h"

#include <vector>

#include "AIDA/IManagedObject.h"
#include "AIDA/ITree.h"

#include "ProxyFactory.h"

#include "CUtil.h"
#include "CITree.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CITree
 * Method:    storeName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CITree_storeName
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    string value = cref->storeName();
    jstring jvalue = env->NewStringUTF(value.c_str());
    return jvalue;
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    find
 * Signature: (Ljava/lang/String;)Lhep/aida/IManagedObject;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITree_find
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    IManagedObject* managedObject = cref->find(name);

    ProxyFactory* factory = ProxyFactory::getFactory();

    return factory->create(env, *managedObject);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    findTree
 * Signature: (Ljava/lang/String;)Lhep/aida/ITree;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITree_findTree
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    ITree* tree = cref->findTree(name);

    ProxyFactory* factory = ProxyFactory::getFactory();

    return factory->create(env, *tree);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    cd
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_cd
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->cd(name);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    pwd
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CITree_pwd
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    string value = cref->pwd();
    jstring jvalue = env->NewStringUTF(value.c_str());
    return jvalue;
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    ls
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_ls__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->ls();
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    ls
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_ls__Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->ls(name);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    ls
 * Signature: (Ljava/lang/String;Z)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_ls__Ljava_lang_String_2Z
  (JNIEnv *env, jobject obj, jstring jname, jboolean jrecursive) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->ls(name, jrecursive);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    ls
 * Signature: (Ljava/lang/String;ZLjava/io/OutputStream;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_ls__Ljava_lang_String_2ZLjava_io_OutputStream_2
  (JNIEnv *env, jobject obj, jstring jname, jboolean jrecursive, jobject jvalue) {

/*
    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);
*/
    cerr << "ERROR - CITree: ls(String, boolean, OutputStream) not implemented." << endl;
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    listObjectNames
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CITree_listObjectNames__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> names = cref->listObjectNames();

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jnames = (jobjectArray)env->NewObjectArray(names.size(), stringClass, NULL);
    for (unsigned int index=0; index<names.size(); index++) {
	    jobject jtmp = env->NewStringUTF(names[index].c_str());
        env->SetObjectArrayElement(jnames, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jnames;
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    listObjectNames
 * Signature: (Ljava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CITree_listObjectNames__Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> names = cref->listObjectNames(name);

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jnames = (jobjectArray)env->NewObjectArray(names.size(), stringClass, NULL);
    for (unsigned int index=0; index<names.size(); index++) {
	    jobject jtmp = env->NewStringUTF(names[index].c_str());
        env->SetObjectArrayElement(jnames, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jnames;
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    listObjectNames
 * Signature: (Ljava/lang/String;Z)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CITree_listObjectNames__Ljava_lang_String_2Z
  (JNIEnv *env, jobject obj, jstring jname, jboolean jrecursive) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> names = cref->listObjectNames(name, jrecursive);

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jnames = (jobjectArray)env->NewObjectArray(names.size(), stringClass, NULL);
    for (unsigned int index=0; index<names.size(); index++) {
	    jobject jtmp = env->NewStringUTF(names[index].c_str());
        env->SetObjectArrayElement(jnames, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jnames;
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    listObjectTypes
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CITree_listObjectTypes__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> types = cref->listObjectTypes();

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jtypes = (jobjectArray)env->NewObjectArray(types.size(), stringClass, NULL);
    for (unsigned int index=0; index<types.size(); index++) {
	    jobject jtmp = env->NewStringUTF(types[index].c_str());
        env->SetObjectArrayElement(jtypes, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jtypes;
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    listObjectTypes
 * Signature: (Ljava/lang/String;)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CITree_listObjectTypes__Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> types = cref->listObjectTypes(name);

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jtypes = (jobjectArray)env->NewObjectArray(types.size(), stringClass, NULL);
    for (unsigned int index=0; index<types.size(); index++) {
	    jobject jtmp = env->NewStringUTF(types[index].c_str());
        env->SetObjectArrayElement(jtypes, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jtypes;
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    listObjectTypes
 * Signature: (Ljava/lang/String;Z)[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CITree_listObjectTypes__Ljava_lang_String_2Z
  (JNIEnv *env, jobject obj, jstring jname, jboolean jrecursive) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> types = cref->listObjectTypes(name, jrecursive);

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jtypes = (jobjectArray)env->NewObjectArray(types.size(), stringClass, NULL);
    for (unsigned int index=0; index<types.size(); index++) {
	    jobject jtmp = env->NewStringUTF(types[index].c_str());
        env->SetObjectArrayElement(jtypes, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jtypes;
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    mkdir
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_mkdir
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->mkdir(name);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    mkdirs
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_mkdirs
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->mkdirs(name);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    rmdir
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_rmdir
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->rmdir(name);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    rm
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_rm
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->rm(name);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    findPath
 * Signature: (Lhep/aida/IManagedObject;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CITree_findPath
  (JNIEnv *env, jobject obj, jobject jmanagedObject) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IManagedObject* managedObject = factory->createIManagedObject(env, jmanagedObject);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    string value = cref->findPath(*managedObject);
    jstring jvalue = env->NewStringUTF(value.c_str());
    return jvalue;
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    mv
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_mv
  (JNIEnv *env, jobject obj, jstring jname1, jstring jname2) {

    jboolean isCopy1;
    string name1 = env->GetStringUTFChars(jname1, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string name2 = env->GetStringUTFChars(jname2, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->mv(name1, name2);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    commit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_commit
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->commit();
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    setOverwrite
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_setOverwrite__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->setOverwrite();
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    setOverwrite
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_setOverwrite__Z
  (JNIEnv *env, jobject obj, jboolean jstate) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->setOverwrite(jstate);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    cp
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_cp__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jname1, jstring jname2) {

    jboolean isCopy1;
    string name1 = env->GetStringUTFChars(jname1, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string name2 = env->GetStringUTFChars(jname2, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->cp(name1, name2);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    cp
 * Signature: (Ljava/lang/String;Ljava/lang/String;Z)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_cp__Ljava_lang_String_2Ljava_lang_String_2Z
  (JNIEnv *env, jobject obj, jstring jname1, jstring jname2, jboolean jrecursive) {

    jboolean isCopy1;
    string name1 = env->GetStringUTFChars(jname1, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string name2 = env->GetStringUTFChars(jname2, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->cp(name1, name2, jrecursive);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    symlink
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_symlink
  (JNIEnv *env, jobject obj, jstring jname1, jstring jname2) {

    jboolean isCopy1;
    string name1 = env->GetStringUTFChars(jname1, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string name2 = env->GetStringUTFChars(jname2, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->symlink(name1, name2);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    mount
 * Signature: (Ljava/lang/String;Lhep/aida/ITree;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_mount
  (JNIEnv *env, jobject obj, jstring jname1, jobject jtree, jstring jname2) {

    jboolean isCopy1;
    string name1 = env->GetStringUTFChars(jname1, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    ProxyFactory* factory = ProxyFactory::getFactory();

    ITree* tree = factory->createITree(env, jtree);

    jboolean isCopy2;
    string name2 = env->GetStringUTFChars(jname2, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->mount(name1, *tree, name2);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    unmount
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_unmount
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->unmount(name);
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    close
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CITree_close
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    cref->close();
}

/*
 * Class:     hep_aida_jni_CITree
 * Method:    isReadOnly
 * Signature: ()Z
 */
/*
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITree_isReadOnly
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITree* cref = (ITree*)ProxyFactory::getCRef(crefID);

    return cref->isReadOnly();
}
*/

