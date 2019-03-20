
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "AIDA/IAxisStyle.h"
#include "AIDA/IDataStyle.h"
#include "AIDA/IInfoStyle.h"
#include "AIDA/ITitleStyle.h"
#include "JIAxisStyle.h"
#include "JIBaseStyle.h"
#include "JIDataStyle.h"
#include "JIInfoStyle.h"
#include "JIPlotterStyle.h"
#include "JITitleStyle.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;

JNIEXPORT JIPlotterStyle::JIPlotterStyle(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JIBaseStyle(jnienv, object, factory),
        iDataStyle(NULL),
        iXaxisStyle(NULL),
        iYaxisStyle(NULL),
        iZaxisStyle(NULL),
        iTitleStyle(NULL),
        iInfoStyle(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    infoStyleOCLhep_aida_IInfoStyleEMethod = env->GetMethodID(cls, "infoStyle", "()Lhep/aida/IInfoStyle;");
    if (infoStyleOCLhep_aida_IInfoStyleEMethod == NULL) {
        std::cerr << "IPlotterStyle" << ": Could not find method: " << "infoStyle" << "()Lhep/aida/IInfoStyle;" << std::endl;
    }

    setAxisStyleXOLhep_aida_IAxisStyleECZMethod = env->GetMethodID(cls, "setAxisStyleX", "(Lhep/aida/IAxisStyle;)Z");
    if (setAxisStyleXOLhep_aida_IAxisStyleECZMethod == NULL) {
        std::cerr << "IPlotterStyle" << ": Could not find method: " << "setAxisStyleX" << "(Lhep/aida/IAxisStyle;)Z" << std::endl;
    }

    setDataStyleOLhep_aida_IDataStyleECZMethod = env->GetMethodID(cls, "setDataStyle", "(Lhep/aida/IDataStyle;)Z");
    if (setDataStyleOLhep_aida_IDataStyleECZMethod == NULL) {
        std::cerr << "IPlotterStyle" << ": Could not find method: " << "setDataStyle" << "(Lhep/aida/IDataStyle;)Z" << std::endl;
    }

    dataStyleOCLhep_aida_IDataStyleEMethod = env->GetMethodID(cls, "dataStyle", "()Lhep/aida/IDataStyle;");
    if (dataStyleOCLhep_aida_IDataStyleEMethod == NULL) {
        std::cerr << "IPlotterStyle" << ": Could not find method: " << "dataStyle" << "()Lhep/aida/IDataStyle;" << std::endl;
    }

    titleStyleOCLhep_aida_ITitleStyleEMethod = env->GetMethodID(cls, "titleStyle", "()Lhep/aida/ITitleStyle;");
    if (titleStyleOCLhep_aida_ITitleStyleEMethod == NULL) {
        std::cerr << "IPlotterStyle" << ": Could not find method: " << "titleStyle" << "()Lhep/aida/ITitleStyle;" << std::endl;
    }

    setInfoStyleOLhep_aida_IInfoStyleECZMethod = env->GetMethodID(cls, "setInfoStyle", "(Lhep/aida/IInfoStyle;)Z");
    if (setInfoStyleOLhep_aida_IInfoStyleECZMethod == NULL) {
        std::cerr << "IPlotterStyle" << ": Could not find method: " << "setInfoStyle" << "(Lhep/aida/IInfoStyle;)Z" << std::endl;
    }

    xAxisStyleOCLhep_aida_IAxisStyleEMethod = env->GetMethodID(cls, "xAxisStyle", "()Lhep/aida/IAxisStyle;");
    if (xAxisStyleOCLhep_aida_IAxisStyleEMethod == NULL) {
        std::cerr << "IPlotterStyle" << ": Could not find method: " << "xAxisStyle" << "()Lhep/aida/IAxisStyle;" << std::endl;
    }

    setAxisStyleZOLhep_aida_IAxisStyleECZMethod = env->GetMethodID(cls, "setAxisStyleZ", "(Lhep/aida/IAxisStyle;)Z");
    if (setAxisStyleZOLhep_aida_IAxisStyleECZMethod == NULL) {
        std::cerr << "IPlotterStyle" << ": Could not find method: " << "setAxisStyleZ" << "(Lhep/aida/IAxisStyle;)Z" << std::endl;
    }

    yAxisStyleOCLhep_aida_IAxisStyleEMethod = env->GetMethodID(cls, "yAxisStyle", "()Lhep/aida/IAxisStyle;");
    if (yAxisStyleOCLhep_aida_IAxisStyleEMethod == NULL) {
        std::cerr << "IPlotterStyle" << ": Could not find method: " << "yAxisStyle" << "()Lhep/aida/IAxisStyle;" << std::endl;
    }

    setTitleStyleOLhep_aida_ITitleStyleECZMethod = env->GetMethodID(cls, "setTitleStyle", "(Lhep/aida/ITitleStyle;)Z");
    if (setTitleStyleOLhep_aida_ITitleStyleECZMethod == NULL) {
        std::cerr << "IPlotterStyle" << ": Could not find method: " << "setTitleStyle" << "(Lhep/aida/ITitleStyle;)Z" << std::endl;
    }

    zAxisStyleOCLhep_aida_IAxisStyleEMethod = env->GetMethodID(cls, "zAxisStyle", "()Lhep/aida/IAxisStyle;");
    if (zAxisStyleOCLhep_aida_IAxisStyleEMethod == NULL) {
        std::cerr << "IPlotterStyle" << ": Could not find method: " << "zAxisStyle" << "()Lhep/aida/IAxisStyle;" << std::endl;
    }

    setAxisStyleYOLhep_aida_IAxisStyleECZMethod = env->GetMethodID(cls, "setAxisStyleY", "(Lhep/aida/IAxisStyle;)Z");
    if (setAxisStyleYOLhep_aida_IAxisStyleECZMethod == NULL) {
        std::cerr << "IPlotterStyle" << ": Could not find method: " << "setAxisStyleY" << "(Lhep/aida/IAxisStyle;)Z" << std::endl;
    }

}

JNIEXPORT JIPlotterStyle::~JIPlotterStyle() {
    delete iDataStyle;
    delete iXaxisStyle;
    delete iYaxisStyle;
    delete iZaxisStyle;
    delete iTitleStyle;
    delete iInfoStyle;
}

JNIEXPORT IDataStyle & JIPlotterStyle::dataStyle() {
    jobject obj = env->CallObjectMethod(ref, dataStyleOCLhep_aida_IDataStyleEMethod);
    iDataStyle = factory->createIDataStyle(env, obj);

    return *iDataStyle;
}

JNIEXPORT IAxisStyle & JIPlotterStyle::xAxisStyle() {
    jobject obj = env->CallObjectMethod(ref, xAxisStyleOCLhep_aida_IAxisStyleEMethod);
    iXaxisStyle = factory->createIAxisStyle(env, obj);

    return *iXaxisStyle;
}

JNIEXPORT IAxisStyle & JIPlotterStyle::yAxisStyle() {
    jobject obj = env->CallObjectMethod(ref, yAxisStyleOCLhep_aida_IAxisStyleEMethod);
    iYaxisStyle = factory->createIAxisStyle(env, obj);

    return *iYaxisStyle;
}

JNIEXPORT IAxisStyle & JIPlotterStyle::zAxisStyle() {
    jobject obj = env->CallObjectMethod(ref, zAxisStyleOCLhep_aida_IAxisStyleEMethod);
    iZaxisStyle = factory->createIAxisStyle(env, obj);

    return *iZaxisStyle;
}

JNIEXPORT ITitleStyle & JIPlotterStyle::titleStyle() {
    jobject obj = env->CallObjectMethod(ref, titleStyleOCLhep_aida_ITitleStyleEMethod);
    iTitleStyle = factory->createITitleStyle(env, obj);

    return *iTitleStyle;
}

JNIEXPORT IInfoStyle & JIPlotterStyle::infoStyle() {
    jobject obj = env->CallObjectMethod(ref, infoStyleOCLhep_aida_IInfoStyleEMethod);
    iInfoStyle = factory->createIInfoStyle(env, obj);

    return *iInfoStyle;
}

JNIEXPORT bool JIPlotterStyle::setDataStyle(const IDataStyle & dataStyle) {
    jobject jstyle = factory->create(env, dataStyle);
    jboolean result = env->CallBooleanMethod(ref, setDataStyleOLhep_aida_IDataStyleECZMethod, jstyle);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JIPlotterStyle::setAxisStyleX(const IAxisStyle & xAxisStyle) {
    jobject jstyle = factory->create(env, xAxisStyle);
    jboolean result = env->CallBooleanMethod(ref, setAxisStyleXOLhep_aida_IAxisStyleECZMethod, jstyle);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JIPlotterStyle::setAxisStyleY(const IAxisStyle & yAxisStyle) {
    jobject jstyle = factory->create(env, yAxisStyle);
    jboolean result = env->CallBooleanMethod(ref, setAxisStyleYOLhep_aida_IAxisStyleECZMethod, jstyle);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JIPlotterStyle::setAxisStyleZ(const IAxisStyle & zAxisStyle) {
    jobject jstyle = factory->create(env, zAxisStyle);
    jboolean result = env->CallBooleanMethod(ref, setAxisStyleZOLhep_aida_IAxisStyleECZMethod, jstyle);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JIPlotterStyle::setTitleStyle(const ITitleStyle & textStyle) {
    jobject jstyle = factory->create(env, textStyle);
    jboolean result = env->CallBooleanMethod(ref, setTitleStyleOLhep_aida_ITitleStyleECZMethod, jstyle);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JIPlotterStyle::setInfoStyle(const IInfoStyle & infoStyle) {
    jobject jstyle = factory->create(env, infoStyle);
    jboolean result = env->CallBooleanMethod(ref, setInfoStyleOLhep_aida_IInfoStyleECZMethod, jstyle);
    JNIUtil::checkExceptions(env);
    return result;
}
