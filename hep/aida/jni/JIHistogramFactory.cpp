
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "AIDA/IBaseHistogram.h"
#include "AIDA/ICloud1D.h"
#include "AIDA/ICloud2D.h"
#include "AIDA/ICloud3D.h"
#include "AIDA/IHistogram1D.h"
#include "AIDA/IHistogram2D.h"
#include "AIDA/IHistogram3D.h"
#include "AIDA/IProfile1D.h"
#include "AIDA/IProfile2D.h"
#include "JIHistogramFactory.h"
#include "JNIUtil.hh"
#include "JNIMacros.hh"

#include "JIHistogram1D.h"
#include "JIHistogram2D.h"
#include "JIHistogram3D.h"
#include "JICloud1D.h"
#include "JICloud2D.h"
#include "JICloud3D.h"
#include "JIProfile1D.h"
#include "JIProfile2D.h"

#include "ProxyFactory.h"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JIHistogramFactory::JIHistogramFactory(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    projectionYOLjava_lang_StringELhep_aida_IHistogram2DECLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "projectionY", "(Ljava/lang/String;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram1D;");
    if (projectionYOLjava_lang_StringELhep_aida_IHistogram2DECLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "projectionY" << "(Ljava/lang/String;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram1D;" << std::endl;
    }

    createProfile2DOLjava_lang_StringEIDDIDDCLhep_aida_IProfile2DEMethod = env->GetMethodID(cls, "createProfile2D", "(Ljava/lang/String;IDDIDD)Lhep/aida/IProfile2D;");
    if (createProfile2DOLjava_lang_StringEIDDIDDCLhep_aida_IProfile2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createProfile2D" << "(Ljava/lang/String;IDDIDD)Lhep/aida/IProfile2D;" << std::endl;
    }

    addOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "add", "(Ljava/lang/String;Lhep/aida/IHistogram1D;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;");
    if (addOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "add" << "(Ljava/lang/String;Lhep/aida/IHistogram1D;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;" << std::endl;
    }

    createProfile1DOLjava_lang_StringELjava_lang_StringEADLjava_lang_StringECLhep_aida_IProfile1DEMethod = env->GetMethodID(cls, "createProfile1D", "(Ljava/lang/String;Ljava/lang/String;[DLjava/lang/String;)Lhep/aida/IProfile1D;");
    if (createProfile1DOLjava_lang_StringELjava_lang_StringEADLjava_lang_StringECLhep_aida_IProfile1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createProfile1D" << "(Ljava/lang/String;Ljava/lang/String;[DLjava/lang/String;)Lhep/aida/IProfile1D;" << std::endl;
    }

    createProfile2DOLjava_lang_StringELjava_lang_StringEIDDIDDDDLjava_lang_StringECLhep_aida_IProfile2DEMethod = env->GetMethodID(cls, "createProfile2D", "(Ljava/lang/String;Ljava/lang/String;IDDIDDDDLjava/lang/String;)Lhep/aida/IProfile2D;");
    if (createProfile2DOLjava_lang_StringELjava_lang_StringEIDDIDDDDLjava_lang_StringECLhep_aida_IProfile2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createProfile2D" << "(Ljava/lang/String;Ljava/lang/String;IDDIDDDDLjava/lang/String;)Lhep/aida/IProfile2D;" << std::endl;
    }

    projectionXZOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "projectionXZ", "(Ljava/lang/String;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram2D;");
    if (projectionXZOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "projectionXZ" << "(Ljava/lang/String;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram2D;" << std::endl;
    }

    createProfile2DOLjava_lang_StringEIDDIDDDDCLhep_aida_IProfile2DEMethod = env->GetMethodID(cls, "createProfile2D", "(Ljava/lang/String;IDDIDDDD)Lhep/aida/IProfile2D;");
    if (createProfile2DOLjava_lang_StringEIDDIDDDDCLhep_aida_IProfile2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createProfile2D" << "(Ljava/lang/String;IDDIDDDD)Lhep/aida/IProfile2D;" << std::endl;
    }

    createProfile2DOLjava_lang_StringELjava_lang_StringEADADDDLjava_lang_StringECLhep_aida_IProfile2DEMethod = env->GetMethodID(cls, "createProfile2D", "(Ljava/lang/String;Ljava/lang/String;[D[DDDLjava/lang/String;)Lhep/aida/IProfile2D;");
    if (createProfile2DOLjava_lang_StringELjava_lang_StringEADADDDLjava_lang_StringECLhep_aida_IProfile2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createProfile2D" << "(Ljava/lang/String;Ljava/lang/String;[D[DDDLjava/lang/String;)Lhep/aida/IProfile2D;" << std::endl;
    }

    createCopyOLjava_lang_StringELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "createCopy", "(Ljava/lang/String;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;");
    if (createCopyOLjava_lang_StringELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCopy" << "(Ljava/lang/String;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;" << std::endl;
    }

    createHistogram1DOLjava_lang_StringELjava_lang_StringEADLjava_lang_StringECLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "createHistogram1D", "(Ljava/lang/String;Ljava/lang/String;[DLjava/lang/String;)Lhep/aida/IHistogram1D;");
    if (createHistogram1DOLjava_lang_StringELjava_lang_StringEADLjava_lang_StringECLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createHistogram1D" << "(Ljava/lang/String;Ljava/lang/String;[DLjava/lang/String;)Lhep/aida/IHistogram1D;" << std::endl;
    }

    projectionYZOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "projectionYZ", "(Ljava/lang/String;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram2D;");
    if (projectionYZOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "projectionYZ" << "(Ljava/lang/String;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram2D;" << std::endl;
    }

    divideOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod = env->GetMethodID(cls, "divide", "(Ljava/lang/String;Lhep/aida/IHistogram3D;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;");
    if (divideOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "divide" << "(Ljava/lang/String;Lhep/aida/IHistogram3D;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;" << std::endl;
    }

    sliceXOLjava_lang_StringELhep_aida_IHistogram2DEIICLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "sliceX", "(Ljava/lang/String;Lhep/aida/IHistogram2D;II)Lhep/aida/IHistogram1D;");
    if (sliceXOLjava_lang_StringELhep_aida_IHistogram2DEIICLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "sliceX" << "(Ljava/lang/String;Lhep/aida/IHistogram2D;II)Lhep/aida/IHistogram1D;" << std::endl;
    }

    addOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "add", "(Ljava/lang/String;Lhep/aida/IHistogram2D;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;");
    if (addOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "add" << "(Ljava/lang/String;Lhep/aida/IHistogram2D;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;" << std::endl;
    }

    subtractOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "subtract", "(Ljava/lang/String;Lhep/aida/IHistogram2D;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;");
    if (subtractOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "subtract" << "(Ljava/lang/String;Lhep/aida/IHistogram2D;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;" << std::endl;
    }

    createCopyOLjava_lang_StringELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "createCopy", "(Ljava/lang/String;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;");
    if (createCopyOLjava_lang_StringELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCopy" << "(Ljava/lang/String;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;" << std::endl;
    }

    createCopyOLjava_lang_StringELhep_aida_IProfile1DECLhep_aida_IProfile1DEMethod = env->GetMethodID(cls, "createCopy", "(Ljava/lang/String;Lhep/aida/IProfile1D;)Lhep/aida/IProfile1D;");
    if (createCopyOLjava_lang_StringELhep_aida_IProfile1DECLhep_aida_IProfile1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCopy" << "(Ljava/lang/String;Lhep/aida/IProfile1D;)Lhep/aida/IProfile1D;" << std::endl;
    }

    createHistogram2DOLjava_lang_StringEIDDIDDCLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "createHistogram2D", "(Ljava/lang/String;IDDIDD)Lhep/aida/IHistogram2D;");
    if (createHistogram2DOLjava_lang_StringEIDDIDDCLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createHistogram2D" << "(Ljava/lang/String;IDDIDD)Lhep/aida/IHistogram2D;" << std::endl;
    }

    divideOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "divide", "(Ljava/lang/String;Lhep/aida/IHistogram1D;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;");
    if (divideOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "divide" << "(Ljava/lang/String;Lhep/aida/IHistogram1D;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;" << std::endl;
    }

    createCopyOLjava_lang_StringELhep_aida_ICloud3DECLhep_aida_ICloud3DEMethod = env->GetMethodID(cls, "createCopy", "(Ljava/lang/String;Lhep/aida/ICloud3D;)Lhep/aida/ICloud3D;");
    if (createCopyOLjava_lang_StringELhep_aida_ICloud3DECLhep_aida_ICloud3DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCopy" << "(Ljava/lang/String;Lhep/aida/ICloud3D;)Lhep/aida/ICloud3D;" << std::endl;
    }

    createHistogram3DOLjava_lang_StringELjava_lang_StringEADADADLjava_lang_StringECLhep_aida_IHistogram3DEMethod = env->GetMethodID(cls, "createHistogram3D", "(Ljava/lang/String;Ljava/lang/String;[D[D[DLjava/lang/String;)Lhep/aida/IHistogram3D;");
    if (createHistogram3DOLjava_lang_StringELjava_lang_StringEADADADLjava_lang_StringECLhep_aida_IHistogram3DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createHistogram3D" << "(Ljava/lang/String;Ljava/lang/String;[D[D[DLjava/lang/String;)Lhep/aida/IHistogram3D;" << std::endl;
    }

    createHistogram3DOLjava_lang_StringEIDDIDDIDDCLhep_aida_IHistogram3DEMethod = env->GetMethodID(cls, "createHistogram3D", "(Ljava/lang/String;IDDIDDIDD)Lhep/aida/IHistogram3D;");
    if (createHistogram3DOLjava_lang_StringEIDDIDDIDDCLhep_aida_IHistogram3DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createHistogram3D" << "(Ljava/lang/String;IDDIDDIDD)Lhep/aida/IHistogram3D;" << std::endl;
    }

    multiplyOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod = env->GetMethodID(cls, "multiply", "(Ljava/lang/String;Lhep/aida/IHistogram3D;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;");
    if (multiplyOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "multiply" << "(Ljava/lang/String;Lhep/aida/IHistogram3D;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;" << std::endl;
    }

    createCopyOLjava_lang_StringELhep_aida_ICloud2DECLhep_aida_ICloud2DEMethod = env->GetMethodID(cls, "createCopy", "(Ljava/lang/String;Lhep/aida/ICloud2D;)Lhep/aida/ICloud2D;");
    if (createCopyOLjava_lang_StringELhep_aida_ICloud2DECLhep_aida_ICloud2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCopy" << "(Ljava/lang/String;Lhep/aida/ICloud2D;)Lhep/aida/ICloud2D;" << std::endl;
    }

    createProfile1DOLjava_lang_StringEIDDDDCLhep_aida_IProfile1DEMethod = env->GetMethodID(cls, "createProfile1D", "(Ljava/lang/String;IDDDD)Lhep/aida/IProfile1D;");
    if (createProfile1DOLjava_lang_StringEIDDDDCLhep_aida_IProfile1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createProfile1D" << "(Ljava/lang/String;IDDDD)Lhep/aida/IProfile1D;" << std::endl;
    }

    projectionXYOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "projectionXY", "(Ljava/lang/String;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram2D;");
    if (projectionXYOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "projectionXY" << "(Ljava/lang/String;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram2D;" << std::endl;
    }

    subtractOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod = env->GetMethodID(cls, "subtract", "(Ljava/lang/String;Lhep/aida/IHistogram3D;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;");
    if (subtractOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "subtract" << "(Ljava/lang/String;Lhep/aida/IHistogram3D;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;" << std::endl;
    }

    createProfile1DOLjava_lang_StringELjava_lang_StringEADDDLjava_lang_StringECLhep_aida_IProfile1DEMethod = env->GetMethodID(cls, "createProfile1D", "(Ljava/lang/String;Ljava/lang/String;[DDDLjava/lang/String;)Lhep/aida/IProfile1D;");
    if (createProfile1DOLjava_lang_StringELjava_lang_StringEADDDLjava_lang_StringECLhep_aida_IProfile1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createProfile1D" << "(Ljava/lang/String;Ljava/lang/String;[DDDLjava/lang/String;)Lhep/aida/IProfile1D;" << std::endl;
    }

    createHistogram2DOLjava_lang_StringELjava_lang_StringEADADLjava_lang_StringECLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "createHistogram2D", "(Ljava/lang/String;Ljava/lang/String;[D[DLjava/lang/String;)Lhep/aida/IHistogram2D;");
    if (createHistogram2DOLjava_lang_StringELjava_lang_StringEADADLjava_lang_StringECLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createHistogram2D" << "(Ljava/lang/String;Ljava/lang/String;[D[DLjava/lang/String;)Lhep/aida/IHistogram2D;" << std::endl;
    }

    sliceXZOLjava_lang_StringELhep_aida_IHistogram3DEIICLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "sliceXZ", "(Ljava/lang/String;Lhep/aida/IHistogram3D;II)Lhep/aida/IHistogram2D;");
    if (sliceXZOLjava_lang_StringELhep_aida_IHistogram3DEIICLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "sliceXZ" << "(Ljava/lang/String;Lhep/aida/IHistogram3D;II)Lhep/aida/IHistogram2D;" << std::endl;
    }

    createCopyOLjava_lang_StringELhep_aida_ICloud1DECLhep_aida_ICloud1DEMethod = env->GetMethodID(cls, "createCopy", "(Ljava/lang/String;Lhep/aida/ICloud1D;)Lhep/aida/ICloud1D;");
    if (createCopyOLjava_lang_StringELhep_aida_ICloud1DECLhep_aida_ICloud1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCopy" << "(Ljava/lang/String;Lhep/aida/ICloud1D;)Lhep/aida/ICloud1D;" << std::endl;
    }

    createProfile1DOLjava_lang_StringEIDDCLhep_aida_IProfile1DEMethod = env->GetMethodID(cls, "createProfile1D", "(Ljava/lang/String;IDD)Lhep/aida/IProfile1D;");
    if (createProfile1DOLjava_lang_StringEIDDCLhep_aida_IProfile1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createProfile1D" << "(Ljava/lang/String;IDD)Lhep/aida/IProfile1D;" << std::endl;
    }

    sliceYZOLjava_lang_StringELhep_aida_IHistogram3DEIICLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "sliceYZ", "(Ljava/lang/String;Lhep/aida/IHistogram3D;II)Lhep/aida/IHistogram2D;");
    if (sliceYZOLjava_lang_StringELhep_aida_IHistogram3DEIICLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "sliceYZ" << "(Ljava/lang/String;Lhep/aida/IHistogram3D;II)Lhep/aida/IHistogram2D;" << std::endl;
    }

    destroyOLhep_aida_IBaseHistogramECVMethod = env->GetMethodID(cls, "destroy", "(Lhep/aida/IBaseHistogram;)V");
    if (destroyOLhep_aida_IBaseHistogramECVMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "destroy" << "(Lhep/aida/IBaseHistogram;)V" << std::endl;
    }

    createCloud1DOLjava_lang_StringELjava_lang_StringEILjava_lang_StringECLhep_aida_ICloud1DEMethod = env->GetMethodID(cls, "createCloud1D", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)Lhep/aida/ICloud1D;");
    if (createCloud1DOLjava_lang_StringELjava_lang_StringEILjava_lang_StringECLhep_aida_ICloud1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCloud1D" << "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)Lhep/aida/ICloud1D;" << std::endl;
    }

    createHistogram3DOLjava_lang_StringELjava_lang_StringEIDDIDDIDDLjava_lang_StringECLhep_aida_IHistogram3DEMethod = env->GetMethodID(cls, "createHistogram3D", "(Ljava/lang/String;Ljava/lang/String;IDDIDDIDDLjava/lang/String;)Lhep/aida/IHistogram3D;");
    if (createHistogram3DOLjava_lang_StringELjava_lang_StringEIDDIDDIDDLjava_lang_StringECLhep_aida_IHistogram3DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createHistogram3D" << "(Ljava/lang/String;Ljava/lang/String;IDDIDDIDDLjava/lang/String;)Lhep/aida/IHistogram3D;" << std::endl;
    }

    createCloud3DOLjava_lang_StringELjava_lang_StringEILjava_lang_StringECLhep_aida_ICloud3DEMethod = env->GetMethodID(cls, "createCloud3D", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)Lhep/aida/ICloud3D;");
    if (createCloud3DOLjava_lang_StringELjava_lang_StringEILjava_lang_StringECLhep_aida_ICloud3DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCloud3D" << "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)Lhep/aida/ICloud3D;" << std::endl;
    }

    createCloud3DOLjava_lang_StringECLhep_aida_ICloud3DEMethod = env->GetMethodID(cls, "createCloud3D", "(Ljava/lang/String;)Lhep/aida/ICloud3D;");
    if (createCloud3DOLjava_lang_StringECLhep_aida_ICloud3DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCloud3D" << "(Ljava/lang/String;)Lhep/aida/ICloud3D;" << std::endl;
    }

    createCloud1DOLjava_lang_StringECLhep_aida_ICloud1DEMethod = env->GetMethodID(cls, "createCloud1D", "(Ljava/lang/String;)Lhep/aida/ICloud1D;");
    if (createCloud1DOLjava_lang_StringECLhep_aida_ICloud1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCloud1D" << "(Ljava/lang/String;)Lhep/aida/ICloud1D;" << std::endl;
    }

    createProfile1DOLjava_lang_StringELjava_lang_StringEIDDDDLjava_lang_StringECLhep_aida_IProfile1DEMethod = env->GetMethodID(cls, "createProfile1D", "(Ljava/lang/String;Ljava/lang/String;IDDDDLjava/lang/String;)Lhep/aida/IProfile1D;");
    if (createProfile1DOLjava_lang_StringELjava_lang_StringEIDDDDLjava_lang_StringECLhep_aida_IProfile1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createProfile1D" << "(Ljava/lang/String;Ljava/lang/String;IDDDDLjava/lang/String;)Lhep/aida/IProfile1D;" << std::endl;
    }

    divideOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "divide", "(Ljava/lang/String;Lhep/aida/IHistogram2D;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;");
    if (divideOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "divide" << "(Ljava/lang/String;Lhep/aida/IHistogram2D;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;" << std::endl;
    }

    sliceXOLjava_lang_StringELhep_aida_IHistogram2DEICLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "sliceX", "(Ljava/lang/String;Lhep/aida/IHistogram2D;I)Lhep/aida/IHistogram1D;");
    if (sliceXOLjava_lang_StringELhep_aida_IHistogram2DEICLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "sliceX" << "(Ljava/lang/String;Lhep/aida/IHistogram2D;I)Lhep/aida/IHistogram1D;" << std::endl;
    }

    sliceYOLjava_lang_StringELhep_aida_IHistogram2DEIICLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "sliceY", "(Ljava/lang/String;Lhep/aida/IHistogram2D;II)Lhep/aida/IHistogram1D;");
    if (sliceYOLjava_lang_StringELhep_aida_IHistogram2DEIICLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "sliceY" << "(Ljava/lang/String;Lhep/aida/IHistogram2D;II)Lhep/aida/IHistogram1D;" << std::endl;
    }

    createProfile1DOLjava_lang_StringELjava_lang_StringEIDDLjava_lang_StringECLhep_aida_IProfile1DEMethod = env->GetMethodID(cls, "createProfile1D", "(Ljava/lang/String;Ljava/lang/String;IDDLjava/lang/String;)Lhep/aida/IProfile1D;");
    if (createProfile1DOLjava_lang_StringELjava_lang_StringEIDDLjava_lang_StringECLhep_aida_IProfile1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createProfile1D" << "(Ljava/lang/String;Ljava/lang/String;IDDLjava/lang/String;)Lhep/aida/IProfile1D;" << std::endl;
    }

    subtractOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "subtract", "(Ljava/lang/String;Lhep/aida/IHistogram1D;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;");
    if (subtractOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "subtract" << "(Ljava/lang/String;Lhep/aida/IHistogram1D;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;" << std::endl;
    }

    sliceXYOLjava_lang_StringELhep_aida_IHistogram3DEIICLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "sliceXY", "(Ljava/lang/String;Lhep/aida/IHistogram3D;II)Lhep/aida/IHistogram2D;");
    if (sliceXYOLjava_lang_StringELhep_aida_IHistogram3DEIICLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "sliceXY" << "(Ljava/lang/String;Lhep/aida/IHistogram3D;II)Lhep/aida/IHistogram2D;" << std::endl;
    }

    createHistogram1DOLjava_lang_StringEIDDCLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "createHistogram1D", "(Ljava/lang/String;IDD)Lhep/aida/IHistogram1D;");
    if (createHistogram1DOLjava_lang_StringEIDDCLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createHistogram1D" << "(Ljava/lang/String;IDD)Lhep/aida/IHistogram1D;" << std::endl;
    }

    sliceYOLjava_lang_StringELhep_aida_IHistogram2DEICLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "sliceY", "(Ljava/lang/String;Lhep/aida/IHistogram2D;I)Lhep/aida/IHistogram1D;");
    if (sliceYOLjava_lang_StringELhep_aida_IHistogram2DEICLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "sliceY" << "(Ljava/lang/String;Lhep/aida/IHistogram2D;I)Lhep/aida/IHistogram1D;" << std::endl;
    }

    createProfile2DOLjava_lang_StringELjava_lang_StringEADADLjava_lang_StringECLhep_aida_IProfile2DEMethod = env->GetMethodID(cls, "createProfile2D", "(Ljava/lang/String;Ljava/lang/String;[D[DLjava/lang/String;)Lhep/aida/IProfile2D;");
    if (createProfile2DOLjava_lang_StringELjava_lang_StringEADADLjava_lang_StringECLhep_aida_IProfile2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createProfile2D" << "(Ljava/lang/String;Ljava/lang/String;[D[DLjava/lang/String;)Lhep/aida/IProfile2D;" << std::endl;
    }

    createCloud2DOLjava_lang_StringELjava_lang_StringEILjava_lang_StringECLhep_aida_ICloud2DEMethod = env->GetMethodID(cls, "createCloud2D", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)Lhep/aida/ICloud2D;");
    if (createCloud2DOLjava_lang_StringELjava_lang_StringEILjava_lang_StringECLhep_aida_ICloud2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCloud2D" << "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)Lhep/aida/ICloud2D;" << std::endl;
    }

    createCopyOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod = env->GetMethodID(cls, "createCopy", "(Ljava/lang/String;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;");
    if (createCopyOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCopy" << "(Ljava/lang/String;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;" << std::endl;
    }

    createProfile2DOLjava_lang_StringELjava_lang_StringEIDDIDDLjava_lang_StringECLhep_aida_IProfile2DEMethod = env->GetMethodID(cls, "createProfile2D", "(Ljava/lang/String;Ljava/lang/String;IDDIDDLjava/lang/String;)Lhep/aida/IProfile2D;");
    if (createProfile2DOLjava_lang_StringELjava_lang_StringEIDDIDDLjava_lang_StringECLhep_aida_IProfile2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createProfile2D" << "(Ljava/lang/String;Ljava/lang/String;IDDIDDLjava/lang/String;)Lhep/aida/IProfile2D;" << std::endl;
    }

    multiplyOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "multiply", "(Ljava/lang/String;Lhep/aida/IHistogram2D;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;");
    if (multiplyOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "multiply" << "(Ljava/lang/String;Lhep/aida/IHistogram2D;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;" << std::endl;
    }

    createHistogram2DOLjava_lang_StringELjava_lang_StringEIDDIDDLjava_lang_StringECLhep_aida_IHistogram2DEMethod = env->GetMethodID(cls, "createHistogram2D", "(Ljava/lang/String;Ljava/lang/String;IDDIDDLjava/lang/String;)Lhep/aida/IHistogram2D;");
    if (createHistogram2DOLjava_lang_StringELjava_lang_StringEIDDIDDLjava_lang_StringECLhep_aida_IHistogram2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createHistogram2D" << "(Ljava/lang/String;Ljava/lang/String;IDDIDDLjava/lang/String;)Lhep/aida/IHistogram2D;" << std::endl;
    }

    projectionXOLjava_lang_StringELhep_aida_IHistogram2DECLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "projectionX", "(Ljava/lang/String;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram1D;");
    if (projectionXOLjava_lang_StringELhep_aida_IHistogram2DECLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "projectionX" << "(Ljava/lang/String;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram1D;" << std::endl;
    }

    createCopyOLjava_lang_StringELhep_aida_IProfile2DECLhep_aida_IProfile2DEMethod = env->GetMethodID(cls, "createCopy", "(Ljava/lang/String;Lhep/aida/IProfile2D;)Lhep/aida/IProfile2D;");
    if (createCopyOLjava_lang_StringELhep_aida_IProfile2DECLhep_aida_IProfile2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCopy" << "(Ljava/lang/String;Lhep/aida/IProfile2D;)Lhep/aida/IProfile2D;" << std::endl;
    }

    addOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod = env->GetMethodID(cls, "add", "(Ljava/lang/String;Lhep/aida/IHistogram3D;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;");
    if (addOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "add" << "(Ljava/lang/String;Lhep/aida/IHistogram3D;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;" << std::endl;
    }

    createCloud2DOLjava_lang_StringECLhep_aida_ICloud2DEMethod = env->GetMethodID(cls, "createCloud2D", "(Ljava/lang/String;)Lhep/aida/ICloud2D;");
    if (createCloud2DOLjava_lang_StringECLhep_aida_ICloud2DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createCloud2D" << "(Ljava/lang/String;)Lhep/aida/ICloud2D;" << std::endl;
    }

    multiplyOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "multiply", "(Ljava/lang/String;Lhep/aida/IHistogram1D;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;");
    if (multiplyOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "multiply" << "(Ljava/lang/String;Lhep/aida/IHistogram1D;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;" << std::endl;
    }

    createHistogram1DOLjava_lang_StringELjava_lang_StringEIDDLjava_lang_StringECLhep_aida_IHistogram1DEMethod = env->GetMethodID(cls, "createHistogram1D", "(Ljava/lang/String;Ljava/lang/String;IDDLjava/lang/String;)Lhep/aida/IHistogram1D;");
    if (createHistogram1DOLjava_lang_StringELjava_lang_StringEIDDLjava_lang_StringECLhep_aida_IHistogram1DEMethod == NULL) {
        std::cerr << "IHistogramFactory" << ": cloud not find method: " << "createHistogram1D" << "(Ljava/lang/String;Ljava/lang/String;IDDLjava/lang/String;)Lhep/aida/IHistogram1D;" << std::endl;
    }

}

