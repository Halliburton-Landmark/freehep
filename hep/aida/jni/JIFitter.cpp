
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "AIDA/IBaseHistogram.h"
#include "AIDA/IDataPointSet.h"
#include "AIDA/IFitData.h"
#include "AIDA/IFitParameterSettings.h"
#include "AIDA/IFitResult.h"
#include "AIDA/IFunction.h"
#include "JIBaseHistogram.h"
#include "JIFitter.h"
#include "JIFitData.h"
#include "JIFitResult.h"
#include "JIFitParameterSettings.h"
#include "JIFunction.h"
#include "JIDataPointSet.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIFitter::JIFitter(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    createScan1DOLhep_aida_IFitDataELhep_aida_IFunctionELjava_lang_StringEIDDCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createScan1D", "(Lhep/aida/IFitData;Lhep/aida/IFunction;Ljava/lang/String;IDD)Lhep/aida/IDataPointSet;");
    if (createScan1DOLhep_aida_IFitDataELhep_aida_IFunctionELjava_lang_StringEIDDCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "createScan1D" << "(Lhep/aida/IFitData;Lhep/aida/IFunction;Ljava/lang/String;IDD)Lhep/aida/IDataPointSet;" << std::endl;
    }

    fitMethodNameOCLjava_lang_StringEMethod = env->GetMethodID(cls, "fitMethodName", "()Ljava/lang/String;");
    if (fitMethodNameOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "fitMethodName" << "()Ljava/lang/String;" << std::endl;
    }

    setFitMethodOLjava_lang_StringECVMethod = env->GetMethodID(cls, "setFitMethod", "(Ljava/lang/String;)V");
    if (setFitMethodOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "setFitMethod" << "(Ljava/lang/String;)V" << std::endl;
    }

    resetParameterSettingsOCVMethod = env->GetMethodID(cls, "resetParameterSettings", "()V");
    if (resetParameterSettingsOCVMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "resetParameterSettings" << "()V" << std::endl;
    }

    fitOLhep_aida_IFitDataELjava_lang_StringEADCLhep_aida_IFitResultEMethod = env->GetMethodID(cls, "fit", "(Lhep/aida/IFitData;Ljava/lang/String;[D)Lhep/aida/IFitResult;");
    if (fitOLhep_aida_IFitDataELjava_lang_StringEADCLhep_aida_IFitResultEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "fit" << "(Lhep/aida/IFitData;Ljava/lang/String;[D)Lhep/aida/IFitResult;" << std::endl;
    }

    fitOLhep_aida_IFitDataELhep_aida_IFunctionECLhep_aida_IFitResultEMethod = env->GetMethodID(cls, "fit", "(Lhep/aida/IFitData;Lhep/aida/IFunction;)Lhep/aida/IFitResult;");
    if (fitOLhep_aida_IFitDataELhep_aida_IFunctionECLhep_aida_IFitResultEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "fit" << "(Lhep/aida/IFitData;Lhep/aida/IFunction;)Lhep/aida/IFitResult;" << std::endl;
    }

    setEngineOLjava_lang_StringECVMethod = env->GetMethodID(cls, "setEngine", "(Ljava/lang/String;)V");
    if (setEngineOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "setEngine" << "(Ljava/lang/String;)V" << std::endl;
    }

    fitOLhep_aida_IBaseHistogramELjava_lang_StringEADCLhep_aida_IFitResultEMethod = env->GetMethodID(cls, "fit", "(Lhep/aida/IBaseHistogram;Ljava/lang/String;[D)Lhep/aida/IFitResult;");
    if (fitOLhep_aida_IBaseHistogramELjava_lang_StringEADCLhep_aida_IFitResultEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "fit" << "(Lhep/aida/IBaseHistogram;Ljava/lang/String;[D)Lhep/aida/IFitResult;" << std::endl;
    }

    useFunctionGradientOCZMethod = env->GetMethodID(cls, "useFunctionGradient", "()Z");
    if (useFunctionGradientOCZMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "useFunctionGradient" << "()Z" << std::endl;
    }

    fitOLhep_aida_IDataPointSetELhep_aida_IFunctionECLhep_aida_IFitResultEMethod = env->GetMethodID(cls, "fit", "(Lhep/aida/IDataPointSet;Lhep/aida/IFunction;)Lhep/aida/IFitResult;");
    if (fitOLhep_aida_IDataPointSetELhep_aida_IFunctionECLhep_aida_IFitResultEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "fit" << "(Lhep/aida/IDataPointSet;Lhep/aida/IFunction;)Lhep/aida/IFitResult;" << std::endl;
    }

    constraintsOCALjava_lang_StringEMethod = env->GetMethodID(cls, "constraints", "()[Ljava/lang/String;");
    if (constraintsOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "constraints" << "()[Ljava/lang/String;" << std::endl;
    }

    fitOLhep_aida_IFitDataELjava_lang_StringECLhep_aida_IFitResultEMethod = env->GetMethodID(cls, "fit", "(Lhep/aida/IFitData;Ljava/lang/String;)Lhep/aida/IFitResult;");
    if (fitOLhep_aida_IFitDataELjava_lang_StringECLhep_aida_IFitResultEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "fit" << "(Lhep/aida/IFitData;Ljava/lang/String;)Lhep/aida/IFitResult;" << std::endl;
    }

    setUseFunctionGradientOZCVMethod = env->GetMethodID(cls, "setUseFunctionGradient", "(Z)V");
    if (setUseFunctionGradientOZCVMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "setUseFunctionGradient" << "(Z)V" << std::endl;
    }

    fitOLhep_aida_IDataPointSetELjava_lang_StringECLhep_aida_IFitResultEMethod = env->GetMethodID(cls, "fit", "(Lhep/aida/IDataPointSet;Ljava/lang/String;)Lhep/aida/IFitResult;");
    if (fitOLhep_aida_IDataPointSetELjava_lang_StringECLhep_aida_IFitResultEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "fit" << "(Lhep/aida/IDataPointSet;Ljava/lang/String;)Lhep/aida/IFitResult;" << std::endl;
    }

    createContourOLhep_aida_IFitDataELhep_aida_IFitResultELjava_lang_StringELjava_lang_StringEIDCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createContour", "(Lhep/aida/IFitData;Lhep/aida/IFitResult;Ljava/lang/String;Ljava/lang/String;ID)Lhep/aida/IDataPointSet;");
    if (createContourOLhep_aida_IFitDataELhep_aida_IFitResultELjava_lang_StringELjava_lang_StringEIDCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "createContour" << "(Lhep/aida/IFitData;Lhep/aida/IFitResult;Ljava/lang/String;Ljava/lang/String;ID)Lhep/aida/IDataPointSet;" << std::endl;
    }

    engineNameOCLjava_lang_StringEMethod = env->GetMethodID(cls, "engineName", "()Ljava/lang/String;");
    if (engineNameOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "engineName" << "()Ljava/lang/String;" << std::endl;
    }

    fitOLhep_aida_IDataPointSetELjava_lang_StringEADCLhep_aida_IFitResultEMethod = env->GetMethodID(cls, "fit", "(Lhep/aida/IDataPointSet;Ljava/lang/String;[D)Lhep/aida/IFitResult;");
    if (fitOLhep_aida_IDataPointSetELjava_lang_StringEADCLhep_aida_IFitResultEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "fit" << "(Lhep/aida/IDataPointSet;Ljava/lang/String;[D)Lhep/aida/IFitResult;" << std::endl;
    }

    fitOLhep_aida_IBaseHistogramELhep_aida_IFunctionECLhep_aida_IFitResultEMethod = env->GetMethodID(cls, "fit", "(Lhep/aida/IBaseHistogram;Lhep/aida/IFunction;)Lhep/aida/IFitResult;");
    if (fitOLhep_aida_IBaseHistogramELhep_aida_IFunctionECLhep_aida_IFitResultEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "fit" << "(Lhep/aida/IBaseHistogram;Lhep/aida/IFunction;)Lhep/aida/IFitResult;" << std::endl;
    }

    fitOLhep_aida_IBaseHistogramELjava_lang_StringECLhep_aida_IFitResultEMethod = env->GetMethodID(cls, "fit", "(Lhep/aida/IBaseHistogram;Ljava/lang/String;)Lhep/aida/IFitResult;");
    if (fitOLhep_aida_IBaseHistogramELjava_lang_StringECLhep_aida_IFitResultEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "fit" << "(Lhep/aida/IBaseHistogram;Ljava/lang/String;)Lhep/aida/IFitResult;" << std::endl;
    }

    setConstraintOLjava_lang_StringECVMethod = env->GetMethodID(cls, "setConstraint", "(Ljava/lang/String;)V");
    if (setConstraintOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "setConstraint" << "(Ljava/lang/String;)V" << std::endl;
    }

    resetConstraintsOCVMethod = env->GetMethodID(cls, "resetConstraints", "()V");
    if (resetConstraintsOCVMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "resetConstraints" << "()V" << std::endl;
    }

    listParameterSettingsOCALjava_lang_StringEMethod = env->GetMethodID(cls, "listParameterSettings", "()[Ljava/lang/String;");
    if (listParameterSettingsOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "listParameterSettings" << "()[Ljava/lang/String;" << std::endl;
    }

    fitParameterSettingsOLjava_lang_StringECLhep_aida_IFitParameterSettingsEMethod = env->GetMethodID(cls, "fitParameterSettings", "(Ljava/lang/String;)Lhep/aida/IFitParameterSettings;");
    if (fitParameterSettingsOLjava_lang_StringECLhep_aida_IFitParameterSettingsEMethod == NULL) {
        std::cerr << "IFitter" << ": Could not find method: " << "fitParameterSettings" << "(Ljava/lang/String;)Lhep/aida/IFitParameterSettings;" << std::endl;
    }

}

