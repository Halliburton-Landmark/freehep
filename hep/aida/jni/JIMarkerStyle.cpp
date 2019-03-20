
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "JIBrushStyle.h"
#include "JIMarkerStyle.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIMarkerStyle::JIMarkerStyle(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIBrushStyle(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    setShapeOLjava_lang_StringECZMethod = env->GetMethodID(cls, "setShape", "(Ljava/lang/String;)Z");
    if (setShapeOLjava_lang_StringECZMethod == NULL) {
        std::cerr << "IMarkerStyle" << ": Could not find method: " << "setShape" << "(Ljava/lang/String;)Z" << std::endl;
    }

    shapeOCLjava_lang_StringEMethod = env->GetMethodID(cls, "shape", "()Ljava/lang/String;");
    if (shapeOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IMarkerStyle" << ": Could not find method: " << "shape" << "()Ljava/lang/String;" << std::endl;
    }

    availableShapesOCALjava_lang_StringEMethod = env->GetMethodID(cls, "availableShapes", "()[Ljava/lang/String;");
    if (availableShapesOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IMarkerStyle" << ": Could not find method: " << "availableShapes" << "()[Ljava/lang/String;" << std::endl;
    }

}

JNIEXPORT JIMarkerStyle::~JIMarkerStyle() {
}

JNIEXPORT std::vector<std::string>  JIMarkerStyle::availableShapes() const {
    vector<string> result;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, availableShapesOCALjava_lang_StringEMethod);

    if (array != NULL) {
        // convert string[] to vector<string>
        unsigned int len = env->GetArrayLength(array);
        for (unsigned int i=0; i<len; i++) {
            jstring jname = (jstring)env->GetObjectArrayElement(array, i);
            jboolean isCopy;
            const char* utf = env->GetStringUTFChars(jname, &isCopy);
            string name = utf;
            if (isCopy) env->ReleaseStringUTFChars(jname, utf);
            result.push_back(name);
        }
    }
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT std::string JIMarkerStyle::shape() const {
    jstring result = (jstring)env->CallObjectMethod(ref, shapeOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    JNIUtil::checkExceptions(env);
    return resultString;
}

JNIEXPORT bool JIMarkerStyle::setShape(const std::string & shape) {
    jstring jshape;
    NEWSTRING(jshape, shape)
    jboolean result = env->CallBooleanMethod(ref, setShapeOLjava_lang_StringECZMethod, jshape);
    DELSTRING(jshape)
    JNIUtil::checkExceptions(env);
    return result;
}
