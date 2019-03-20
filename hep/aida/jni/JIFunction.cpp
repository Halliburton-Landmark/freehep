
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "AIDA/IAnnotation.h"
#include "AIDA/IFunction.h"
#include "JIAnnotation.h"
#include "JIFunction.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"


using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIFunction::JIFunction(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory), JIManagedObject(jnienv, object),
        iAnnotation(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    providesGradientOCZMethod = env->GetMethodID(cls, "providesGradient", "()Z");
    if (providesGradientOCZMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "providesGradient" << "()Z" << std::endl;
    }

    annotationOCLhep_aida_IAnnotationEMethod = env->GetMethodID(cls, "annotation", "()Lhep/aida/IAnnotation;");
    if (annotationOCLhep_aida_IAnnotationEMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "annotation" << "()Lhep/aida/IAnnotation;" << std::endl;
    }

    parameterOLjava_lang_StringECDMethod = env->GetMethodID(cls, "parameter", "(Ljava/lang/String;)D");
    if (parameterOLjava_lang_StringECDMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "parameter" << "(Ljava/lang/String;)D" << std::endl;
    }

    variableNameOICLjava_lang_StringEMethod = env->GetMethodID(cls, "variableName", "(I)Ljava/lang/String;");
    if (variableNameOICLjava_lang_StringEMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "variableName" << "(I)Ljava/lang/String;" << std::endl;
    }

    setParameterOLjava_lang_StringEDCVMethod = env->GetMethodID(cls, "setParameter", "(Ljava/lang/String;D)V");
    if (setParameterOLjava_lang_StringEDCVMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "setParameter" << "(Ljava/lang/String;D)V" << std::endl;
    }

    isEqualOLhep_aida_IFunctionECZMethod = env->GetMethodID(cls, "isEqual", "(Lhep/aida/IFunction;)Z");
    if (isEqualOLhep_aida_IFunctionECZMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "isEqual" << "(Lhep/aida/IFunction;)Z" << std::endl;
    }

    parametersOCADMethod = env->GetMethodID(cls, "parameters", "()[D");
    if (parametersOCADMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "parameters" << "()[D" << std::endl;
    }

    codeletStringOCLjava_lang_StringEMethod = env->GetMethodID(cls, "codeletString", "()Ljava/lang/String;");
    if (codeletStringOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "codeletString" << "()Ljava/lang/String;" << std::endl;
    }

    setParametersOADCVMethod = env->GetMethodID(cls, "setParameters", "([D)V");
    if (setParametersOADCVMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "setParameters" << "([D)V" << std::endl;
    }

    numberOfParametersOCIMethod = env->GetMethodID(cls, "numberOfParameters", "()I");
    if (numberOfParametersOCIMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "numberOfParameters" << "()I" << std::endl;
    }

    parameterNamesOCALjava_lang_StringEMethod = env->GetMethodID(cls, "parameterNames", "()[Ljava/lang/String;");
    if (parameterNamesOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "parameterNames" << "()[Ljava/lang/String;" << std::endl;
    }

    indexOfParameterOLjava_lang_StringECIMethod = env->GetMethodID(cls, "indexOfParameter", "(Ljava/lang/String;)I");
    if (indexOfParameterOLjava_lang_StringECIMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "indexOfParameter" << "(Ljava/lang/String;)I" << std::endl;
    }

    variableNamesOCALjava_lang_StringEMethod = env->GetMethodID(cls, "variableNames", "()[Ljava/lang/String;");
    if (variableNamesOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "variableNames" << "()[Ljava/lang/String;" << std::endl;
    }

    gradientOADCADMethod = env->GetMethodID(cls, "gradient", "([D)[D");
    if (gradientOADCADMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "gradient" << "([D)[D" << std::endl;
    }

    dimensionOCIMethod = env->GetMethodID(cls, "dimension", "()I");
    if (dimensionOCIMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "dimension" << "()I" << std::endl;
    }

    valueOADCDMethod = env->GetMethodID(cls, "value", "([D)D");
    if (valueOADCDMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "value" << "([D)D" << std::endl;
    }

    setTitleOLjava_lang_StringECVMethod = env->GetMethodID(cls, "setTitle", "(Ljava/lang/String;)V");
    if (setTitleOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "setTitle" << "(Ljava/lang/String;)V" << std::endl;
    }

    titleOCLjava_lang_StringEMethod = env->GetMethodID(cls, "title", "()Ljava/lang/String;");
    if (titleOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IFunction" << ": Could not find method: " << "title" << "()Ljava/lang/String;" << std::endl;
    }
}

JNIEXPORT JIFunction::~JIFunction() {
    delete iAnnotation;
}