JNIEXPORT JIFitter::~JIFitter() {
}

JNIEXPORT IFitResult * JIFitter::fit(IFitData & fitData, IFunction & func) {
    jobject jfitData = factory->create(env, fitData);
    jobject jfunction = factory->create(env, func);
    jobject obj = env->CallObjectMethod(ref, fitOLhep_aida_IFitDataELhep_aida_IFunctionECLhep_aida_IFitResultEMethod, jfitData, jfunction );
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIFitResult(env, obj);
}

JNIEXPORT IFitResult * JIFitter::fit(IBaseHistogram & hist, IFunction & func) {
    jobject jhistogram = factory->create(env, hist);
    jobject jfunction = factory->create(env, func);
    jobject obj = env->CallObjectMethod(ref, fitOLhep_aida_IBaseHistogramELhep_aida_IFunctionECLhep_aida_IFitResultEMethod, jhistogram, jfunction);
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIFitResult(env, obj);
}

JNIEXPORT IFitResult * JIFitter::fit(IBaseHistogram & hist, const std::string & model) {
    jobject jhistogram = factory->create(env, hist);
    jstring jmodel;
    NEWSTRING(jmodel, model)
    jobject obj = env->CallObjectMethod(ref, fitOLhep_aida_IBaseHistogramELjava_lang_StringECLhep_aida_IFitResultEMethod, jhistogram, jmodel);
    DELSTRING(jmodel)
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIFitResult(env, obj);
}

