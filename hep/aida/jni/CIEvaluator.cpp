
#include "FreeHepTypes.h"

#include "AIDA/IEvaluator.h"
#include "AIDA/ITuple.h"

#include "ProxyFactory.h"

#include "CIEvaluator.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIEvaluator
 * Method:    initialize
 * Signature: (Lhep/aida/ITuple;)V
 */
JNIEXPORT void JNICALL Java_hep_aida_jni_CIEvaluator_initialize
  (JNIEnv *env, jobject obj, jobject jtuple) {
    ProxyFactory* factory = ProxyFactory::getFactory();

    ITuple* tuple = factory->createITuple(env, jtuple);

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IEvaluator* cref = (IEvaluator*)ProxyFactory::getCRef(crefID);

    cref->initialize(*tuple);
}

/*
 * Class:     hep_aida_jni_CIEvaluator
 * Method:    evaluateDouble
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_hep_aida_jni_CIEvaluator_evaluateDouble
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IEvaluator* cref = (IEvaluator*)ProxyFactory::getCRef(crefID);

    return cref->evaluateDouble();
}

/*
 * Class:     hep_aida_jni_CIEvaluator
 * Method:    expression
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_hep_aida_jni_CIEvaluator_expression
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IEvaluator* cref = (IEvaluator*)ProxyFactory::getCRef(crefID);

    string result = cref->expression();
    jstring jresult = env->NewStringUTF(result.c_str());
    return jresult;
}
