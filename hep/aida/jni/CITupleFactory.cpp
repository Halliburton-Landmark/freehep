
#include "FreeHepTypes.h"

#include "AIDA/ITupleFactory.h"
#include "AIDA/ITuple.h"
#include "AIDA/IFilter.h"
#include "AIDA/IEvaluator.h"

#include "ProxyFactory.h"

#include "CITupleFactory.h"

#include "CUtil.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CITupleFactory
 * Method:    create
 * Signature: (Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;[Ljava/lang/Class;)Lhep/aida/ITuple;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITupleFactory_create__Ljava_lang_String_2Ljava_lang_String_2_3Ljava_lang_String_2_3Ljava_lang_Class_2
  (JNIEnv *env, jobject obj, jstring jpath, jstring jtitle, jobjectArray jcolumnNames, jobjectArray jcolumnTypes) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    jboolean isCopy1;
    string path = env->GetStringUTFChars(jpath, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string title = env->GetStringUTFChars(jtitle, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	vector<string> columnNames;
    unsigned int len = env->GetArrayLength(jcolumnNames);
    for (unsigned int i=0; i<len; i++) {
        jboolean isCopy;
        jstring s = (jstring)env->GetObjectArrayElement(jcolumnNames, i);
        const char *c = env->GetStringUTFChars(s, &isCopy);
        columnNames.push_back(c);
        if (isCopy == JNI_TRUE)
            env->ReleaseStringUTFChars(s, c);
        env->DeleteLocalRef(s);
    }
	
	vector<string> columnTypes;
    len = env->GetArrayLength(jcolumnTypes);
    for (unsigned int i=0; i<len; i++) {
        jclass c = (jclass)env->GetObjectArrayElement(jcolumnTypes, i);
        columnNames.push_back(string(Java_hep_aida_jni_convert_to_string(env, c)));
    }	

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITupleFactory* cref = (ITupleFactory*)ProxyFactory::getCRef(crefID);

    ITuple* result = cref->create(path, title, columnNames, columnTypes);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CITupleFactory
 * Method:    create
 * Signature: (Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;[Ljava/lang/Class;Ljava/lang/String;)Lhep/aida/ITuple;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITupleFactory_create__Ljava_lang_String_2Ljava_lang_String_2_3Ljava_lang_String_2_3Ljava_lang_Class_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jpath, jstring jtitle, jobjectArray jcolumnNames, jobjectArray jcolumnTypes, jstring joptions) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    jboolean isCopy1;
    string path = env->GetStringUTFChars(jpath, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string title = env->GetStringUTFChars(jtitle, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy3;
    string options = env->GetStringUTFChars(joptions, &isCopy3);
    // FIXME 4.0, we need to deal with isCopy here..

	vector<string> columnNames;
    unsigned int len = env->GetArrayLength(jcolumnNames);
    for (unsigned int i=0; i<len; i++) {
        jboolean isCopy;
        jstring s = (jstring)env->GetObjectArrayElement(jcolumnNames, i);
        const char *c = env->GetStringUTFChars(s, &isCopy);
        columnNames.push_back(c);
        if (isCopy == JNI_TRUE)
            env->ReleaseStringUTFChars(s, c);
        env->DeleteLocalRef(s);
    }
	
	// FIXME 3.2.4 columnTypes needs conversion from string to Class
	vector<string> columnTypes;

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITupleFactory* cref = (ITupleFactory*)ProxyFactory::getCRef(crefID);

    ITuple* result = cref->create(path, title, columnNames, columnTypes, options);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CITupleFactory
 * Method:    create
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/ITuple;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITupleFactory_create__Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jpath, jstring jtitle, jstring jcolumns) {

    jboolean isCopy1;
    string path = env->GetStringUTFChars(jpath, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string title = env->GetStringUTFChars(jtitle, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy3;
    string columns = env->GetStringUTFChars(jcolumns, &isCopy3);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITupleFactory* cref = (ITupleFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITuple* result = cref->create(path, title, columns);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CITupleFactory
 * Method:    create
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/ITuple;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITupleFactory_create__Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jpath, jstring jtitle, jstring jcolumns, jstring joptions) {

    jboolean isCopy1;
    string path = env->GetStringUTFChars(jpath, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string title = env->GetStringUTFChars(jtitle, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy3;
    string columns = env->GetStringUTFChars(jcolumns, &isCopy3);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy4;
    string options = env->GetStringUTFChars(joptions, &isCopy4);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITupleFactory* cref = (ITupleFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITuple* result = cref->create(path, title, columns, options);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CITupleFactory
 * Method:    createChained
 * Signature: (Ljava/lang/String;Ljava/lang/String;[Lhep/aida/ITuple;)Lhep/aida/ITuple;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITupleFactory_createChained__Ljava_lang_String_2Ljava_lang_String_2_3Lhep_aida_ITuple_2
  (JNIEnv *env, jobject obj, jstring jpath, jstring jtitle, jobjectArray jset) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    jboolean isCopy1;
    string path = env->GetStringUTFChars(jpath, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string title = env->GetStringUTFChars(jtitle, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	vector<ITuple *> set;
    unsigned int len = env->GetArrayLength(jset);
    for (unsigned int i=0; i<len; i++) {
        jobject o = env->GetObjectArrayElement(jset, i);
        ITuple* tuple = factory->createITuple(env, o);
        set.push_back(tuple);
    }
	
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITupleFactory* cref = (ITupleFactory*)ProxyFactory::getCRef(crefID);

    ITuple* result = cref->createChained(path, title, set);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CITupleFactory
 * Method:    createChained
 * Signature: (Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Lhep/aida/ITuple;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITupleFactory_createChained__Ljava_lang_String_2Ljava_lang_String_2_3Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jpath, jstring jtitle, jobjectArray jset) {

    jboolean isCopy1;
    string path = env->GetStringUTFChars(jpath, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    jboolean isCopy2;
    string title = env->GetStringUTFChars(jtitle, &isCopy2);
    // FIXME 4.0, we need to deal with isCopy here..

	vector<string> set;
    unsigned int len = env->GetArrayLength(jset);
    for (unsigned int i=0; i<len; i++) {
        jboolean isCopy;
        jstring s = (jstring)env->GetObjectArrayElement(jset, i);
        const char *c = env->GetStringUTFChars(s, &isCopy);
        set.push_back(c);
        if (isCopy == JNI_TRUE)
            env->ReleaseStringUTFChars(s, c);
        env->DeleteLocalRef(s);
    }
	
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITupleFactory* cref = (ITupleFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITuple* result = cref->createChained(path, title, set);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CITupleFactory
 * Method:    createFiltered
 * Signature: (Ljava/lang/String;Lhep/aida/ITuple;Lhep/aida/IFilter;)Lhep/aida/ITuple;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITupleFactory_createFiltered__Ljava_lang_String_2Lhep_aida_ITuple_2Lhep_aida_IFilter_2
  (JNIEnv *env, jobject obj, jstring jpath, jobject jtuple, jobject jfilter) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    jboolean isCopy1;
    string path = env->GetStringUTFChars(jpath, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    ITuple* tuple = factory->createITuple(env, jtuple);
    IFilter* filter = factory->createIFilter(env, jfilter);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITupleFactory* cref = (ITupleFactory*)ProxyFactory::getCRef(crefID);

    ITuple* result = cref->createFiltered(path, *tuple, *filter);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CITupleFactory
 * Method:    createFiltered
 * Signature: (Ljava/lang/String;Lhep/aida/ITuple;Lhep/aida/IFilter;[Ljava/lang/String;)Lhep/aida/ITuple;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITupleFactory_createFiltered__Ljava_lang_String_2Lhep_aida_ITuple_2Lhep_aida_IFilter_2_3Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jpath, jobject jtuple, jobject jfilter, jobjectArray jcolumns) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    jboolean isCopy1;
    string path = env->GetStringUTFChars(jpath, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

    ITuple* tuple = factory->createITuple(env, jtuple);
    IFilter* filter = factory->createIFilter(env, jfilter);

	vector<string> columns;
    unsigned int len = env->GetArrayLength(jcolumns);
    for (unsigned int i=0; i<len; i++) {
        jboolean isCopy;
        jstring s = (jstring)env->GetObjectArrayElement(jcolumns, i);
        const char *c = env->GetStringUTFChars(s, &isCopy);
        columns.push_back(c);
        if (isCopy == JNI_TRUE)
            env->ReleaseStringUTFChars(s, c);
        env->DeleteLocalRef(s);
    }
	
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITupleFactory* cref = (ITupleFactory*)ProxyFactory::getCRef(crefID);

    ITuple* result = cref->createFiltered(path, *tuple, *filter, columns);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CITupleFactory
 * Method:    createFilter
 * Signature: (Ljava/lang/String;)Lhep/aida/IFilter;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITupleFactory_createFilter__Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jstring jexpression) {

    jboolean isCopy1;
    string expression = env->GetStringUTFChars(jexpression, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITupleFactory* cref = (ITupleFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFilter* result = cref->createFilter(expression);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CITupleFactory
 * Method:    createFilter
 * Signature: (Ljava/lang/String;I)Lhep/aida/IFilter;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITupleFactory_createFilter__Ljava_lang_String_2I
  (JNIEnv *env, jobject obj, jstring jexpression, jint rows) {

    jboolean isCopy1;
    string expression = env->GetStringUTFChars(jexpression, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITupleFactory* cref = (ITupleFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFilter* result = cref->createFilter(expression, rows);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CITupleFactory
 * Method:    createFilter
 * Signature: (Ljava/lang/String;II)Lhep/aida/IFilter;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITupleFactory_createFilter__Ljava_lang_String_2II
  (JNIEnv *env, jobject obj, jstring jexpression, jint rows, jint start) {

    jboolean isCopy1;
    string expression = env->GetStringUTFChars(jexpression, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITupleFactory* cref = (ITupleFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IFilter* result = cref->createFilter(expression, rows, start);
    return factory->create(env, *result);
}

/*
 * Class:     hep_aida_jni_CITupleFactory
 * Method:    createEvaluator
 * Signature: (Ljava/lang/String;)Lhep/aida/IEvaluator;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITupleFactory_createEvaluator
  (JNIEnv *env, jobject obj, jstring jexpression) {

    jboolean isCopy1;
    string expression = env->GetStringUTFChars(jexpression, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITupleFactory* cref = (ITupleFactory*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();
    IEvaluator* result = cref->createEvaluator(expression);
    return factory->create(env, *result);
}