JNIEXPORT IFitResult * JIFitter::fit(IBaseHistogram & hist, const std::string & model, const std::vector<double> & initialParameters) {
    jobject jhistogram = factory->create(env, hist);
    jstring jmodel;
    jdoubleArray jinitialParameters;
    NEWSTRING(jmodel, model)
    NEWDOUBLEARRAY(jinitialParameters, initialParameters)
    jobject obj = env->CallObjectMethod(ref, fitOLhep_aida_IBaseHistogramELjava_lang_StringEADCLhep_aida_IFitResultEMethod, jhistogram, jmodel, jinitialParameters);
    DELSTRING(jmodel)
    DELDOUBLEARRAY(jinitialParameters)
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIFitResult(env, obj);
}

JNIEXPORT IFitResult * JIFitter::fit(IDataPointSet & dataPointSet, IFunction & func) {
    jobject jdataPointSet = factory->create(env, dataPointSet);
    jobject jfunction = factory->create(env, func);
    jobject obj = env->CallObjectMethod(ref, fitOLhep_aida_IDataPointSetELhep_aida_IFunctionECLhep_aida_IFitResultEMethod, jdataPointSet, jfunction);
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIFitResult(env, obj);
}

JNIEXPORT IFitResult * JIFitter::fit(IDataPointSet & dataPointSet, const std::string & model) {
    jobject jdataPointSet = factory->create(env, dataPointSet);
    jstring jmodel;
    NEWSTRING(jmodel, model)
    jobject obj = env->CallObjectMethod(ref, fitOLhep_aida_IDataPointSetELjava_lang_StringECLhep_aida_IFitResultEMethod, jdataPointSet, jmodel);
    DELSTRING(jmodel)
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIFitResult(env, obj);
}

