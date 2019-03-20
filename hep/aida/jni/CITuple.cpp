
#include "FreeHepTypes.h"

#include <vector>

#include "AIDA/IAnnotation.h"
#include "AIDA/ITuple.h"

#include "ProxyFactory.h"

#include "CUtil.h"
#include "CITuple.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT jstring JNICALL Java_hep_aida_jni_CITuple_title
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    string title = cref->title();
    jstring jtitle = env->NewStringUTF(title.c_str());
    return jtitle;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_setTitle
  (JNIEnv *env, jobject obj, jstring jtitle) {

    jboolean isCopy1;
    string title = env->GetStringUTFChars(jtitle, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);
	
	cref->setTitle(title);
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITuple_annotation
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);
	
    ProxyFactory* factory = ProxyFactory::getFactory();

    const IAnnotation& annotation = cref->annotation();
    return factory->create(env, annotation);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_fill__ID
  (JNIEnv *env, jobject obj, jint jcolumn, jdouble jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->fill(jcolumn, jvalue);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_fill__IF
  (JNIEnv *env, jobject obj, jint jcolumn, jfloat jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->fill(jcolumn, jvalue);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_fill__II
  (JNIEnv *env, jobject obj, jint jcolumn, jint jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->fill(jcolumn, jvalue);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_fill__IS
  (JNIEnv *env, jobject obj, jint jcolumn, jshort jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->fill(jcolumn, jvalue);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_fill__IJ
  (JNIEnv *env, jobject obj, jint jcolumn, jlong jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);
// NOTE cast needed for ambiguity with int fill
    cref->fill(jcolumn, (long)jvalue);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_fill__IC
  (JNIEnv *env, jobject obj, jint jcolumn, jchar jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->fill(jcolumn, jvalue);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_fill__IB
  (JNIEnv *env, jobject obj, jint jcolumn, jbyte jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->fill(jcolumn, jvalue);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_fill__IZ
  (JNIEnv *env, jobject obj, jint jcolumn, jboolean jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->fill(jcolumn, jvalue);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_fill__ILjava_lang_String_2
  (JNIEnv *env, jobject obj, jint jcolumn, jstring jvalue) {

    jboolean isCopy1;
    string value = env->GetStringUTFChars(jvalue, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->fill(jcolumn, jvalue);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_fill__ILjava_lang_Object_2
  (JNIEnv *env, jobject obj, jint jcolumn, jobject jvalue) {

/*
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);
*/
    // FIXME
    cerr << "CITuple.fill(column, object) not implemented." << endl;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_fill___3D
  (JNIEnv *env, jobject obj, jdoubleArray jvalue) {

    vector<double> value;
    unsigned int len = env->GetArrayLength(jvalue);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jvalue, i, 1, &d);
        value.push_back(d);
    }

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->fill(value);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_fill___3F
  (JNIEnv *env, jobject obj, jfloatArray jvalue) {

    vector<float> value;
    unsigned int len = env->GetArrayLength(jvalue);
    for (unsigned int i=0; i<len; i++) {
        jfloat f;
        env->GetFloatArrayRegion(jvalue, i, 1, &f);
        value.push_back(f);
    }

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->fill(value);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_addRow
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->addRow();
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_resetRow
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->resetRow();
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_reset
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->reset();
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CITuple_rows
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);
 
    return cref->rows();
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_start
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->start();
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_skip
  (JNIEnv *env, jobject obj, jint jrows) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->skip(jrows);
}

JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITuple_next
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->next();
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_setRow
  (JNIEnv *env, jobject obj, jint jrowIndex) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->setRow(jrowIndex);
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CITuple_findColumn
  (JNIEnv *env, jobject obj, jstring jname) {

    jboolean isCopy1;
    string name = env->GetStringUTFChars(jname, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->findColumn(name);
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CITuple_getDouble
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->getDouble(jcolumn);
}

JNIEXPORT jfloat JNICALL Java_hep_aida_jni_CITuple_getFloat
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->getFloat(jcolumn);
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CITuple_getInt
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->getInt(jcolumn);
}

JNIEXPORT jshort JNICALL Java_hep_aida_jni_CITuple_getShort
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->getShort(jcolumn);
}

JNIEXPORT jlong JNICALL Java_hep_aida_jni_CITuple_getLong
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->getLong(jcolumn);
}

JNIEXPORT jchar JNICALL Java_hep_aida_jni_CITuple_getChar
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->getChar(jcolumn);
}

JNIEXPORT jbyte JNICALL Java_hep_aida_jni_CITuple_getByte
  (JNIEnv *env, jobject obj, jint jcolumn) {

/*
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);
*/
// FIXME 3.3
    cerr << "CITuple.getByte not implemented in C++." << endl;

    return 0;
}

JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CITuple_getBoolean
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->getBoolean(jcolumn);
}

JNIEXPORT jstring JNICALL Java_hep_aida_jni_CITuple_getString
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    string value = cref->getString(jcolumn);
    jstring jvalue = env->NewStringUTF(value.c_str());
    return jvalue;
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITuple_getObject
  (JNIEnv *env, jobject obj, jint jcolumn) {

/*
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);
*/
// FIXME 3.3
    cerr << "CITuple.getObject not implemented." << endl;

    return NULL;
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CITuple_getTuple
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    ProxyFactory* factory = ProxyFactory::getFactory();

    const ITuple* tuple = cref->getTuple(jcolumn);
    return factory->create(env, *tuple);
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CITuple_columns
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->columns();
}

JNIEXPORT jstring JNICALL Java_hep_aida_jni_CITuple_columnName
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    string value = cref->columnName(jcolumn);
    jstring jvalue = env->NewStringUTF(value.c_str());
    return jvalue;
}

JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CITuple_columnNames
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> names = cref->columnNames();

    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray jnames = (jobjectArray)env->NewObjectArray(names.size(), stringClass, NULL);
    for (unsigned int index=0; index<names.size(); index++) {
	    jobject jtmp = env->NewStringUTF(names[index].c_str());
        env->SetObjectArrayElement(jnames, index, jtmp);
        env->DeleteLocalRef(jtmp);
    }

    return jnames;
}

JNIEXPORT jclass JNICALL Java_hep_aida_jni_CITuple_columnType
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return Java_hep_aida_jni_convert_to_class(env, cref->columnType(jcolumn));
}

JNIEXPORT jobjectArray JNICALL Java_hep_aida_jni_CITuple_columnTypes
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    std::vector<std::string> types = cref->columnTypes();

    jclass classClass = env->FindClass("java/lang/Class");
    jobjectArray jtypes = (jobjectArray)env->NewObjectArray(types.size(), classClass, NULL);
    for (unsigned int index=0; index<types.size(); index++) {
        env->SetObjectArrayElement(jtypes, index, Java_hep_aida_jni_convert_to_class(env, types[index]));
    }

    return jtypes;
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CITuple_columnMin
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->columnMin(jcolumn);
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CITuple_columnMax
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->columnMax(jcolumn);
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CITuple_columnMean
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->columnMean(jcolumn);
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CITuple_columnRms
  (JNIEnv *env, jobject obj, jint jcolumn) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    return cref->columnRms(jcolumn);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram1D_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jhistogram, jobject jevaluatorX) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram1D* histogram = factory->createIHistogram1D(env, jhistogram);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*histogram, *evaluatorX);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram1D_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2
  (JNIEnv *env, jobject obj, jobject jhistogram, jobject jevaluatorX, jobject jfilter) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram1D* histogram = factory->createIHistogram1D(env, jhistogram);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IFilter* filter = factory->createIFilter(env, jfilter);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*histogram, *evaluatorX, *filter);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram1D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jhistogram, jobject jevaluatorX, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram1D* histogram = factory->createIHistogram1D(env, jhistogram);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*histogram, *evaluatorX, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram1D_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jhistogram, jobject jevaluatorX, jobject jfilter, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram1D* histogram = factory->createIHistogram1D(env, jhistogram);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IFilter* filter = factory->createIFilter(env, jfilter);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*histogram, *evaluatorX, *filter, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jhistogram, jobject jevaluatorX, jobject jevaluatorY) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram2D* histogram = factory->createIHistogram2D(env, jhistogram);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*histogram, *evaluatorX, *evaluatorY);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2
  (JNIEnv *env, jobject obj, jobject jhistogram, jobject jevaluatorX, jobject jevaluatorY, jobject jfilter) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IFilter* filter = factory->createIFilter(env, jfilter);

    IHistogram2D* histogram = factory->createIHistogram2D(env, jhistogram);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*histogram, *evaluatorX, *evaluatorY, *filter);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jhistogram, jobject jevaluatorX, jobject jevaluatorY, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram2D* histogram = factory->createIHistogram2D(env, jhistogram);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*histogram, *evaluatorX, *evaluatorY, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jhistogram, jobject jevaluatorX, jobject jevaluatorY, jobject jfilter, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram2D* histogram = factory->createIHistogram2D(env, jhistogram);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IFilter* filter = factory->createIFilter(env, jfilter);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*histogram, *evaluatorX, *evaluatorY, *filter, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jhistogram, jobject jevaluatorX, jobject jevaluatorY, jobject jevaluatorZ) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram3D* histogram = factory->createIHistogram3D(env, jhistogram);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* evaluatorZ = factory->createIEvaluator(env, jevaluatorZ);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*histogram, *evaluatorX, *evaluatorY, *evaluatorZ);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2
  (JNIEnv *env, jobject obj, jobject jhistogram, jobject jevaluatorX, jobject jevaluatorY, jobject jevaluatorZ, jobject jfilter) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram3D* histogram = factory->createIHistogram3D(env, jhistogram);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* evaluatorZ = factory->createIEvaluator(env, jevaluatorZ);
    IFilter* filter = factory->createIFilter(env, jfilter);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*histogram, *evaluatorX, *evaluatorY, *evaluatorZ, *filter);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jhistogram, jobject jevaluatorX, jobject jevaluatorY, jobject jevaluatorZ, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram3D* histogram = factory->createIHistogram3D(env, jhistogram);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* evaluatorZ = factory->createIEvaluator(env, jevaluatorZ);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*histogram, *evaluatorX, *evaluatorY, *evaluatorZ, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jhistogram, jobject jevaluatorX, jobject jevaluatorY, jobject jevaluatorZ, jobject jfilter, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IHistogram3D* histogram = factory->createIHistogram3D(env, jhistogram);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* evaluatorZ = factory->createIEvaluator(env, jevaluatorZ);
    IFilter* filter = factory->createIFilter(env, jfilter);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*histogram, *evaluatorX, *evaluatorY, *evaluatorZ, *filter, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud1D_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jcloud, jobject jevaluatorX) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ICloud1D* cloud = factory->createICloud1D(env, jcloud);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*cloud, *evaluatorX);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud1D_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2
  (JNIEnv *env, jobject obj, jobject jcloud, jobject jevaluatorX, jobject jfilter) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ICloud1D* cloud = factory->createICloud1D(env, jcloud);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IFilter* filter = factory->createIFilter(env, jfilter);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*cloud, *evaluatorX, *filter);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud1D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jcloud, jobject jevaluatorX, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ICloud1D* cloud = factory->createICloud1D(env, jcloud);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*cloud, *evaluatorX, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud1D_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jcloud, jobject jevaluatorX, jobject jfilter, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ICloud1D* cloud = factory->createICloud1D(env, jcloud);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IFilter* filter = factory->createIFilter(env, jfilter);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*cloud, *evaluatorX, *filter, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jcloud, jobject jevaluatorX, jobject jevaluatorY) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ICloud2D* cloud = factory->createICloud2D(env, jcloud);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*cloud, *evaluatorX, *evaluatorY);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2
  (JNIEnv *env, jobject obj, jobject jcloud, jobject jevaluatorX, jobject jevaluatorY, jobject jfilter) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ICloud2D* cloud = factory->createICloud2D(env, jcloud);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IFilter* filter = factory->createIFilter(env, jfilter);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*cloud, *evaluatorX, *evaluatorY, *filter);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jcloud, jobject jevaluatorX, jobject jevaluatorY, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ICloud2D* cloud = factory->createICloud2D(env, jcloud);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*cloud, *evaluatorX, *evaluatorY, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jcloud, jobject jevaluatorX, jobject jevaluatorY, jobject jfilter, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ICloud2D* cloud = factory->createICloud2D(env, jcloud);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IFilter* filter = factory->createIFilter(env, jfilter);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*cloud, *evaluatorX, *evaluatorY, *filter, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jcloud, jobject jevaluatorX, jobject jevaluatorY, jobject jevaluatorZ) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ICloud3D* cloud = factory->createICloud3D(env, jcloud);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* evaluatorZ = factory->createIEvaluator(env, jevaluatorZ);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*cloud, *evaluatorX, *evaluatorY, *evaluatorZ);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2
  (JNIEnv *env, jobject obj, jobject jcloud, jobject jevaluatorX, jobject jevaluatorY, jobject jevaluatorZ, jobject jfilter) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ICloud3D* cloud = factory->createICloud3D(env, jcloud);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* evaluatorZ = factory->createIEvaluator(env, jevaluatorZ);
    IFilter* filter = factory->createIFilter(env, jfilter);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*cloud, *evaluatorX, *evaluatorY, *evaluatorZ, *filter);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jcloud, jobject jevaluatorX, jobject jevaluatorY, jobject jevaluatorZ, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ICloud3D* cloud = factory->createICloud3D(env, jcloud);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* evaluatorZ = factory->createIEvaluator(env, jevaluatorZ);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*cloud, *evaluatorX, *evaluatorY, *evaluatorZ, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jcloud, jobject jevaluatorX, jobject jevaluatorY, jobject jevaluatorZ, jobject jfilter, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ICloud3D* cloud = factory->createICloud3D(env, jcloud);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* evaluatorZ = factory->createIEvaluator(env, jevaluatorZ);
    IFilter* filter = factory->createIFilter(env, jfilter);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*cloud, *evaluatorX, *evaluatorY, *evaluatorZ, *filter, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile1D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jprofile, jobject jevaluatorX, jobject jevaluatorY) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IProfile1D* profile = factory->createIProfile1D(env, jprofile);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*profile, *evaluatorX, *evaluatorY);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile1D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2
  (JNIEnv *env, jobject obj, jobject jprofile, jobject jevaluatorX, jobject jevaluatorY, jobject jfilter) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IProfile1D* profile = factory->createIProfile1D(env, jprofile);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IFilter* filter = factory->createIFilter(env, jfilter);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*profile, *evaluatorX, *evaluatorY, *filter);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile1D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jprofile, jobject jevaluatorX, jobject jevaluatorY, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IProfile1D* profile = factory->createIProfile1D(env, jprofile);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*profile, *evaluatorX, *evaluatorY, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile1D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jprofile, jobject jevaluatorX, jobject jevaluatorY, jobject jfilter, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IProfile1D* profile = factory->createIProfile1D(env, jprofile);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IFilter* filter = factory->createIFilter(env, jfilter);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*profile, *evaluatorX, *evaluatorY, *filter, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jprofile, jobject jevaluatorX, jobject jevaluatorY, jobject jevaluatorZ) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IProfile2D* profile = factory->createIProfile2D(env, jprofile);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* evaluatorZ = factory->createIEvaluator(env, jevaluatorZ);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*profile, *evaluatorX, *evaluatorY, *evaluatorZ);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2
  (JNIEnv *env, jobject obj, jobject jprofile, jobject jevaluatorX, jobject jevaluatorY, jobject jevaluatorZ, jobject jfilter) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IProfile2D* profile = factory->createIProfile2D(env, jprofile);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* evaluatorZ = factory->createIEvaluator(env, jevaluatorZ);
    IFilter* filter = factory->createIFilter(env, jfilter);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*profile, *evaluatorX, *evaluatorY, *evaluatorZ, *filter);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jprofile, jobject jevaluatorX, jobject jevaluatorY, jobject jevaluatorZ, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IProfile2D* profile = factory->createIProfile2D(env, jprofile);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* evaluatorZ = factory->createIEvaluator(env, jevaluatorZ);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*profile, *evaluatorX, *evaluatorY, *evaluatorZ, *weight);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jprofile, jobject jevaluatorX, jobject jevaluatorY, jobject jevaluatorZ, jobject jfilter, jobject jweight) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IProfile2D* profile = factory->createIProfile2D(env, jprofile);
    IEvaluator* evaluatorX = factory->createIEvaluator(env, jevaluatorX);
    IEvaluator* evaluatorY = factory->createIEvaluator(env, jevaluatorY);
    IEvaluator* evaluatorZ = factory->createIEvaluator(env, jevaluatorZ);
    IFilter* filter = factory->createIFilter(env, jfilter);
    IEvaluator* weight = factory->createIEvaluator(env, jweight);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	ITuple* cref = (ITuple*)ProxyFactory::getCRef(crefID);

    cref->project(*profile, *evaluatorX, *evaluatorY, *evaluatorZ, *filter, *weight);
}