JNIEXPORT JIHistogramFactory::~JIHistogramFactory() {
}

JNIEXPORT bool JIHistogramFactory::destroy(IBaseHistogram * hist) {
   jobject jhist = factory->create(env, *hist);
   env->CallObjectMethod(ref, destroyOLhep_aida_IBaseHistogramECVMethod, jhist);
   delete(jhist);
   if (JNIUtil::exceptions(env)) return false;
   else return true;
}

JNIEXPORT ICloud1D * JIHistogramFactory::createCloud1D(const std::string & name, const std::string & title, int nMax, const std::string & options) {
   jstring jname, jtitle, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createCloud1DOLjava_lang_StringELjava_lang_StringEILjava_lang_StringECLhep_aida_ICloud1DEMethod, jname, jtitle, nMax, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createICloud1D(env, obj);
}

JNIEXPORT ICloud1D * JIHistogramFactory::createCloud1D(const std::string & nameAndTitle) {
   jstring jname;
   NEWSTRING(jname, nameAndTitle)
   jobject obj = env->CallObjectMethod(ref, createCloud1DOLjava_lang_StringECLhep_aida_ICloud1DEMethod, jname);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createICloud1D(env, obj);
}

JNIEXPORT ICloud1D * JIHistogramFactory::createCopy(const std::string & name, const ICloud1D & cloud) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jcloud = factory->create(env, cloud);
   jobject obj = env->CallObjectMethod(ref, createCopyOLjava_lang_StringELhep_aida_ICloud1DECLhep_aida_ICloud1DEMethod, jname, jcloud);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createICloud1D(env, obj);
}