JNIEXPORT IFitResult * JIFitter::fit(IDataPointSet & dataPointSet, const std::string & model, const std::vector<double> & initialParameters) {
    jobject jdataPointSet = factory->create(env, dataPointSet);
    jstring jmodel;
    jdoubleArray jinitialParameters;
    NEWSTRING(jmodel, model)
    NEWDOUBLEARRAY(jinitialParameters, initialParameters)
    jobject obj = env->CallObjectMethod(ref, fitOLhep_aida_IDataPointSetELjava_lang_StringEADCLhep_aida_IFitResultEMethod, jdataPointSet, jmodel, jinitialParameters);
    DELSTRING(jmodel)
    DELDOUBLEARRAY(jinitialParameters)
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIFitResult(env, obj);
}

JNIEXPORT IFitResult * JIFitter::fit(IFitData & fitData, const std::string & model) {
    jobject jfitData = factory->create(env, fitData);
    jstring jmodel;
    NEWSTRING(jmodel, model)
    jobject obj = env->CallObjectMethod(ref, fitOLhep_aida_IFitDataELjava_lang_StringECLhep_aida_IFitResultEMethod, jfitData, jmodel );
    DELSTRING(jmodel)
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIFitResult(env, obj);
}

JNIEXPORT IFitResult * JIFitter::fit(IFitData & fitData, const std::string & model, const std::vector<double> & initialParameters) {
    jobject jfitData = factory->create(env, fitData);
    jstring jmodel;
    jdoubleArray jinitialParameters;
    NEWSTRING(jmodel, model)
    NEWDOUBLEARRAY(jinitialParameters, initialParameters)
    jobject obj = env->CallObjectMethod(ref, fitOLhep_aida_IFitDataELjava_lang_StringEADCLhep_aida_IFitResultEMethod, jfitData, jmodel, jinitialParameters );
    DELSTRING(jmodel)
    DELDOUBLEARRAY(jinitialParameters)
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIFitResult(env, obj);
}

