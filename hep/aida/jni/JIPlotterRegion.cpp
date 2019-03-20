
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "AIDA/IBaseHistogram.h"
#include "AIDA/IHistogram.h"
#include "AIDA/IHistogram1D.h"
#include "AIDA/IDataPointSet.h"
#include "AIDA/IFunction.h"
#include "AIDA/IInfo.h"
#include "AIDA/IPlotterLayout.h"
#include "AIDA/IPlotterStyle.h"
#include "JIPlotterLayout.h"
#include "JIPlotterRegion.h"
#include "JIPlotterStyle.h"
#include "JIBaseHistogram.h"
#include "JIInfo.h"
#include "JIFunction.h"
#include "JIDataPointSet.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIPlotterRegion::JIPlotterRegion(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory),
        iPlotterStyle(NULL),
        iLayout(NULL),
        iInfo(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    availableParameterOptionsOLjava_lang_StringECALjava_lang_StringEMethod = env->GetMethodID(cls, "availableParameterOptions", "(Ljava/lang/String;)[Ljava/lang/String;");
    if (availableParameterOptionsOLjava_lang_StringECALjava_lang_StringEMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "availableParameterOptions" << "(Ljava/lang/String;)[Ljava/lang/String;" << std::endl;
    }

    plotOLhep_aida_IDataPointSetELhep_aida_IPlotterStyleELjava_lang_StringECVMethod = env->GetMethodID(cls, "plot", "(Lhep/aida/IDataPointSet;Lhep/aida/IPlotterStyle;Ljava/lang/String;)V");
    if (plotOLhep_aida_IDataPointSetELhep_aida_IPlotterStyleELjava_lang_StringECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "plot" << "(Lhep/aida/IDataPointSet;Lhep/aida/IPlotterStyle;Ljava/lang/String;)V" << std::endl;
    }

    availableParametersOCALjava_lang_StringEMethod = env->GetMethodID(cls, "availableParameters", "()[Ljava/lang/String;");
    if (availableParametersOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "availableParameters" << "()[Ljava/lang/String;" << std::endl;
    }

    plotOLhep_aida_IDataPointSetELjava_lang_StringECVMethod = env->GetMethodID(cls, "plot", "(Lhep/aida/IDataPointSet;Ljava/lang/String;)V");
    if (plotOLhep_aida_IDataPointSetELjava_lang_StringECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "plot" << "(Lhep/aida/IDataPointSet;Ljava/lang/String;)V" << std::endl;
    }

    setParameterOLjava_lang_StringELjava_lang_StringECVMethod = env->GetMethodID(cls, "setParameter", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (setParameterOLjava_lang_StringELjava_lang_StringECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "setParameter" << "(Ljava/lang/String;Ljava/lang/String;)V" << std::endl;
    }

    setStyleOLhep_aida_IPlotterStyleECVMethod = env->GetMethodID(cls, "setStyle", "(Lhep/aida/IPlotterStyle;)V");
    if (setStyleOLhep_aida_IPlotterStyleECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "setStyle" << "(Lhep/aida/IPlotterStyle;)V" << std::endl;
    }

    removeOLhep_aida_IBaseHistogramECVMethod = env->GetMethodID(cls, "remove", "(Lhep/aida/IBaseHistogram;)V");
    if (removeOLhep_aida_IBaseHistogramECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "remove" << "(Lhep/aida/IBaseHistogram;)V" << std::endl;
    }

    setLayoutOLhep_aida_IPlotterLayoutECVMethod = env->GetMethodID(cls, "setLayout", "(Lhep/aida/IPlotterLayout;)V");
    if (setLayoutOLhep_aida_IPlotterLayoutECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "setLayout" << "(Lhep/aida/IPlotterLayout;)V" << std::endl;
    }

    removeOLhep_aida_IFunctionECVMethod = env->GetMethodID(cls, "remove", "(Lhep/aida/IFunction;)V");
    if (removeOLhep_aida_IFunctionECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "remove" << "(Lhep/aida/IFunction;)V" << std::endl;
    }

    setYLimitsODDCVMethod = env->GetMethodID(cls, "setYLimits", "(DD)V");
    if (setYLimitsODDCVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "setYLimits" << "(DD)V" << std::endl;
    }

    removeOLhep_aida_IDataPointSetECVMethod = env->GetMethodID(cls, "remove", "(Lhep/aida/IDataPointSet;)V");
    if (removeOLhep_aida_IDataPointSetECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "remove" << "(Lhep/aida/IDataPointSet;)V" << std::endl;
    }

    plotOLhep_aida_IBaseHistogramELjava_lang_StringECVMethod = env->GetMethodID(cls, "plot", "(Lhep/aida/IBaseHistogram;Ljava/lang/String;)V");
    if (plotOLhep_aida_IBaseHistogramELjava_lang_StringECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "plot" << "(Lhep/aida/IBaseHistogram;Ljava/lang/String;)V" << std::endl;
    }

    plotOLhep_aida_IFunctionELjava_lang_StringECVMethod = env->GetMethodID(cls, "plot", "(Lhep/aida/IFunction;Ljava/lang/String;)V");
    if (plotOLhep_aida_IFunctionELjava_lang_StringECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "plot" << "(Lhep/aida/IFunction;Ljava/lang/String;)V" << std::endl;
    }

    styleOCLhep_aida_IPlotterStyleEMethod = env->GetMethodID(cls, "style", "()Lhep/aida/IPlotterStyle;");
    if (styleOCLhep_aida_IPlotterStyleEMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "style" << "()Lhep/aida/IPlotterStyle;" << std::endl;
    }

    layoutOCLhep_aida_IPlotterLayoutEMethod = env->GetMethodID(cls, "layout", "()Lhep/aida/IPlotterLayout;");
    if (layoutOCLhep_aida_IPlotterLayoutEMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "layout" << "()Lhep/aida/IPlotterLayout;" << std::endl;
    }

    setXLimitsODDCVMethod = env->GetMethodID(cls, "setXLimits", "(DD)V");
    if (setXLimitsODDCVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "setXLimits" << "(DD)V" << std::endl;
    }

    parameterValueOLjava_lang_StringECLjava_lang_StringEMethod = env->GetMethodID(cls, "parameterValue", "(Ljava/lang/String;)Ljava/lang/String;");
    if (parameterValueOLjava_lang_StringECLjava_lang_StringEMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "parameterValue" << "(Ljava/lang/String;)Ljava/lang/String;" << std::endl;
    }

    applyStyleOLhep_aida_IPlotterStyleECVMethod = env->GetMethodID(cls, "applyStyle", "(Lhep/aida/IPlotterStyle;)V");
    if (applyStyleOLhep_aida_IPlotterStyleECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "applyStyle" << "(Lhep/aida/IPlotterStyle;)V" << std::endl;
    }

    infoOCLhep_aida_IInfoEMethod = env->GetMethodID(cls, "info", "()Lhep/aida/IInfo;");
    if (infoOCLhep_aida_IInfoEMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "info" << "()Lhep/aida/IInfo;" << std::endl;
    }

    setTitleOLjava_lang_StringECVMethod = env->GetMethodID(cls, "setTitle", "(Ljava/lang/String;)V");
    if (setTitleOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "setTitle" << "(Ljava/lang/String;)V" << std::endl;
    }

    setZLimitsODDCVMethod = env->GetMethodID(cls, "setZLimits", "(DD)V");
    if (setZLimitsODDCVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "setZLimits" << "(DD)V" << std::endl;
    }

    plotOLhep_aida_IFunctionELhep_aida_IPlotterStyleELjava_lang_StringECVMethod = env->GetMethodID(cls, "plot", "(Lhep/aida/IFunction;Lhep/aida/IPlotterStyle;Ljava/lang/String;)V");
    if (plotOLhep_aida_IFunctionELhep_aida_IPlotterStyleELjava_lang_StringECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "plot" << "(Lhep/aida/IFunction;Lhep/aida/IPlotterStyle;Ljava/lang/String;)V" << std::endl;
    }

    plotOLhep_aida_IBaseHistogramELhep_aida_IPlotterStyleELjava_lang_StringECVMethod = env->GetMethodID(cls, "plot", "(Lhep/aida/IBaseHistogram;Lhep/aida/IPlotterStyle;Ljava/lang/String;)V");
    if (plotOLhep_aida_IBaseHistogramELhep_aida_IPlotterStyleELjava_lang_StringECVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "plot" << "(Lhep/aida/IBaseHistogram;Lhep/aida/IPlotterStyle;Ljava/lang/String;)V" << std::endl;
    }

    clearOCVMethod = env->GetMethodID(cls, "clear", "()V");
    if (clearOCVMethod == NULL) {
        std::cerr << "IPlotterRegion" << ": Could not find method: " << "clear" << "()V" << std::endl;
    }
}

JNIEXPORT JIPlotterRegion::~JIPlotterRegion() {
    delete iInfo;
}

JNIEXPORT bool JIPlotterRegion::plot(const IBaseHistogram & histogram, const std::string & options) {
    jobject jhistogram = factory->create(env, histogram);
    jstring joptions;    
    NEWSTRING(joptions, options);
    env->CallVoidMethod(ref, plotOLhep_aida_IBaseHistogramELjava_lang_StringECVMethod, jhistogram, joptions);
    DELSTRING(joptions);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotterRegion::plot(const IBaseHistogram & histogram, const IPlotterStyle & style, const std::string & options) {
    jobject jhistogram = factory->create(env, histogram);
    jobject jstyle = factory->create(env, style);
    jstring joptions;
    NEWSTRING(joptions, options)
    env->CallVoidMethod(ref, plotOLhep_aida_IBaseHistogramELhep_aida_IPlotterStyleELjava_lang_StringECVMethod, jhistogram, jstyle, joptions);
    DELSTRING(joptions)
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotterRegion::plot(const IFunction & function, const std::string & options) {
    jobject jfunction = factory->create(env, function);
    jstring joptions;
    NEWSTRING(joptions, options)
    env->CallVoidMethod(ref, plotOLhep_aida_IFunctionELjava_lang_StringECVMethod, jfunction, joptions);
    DELSTRING(joptions)
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotterRegion::plot(const IFunction & function, const IPlotterStyle & style, const std::string & options) {
    jobject jfunction = factory->create(env, function);
    jobject jstyle = factory->create(env, style);
    jstring joptions;
    NEWSTRING(joptions, options)
    env->CallVoidMethod(ref, plotOLhep_aida_IFunctionELhep_aida_IPlotterStyleELjava_lang_StringECVMethod, jfunction, jstyle, joptions);
    DELSTRING(joptions)
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotterRegion::plot(const IDataPointSet & dataPointSet, const std::string & options) {
    jobject jdataPointSet = factory->create(env, dataPointSet);
    jstring joptions;
    NEWSTRING(joptions, options)
    env->CallVoidMethod(ref, plotOLhep_aida_IDataPointSetELjava_lang_StringECVMethod, jdataPointSet, joptions);
    DELSTRING(joptions)
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotterRegion::plot(const IDataPointSet & dataPointSet, const IPlotterStyle & style, const std::string & options) {
    jobject jdataPointSet = factory->create(env, dataPointSet);
    jobject jstyle = factory->create(env, style);
    jstring joptions;
    NEWSTRING(joptions, options)
    env->CallVoidMethod(ref, plotOLhep_aida_IDataPointSetELhep_aida_IPlotterStyleELjava_lang_StringECVMethod, jdataPointSet, jstyle, joptions);
    DELSTRING(joptions)
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotterRegion::remove(const IBaseHistogram & histogram) {
    jobject jhistogram = factory->create(env, histogram);
    env->CallVoidMethod(ref, removeOLhep_aida_IBaseHistogramECVMethod, jhistogram);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotterRegion::remove(const IFunction & function) {
    jobject jfunction = factory->create(env, function);
    env->CallVoidMethod(ref, removeOLhep_aida_IFunctionECVMethod, jfunction);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotterRegion::remove(const IDataPointSet & dataPointSet) {
    jobject jdataPointSet = factory->create(env, dataPointSet);
    env->CallVoidMethod(ref, removeOLhep_aida_IDataPointSetECVMethod, jdataPointSet);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT void JIPlotterRegion::clear() {
    env->CallVoidMethod(ref, clearOCVMethod);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT bool JIPlotterRegion::setParameter(const std::string & parameter, const std::string & options) {
    jstring jparameter, joptions;
    NEWSTRING(jparameter, parameter)
    NEWSTRING(joptions, options)
    env->CallVoidMethod(ref, setParameterOLjava_lang_StringELjava_lang_StringECVMethod, jparameter, joptions);
    DELSTRING(jparameter)
    DELSTRING(joptions)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT std::string JIPlotterRegion::parameterValue(const std::string & parameter) const {
    jstring jparameter;
    NEWSTRING(jparameter, parameter)

    jstring result = (jstring)env->CallObjectMethod(ref, parameterValueOLjava_lang_StringECLjava_lang_StringEMethod, jparameter);
    DELSTRING(jparameter)

    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    JNIUtil::checkExceptions(env);
    return resultString;
}

JNIEXPORT std::vector<std::string>  JIPlotterRegion::availableParameterOptions(const std::string & parameter) const {
    jstring jparameter;
    NEWSTRING(jparameter, parameter)
    vector<string> result;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, availableParameterOptionsOLjava_lang_StringECALjava_lang_StringEMethod, jparameter);

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
    DELSTRING(jparameter)
    return result;
}

JNIEXPORT std::vector<std::string>  JIPlotterRegion::availableParameters() const {
    vector<string> result;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, availableParametersOCALjava_lang_StringEMethod);

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

JNIEXPORT IPlotterStyle & JIPlotterRegion::style() {
    jobject obj = env->CallObjectMethod(ref, styleOCLhep_aida_IPlotterStyleEMethod);
    iPlotterStyle = factory->createIPlotterStyle(env, obj);

    return *iPlotterStyle;
}

JNIEXPORT bool JIPlotterRegion::setStyle(const IPlotterStyle & style) {
    jobject jstyle = factory->create(env, style);
    env->CallVoidMethod(ref, setStyleOLhep_aida_IPlotterStyleECVMethod, jstyle);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotterRegion::applyStyle(const IPlotterStyle & style) {
    jobject jstyle = factory->create(env, style);
    env->CallBooleanMethod(ref, applyStyleOLhep_aida_IPlotterStyleECVMethod, jstyle);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT void JIPlotterRegion::setTitle(const std::string & title) {
    jstring jtitle;
    NEWSTRING(jtitle, title)
    env->CallVoidMethod(ref, setTitleOLjava_lang_StringECVMethod, jtitle);
    DELSTRING(jtitle)
    JNIUtil::checkExceptions(env);
}

JNIEXPORT bool JIPlotterRegion::setXLimits(double min, double max) {
    env->CallVoidMethod(ref, setXLimitsODDCVMethod, min, max);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotterRegion::setYLimits(double min, double max) {
    env->CallVoidMethod(ref, setYLimitsODDCVMethod, min, max);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotterRegion::setZLimits(double min, double max) {
    env->CallVoidMethod(ref, setZLimitsODDCVMethod, min, max);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT IPlotterLayout & JIPlotterRegion::layout() {
    jobject obj = env->CallObjectMethod(ref, layoutOCLhep_aida_IPlotterLayoutEMethod);
    iLayout = factory->createIPlotterLayout(env, obj);

    return *iLayout;
}

JNIEXPORT bool JIPlotterRegion::setLayout(const IPlotterLayout & layout) {
    jobject jlayout = factory->create(env, layout);
    env->CallBooleanMethod(ref, setLayoutOLhep_aida_IPlotterLayoutECVMethod, jlayout);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT IInfo & JIPlotterRegion::info() {
    if (iInfo == NULL) {
        jobject infoObj = env->CallObjectMethod(ref, infoOCLhep_aida_IInfoEMethod);
        iInfo = factory->createIInfo(env, infoObj);
    }
    return *iInfo;
}

// QUESTION no getTitle ?
