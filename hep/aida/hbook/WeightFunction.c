
#include <stdio.h>

#include "jni.h"

#include "WeightFunction.h"


jclass clazz = NULL;
jfieldID ptrID = NULL;

void WF_init(JNIEnv *env, jobject obj) {
    if (clazz == NULL) clazz = (*env)->GetObjectClass(env, obj);
    if (ptrID == NULL) ptrID = (*env)->GetFieldID(env, clazz, "functionPtr", "J");
}    


/**
 * HBOOK-AIDA WeightFunction stub to callback c or FORTRAN
 *
 *
 * @author Mark Donszelmann
 * @version $Id: WeightFunction.c,v 1.2 2001/03/28 20:42:31 duns Exp $
 */

/*
 * Class:     hep_aida_hbook_WeightFunction
 * Method:    weight
 * Signature: (FI)F
 */
JNIEXPORT jfloat JNICALL Java_hep_aida_hbook_WeightFunction_weight__FI
  (JNIEnv *env, jobject obj, jfloat x, jint isel) {
    
    jlong ptr;
    jfloat weight;
    WF_init(env, obj);
        
    ptr = (*env)->GetLongField(env, clazz, ptrID);
    weight = ((jfloat (*)(jfloat*, jint*))ptr)(&x, &isel);
    return weight;
}

/*
 * Class:     hep_aida_hbook_WeightFunction
 * Method:    weight
 * Signature: (FFI)F
 */
JNIEXPORT jfloat JNICALL Java_hep_aida_hbook_WeightFunction_weight__FFI
  (JNIEnv *env, jobject obj, jfloat x, jfloat y, jint isel) {
    
    jlong ptr;
    jfloat weight;
    jfloat (*pf)(float, float, int);
    WF_init(env, obj);
    ptr = (*env)->GetLongField(env, clazz, ptrID);
    weight = ((jfloat (*)(jfloat*, jfloat*, jint*))ptr)(&x, &y, &isel);
    return weight;
}

