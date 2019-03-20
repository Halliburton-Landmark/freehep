
#include "FreeHepTypes.h"

#include <iostream>
#include <string>

#include "CUtil.h"

#include "JNIMacros.hh"

using namespace std;

jboolean Java_hep_aida_jni_inited = false;
jclass Java_hep_aida_jni_intClass, Java_hep_aida_jni_shortClass, Java_hep_aida_jni_longClass;
jclass Java_hep_aida_jni_floatClass, Java_hep_aida_jni_doubleClass, Java_hep_aida_jni_booleanClass;
jclass Java_hep_aida_jni_byteClass, Java_hep_aida_jni_characterClass;
jclass Java_hep_aida_jni_stringClass, Java_hep_aida_jni_objectClass, Java_hep_aida_jni_tupleClass;

void Java_hep_aida_jni_init(JNIEnv* env) {
    if (Java_hep_aida_jni_inited) return;
    
    GETPRIMITIVECLASS(Java_hep_aida_jni_intClass,         "java/lang/Integer")
    GETPRIMITIVECLASS(Java_hep_aida_jni_shortClass,       "java/lang/Short")
    GETPRIMITIVECLASS(Java_hep_aida_jni_longClass,        "java/lang/Long")
    GETPRIMITIVECLASS(Java_hep_aida_jni_floatClass,       "java/lang/Float")
    GETPRIMITIVECLASS(Java_hep_aida_jni_doubleClass,      "java/lang/Double")
    GETPRIMITIVECLASS(Java_hep_aida_jni_booleanClass,     "java/lang/Boolean")
    GETPRIMITIVECLASS(Java_hep_aida_jni_byteClass,        "java/lang/Byte")
    GETPRIMITIVECLASS(Java_hep_aida_jni_characterClass,   "java/lang/Character")

    Java_hep_aida_jni_stringClass = env->FindClass("java/lang/String");
    Java_hep_aida_jni_objectClass = env->FindClass("java/lang/Object");
    Java_hep_aida_jni_tupleClass =  env->FindClass("hep/aida/ITuple");

    Java_hep_aida_jni_inited = true;
}

JNIEXPORT jclass JNICALL Java_hep_aida_jni_convert_to_class(JNIEnv *env, string type) {
    Java_hep_aida_jni_init(env);
    
    if (type == "int") return Java_hep_aida_jni_intClass;
    if (type == "short") return env->FindClass("java/lang/Short");
    if (type == "long") return env->FindClass("java/lang/Long");
    if (type == "float") return env->FindClass("java/lang/Float");
    if (type == "double") return env->FindClass("java/lang/Double");
    if (type == "boolean") return env->FindClass("java/lang/Boolean");
    if (type == "byte") return env->FindClass("java/lang/Byte");
    if (type == "char") return env->FindClass("java/lang/Character");
    if (type == "string") return env->FindClass("java/lang/String");
    if (type == "java.lang.Object") return env->FindClass("java/lang/Object");
    if (type == "ITuple") return env->FindClass("hep/aida/ITuple");

    cerr << "Java_hep_aida_jni_convert_to_class(type) could not find jclass for type: " << type << endl;

    return NULL;
}

JNIEXPORT char* JNICALL Java_hep_aida_jni_convert_to_string(JNIEnv *env, jclass c) {
    Java_hep_aida_jni_init(env);

    if (env->IsSameObject(c, Java_hep_aida_jni_intClass) == JNI_TRUE) {
        return "int";
    } else if (env->IsSameObject(c, Java_hep_aida_jni_shortClass) == JNI_TRUE) {
        return "short";
    } else if (env->IsSameObject(c, Java_hep_aida_jni_longClass) == JNI_TRUE) {
        return "long";
    } else if (env->IsSameObject(c, Java_hep_aida_jni_floatClass) == JNI_TRUE) {
        return "float";
    } else if (env->IsSameObject(c, Java_hep_aida_jni_doubleClass) == JNI_TRUE) {
        return "double";
    } else if (env->IsSameObject(c, Java_hep_aida_jni_booleanClass) == JNI_TRUE) {
        return "boolean";
    } else if (env->IsSameObject(c, Java_hep_aida_jni_byteClass) == JNI_TRUE) {
        return "byte";
    } else if (env->IsSameObject(c, Java_hep_aida_jni_characterClass) == JNI_TRUE) {
        return "char";
    } else if (env->IsSameObject(c, Java_hep_aida_jni_stringClass) == JNI_TRUE) {
        return "string";
    } else if (env->IsSameObject(c, Java_hep_aida_jni_objectClass) == JNI_TRUE) {
        return "java.lang.Object";
    } else if (env->IsSameObject(c, Java_hep_aida_jni_tupleClass) == JNI_TRUE) {
        return "ITuple";
    } else {
        return "unknown";
    }
}