JNIEXPORT std::string JIFunction::title() const {
    // Call to Java
    jstring jtitle = (jstring)env->CallObjectMethod(ref, titleOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(jtitle, &isCopy);
    string titleString = utf;
    if (isCopy) env->ReleaseStringUTFChars(jtitle, utf);
    return titleString;
}

JNIEXPORT bool JIFunction::setTitle(const std::string & title) {
    jstring jtitle;
    NEWSTRING(jtitle, title)
    env->CallObjectMethod(ref, setTitleOLjava_lang_StringECVMethod, jtitle);
    DELSTRING(jtitle)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT double JIFunction::value(const std::vector<double>  & x) const {
    jdoubleArray jx;
    NEWDOUBLEARRAY(jx, x)
    jdouble result = env->CallDoubleMethod(ref, valueOADCDMethod, jx);
    DELDOUBLEARRAY(jx)
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT int JIFunction::dimension() const {
    jint result = env->CallIntMethod(ref, dimensionOCIMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

// QUESTION: why pointer to a function here rather than reference?
JNIEXPORT bool JIFunction::isEqual(const IFunction & f) const {
    jobject jfunction = factory->create(env, f);
    jboolean result = env->CallBooleanMethod(ref, isEqualOLhep_aida_IFunctionECZMethod, jfunction);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT const std::vector<double> & JIFunction::gradient(const std::vector<double>  & x) const {
    jdoubleArray jx;
    NEWDOUBLEARRAY(jx, x)
    gradientVector.clear();
    // Call to Java
    jdoubleArray jresult = (jdoubleArray)env->CallObjectMethod(ref, gradientOADCADMethod, jx);
    // convert double[] to vector<double>
    unsigned int len = env->GetArrayLength(jresult);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jresult, i, 1, &d);
        gradientVector.push_back(d);
    }
    DELDOUBLEARRAY(jx)
    JNIUtil::checkExceptions(env);
    return gradientVector;
}

JNIEXPORT bool JIFunction::providesGradient() const {
    jboolean result = env->CallBooleanMethod(ref, providesGradientOCZMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT std::string JIFunction::variableName(int i) const {
    jstring result = (jstring)env->CallObjectMethod(ref, variableNameOICLjava_lang_StringEMethod, i);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    JNIUtil::checkExceptions(env);
    return resultString;
}

JNIEXPORT std::vector<std::string> JIFunction::variableNames() const {
    std::vector<std::string> variableNamesVector;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, variableNamesOCALjava_lang_StringEMethod);

    if (array != NULL) {
        // convert string[] to vector<string>
        unsigned int len = env->GetArrayLength(array);
        for (unsigned int i=0; i<len; i++) {
            jstring jname = (jstring)env->GetObjectArrayElement(array, i);
            jboolean isCopy;
            const char* utf = env->GetStringUTFChars(jname, &isCopy);
            string name = utf;
            if (isCopy) env->ReleaseStringUTFChars(jname, utf);
            variableNamesVector.push_back(name);
        }
    }
    JNIUtil::checkExceptions(env);
    return variableNamesVector;
}

JNIEXPORT bool JIFunction::setParameters(const std::vector<double>  & params) {
    jdoubleArray jparams;
    NEWDOUBLEARRAY(jparams, params)
    env->CallVoidMethod(ref, setParametersOADCVMethod, jparams);
    DELDOUBLEARRAY(jparams)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT const std::vector<double> & JIFunction::parameters() const {
    parametersVector.clear();
    // Call to Java
    jdoubleArray jresult = (jdoubleArray)env->CallObjectMethod(ref, parametersOCADMethod);
    // convert double[] to vector<double>
    unsigned int len = env->GetArrayLength(jresult);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jresult, i, 1, &d);
        parametersVector.push_back(d);
    }
    JNIUtil::checkExceptions(env);
    return parametersVector;
}

JNIEXPORT int JIFunction::numberOfParameters() const {
    jint result = env->CallIntMethod(ref, numberOfParametersOCIMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT std::vector<std::string> JIFunction::parameterNames() const {
    std::vector<std::string> parameterNamesVector;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, parameterNamesOCALjava_lang_StringEMethod);

    if (array != NULL) {
        // convert string[] to vector<string>
        unsigned int len = env->GetArrayLength(array);
        for (unsigned int i=0; i<len; i++) {
            jstring jname = (jstring)env->GetObjectArrayElement(array, i);
            jboolean isCopy;
            const char* utf = env->GetStringUTFChars(jname, &isCopy);
            string name = utf;
            if (isCopy) env->ReleaseStringUTFChars(jname, utf);
            parameterNamesVector.push_back(name);
        }
    }
    JNIUtil::checkExceptions(env);
    return parameterNamesVector;
}

JNIEXPORT bool JIFunction::setParameter(const std::string & name, double x) {
    jstring jname;
    NEWSTRING(jname, name)
    env->CallVoidMethod(ref, setParameterOLjava_lang_StringEDCVMethod, jname, x);
    DELSTRING(jname)
	return !JNIUtil::exceptions(env);
}

JNIEXPORT double JIFunction::parameter(const std::string & name) const {
    jstring jname;
    NEWSTRING(jname, name)
    jdouble result = env->CallDoubleMethod(ref, parameterOLjava_lang_StringECDMethod, jname);
    DELSTRING(jname)
	JNIUtil::checkExceptions(env);
	return result;
}

JNIEXPORT int JIFunction::indexOfParameter(const std::string & name) const {
    jstring jname;
    NEWSTRING(jname, name)
    jint result = env->CallIntMethod(ref, indexOfParameterOLjava_lang_StringECIMethod, jname);
    DELSTRING(jname)
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT IAnnotation & JIFunction::annotation() {
    if (iAnnotation == NULL) {
        jobject jannotation = env->CallObjectMethod(ref, annotationOCLhep_aida_IAnnotationEMethod);
        iAnnotation = factory->createIAnnotation(env, jannotation);
    }
    return *iAnnotation;
}

JNIEXPORT const IAnnotation & JIFunction::annotation() const {
    if (iAnnotation == NULL) {
        jobject jannotation = env->CallObjectMethod(ref, annotationOCLhep_aida_IAnnotationEMethod);
        iAnnotation = factory->createIAnnotation(env, jannotation);
    }
    return *iAnnotation;
}

JNIEXPORT std::string JIFunction::codeletString() const {
    jstring result = (jstring)env->CallObjectMethod(ref, codeletStringOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    return resultString;
}

JNIEXPORT void * JIFunction::cast(const std::string & className) const {
    return (className == "AIDA::IFunction") ? (void *)this : NULL;
}
