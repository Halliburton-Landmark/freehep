
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "AIDA/IFitParameterSettings.h"
#include "AIDA/IFunction.h"
#include "JIFitParameterSettings.h"
#include "JIFitResult.h"
#include "JIFunction.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIFitResult::JIFitResult(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory),
        fittedFunctionPtr(NULL) {
    jclass cls = env->GetObjectClass(getRef());

    fitMethodNameOCLjava_lang_StringEMethod = env->GetMethodID(cls, "fitMethodName", "()Ljava/lang/String;");
    if (fitMethodNameOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "fitMethodName" << "()Ljava/lang/String;" << std::endl;
    }

    fittedParameterNamesOCALjava_lang_StringEMethod = env->GetMethodID(cls, "fittedParameterNames", "()[Ljava/lang/String;");
    if (fittedParameterNamesOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "fittedParameterNames" << "()[Ljava/lang/String;" << std::endl;
    }

    errorsPlusOCADMethod = env->GetMethodID(cls, "errorsPlus", "()[D");
    if (errorsPlusOCADMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "errorsPlus" << "()[D" << std::endl;
    }

    errorsOCADMethod = env->GetMethodID(cls, "errors", "()[D");
    if (errorsOCADMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "errors" << "()[D" << std::endl;
    }

    ndfOCIMethod = env->GetMethodID(cls, "ndf", "()I");
    if (ndfOCIMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "ndf" << "()I" << std::endl;
    }

    fittedFunctionOCLhep_aida_IFunctionEMethod = env->GetMethodID(cls, "fittedFunction", "()Lhep/aida/IFunction;");
    if (fittedFunctionOCLhep_aida_IFunctionEMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "fittedFunction" << "()Lhep/aida/IFunction;" << std::endl;
    }

    covMatrixElementOIICDMethod = env->GetMethodID(cls, "covMatrixElement", "(II)D");
    if (covMatrixElementOIICDMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "covMatrixElement" << "(II)D" << std::endl;
    }

    fittedParametersOCADMethod = env->GetMethodID(cls, "fittedParameters", "()[D");
    if (fittedParametersOCADMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "fittedParameters" << "()[D" << std::endl;
    }

    fitStatusOCIMethod = env->GetMethodID(cls, "fitStatus", "()I");
    if (fitStatusOCIMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "fitStatus" << "()I" << std::endl;
    }

    constraintsOCALjava_lang_StringEMethod = env->GetMethodID(cls, "constraints", "()[Ljava/lang/String;");
    if (constraintsOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "constraints" << "()[Ljava/lang/String;" << std::endl;
    }

    fittedParameterOLjava_lang_StringECDMethod = env->GetMethodID(cls, "fittedParameter", "(Ljava/lang/String;)D");
    if (fittedParameterOLjava_lang_StringECDMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "fittedParameter" << "(Ljava/lang/String;)D" << std::endl;
    }

    isValidOCZMethod = env->GetMethodID(cls, "isValid", "()Z");
    if (isValidOCZMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "isValid" << "()Z" << std::endl;
    }

    dataDescriptionOCLjava_lang_StringEMethod = env->GetMethodID(cls, "dataDescription", "()Ljava/lang/String;");
    if (dataDescriptionOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "dataDescription" << "()Ljava/lang/String;" << std::endl;
    }

    qualityOCDMethod = env->GetMethodID(cls, "quality", "()D");
    if (qualityOCDMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "quality" << "()D" << std::endl;
    }

    engineNameOCLjava_lang_StringEMethod = env->GetMethodID(cls, "engineName", "()Ljava/lang/String;");
    if (engineNameOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "engineName" << "()Ljava/lang/String;" << std::endl;
    }

    errorsMinusOCADMethod = env->GetMethodID(cls, "errorsMinus", "()[D");
    if (errorsMinusOCADMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "errorsMinus" << "()[D" << std::endl;
    }

    fitParameterSettingsOLjava_lang_StringECLhep_aida_IFitParameterSettingsEMethod = env->GetMethodID(cls, "fitParameterSettings", "(Ljava/lang/String;)Lhep/aida/IFitParameterSettings;");
    if (fitParameterSettingsOLjava_lang_StringECLhep_aida_IFitParameterSettingsEMethod == NULL) {
        std::cerr << "IFitResult" << ": Could not find method: " << "fitParameterSettings" << "(Ljava/lang/String;)Lhep/aida/IFitParameterSettings;" << std::endl;
    }

}

JNIEXPORT JIFitResult::~JIFitResult() {
	delete fittedFunctionPtr;
}

JNIEXPORT bool JIFitResult::isValid() {
    jboolean result = env->CallBooleanMethod(ref, isValidOCZMethod);
	if (JNIUtil::exceptions(env)) return false;
	else return result;
}

JNIEXPORT int JIFitResult::fitStatus() {
    jint result = env->CallIntMethod(ref, fitStatusOCIMethod);
	JNIUtil::checkExceptions(env);
	return result;
}

JNIEXPORT IFunction & JIFitResult::fittedFunction() {
    jobject obj = (jobject)env->CallObjectMethod(ref, fittedFunctionOCLhep_aida_IFunctionEMethod);
	JNIUtil::checkExceptions(env);
	delete fittedFunctionPtr;
	fittedFunctionPtr = factory->createIFunction(env, obj);
	return *fittedFunctionPtr;
}

JNIEXPORT double JIFitResult::quality() {
    jdouble result = env->CallDoubleMethod(ref, qualityOCDMethod);
	JNIUtil::checkExceptions(env);
	return result;
}