JNIEXPORT ICloud2D * JIHistogramFactory::createCloud2D(const std::string & name, const std::string & title, int nMax, const std::string & options) {
   jstring jname, jtitle, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createCloud2DOLjava_lang_StringELjava_lang_StringEILjava_lang_StringECLhep_aida_ICloud2DEMethod, jname, jtitle, nMax, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createICloud2D(env, obj);
}

JNIEXPORT ICloud2D * JIHistogramFactory::createCloud2D(const std::string & nameAndTitle) {
   jstring jname;
   NEWSTRING(jname, nameAndTitle)
   jobject obj = env->CallObjectMethod(ref, createCloud2DOLjava_lang_StringECLhep_aida_ICloud2DEMethod, jname);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createICloud2D(env, obj);
}

JNIEXPORT ICloud2D * JIHistogramFactory::createCopy(const std::string & name, const ICloud2D & cloud) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jcloud = factory->create(env, cloud);
   jobject obj = env->CallObjectMethod(ref, createCopyOLjava_lang_StringELhep_aida_ICloud2DECLhep_aida_ICloud2DEMethod, jname, jcloud);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createICloud2D(env, obj);
}

JNIEXPORT ICloud3D * JIHistogramFactory::createCloud3D(const std::string & name, const std::string & title, int nMax, const std::string & options) {
   jstring jname, jtitle, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createCloud3DOLjava_lang_StringELjava_lang_StringEILjava_lang_StringECLhep_aida_ICloud3DEMethod, jname, jtitle, nMax, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createICloud3D(env, obj);
}

