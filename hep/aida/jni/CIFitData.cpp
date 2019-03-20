
#include "FreeHepTypes.h"

#include "AIDA/IFitData.h"
#include "AIDA/IEvaluator.h"
#include "AIDA/IHistogram1D.h"
#include "AIDA/IHistogram2D.h"
#include "AIDA/IHistogram3D.h"
#include "AIDA/ICloud1D.h"
#include "AIDA/ICloud2D.h"
#include "AIDA/ICloud3D.h"
#include "AIDA/IProfile1D.h"
#include "AIDA/IProfile2D.h"
#include "AIDA/IDataPointSet.h"
#include "AIDA/ITuple.h"
#include "AIDA/IRangeSet.h"

#include "ProxyFactory.h"

#include "CIFitData.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create1DConnection
 * Signature: (Lhep/aida/IHistogram1D;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create1DConnection__Lhep_aida_IHistogram1D_2
  (JNIEnv *env, jobject obj, jobject jh) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IHistogram1D* h = factory->createIHistogram1D(env, jh);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create1DConnection(*h);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create1DConnection
 * Signature: (Lhep/aida/ICloud1D;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create1DConnection__Lhep_aida_ICloud1D_2
  (JNIEnv *env, jobject obj, jobject jc) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    ICloud1D* c = factory->createICloud1D(env, jc);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create1DConnection(*c);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create1DConnection
 * Signature: (Lhep/aida/IProfile1D;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create1DConnection__Lhep_aida_IProfile1D_2
  (JNIEnv *env, jobject obj, jobject jp) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IProfile1D* p = factory->createIProfile1D(env, jp);    

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create1DConnection(*p);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create1DConnection
 * Signature: (Lhep/aida/IDataPointSet;II)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create1DConnection__Lhep_aida_IDataPointSet_2II
  (JNIEnv *env, jobject obj, jobject jdp, jint x, jint val) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IDataPointSet* dp = factory->createIDataPointSet(env, jdp);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create1DConnection(*dp, x, val);
}


/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create1DConnection
 * Signature: ([D[D[[D)V
 */
//JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create1DConnection___3D_3D_3_3D
//  (JNIEnv *env, jobject obj, jdoubleArray, jdoubleArray, jobjectArray) {
//}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create2DConnection
 * Signature: (Lhep/aida/IHistogram2D;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_IHistogram2D_2
  (JNIEnv *env, jobject obj, jobject jh) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IHistogram2D* h = factory->createIHistogram2D(env, jh);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create2DConnection(*h);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create2DConnection
 * Signature: (Lhep/aida/IHistogram2D;II)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_IHistogram2D_2II
  (JNIEnv *env, jobject obj, jobject jh, jint x, jint y) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IHistogram2D* h = factory->createIHistogram2D(env, jh);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create2DConnection(*h, x, y);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create2DConnection
 * Signature: (Lhep/aida/ICloud2D;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_ICloud2D_2
  (JNIEnv *env, jobject obj, jobject jc) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    ICloud2D* c = factory->createICloud2D(env, jc);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create2DConnection(*c);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create2DConnection
 * Signature: (Lhep/aida/ICloud2D;II)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_ICloud2D_2II
  (JNIEnv *env, jobject obj, jobject jc, jint x, jint y) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    ICloud2D* c = factory->createICloud2D(env, jc);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create2DConnection(*c, x, y);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create2DConnection
 * Signature: (Lhep/aida/IProfile2D;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_IProfile2D_2
  (JNIEnv *env, jobject obj, jobject jp) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IProfile2D* p = factory->createIProfile2D(env, jp);    

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create2DConnection(*p);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create2DConnection
 * Signature: (Lhep/aida/IProfile2D;II)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_IProfile2D_2II
  (JNIEnv *env, jobject obj, jobject jp, jint x, jint y) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IProfile2D* p = factory->createIProfile2D(env, jp);    

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create2DConnection(*p, x, y);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create2DConnection
 * Signature: (Lhep/aida/IDataPointSet;III)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_IDataPointSet_2III
  (JNIEnv *env, jobject obj, jobject jdp, jint x, jint y, jint val) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IDataPointSet* dp = factory->createIDataPointSet(env, jdp);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create2DConnection(*dp, x, y, val);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create3DConnection
 * Signature: (Lhep/aida/IHistogram3D;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create3DConnection__Lhep_aida_IHistogram3D_2
  (JNIEnv *env, jobject obj, jobject jh) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IHistogram3D* h = factory->createIHistogram3D(env, jh);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create3DConnection(*h);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create3DConnection
 * Signature: (Lhep/aida/IHistogram3D;III)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create3DConnection__Lhep_aida_IHistogram3D_2III
  (JNIEnv *env, jobject obj, jobject jh, jint x, jint y, jint z) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IHistogram3D* h = factory->createIHistogram3D(env, jh);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create3DConnection(*h, x, y, z);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create3DConnection
 * Signature: (Lhep/aida/ICloud3D;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create3DConnection__Lhep_aida_ICloud3D_2
  (JNIEnv *env, jobject obj, jobject jc) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    ICloud3D* c = factory->createICloud3D(env, jc);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create3DConnection(*c);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create3DConnection
 * Signature: (Lhep/aida/ICloud3D;III)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create3DConnection__Lhep_aida_ICloud3D_2III
  (JNIEnv *env, jobject obj, jobject jc, jint x, jint y, jint z) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    ICloud3D* c = factory->createICloud3D(env, jc);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create3DConnection(*c, x, y, z);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    create3DConnection
 * Signature: (Lhep/aida/IDataPointSet;IIII)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_create3DConnection__Lhep_aida_IDataPointSet_2IIII
  (JNIEnv *env, jobject obj, jobject jdp, jint x, jint y, jint z, jint val) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IDataPointSet* dp = factory->createIDataPointSet(env, jdp);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	cref->create3DConnection(*dp, x, y, z, val);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    createConnection
 * Signature: (Lhep/aida/ITuple;[Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_createConnection__Lhep_aida_ITuple_2_3Ljava_lang_String_2
  (JNIEnv *env, jobject obj, jobject jt, jobjectArray jcolNames) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITuple* t = factory->createITuple(env, jt);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);
	
	vector<string> colNames;
    unsigned int len = env->GetArrayLength(jcolNames);
    for (unsigned int i=0; i<len; i++) {
        jboolean isCopy;
        jstring s = (jstring)env->GetObjectArrayElement(jcolNames, i);
        const char *c = env->GetStringUTFChars(s, &isCopy);
        colNames.push_back(c);
        if (isCopy == JNI_TRUE)
            env->ReleaseStringUTFChars(s, c);
        env->DeleteLocalRef(s);
    }
	
	cref->createConnection(*t, colNames);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    createConnection
 * Signature: (Lhep/aida/ITuple;[Lhep/aida/IEvaluator;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_createConnection__Lhep_aida_ITuple_2_3Lhep_aida_IEvaluator_2
  (JNIEnv *env, jobject obj, jobject jt, jobjectArray jevals) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    ITuple* t = factory->createITuple(env, jt);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);

	vector<IEvaluator *> evals;

    unsigned int len = env->GetArrayLength(jevals);
    for (unsigned int i=0; i<len; i++) {
        jobject jeval = env->GetObjectArrayElement(jevals, i);
        IEvaluator* eval = factory->createIEvaluator(env, jeval);
        evals.push_back(eval);
        env->DeleteLocalRef(jeval);
    }
	
	cref->createConnection(*t, evals);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    createConnection
 * Signature: (Lhep/aida/IDataPointSet;[II)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_createConnection__Lhep_aida_IDataPointSet_2_3II
  (JNIEnv *env, jobject obj, jobject jdp, jintArray jindices, jint val) {

    ProxyFactory* factory = ProxyFactory::getFactory();
    IDataPointSet* dp = factory->createIDataPointSet(env, jdp);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);

    vector<int> indices;
    unsigned int len = env->GetArrayLength(jindices);
    for (unsigned int i=0; i<len; i++) {
        jint d;
        env->GetIntArrayRegion(jindices, i, 1, &d);
        indices.push_back(d);
    }

	cref->createConnection(*dp, indices, val);
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    reset
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIFitData_reset
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);

    cref->reset();
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    dimension
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_hep_aida_jni_CIFitData_dimension
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);

    return cref->dimension();
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    dataDescription
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIFitData_dataDescription
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);

    string result = cref->dataDescription();
    jstring jresult = env->NewStringUTF(result.c_str());
    return jresult;
}

/*
 * Class:     hep_aida_jni_CIFitData
 * Method:    range
 * Signature: (I)Lhep/aida/IRangeSet;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIFitData_range
  (JNIEnv *env, jobject obj, jint index) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IFitData* cref = (IFitData*)ProxyFactory::getCRef(crefID);

    IRangeSet& range = cref->range(index);

    ProxyFactory* factory = ProxyFactory::getFactory();
    return factory->create(env, range);
}