JNIEXPORT int JIFitResult::ndf() {
    jint result = env->CallIntMethod(ref, ndfOCIMethod);
	JNIUtil::checkExceptions(env);
	return result;
}

JNIEXPORT double JIFitResult::covMatrixElement(int i, int j) {
    jdouble result = env->CallDoubleMethod(ref, covMatrixElementOIICDMethod, i, j);
	JNIUtil::checkExceptions(env);
	return result;
}

JNIEXPORT std::string JIFitResult::fitMethodName() {
    jstring result = (jstring)env->CallObjectMethod(ref, fitMethodNameOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    JNIUtil::checkExceptions(env);
    return resultString;
}

JNIEXPORT std::string JIFitResult::engineName() {
    jstring result = (jstring)env->CallObjectMethod(ref, engineNameOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    JNIUtil::checkExceptions(env);
    return resultString;
}

JNIEXPORT std::string JIFitResult::dataDescription() {
    jstring result = (jstring)env->CallObjectMethod(ref, dataDescriptionOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    JNIUtil::checkExceptions(env);
    return resultString;
}

JNIEXPORT std::vector<std::string> JIFitResult::constraints() {
    std::vector<std::string> constraintsVector;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, constraintsOCALjava_lang_StringEMethod);

    if (array != NULL) {
        // convert string[] to vector<string>
        unsigned int len = env->GetArrayLength(array);
        for (unsigned int i=0; i<len; i++) {
            jstring jname = (jstring)env->GetObjectArrayElement(array, i);
            jboolean isCopy;
            const char* utf = env->GetStringUTFChars(jname, &isCopy);
            string name = utf;
            if (isCopy) env->ReleaseStringUTFChars(jname, utf);
            constraintsVector.push_back(name);
        }
    }
    JNIUtil::checkExceptions(env);
    return constraintsVector;
}

JNIEXPORT IFitParameterSettings * JIFitResult::fitParameterSettings(const std::string & name) {
    jstring jname;
    NEWSTRING(jname, name);
    jobject obj = env->CallObjectMethod(ref, fitParameterSettingsOLjava_lang_StringECLhep_aida_IFitParameterSettingsEMethod, jname);
    DELSTRING(jname)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIFitParameterSettings(env, obj);
}

JNIEXPORT const std::vector<double>  & JIFitResult::fittedParameters() const {
    fittedParametersVector.clear();
    // Call to Java
    jdoubleArray jresult = (jdoubleArray)env->CallObjectMethod(ref, fittedParametersOCADMethod);
    // convert double[] to vector<double>
    unsigned int len = env->GetArrayLength(jresult);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jresult, i, 1, &d);
        fittedParametersVector.push_back(d);
    }
    JNIUtil::checkExceptions(env);
    return fittedParametersVector;
}

JNIEXPORT std::vector<std::string> JIFitResult::fittedParameterNames() const {
    std::vector<std::string> fittedParameterNamesVector;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, fittedParameterNamesOCALjava_lang_StringEMethod);

    if (array != NULL) {
        // convert string[] to vector<string>
        unsigned int len = env->GetArrayLength(array);
        for (unsigned int i=0; i<len; i++) {
            jstring jname = (jstring)env->GetObjectArrayElement(array, i);
            jboolean isCopy;
            const char* utf = env->GetStringUTFChars(jname, &isCopy);
            string name = utf;
            if (isCopy) env->ReleaseStringUTFChars(jname, utf);
            fittedParameterNamesVector.push_back(name);
        }
    }
    JNIUtil::checkExceptions(env);
    return fittedParameterNamesVector;
}

JNIEXPORT double JIFitResult::fittedParameter(const std::string & name) {
    jstring jname;
    NEWSTRING(jname, name);
    jdouble result = env->CallDoubleMethod(ref, fittedParameterOLjava_lang_StringECDMethod, jname);
    DELSTRING(jname)
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT const std::vector<double>  & JIFitResult::errors() const {
    errorsVector.clear();
    // Call to Java
    jdoubleArray jresult = (jdoubleArray)env->CallObjectMethod(ref, errorsOCADMethod);
    // convert double[] to vector<double>
    unsigned int len = env->GetArrayLength(jresult);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jresult, i, 1, &d);
        errorsVector.push_back(d);
    }
    JNIUtil::checkExceptions(env);
    return errorsVector;
}

JNIEXPORT const std::vector<double>  & JIFitResult::errorsPlus() const {
    errorsPlusVector.clear();
    // Call to Java
    jdoubleArray jresult = (jdoubleArray)env->CallObjectMethod(ref, errorsPlusOCADMethod);
    // convert double[] to vector<double>
    unsigned int len = env->GetArrayLength(jresult);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jresult, i, 1, &d);
        errorsPlusVector.push_back(d);
    }
    JNIUtil::checkExceptions(env);
    return errorsPlusVector;
}

JNIEXPORT const std::vector<double>  & JIFitResult::errorsMinus() const {
    errorsMinusVector.clear();
    // Call to Java
    jdoubleArray jresult = (jdoubleArray)env->CallObjectMethod(ref, errorsMinusOCADMethod);
    // convert double[] to vector<double>
    unsigned int len = env->GetArrayLength(jresult);
    for (unsigned int i=0; i<len; i++) {
        jdouble d;
        env->GetDoubleArrayRegion(jresult, i, 1, &d);
        errorsMinusVector.push_back(d);
    }
    JNIUtil::checkExceptions(env);
    return errorsMinusVector;
}