JNIEXPORT ICloud3D * JIHistogramFactory::createCloud3D(const std::string & nameAndTitle) {
   jstring jname;
   NEWSTRING(jname, nameAndTitle)
   jobject obj = env->CallObjectMethod(ref, createCloud3DOLjava_lang_StringECLhep_aida_ICloud3DEMethod, jname);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createICloud3D(env, obj);
}

JNIEXPORT ICloud3D * JIHistogramFactory::createCopy(const std::string & name, const ICloud3D & cloud) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jcloud = factory->create(env, cloud);
   jobject obj = env->CallObjectMethod(ref, createCopyOLjava_lang_StringELhep_aida_ICloud3DECLhep_aida_ICloud3DEMethod, jname, jcloud);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createICloud3D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::createHistogram1D(const std::string & name, const std::string & title, int nBins, double lowerEdge, double upperEdge, const std::string & options) {
   jstring jname, jtitle, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createHistogram1DOLjava_lang_StringELjava_lang_StringEIDDLjava_lang_StringECLhep_aida_IHistogram1DEMethod, jname, jtitle, nBins, lowerEdge, upperEdge, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::createHistogram1D(const std::string & nameAndTitle, int nBins, double lowerEdge, double upperEdge) {
   jstring jname;
   NEWSTRING(jname, nameAndTitle)
   jobject obj = env->CallObjectMethod(ref, createHistogram1DOLjava_lang_StringEIDDCLhep_aida_IHistogram1DEMethod, jname, nBins, lowerEdge, upperEdge);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::createHistogram1D(const std::string & name, const std::string & title, const std::vector<double>  & binEdges, const std::string & options) {
   jstring jname, jtitle, joptions;
   jdoubleArray jbinEdges;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWDOUBLEARRAY(jbinEdges, binEdges)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createHistogram1DOLjava_lang_StringELjava_lang_StringEADLjava_lang_StringECLhep_aida_IHistogram1DEMethod,
                                       jname, jtitle, jbinEdges, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELDOUBLEARRAY(jbinEdges)
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::createCopy(const std::string & name, const IHistogram1D & hist) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, createCopyOLjava_lang_StringELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod, jname, jhist);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::createHistogram2D(const std::string & name, const std::string & title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, const std::string & options) {
   jstring jname, jtitle, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createHistogram2DOLjava_lang_StringELjava_lang_StringEIDDIDDLjava_lang_StringECLhep_aida_IHistogram2DEMethod, jname, jtitle, nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::createHistogram2D(const std::string & nameAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY) {
   jstring jname;
   NEWSTRING(jname, nameAndTitle)
   jobject obj = env->CallObjectMethod(ref, createHistogram2DOLjava_lang_StringEIDDIDDCLhep_aida_IHistogram2DEMethod, jname, nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::createHistogram2D(const std::string & name, const std::string & title, const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, const std::string & options) {
   jstring jname, jtitle, joptions;
   jdoubleArray jbinEdgesX, jbinEdgesY;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWDOUBLEARRAY(jbinEdgesX, binEdgesX)
   NEWDOUBLEARRAY(jbinEdgesY, binEdgesY)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createHistogram2DOLjava_lang_StringELjava_lang_StringEADADLjava_lang_StringECLhep_aida_IHistogram2DEMethod,
                                       jname, jtitle, jbinEdgesX, jbinEdgesY, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELDOUBLEARRAY(jbinEdgesX)
   DELDOUBLEARRAY(jbinEdgesY)
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::createCopy(const std::string & name, const IHistogram2D & hist) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, createCopyOLjava_lang_StringELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod, jname, jhist);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}

JNIEXPORT IHistogram3D * JIHistogramFactory::createHistogram3D(const std::string & name, const std::string & title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, int nBinsZ, double lowerEdgeZ, double upperEdgeZ, const std::string & options) {
   jstring jname, jtitle, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createHistogram3DOLjava_lang_StringELjava_lang_StringEIDDIDDIDDLjava_lang_StringECLhep_aida_IHistogram3DEMethod, jname, jtitle, nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY, nBinsZ, lowerEdgeZ, upperEdgeZ, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram3D(env, obj);
}

JNIEXPORT IHistogram3D * JIHistogramFactory::createHistogram3D(const std::string & nameAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, int nBinsZ, double lowerEdgeZ, double upperEdgeZ) {
   jstring jname;
   NEWSTRING(jname, nameAndTitle)
   jobject obj = env->CallObjectMethod(ref, createHistogram3DOLjava_lang_StringEIDDIDDIDDCLhep_aida_IHistogram3DEMethod, jname, nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY, nBinsZ, lowerEdgeZ, upperEdgeZ);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram3D(env, obj);
}

JNIEXPORT IHistogram3D * JIHistogramFactory::createHistogram3D(const std::string & name, const std::string & title, const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, const std::vector<double>  & binEdgesZ, const std::string & options) {
   jstring jname, jtitle, joptions;
   jdoubleArray jbinEdgesX, jbinEdgesY, jbinEdgesZ;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWDOUBLEARRAY(jbinEdgesX, binEdgesX)
   NEWDOUBLEARRAY(jbinEdgesY, binEdgesY)
   NEWDOUBLEARRAY(jbinEdgesZ, binEdgesZ)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createHistogram3DOLjava_lang_StringELjava_lang_StringEADADADLjava_lang_StringECLhep_aida_IHistogram3DEMethod,
                                       jname, jtitle, jbinEdgesX, jbinEdgesY, jbinEdgesZ, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELDOUBLEARRAY(jbinEdgesX)
   DELDOUBLEARRAY(jbinEdgesY)
   DELDOUBLEARRAY(jbinEdgesZ)
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram3D(env, obj);
}

JNIEXPORT IHistogram3D * JIHistogramFactory::createCopy(const std::string & name, const IHistogram3D & hist) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, createCopyOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod, jname, jhist);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram3D(env, obj);
}

JNIEXPORT IProfile1D * JIHistogramFactory::createProfile1D(const std::string & name, const std::string & title, int nBins, double lowerEdge, double upperEdge, const std::string & options) {
   jstring jname, jtitle, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createProfile1DOLjava_lang_StringELjava_lang_StringEIDDLjava_lang_StringECLhep_aida_IProfile1DEMethod, jname, jtitle, nBins, lowerEdge, upperEdge, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile1D(env, obj);
}

JNIEXPORT IProfile1D * JIHistogramFactory::createProfile1D(const std::string & name, const std::string & title, int nBins, double lowerEdge, double upperEdge, double lowerValue, double upperValue, const std::string & options) {
   jstring jname, jtitle, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createProfile1DOLjava_lang_StringELjava_lang_StringEIDDDDLjava_lang_StringECLhep_aida_IProfile1DEMethod, jname, jtitle, nBins, lowerEdge, upperEdge, lowerValue, upperValue, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile1D(env, obj);
}

JNIEXPORT IProfile1D * JIHistogramFactory::createProfile1D(const std::string & name, const std::string & title, const std::vector<double>  & binEdges, const std::string & options) {
   jstring jname, jtitle, joptions;
   jdoubleArray jbinEdges;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWDOUBLEARRAY(jbinEdges, binEdges)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createProfile1DOLjava_lang_StringELjava_lang_StringEADLjava_lang_StringECLhep_aida_IProfile1DEMethod, jname, jtitle, jbinEdges, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELDOUBLEARRAY(jbinEdges)
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile1D(env, obj);
}

JNIEXPORT IProfile1D * JIHistogramFactory::createProfile1D(const std::string & name, const std::string & title, const std::vector<double>  & binEdges, double lowerValue, double upperValue, const std::string & options) {
   jstring jname, jtitle, joptions;
   jdoubleArray jbinEdges;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWDOUBLEARRAY(jbinEdges, binEdges)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createProfile1DOLjava_lang_StringELjava_lang_StringEADDDLjava_lang_StringECLhep_aida_IProfile1DEMethod, jname, jtitle, jbinEdges, lowerValue, upperValue, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELDOUBLEARRAY(jbinEdges)
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile1D(env, obj);
}

JNIEXPORT IProfile1D * JIHistogramFactory::createProfile1D(const std::string & nameAndTitle, int nBins, double lowerEdge, double upperEdge) {
   jstring jname;
   NEWSTRING(jname, nameAndTitle)
   jobject obj = env->CallObjectMethod(ref, createProfile1DOLjava_lang_StringEIDDCLhep_aida_IProfile1DEMethod, jname, nBins, lowerEdge, upperEdge);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile1D(env, obj);
}

JNIEXPORT IProfile1D * JIHistogramFactory::createProfile1D(const std::string & nameAndTitle, int nBins, double lowerEdge, double upperEdge, double lowerValue, double upperValue) {
   jstring jname;
   NEWSTRING(jname, nameAndTitle)
   jobject obj = env->CallObjectMethod(ref, createProfile1DOLjava_lang_StringEIDDDDCLhep_aida_IProfile1DEMethod, jname, nBins, lowerEdge, upperEdge, lowerValue, upperValue);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile1D(env, obj);
}

JNIEXPORT IProfile1D * JIHistogramFactory::createCopy(const std::string & name, const IProfile1D & profile) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jprofile = factory->create(env, profile);
   jobject obj = env->CallObjectMethod(ref, createCopyOLjava_lang_StringELhep_aida_IProfile1DECLhep_aida_IProfile1DEMethod, jname, jprofile);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile1D(env, obj);
}

JNIEXPORT IProfile2D * JIHistogramFactory::createProfile2D(const std::string & name, const std::string & title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, const std::string & options) {
   jstring jname, jtitle, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createProfile2DOLjava_lang_StringELjava_lang_StringEIDDIDDLjava_lang_StringECLhep_aida_IProfile2DEMethod, jname, jtitle, nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile2D(env, obj);
}

JNIEXPORT IProfile2D * JIHistogramFactory::createProfile2D(const std::string & name, const std::string & title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, double lowerValue, double upperValue, const std::string & options) {
   jstring jname, jtitle, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createProfile2DOLjava_lang_StringELjava_lang_StringEIDDIDDDDLjava_lang_StringECLhep_aida_IProfile2DEMethod, jname, jtitle, nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY, lowerValue, upperValue, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile2D(env, obj);
}

JNIEXPORT IProfile2D * JIHistogramFactory::createProfile2D(const std::string & name, const std::string & title, const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, const std::string & options) {
   jstring jname, jtitle, joptions;
   jdoubleArray jbinEdgesX, jbinEdgesY;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWDOUBLEARRAY(jbinEdgesX, binEdgesX)
   NEWDOUBLEARRAY(jbinEdgesY, binEdgesY)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createProfile2DOLjava_lang_StringELjava_lang_StringEADADLjava_lang_StringECLhep_aida_IProfile2DEMethod, jname, jtitle, jbinEdgesX, jbinEdgesY, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELDOUBLEARRAY(jbinEdgesX)
   DELDOUBLEARRAY(jbinEdgesY)
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile2D(env, obj);
}

JNIEXPORT IProfile2D * JIHistogramFactory::createProfile2D(const std::string & name, const std::string & title, const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, double lowerValue, double upperValue, const std::string & options) {
   jstring jname, jtitle, joptions;
   jdoubleArray jbinEdgesX, jbinEdgesY;
   NEWSTRING(jname, name)
   NEWSTRING(jtitle, title)
   NEWDOUBLEARRAY(jbinEdgesX, binEdgesX)
   NEWDOUBLEARRAY(jbinEdgesY, binEdgesY)
   NEWSTRING(joptions, options)
   jobject obj = env->CallObjectMethod(ref, createProfile2DOLjava_lang_StringELjava_lang_StringEADADDDLjava_lang_StringECLhep_aida_IProfile2DEMethod, jname, jtitle, jbinEdgesX, jbinEdgesY, lowerValue, upperValue, joptions);
   DELSTRING(jname);
   DELSTRING(jtitle);
   DELDOUBLEARRAY(jbinEdgesX)
   DELDOUBLEARRAY(jbinEdgesY)
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile2D(env, obj);
}

JNIEXPORT IProfile2D * JIHistogramFactory::createProfile2D(const std::string & nameAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY) {
   jstring jname;
   NEWSTRING(jname, nameAndTitle)
   jobject obj = env->CallObjectMethod(ref, createProfile2DOLjava_lang_StringEIDDIDDCLhep_aida_IProfile2DEMethod, jname, nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile2D(env, obj);
}

JNIEXPORT IProfile2D * JIHistogramFactory::createProfile2D(const std::string & nameAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, double lowerValue, double upperValue) {
   jstring jname;
   NEWSTRING(jname, nameAndTitle)
   jobject obj = env->CallObjectMethod(ref, createProfile2DOLjava_lang_StringEIDDIDDDDCLhep_aida_IProfile2DEMethod, jname, nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY, lowerValue, upperValue);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile2D(env, obj);
}

JNIEXPORT IProfile2D * JIHistogramFactory::createCopy(const std::string & name, const IProfile2D & profile) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jprofile = factory->create(env, profile);
   jobject obj = env->CallObjectMethod(ref, createCopyOLjava_lang_StringELhep_aida_IProfile2DECLhep_aida_IProfile2DEMethod, jname, jprofile);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIProfile2D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::add(const std::string & name, const IHistogram1D & hist1, const IHistogram1D & hist2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist1 = factory->create(env, hist1);
   jobject jhist2 = factory->create(env, hist2);
   jobject obj = env->CallObjectMethod(ref, addOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod, jname, jhist1, jhist2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::subtract(const std::string & name, const IHistogram1D & hist1, const IHistogram1D & hist2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist1 = factory->create(env, hist1);
   jobject jhist2 = factory->create(env, hist2);
   jobject obj = env->CallObjectMethod(ref, subtractOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod, jname, jhist1, jhist2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::multiply(const std::string & name, const IHistogram1D & hist1, const IHistogram1D & hist2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist1 = factory->create(env, hist1);
   jobject jhist2 = factory->create(env, hist2);
   jobject obj = env->CallObjectMethod(ref, multiplyOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod, jname, jhist1, jhist2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::divide(const std::string & name, const IHistogram1D & hist1, const IHistogram1D & hist2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist1 = factory->create(env, hist1);
   jobject jhist2 = factory->create(env, hist2);
   jobject obj = env->CallObjectMethod(ref, divideOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod, jname, jhist1, jhist2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::add(const std::string & name, const IHistogram2D & hist1, const IHistogram2D & hist2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist1 = factory->create(env, hist1);
   jobject jhist2 = factory->create(env, hist2);
   jobject obj = env->CallObjectMethod(ref, addOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod, jname, jhist1, jhist2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::subtract(const std::string & name, const IHistogram2D & hist1, const IHistogram2D & hist2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist1 = factory->create(env, hist1);
   jobject jhist2 = factory->create(env, hist2);
   jobject obj = env->CallObjectMethod(ref, subtractOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod, jname, jhist1, jhist2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::multiply(const std::string & name, const IHistogram2D & hist1, const IHistogram2D & hist2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist1 = factory->create(env, hist1);
   jobject jhist2 = factory->create(env, hist2);
   jobject obj = env->CallObjectMethod(ref, multiplyOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod, jname, jhist1, jhist2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::divide(const std::string & name, const IHistogram2D & hist1, const IHistogram2D & hist2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist1 = factory->create(env, hist1);
   jobject jhist2 = factory->create(env, hist2);
   jobject obj = env->CallObjectMethod(ref, divideOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod, jname, jhist1, jhist2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}

JNIEXPORT IHistogram3D * JIHistogramFactory::add(const std::string & name, const IHistogram3D & hist1, const IHistogram3D & hist2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist1 = factory->create(env, hist1);
   jobject jhist2 = factory->create(env, hist2);
   jobject obj = env->CallObjectMethod(ref, addOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod, jname, jhist1, jhist2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram3D(env, obj);
}

JNIEXPORT IHistogram3D * JIHistogramFactory::subtract(const std::string & name, const IHistogram3D & hist1, const IHistogram3D & hist2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist1 = factory->create(env, hist1);
   jobject jhist2 = factory->create(env, hist2);
   jobject obj = env->CallObjectMethod(ref, subtractOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod, jname, jhist1, jhist2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram3D(env, obj);
}

JNIEXPORT IHistogram3D * JIHistogramFactory::multiply(const std::string & name, const IHistogram3D & hist1, const IHistogram3D & hist2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist1 = factory->create(env, hist1);
   jobject jhist2 = factory->create(env, hist2);
   jobject obj = env->CallObjectMethod(ref, multiplyOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod, jname, jhist1, jhist2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram3D(env, obj);
}

JNIEXPORT IHistogram3D * JIHistogramFactory::divide(const std::string & name, const IHistogram3D & hist1, const IHistogram3D & hist2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist1 = factory->create(env, hist1);
   jobject jhist2 = factory->create(env, hist2);
   jobject obj = env->CallObjectMethod(ref, divideOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod, jname, jhist1, jhist2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram3D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::projectionX(const std::string & name, const IHistogram2D & hist) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, projectionXOLjava_lang_StringELhep_aida_IHistogram2DECLhep_aida_IHistogram1DEMethod, jname, jhist);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::projectionY(const std::string & name, const IHistogram2D & hist) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, projectionYOLjava_lang_StringELhep_aida_IHistogram2DECLhep_aida_IHistogram1DEMethod, jname, jhist);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::sliceX(const std::string & name, const IHistogram2D & hist, int index) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, sliceXOLjava_lang_StringELhep_aida_IHistogram2DEICLhep_aida_IHistogram1DEMethod, jname, jhist, index);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::sliceY(const std::string & name, const IHistogram2D & hist, int index) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, sliceYOLjava_lang_StringELhep_aida_IHistogram2DEICLhep_aida_IHistogram1DEMethod, jname, jhist, index);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::sliceX(const std::string & name, const IHistogram2D & hist, int index1, int index2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, sliceXOLjava_lang_StringELhep_aida_IHistogram2DEIICLhep_aida_IHistogram1DEMethod, jname, jhist, index1, index2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram1D * JIHistogramFactory::sliceY(const std::string & name, const IHistogram2D & hist, int index1, int index2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, sliceYOLjava_lang_StringELhep_aida_IHistogram2DEIICLhep_aida_IHistogram1DEMethod, jname, jhist, index1, index2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram1D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::projectionXY(const std::string & name, const IHistogram3D & hist) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, projectionXYOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram2DEMethod, jname, jhist);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::projectionXZ(const std::string & name, const IHistogram3D & hist) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, projectionXZOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram2DEMethod, jname, jhist);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::projectionYZ(const std::string & name, const IHistogram3D & hist) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, projectionYZOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram2DEMethod, jname, jhist);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::sliceXY(const std::string & name, const IHistogram3D & hist, int index1, int index2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, sliceXYOLjava_lang_StringELhep_aida_IHistogram3DEIICLhep_aida_IHistogram2DEMethod, jname, jhist, index1, index2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::sliceXZ(const std::string & name, const IHistogram3D & hist, int index1, int index2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, sliceXZOLjava_lang_StringELhep_aida_IHistogram3DEIICLhep_aida_IHistogram2DEMethod, jname, jhist, index1, index2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}

JNIEXPORT IHistogram2D * JIHistogramFactory::sliceYZ(const std::string & name, const IHistogram3D & hist, int index1, int index2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, sliceYZOLjava_lang_StringELhep_aida_IHistogram3DEIICLhep_aida_IHistogram2DEMethod, jname, jhist, index1, index2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIHistogram2D(env, obj);
}