JNIEXPORT bool JIFitter::setEngine(const std::string & name) {
    jstring jname;
    NEWSTRING(jname, name)
    env->CallVoidMethod(ref, setEngineOLjava_lang_StringECVMethod, jname);
    DELSTRING(jname)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT std::string JIFitter::engineName() {
    // Call to Java
    jstring jname = (jstring)env->CallObjectMethod(ref, engineNameOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(jname, &isCopy);
    string name = utf;
    if (isCopy) env->ReleaseStringUTFChars(jname, utf);
    JNIUtil::checkExceptions(env);
    return name;
}

JNIEXPORT IFitParameterSettings & JIFitter::fitParameterSettings(const std::string & name) {
    jstring jname;
    NEWSTRING(jname, name)
    jobject obj = env->CallObjectMethod(ref, fitParameterSettingsOLjava_lang_StringECLhep_aida_IFitParameterSettingsEMethod, jname);
    DELSTRING(jname)
    JNIUtil::checkExceptions(env);
    IFitParameterSettings* settings = factory->createIFitParameterSettings(env, obj);
    fitParameterSettingsMap[name] = settings;
    return *settings;
}

JNIEXPORT std::vector<std::string> JIFitter::listParameterSettings() {
    std::vector<std::string> listParameterSettingsVector;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, listParameterSettingsOCALjava_lang_StringEMethod);

    if (array != NULL) {
        // convert string[] to vector<string>
        unsigned int len = env->GetArrayLength(array);
        for (unsigned int i=0; i<len; i++) {
            jstring jname = (jstring)env->GetObjectArrayElement(array, i);
            jboolean isCopy;
            const char* utf = env->GetStringUTFChars(jname, &isCopy);
            string name = utf;
            if (isCopy) env->ReleaseStringUTFChars(jname, utf);
            listParameterSettingsVector.push_back(name);
        }
    }
    JNIUtil::checkExceptions(env);
    return listParameterSettingsVector;
}

JNIEXPORT void JIFitter::resetParameterSettings() {
    env->CallVoidMethod(ref, resetParameterSettingsOCVMethod);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT bool JIFitter::setConstraint(const std::string & expr) {
    jstring jexpr;
    NEWSTRING(jexpr, expr)
    jboolean result = env->CallBooleanMethod(ref, setConstraintOLjava_lang_StringECVMethod, jexpr);
    DELSTRING(jexpr)
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT std::vector<std::string> JIFitter::constraints() {
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

JNIEXPORT void JIFitter::resetConstraints() {
    env->CallVoidMethod(ref, resetConstraintsOCVMethod);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT bool JIFitter::setFitMethod(const std::string & name) {
    jstring jname;
    NEWSTRING(jname, name)
    jboolean result = env->CallBooleanMethod(ref, setFitMethodOLjava_lang_StringECVMethod, jname);
    DELSTRING(jname)
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT std::string JIFitter::fitMethodName() {
    // Call to Java
    jstring jname = (jstring)env->CallObjectMethod(ref, fitMethodNameOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(jname, &isCopy);
    string name = utf;
    if (isCopy) env->ReleaseStringUTFChars(jname, utf);
    JNIUtil::checkExceptions(env);
    return name;
}

JNIEXPORT IDataPointSet * JIFitter::createScan1D(IFitData & fitData, IFunction & func, const std::string & par, int npts, double pmin, double pmax) {
    jobject jfitData = factory->create(env, fitData);
    jobject jfunction = factory->create(env, func);
    jstring jpar;
    NEWSTRING(jpar, par)
    jobject obj = env->CallObjectMethod(ref, createScan1DOLhep_aida_IFitDataELhep_aida_IFunctionELjava_lang_StringEIDDCLhep_aida_IDataPointSetEMethod, jfitData, jfunction, jpar, npts, pmin, pmax );
    DELSTRING(jpar)
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIFitter::createContour(IFitData & fitData, IFitResult & fitResult, const std::string & par1, const std::string & par2, int npts, double up) {
    jobject jfitData = factory->create(env, fitData);
    jobject jfitResult = factory->create(env, fitResult);
    jstring jpar1, jpar2;
    NEWSTRING(jpar1, par1)
    NEWSTRING(jpar2, par2)
    jobject obj = env->CallObjectMethod(ref, createContourOLhep_aida_IFitDataELhep_aida_IFitResultELjava_lang_StringELjava_lang_StringEIDCLhep_aida_IDataPointSetEMethod, jfitData, jfitResult, jpar1, jpar2, npts, up );
    DELSTRING(jpar1)
    DELSTRING(jpar2)
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT void JIFitter::setUseFunctionGradient(bool useGrad) {
    env->CallVoidMethod(ref, setUseFunctionGradientOZCVMethod, useGrad);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT bool JIFitter::useFunctionGradient() {
    jboolean result = env->CallBooleanMethod(ref, useFunctionGradientOCZMethod);
    JNIUtil::checkExceptions(env);
    return result;
}
