
#include "FreeHepTypes.h"

#include <vector>

#include "AIDA/IDataPoint.h"

#include "ProxyFactory.h"

#include "CIDataPoint.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

JNIEXPORT jint JNICALL Java_hep_aida_jni_CIDataPoint_dimension
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPoint* cref = (IDataPoint*)ProxyFactory::getCRef(crefID);
 
    return cref->dimension();
}

JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIDataPoint_coordinate
  (JNIEnv *env, jobject obj, jint jvalue) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IDataPoint* cref = (IDataPoint*)ProxyFactory::getCRef(crefID);
 
    
    ProxyFactory* factory = ProxyFactory::getFactory();

    IMeasurement* measurement = cref->coordinate(jvalue);
    return factory->create(env, *measurement);
}
