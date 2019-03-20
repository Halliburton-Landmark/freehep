
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "AIDA/ICloud1D.h"
#include "AIDA/ICloud2D.h"
#include "AIDA/ICloud3D.h"
#include "AIDA/IDataPointSet.h"
#include "AIDA/IEvaluator.h"
#include "AIDA/IHistogram1D.h"
#include "AIDA/IHistogram2D.h"
#include "AIDA/IHistogram3D.h"
#include "AIDA/IProfile1D.h"
#include "AIDA/IProfile2D.h"
#include "AIDA/IRangeSet.h"
#include "AIDA/ITuple.h"
#include "JIFitData.h"
#include "JIHistogram1D.h"
#include "JIHistogram2D.h"
#include "JIHistogram3D.h"
#include "JIProfile1D.h"
#include "JIProfile2D.h"
#include "JICloud1D.h"
#include "JICloud2D.h"
#include "JICloud3D.h"
#include "JITuple.h"
#include "JIDataPointSet.h"
#include "JIRangeSet.h"
#include "JIEvaluator.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIFitData::JIFitData(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    create2DConnectionOLhep_aida_IDataPointSetEIIICVMethod = env->GetMethodID(cls, "create2DConnection", "(Lhep/aida/IDataPointSet;III)V");
    if (create2DConnectionOLhep_aida_IDataPointSetEIIICVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create2DConnection" << "(Lhep/aida/IDataPointSet;III)V" << std::endl;
    }

    create1DConnectionOLhep_aida_IProfile1DECVMethod = env->GetMethodID(cls, "create1DConnection", "(Lhep/aida/IProfile1D;)V");
    if (create1DConnectionOLhep_aida_IProfile1DECVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create1DConnection" << "(Lhep/aida/IProfile1D;)V" << std::endl;
    }

    create2DConnectionOLhep_aida_IHistogram2DEIICVMethod = env->GetMethodID(cls, "create2DConnection", "(Lhep/aida/IHistogram2D;II)V");
    if (create2DConnectionOLhep_aida_IHistogram2DEIICVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create2DConnection" << "(Lhep/aida/IHistogram2D;II)V" << std::endl;
    }

    create2DConnectionOLhep_aida_ICloud2DEIICVMethod = env->GetMethodID(cls, "create2DConnection", "(Lhep/aida/ICloud2D;II)V");
    if (create2DConnectionOLhep_aida_ICloud2DEIICVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create2DConnection" << "(Lhep/aida/ICloud2D;II)V" << std::endl;
    }

    create2DConnectionOLhep_aida_IProfile2DECVMethod = env->GetMethodID(cls, "create2DConnection", "(Lhep/aida/IProfile2D;)V");
    if (create2DConnectionOLhep_aida_IProfile2DECVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create2DConnection" << "(Lhep/aida/IProfile2D;)V" << std::endl;
    }

    create1DConnectionOLhep_aida_ICloud1DECVMethod = env->GetMethodID(cls, "create1DConnection", "(Lhep/aida/ICloud1D;)V");
    if (create1DConnectionOLhep_aida_ICloud1DECVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create1DConnection" << "(Lhep/aida/ICloud1D;)V" << std::endl;
    }

    createConnectionOLhep_aida_ITupleEALhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "createConnection", "(Lhep/aida/ITuple;[Lhep/aida/IEvaluator;)V");
    if (createConnectionOLhep_aida_ITupleEALhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "createConnection" << "(Lhep/aida/ITuple;[Lhep/aida/IEvaluator;)V" << std::endl;
    }

    createConnectionOLhep_aida_ITupleEALjava_lang_StringECVMethod = env->GetMethodID(cls, "createConnection", "(Lhep/aida/ITuple;[Ljava/lang/String;)V");
    if (createConnectionOLhep_aida_ITupleEALjava_lang_StringECVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "createConnection" << "(Lhep/aida/ITuple;[Ljava/lang/String;)V" << std::endl;
    }

    resetOCVMethod = env->GetMethodID(cls, "reset", "()V");
    if (resetOCVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "reset" << "()V" << std::endl;
    }

    rangeOICLhep_aida_IRangeSetEMethod = env->GetMethodID(cls, "range", "(I)Lhep/aida/IRangeSet;");
    if (rangeOICLhep_aida_IRangeSetEMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "range" << "(I)Lhep/aida/IRangeSet;" << std::endl;
    }

    create2DConnectionOLhep_aida_IHistogram2DECVMethod = env->GetMethodID(cls, "create2DConnection", "(Lhep/aida/IHistogram2D;)V");
    if (create2DConnectionOLhep_aida_IHistogram2DECVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create2DConnection" << "(Lhep/aida/IHistogram2D;)V" << std::endl;
    }

    dataDescriptionOCLjava_lang_StringEMethod = env->GetMethodID(cls, "dataDescription", "()Ljava/lang/String;");
    if (dataDescriptionOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "dataDescription" << "()Ljava/lang/String;" << std::endl;
    }

    create1DConnectionOLhep_aida_IHistogram1DECVMethod = env->GetMethodID(cls, "create1DConnection", "(Lhep/aida/IHistogram1D;)V");
    if (create1DConnectionOLhep_aida_IHistogram1DECVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create1DConnection" << "(Lhep/aida/IHistogram1D;)V" << std::endl;
    }

    createConnectionOLhep_aida_IDataPointSetEAIICVMethod = env->GetMethodID(cls, "createConnection", "(Lhep/aida/IDataPointSet;[II)V");
    if (createConnectionOLhep_aida_IDataPointSetEAIICVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "createConnection" << "(Lhep/aida/IDataPointSet;[II)V" << std::endl;
    }

    create3DConnectionOLhep_aida_IHistogram3DEIIICVMethod = env->GetMethodID(cls, "create3DConnection", "(Lhep/aida/IHistogram3D;III)V");
    if (create3DConnectionOLhep_aida_IHistogram3DEIIICVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create3DConnection" << "(Lhep/aida/IHistogram3D;III)V" << std::endl;
    }

    create2DConnectionOLhep_aida_ICloud2DECVMethod = env->GetMethodID(cls, "create2DConnection", "(Lhep/aida/ICloud2D;)V");
    if (create2DConnectionOLhep_aida_ICloud2DECVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create2DConnection" << "(Lhep/aida/ICloud2D;)V" << std::endl;
    }

    create1DConnectionOLhep_aida_IDataPointSetEIICVMethod = env->GetMethodID(cls, "create1DConnection", "(Lhep/aida/IDataPointSet;II)V");
    if (create1DConnectionOLhep_aida_IDataPointSetEIICVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create1DConnection" << "(Lhep/aida/IDataPointSet;II)V" << std::endl;
    }

    create3DConnectionOLhep_aida_IDataPointSetEIIIICVMethod = env->GetMethodID(cls, "create3DConnection", "(Lhep/aida/IDataPointSet;IIII)V");
    if (create3DConnectionOLhep_aida_IDataPointSetEIIIICVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create3DConnection" << "(Lhep/aida/IDataPointSet;IIII)V" << std::endl;
    }

    create2DConnectionOLhep_aida_IProfile2DEIICVMethod = env->GetMethodID(cls, "create2DConnection", "(Lhep/aida/IProfile2D;II)V");
    if (create2DConnectionOLhep_aida_IProfile2DEIICVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create2DConnection" << "(Lhep/aida/IProfile2D;II)V" << std::endl;
    }

    create3DConnectionOLhep_aida_IHistogram3DECVMethod = env->GetMethodID(cls, "create3DConnection", "(Lhep/aida/IHistogram3D;)V");
    if (create3DConnectionOLhep_aida_IHistogram3DECVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create3DConnection" << "(Lhep/aida/IHistogram3D;)V" << std::endl;
    }

    create3DConnectionOLhep_aida_ICloud3DEIIICVMethod = env->GetMethodID(cls, "create3DConnection", "(Lhep/aida/ICloud3D;III)V");
    if (create3DConnectionOLhep_aida_ICloud3DEIIICVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create3DConnection" << "(Lhep/aida/ICloud3D;III)V" << std::endl;
    }

    dimensionOCIMethod = env->GetMethodID(cls, "dimension", "()I");
    if (dimensionOCIMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "dimension" << "()I" << std::endl;
    }

    create3DConnectionOLhep_aida_ICloud3DECVMethod = env->GetMethodID(cls, "create3DConnection", "(Lhep/aida/ICloud3D;)V");
    if (create3DConnectionOLhep_aida_ICloud3DECVMethod == NULL) {
        std::cerr << "IFitData" << ": Could not find method: " << "create3DConnection" << "(Lhep/aida/ICloud3D;)V" << std::endl;
    }

}

