
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "AIDA/IPlotterRegion.h"
#include "AIDA/ITitleStyle.h"
#include "JIPlotter.h"
#include "JIPlotterRegion.h"
#include "JITitleStyle.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;

JNIEXPORT JIPlotter::JIPlotter(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory),
        iTitleStyle(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    availableParameterOptionsOLjava_lang_StringECALjava_lang_StringEMethod = env->GetMethodID(cls, "availableParameterOptions", "(Ljava/lang/String;)[Ljava/lang/String;");
    if (availableParameterOptionsOLjava_lang_StringECALjava_lang_StringEMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "availableParameterOptions" << "(Ljava/lang/String;)[Ljava/lang/String;" << std::endl;
    }

    currentRegionOCLhep_aida_IPlotterRegionEMethod = env->GetMethodID(cls, "currentRegion", "()Lhep/aida/IPlotterRegion;");
    if (currentRegionOCLhep_aida_IPlotterRegionEMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "currentRegion" << "()Lhep/aida/IPlotterRegion;" << std::endl;
    }

    availableParametersOCALjava_lang_StringEMethod = env->GetMethodID(cls, "availableParameters", "()[Ljava/lang/String;");
    if (availableParametersOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "availableParameters" << "()[Ljava/lang/String;" << std::endl;
    }

    titleStyleOCLhep_aida_ITitleStyleEMethod = env->GetMethodID(cls, "titleStyle", "()Lhep/aida/ITitleStyle;");
    if (titleStyleOCLhep_aida_ITitleStyleEMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "titleStyle" << "()Lhep/aida/ITitleStyle;" << std::endl;
    }

    createRegionsOIIICVMethod = env->GetMethodID(cls, "createRegions", "(III)V");
    if (createRegionsOIIICVMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "createRegions" << "(III)V" << std::endl;
    }

    setParameterOLjava_lang_StringELjava_lang_StringECVMethod = env->GetMethodID(cls, "setParameter", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (setParameterOLjava_lang_StringELjava_lang_StringECVMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "setParameter" << "(Ljava/lang/String;Ljava/lang/String;)V" << std::endl;
    }

    createRegionODDDDCLhep_aida_IPlotterRegionEMethod = env->GetMethodID(cls, "createRegion", "(DDDD)Lhep/aida/IPlotterRegion;");
    if (createRegionODDDDCLhep_aida_IPlotterRegionEMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "createRegion" << "(DDDD)Lhep/aida/IPlotterRegion;" << std::endl;
    }

    setTitleStyleOLhep_aida_ITitleStyleECVMethod = env->GetMethodID(cls, "setTitleStyle", "(Lhep/aida/ITitleStyle;)V");
    if (setTitleStyleOLhep_aida_ITitleStyleECVMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "setTitleStyle" << "(Lhep/aida/ITitleStyle;)V" << std::endl;
    }

    setCurrentRegionNumberOICVMethod = env->GetMethodID(cls, "setCurrentRegionNumber", "(I)V");
    if (setCurrentRegionNumberOICVMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "setCurrentRegionNumber" << "(I)V" << std::endl;
    }

    regionOICLhep_aida_IPlotterRegionEMethod = env->GetMethodID(cls, "region", "(I)Lhep/aida/IPlotterRegion;");
    if (regionOICLhep_aida_IPlotterRegionEMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "region" << "(I)Lhep/aida/IPlotterRegion;" << std::endl;
    }

    clearRegionsOCVMethod = env->GetMethodID(cls, "clearRegions", "()V");
    if (clearRegionsOCVMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "clearRegions" << "()V" << std::endl;
    }

    nextOCLhep_aida_IPlotterRegionEMethod = env->GetMethodID(cls, "next", "()Lhep/aida/IPlotterRegion;");
    if (nextOCLhep_aida_IPlotterRegionEMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "next" << "()Lhep/aida/IPlotterRegion;" << std::endl;
    }

    hideOCVMethod = env->GetMethodID(cls, "hide", "()V");
    if (hideOCVMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "hide" << "()V" << std::endl;
    }

    destroyRegionsOCVMethod = env->GetMethodID(cls, "destroyRegions", "()V");
    if (destroyRegionsOCVMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "destroyRegions" << "()V" << std::endl;
    }

    parameterValueOLjava_lang_StringECLjava_lang_StringEMethod = env->GetMethodID(cls, "parameterValue", "(Ljava/lang/String;)Ljava/lang/String;");
    if (parameterValueOLjava_lang_StringECLjava_lang_StringEMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "parameterValue" << "(Ljava/lang/String;)Ljava/lang/String;" << std::endl;
    }

    showOCVMethod = env->GetMethodID(cls, "show", "()V");
    if (showOCVMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "show" << "()V" << std::endl;
    }

    setTitleOLjava_lang_StringECVMethod = env->GetMethodID(cls, "setTitle", "(Ljava/lang/String;)V");
    if (setTitleOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "setTitle" << "(Ljava/lang/String;)V" << std::endl;
    }

    writeToFileOLjava_lang_StringELjava_lang_StringECVMethod = env->GetMethodID(cls, "writeToFile", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (writeToFileOLjava_lang_StringELjava_lang_StringECVMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "writeToFile" << "(Ljava/lang/String;Ljava/lang/String;)V" << std::endl;
    }

    numberOfRegionsOCIMethod = env->GetMethodID(cls, "numberOfRegions", "()I");
    if (numberOfRegionsOCIMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "numberOfRegions" << "()I" << std::endl;
    }

    currentRegionNumberOCIMethod = env->GetMethodID(cls, "currentRegionNumber", "()I");
    if (currentRegionNumberOCIMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "currentRegionNumber" << "()I" << std::endl;
    }

    refreshOCVMethod = env->GetMethodID(cls, "refresh", "()V");
    if (refreshOCVMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "refresh" << "()V" << std::endl;
    }

    interactOCVMethod = env->GetMethodID(cls, "interact", "()V");
    if (interactOCVMethod == NULL) {
        std::cerr << "IPlotter" << ": Could not find method: " << "interact" << "()V" << std::endl;
    }

}

JNIEXPORT JIPlotter::~JIPlotter() {
    delete iTitleStyle;
}

JNIEXPORT IPlotterRegion * JIPlotter::createRegion(double x, double y, double w, double h) {
    jobject r = env->CallObjectMethod(ref, createRegionODDDDCLhep_aida_IPlotterRegionEMethod,x,y,w,h);
    JNIUtil::checkExceptions(env);
    return factory->createIPlotterRegion(env,r);
}

JNIEXPORT bool JIPlotter::createRegions(int columns, int rows, int index) {
    env->CallVoidMethod(ref, createRegionsOIIICVMethod,columns,rows,index);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT IPlotterRegion & JIPlotter::currentRegion() const {
    jobject r = env->CallObjectMethod(ref, currentRegionOCLhep_aida_IPlotterRegionEMethod);
    JNIUtil::checkExceptions(env);
    IPlotterRegion* result = factory->createIPlotterRegion(env,r);
    return  *result;
}

JNIEXPORT int JIPlotter::currentRegionNumber() const {
    jint r = env->CallIntMethod(ref, currentRegionNumberOCIMethod);
    JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT int JIPlotter::numberOfRegions() const {
    jint r = env->CallIntMethod(ref, numberOfRegionsOCIMethod);
    JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT bool JIPlotter::setCurrentRegionNumber(int index) {
    env->CallVoidMethod(ref, setCurrentRegionNumberOICVMethod,index);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT IPlotterRegion & JIPlotter::next() {
    jobject r = env->CallObjectMethod(ref, nextOCLhep_aida_IPlotterRegionEMethod);
    JNIUtil::checkExceptions(env);
    IPlotterRegion* result = factory->createIPlotterRegion(env,r);
    return  *result;
}

JNIEXPORT IPlotterRegion * JIPlotter::region(int index) const {
    jobject r = env->CallObjectMethod(ref, regionOICLhep_aida_IPlotterRegionEMethod,index);
    JNIUtil::checkExceptions(env);
    return factory->createIPlotterRegion(env,r);
}

JNIEXPORT void JIPlotter::destroyRegions() {
    env->CallVoidMethod(ref, destroyRegionsOCVMethod);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT void JIPlotter::clearRegions() {
    env->CallVoidMethod(ref, clearRegionsOCVMethod);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT bool JIPlotter::setParameter(const std::string & parameter, const std::string & options) {
    jstring jparameter, joptions;
    NEWSTRING(jparameter, parameter)
    NEWSTRING(joptions, options)
    env->CallVoidMethod(ref, setParameterOLjava_lang_StringELjava_lang_StringECVMethod, jparameter, joptions);
    DELSTRING(jparameter)
    DELSTRING(joptions)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT std::string JIPlotter::parameterValue(const std::string & parameter) const {
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

JNIEXPORT std::vector<std::string>  JIPlotter::availableParameterOptions(const std::string & parameter) const {
    vector<string> result;
    jstring jparameter;
    NEWSTRING(jparameter, parameter)
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, availableParameterOptionsOLjava_lang_StringECALjava_lang_StringEMethod, jparameter);
    DELSTRING(jparameter)
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

JNIEXPORT std::vector<std::string>  JIPlotter::availableParameters() const {
    vector<string> result;
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

JNIEXPORT bool JIPlotter::show() {
    env->CallVoidMethod(ref, showOCVMethod);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotter::refresh() {
    env->CallVoidMethod(ref, refreshOCVMethod);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotter::hide() {
    env->CallVoidMethod(ref, hideOCVMethod);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotter::interact() {
    env->CallVoidMethod(ref, interactOCVMethod);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIPlotter::writeToFile(const std::string & filename, const std::string & type) {
    jstring jfilename, jtype;
    NEWSTRING(jfilename, filename)
    NEWSTRING(jtype, type)
    env->CallVoidMethod(ref, writeToFileOLjava_lang_StringELjava_lang_StringECVMethod, jfilename, jtype);
    DELSTRING(jfilename)
    DELSTRING(jtype)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT void JIPlotter::setTitle(const std::string & title) {
    jstring jtitle;
    NEWSTRING(jtitle, title)
    env->CallVoidMethod(ref, setTitleOLjava_lang_StringECVMethod, jtitle);
    DELSTRING(jtitle)
    JNIUtil::checkExceptions(env);
}

JNIEXPORT ITitleStyle & JIPlotter::titleStyle() {
    jobject jtitlestyle = env->CallObjectMethod(ref, titleStyleOCLhep_aida_ITitleStyleEMethod);
    iTitleStyle = factory->createITitleStyle(env, jtitlestyle);

    return *iTitleStyle;
}

JNIEXPORT void JIPlotter::setTitleStyle(const ITitleStyle & style) {
    jobject jstyle = factory->create(env, style);
    env->CallBooleanMethod(ref, setTitleStyleOLhep_aida_ITitleStyleECVMethod, jstyle);
    JNIUtil::exceptions(env);
}
