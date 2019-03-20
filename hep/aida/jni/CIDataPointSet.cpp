
#include "FreeHepTypes.h"

#include <vector>

#include "AIDA/IAnnotation.h"
#include "AIDA/IDataPoint.h"
#include "AIDA/IDataPointSet.h"

#include "ProxyFactory.h"

#include "CIDataPointSet.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIDataPointSet_annotation
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
    ProxyFactory* factory = ProxyFactory::getFactory();

    const IAnnotation& annotation = cref->annotation();
    return factory->create(env, annotation);
}

JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIDataPointSet_title
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
    string title = cref->title();
    jstring jtitle = env->NewStringUTF(title.c_str());
    return jtitle;
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_setTitle
  (JNIEnv *env, jobject obj, jstring jtitle) {

    jboolean isCopy1;
    string title = env->GetStringUTFChars(jtitle, &isCopy1);
    // FIXME 4.0, we need to deal with isCopy here..

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
	cref->setTitle(title);
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIDataPointSet_dimension
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);

    return cref->dimension(); 
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_clear
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
    cref->clear(); 
}

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIDataPointSet_size
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
    return cref->size(); 
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIDataPointSet_point
  (JNIEnv *env, jobject obj, jint jindex) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
    ProxyFactory* factory = ProxyFactory::getFactory();

    IDataPoint* point = cref->point(jindex);
    return factory->create(env, *point);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_setCoordinate__I_3D_3D
  (JNIEnv *env, jobject obj, jint jcoord, jdoubleArray jval, jdoubleArray jerr) {

    vector<double> val;
    unsigned int len = env->GetArrayLength(jval);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jval, i, 1, &d);
        val.push_back(d);
    }

    vector<double> err;
    unsigned int len2 = env->GetArrayLength(jerr);
    for (unsigned int i2=0; i2<len2; i2++) {
        jdouble d;
        env->GetDoubleArrayRegion(jerr, i2, 1, &d);
        err.push_back(d);
    }

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
    cref->setCoordinate(jcoord, val, err); 
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_setCoordinate__I_3D_3D_3D
  (JNIEnv *env, jobject obj, jint jcoord, jdoubleArray jval, jdoubleArray jerrp, jdoubleArray jerrm) {

    vector<double> val;
    unsigned int len = env->GetArrayLength(jval);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jval, i, 1, &d);
        val.push_back(d);
    }

    vector<double> errp;
    unsigned int len2 = env->GetArrayLength(jerrp);
    for (unsigned int i2=0; i2<len2; i2++) {
        jdouble d;
        env->GetDoubleArrayRegion(jerrp, i2, 1, &d);
        errp.push_back(d);
    }

    vector<double> errm;
    unsigned int len3 = env->GetArrayLength(jerrm);
    for (unsigned int i3=0; i3<len3; i3++) {
        jdouble d;
        env->GetDoubleArrayRegion(jerrm, i3, 1, &d);
        errm.push_back(d);
    }

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
    cref->setCoordinate(jcoord, val, errp, errm); 
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIDataPointSet_addPoint__
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
    ProxyFactory* factory = ProxyFactory::getFactory();

    IDataPoint* point = cref->addPoint();
    return factory->create(env, *point);
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_addPoint__Lhep_aida_IDataPoint_2
  (JNIEnv *env, jobject obj, jobject jpoint) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    IDataPoint* point = factory->createIDataPoint(env, jpoint);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);

    cref->addPoint(*point); 
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_removePoint
  (JNIEnv *env, jobject obj, jint jindex) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);

    cref->removePoint(jindex); 
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIDataPointSet_lowerExtent
  (JNIEnv *env, jobject obj, jint jcoord) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
    return cref->lowerExtent(jcoord); 
}

JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIDataPointSet_upperExtent
  (JNIEnv *env, jobject obj, jint jcoord) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
    return cref->upperExtent(jcoord); 
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_scale
  (JNIEnv *env, jobject obj, jdouble jscaleFactor) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
    cref->scale(jscaleFactor); 
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_scaleValues
  (JNIEnv *env, jobject obj, jdouble jscaleFactor) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
    cref->scaleValues(jscaleFactor); 
}

JNIEXPORT void JNICALL Java_hep_aida_jni_CIDataPointSet_scaleErrors
  (JNIEnv *env, jobject obj, jdouble jscaleFactor) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPointSet* cref = (IDataPointSet*)ProxyFactory::getCRef(crefID);
 
    cref->scaleErrors(jscaleFactor); 
}