JNIEXPORT JIFitData::~JIFitData() {
}

JNIEXPORT bool JIFitData::create1DConnection(const IHistogram1D & h) {
    jobject connectTo = factory->create(env, h);
    env->CallVoidMethod(ref, create1DConnectionOLhep_aida_IHistogram1DECVMethod, connectTo);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create1DConnection(const ICloud1D & c) {
    jobject connectTo = factory->create(env, c);
    env->CallVoidMethod(ref, create1DConnectionOLhep_aida_ICloud1DECVMethod, connectTo);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create1DConnection(const IProfile1D & p) {
    jobject connectTo = factory->create(env, p);
    env->CallVoidMethod(ref, create1DConnectionOLhep_aida_IProfile1DECVMethod, connectTo);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create1DConnection(const IDataPointSet & dp, int xIndex, int valIndex) {
    jobject connectTo = factory->create(env, dp);
    env->CallVoidMethod(ref, create1DConnectionOLhep_aida_IDataPointSetEIICVMethod, connectTo, xIndex, valIndex);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create2DConnection(const IHistogram2D & h) {
    jobject connectTo = factory->create(env, h);
    env->CallVoidMethod(ref, create2DConnectionOLhep_aida_IHistogram2DECVMethod, connectTo);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create2DConnection(const IHistogram2D & h, int xIndex, int yIndex) {
    jobject connectTo = factory->create(env, h);
    env->CallVoidMethod(ref, create2DConnectionOLhep_aida_IHistogram2DEIICVMethod, connectTo, xIndex, yIndex);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create2DConnection(const ICloud2D & c) {
    jobject connectTo = factory->create(env, c);
    env->CallVoidMethod(ref, create2DConnectionOLhep_aida_ICloud2DECVMethod, connectTo);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create2DConnection(const ICloud2D & c, int xIndex, int yIndex) {
    jobject connectTo = factory->create(env, c);
    env->CallVoidMethod(ref, create2DConnectionOLhep_aida_ICloud2DEIICVMethod, connectTo, xIndex, yIndex);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create2DConnection(const IProfile2D & p) {
    jobject connectTo = factory->create(env, p);
    env->CallVoidMethod(ref, create2DConnectionOLhep_aida_IProfile2DECVMethod, connectTo);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create2DConnection(const IProfile2D & p, int xIndex, int yIndex) {
    jobject connectTo = factory->create(env, p);
    env->CallVoidMethod(ref, create2DConnectionOLhep_aida_IProfile2DEIICVMethod, connectTo, xIndex, yIndex);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create2DConnection(const IDataPointSet & dp, int xIndex, int yIndex, int valIndex) {
    jobject connectTo = factory->create(env, dp);
    env->CallVoidMethod(ref, create2DConnectionOLhep_aida_IDataPointSetEIIICVMethod, connectTo, xIndex, yIndex, valIndex);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create3DConnection(const IHistogram3D & h) {
    jobject connectTo = factory->create(env, h);
    env->CallVoidMethod(ref, create3DConnectionOLhep_aida_IHistogram3DECVMethod, connectTo);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create3DConnection(const IHistogram3D & h, int xIndex, int yIndex, int zIndex) {
    jobject connectTo = factory->create(env, h);
    env->CallVoidMethod(ref, create3DConnectionOLhep_aida_IHistogram3DEIIICVMethod, connectTo, xIndex, yIndex, zIndex);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create3DConnection(const ICloud3D & c) {
    jobject connectTo = factory->create(env, c);
    env->CallVoidMethod(ref, create3DConnectionOLhep_aida_ICloud3DECVMethod, connectTo);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create3DConnection(const ICloud3D & c, int xIndex, int yIndex, int zIndex) {
    jobject connectTo = factory->create(env, c);
    env->CallVoidMethod(ref, create3DConnectionOLhep_aida_ICloud3DEIIICVMethod, connectTo, xIndex, yIndex, zIndex);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::create3DConnection(const IDataPointSet & dp, int xIndex, int yIndex, int zIndex, int valIndex) {
    jobject connectTo = factory->create(env, dp);
    env->CallVoidMethod(ref, create3DConnectionOLhep_aida_IDataPointSetEIIIICVMethod, connectTo, xIndex, yIndex, zIndex, valIndex);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::createConnection(const ITuple & t, std::vector<std::string>  colNames) {
    jobject connectTo = factory->create(env, t);
    jobjectArray jcolNames;
    NEWSTRINGARRAY(jcolNames, colNames)
    env->CallVoidMethod(ref, createConnectionOLhep_aida_ITupleEALjava_lang_StringECVMethod, connectTo, jcolNames);
    DELSTRINGARRAY(jcolNames)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::createConnection(const ITuple & t, std::vector<IEvaluator *>  & evals) {
    jobject connectTo = factory->create(env, t);
    jclass evaluatorClass = env->FindClass("hep/aida/IEvaluator");
    jobjectArray jevals = (jobjectArray)env->NewObjectArray(evals.size(), evaluatorClass, NULL);
    for (unsigned int index=0; index<evals.size(); index++) {
        jobject jevaluator = factory->create(env, *evals[index]);
        env->SetObjectArrayElement(jevals, index, jevaluator);
    }
    env->CallVoidMethod(ref, createConnectionOLhep_aida_ITupleEALhep_aida_IEvaluatorECVMethod, connectTo, jevals);
    env->DeleteLocalRef(jevals);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFitData::createConnection(const IDataPointSet & dp, std::vector<int> indices, int valIndex) {
    jobject connectTo = factory->create(env, dp);
    jintArray jindices;
    NEWINTARRAY(jindices, indices)
    env->CallVoidMethod(ref, createConnectionOLhep_aida_IDataPointSetEAIICVMethod, connectTo, jindices, valIndex);
    DELINTARRAY(jindices)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT void JIFitData::reset() {
    env->CallVoidMethod(ref, resetOCVMethod);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT int JIFitData::dimension() const {
    jint result = env->CallIntMethod(ref, dimensionOCIMethod);
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT std::string JIFitData::dataDescription() const {
    jstring result = (jstring)env->CallObjectMethod(ref, dataDescriptionOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(result, &isCopy);
    string resultString = utf;
    if (isCopy) env->ReleaseStringUTFChars(result, utf);
    JNIUtil::checkExceptions(env);
    return resultString;
}

// QUESTION should we make IRangeSet implement a copy constructor and return no ref here?
JNIEXPORT IRangeSet & JIFitData::range(int index) const {
    jobject obj = env->CallObjectMethod(ref, rangeOICLhep_aida_IRangeSetEMethod, index);
    JNIUtil::checkExceptions(env);
    IRangeSet* rangeSet = factory->createIRangeSet(env, obj);
    rangeSetMap[index] = rangeSet;
    return *rangeSet;
}
