
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AIDA/ICloud1D.h"
#include "AIDA/ICloud2D.h"
#include "AIDA/ICloud3D.h"
#include "AIDA/IDataPointSet.h"
#include "AIDA/IHistogram1D.h"
#include "AIDA/IHistogram2D.h"
#include "AIDA/IHistogram3D.h"
#include "AIDA/IProfile1D.h"
#include "AIDA/IProfile2D.h"
#include "JIDataPointSetFactory.h"
#include "JIDataPointSet.h"
#include "JIHistogram1D.h"
#include "JIHistogram2D.h"
#include "JIHistogram3D.h"
#include "JICloud1D.h"
#include "JICloud2D.h"
#include "JICloud3D.h"
#include "JIProfile1D.h"
#include "JIProfile2D.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JIDataPointSetFactory::JIDataPointSetFactory(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    createOLjava_lang_StringELhep_aida_IHistogram3DELjava_lang_StringECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;Lhep/aida/IHistogram3D;Ljava/lang/String;)Lhep/aida/IDataPointSet;");
    if (createOLjava_lang_StringELhep_aida_IHistogram3DELjava_lang_StringECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;Lhep/aida/IHistogram3D;Ljava/lang/String;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    createOLjava_lang_StringELhep_aida_IHistogram2DELjava_lang_StringECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;Lhep/aida/IHistogram2D;Ljava/lang/String;)Lhep/aida/IDataPointSet;");
    if (createOLjava_lang_StringELhep_aida_IHistogram2DELjava_lang_StringECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;Lhep/aida/IHistogram2D;Ljava/lang/String;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    createOLjava_lang_StringELhep_aida_ICloud2DELjava_lang_StringECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;Lhep/aida/ICloud2D;Ljava/lang/String;)Lhep/aida/IDataPointSet;");
    if (createOLjava_lang_StringELhep_aida_ICloud2DELjava_lang_StringECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;Lhep/aida/ICloud2D;Ljava/lang/String;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    createOLjava_lang_StringEICLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;I)Lhep/aida/IDataPointSet;");
    if (createOLjava_lang_StringEICLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;I)Lhep/aida/IDataPointSet;" << std::endl;
    }

    createOLjava_lang_StringELhep_aida_IProfile2DELjava_lang_StringECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;Lhep/aida/IProfile2D;Ljava/lang/String;)Lhep/aida/IDataPointSet;");
    if (createOLjava_lang_StringELhep_aida_IProfile2DELjava_lang_StringECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;Lhep/aida/IProfile2D;Ljava/lang/String;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    createCopyOLjava_lang_StringELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createCopy", "(Ljava/lang/String;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;");
    if (createCopyOLjava_lang_StringELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createCopy" << "(Ljava/lang/String;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    createOLjava_lang_StringELhep_aida_ICloud1DELjava_lang_StringECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;Lhep/aida/ICloud1D;Ljava/lang/String;)Lhep/aida/IDataPointSet;");
    if (createOLjava_lang_StringELhep_aida_ICloud1DELjava_lang_StringECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;Lhep/aida/ICloud1D;Ljava/lang/String;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    createOLjava_lang_StringELjava_lang_StringEICLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;Ljava/lang/String;I)Lhep/aida/IDataPointSet;");
    if (createOLjava_lang_StringELjava_lang_StringEICLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;Ljava/lang/String;I)Lhep/aida/IDataPointSet;" << std::endl;
    }

    divideOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "divide", "(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;");
    if (divideOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "divide" << "(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    createOLjava_lang_StringELhep_aida_IHistogram1DELjava_lang_StringECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;Lhep/aida/IHistogram1D;Ljava/lang/String;)Lhep/aida/IDataPointSet;");
    if (createOLjava_lang_StringELhep_aida_IHistogram1DELjava_lang_StringECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;Lhep/aida/IHistogram1D;Ljava/lang/String;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    createOLjava_lang_StringELhep_aida_IProfile1DELjava_lang_StringECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;Lhep/aida/IProfile1D;Ljava/lang/String;)Lhep/aida/IDataPointSet;");
    if (createOLjava_lang_StringELhep_aida_IProfile1DELjava_lang_StringECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;Lhep/aida/IProfile1D;Ljava/lang/String;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    createOLjava_lang_StringELhep_aida_ICloud3DELjava_lang_StringECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;Lhep/aida/ICloud3D;Ljava/lang/String;)Lhep/aida/IDataPointSet;");
    if (createOLjava_lang_StringELhep_aida_ICloud3DELjava_lang_StringECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;Lhep/aida/ICloud3D;Ljava/lang/String;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    subtractOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "subtract", "(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;");
    if (subtractOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "subtract" << "(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    addOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "add", "(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;");
    if (addOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "add" << "(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    weightedMeanOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "weightedMean", "(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;");
    if (weightedMeanOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "weightedMean" << "(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    multiplyOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "multiply", "(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;");
    if (multiplyOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "multiply" << "(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;" << std::endl;
    }

    destroyOLhep_aida_IDataPointSetECVMethod = env->GetMethodID(cls, "destroy", "(Lhep/aida/IDataPointSet;)V");
    if (destroyOLhep_aida_IDataPointSetECVMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "destroy" << "(Lhep/aida/IDataPointSet;)V" << std::endl;
    }

    createYOLjava_lang_StringELjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createY", "(Ljava/lang/String;Ljava/lang/String;[D[D)Lhep/aida/IDataPointSet;");
    if (createYOLjava_lang_StringELjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createY" << "(Ljava/lang/String;Ljava/lang/String;[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }
        
    createYOLjava_lang_StringELjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createY", "(Ljava/lang/String;Ljava/lang/String;[D[D[D)Lhep/aida/IDataPointSet;");
    if (createYOLjava_lang_StringELjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createY" << "(Ljava/lang/String;Ljava/lang/String;[D[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }
        
    createYOLjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createY", "(Ljava/lang/String;[D[D)Lhep/aida/IDataPointSet;");
    if (createYOLjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createY" << "(Ljava/lang/String;[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }
        
    createYOLjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createY", "(Ljava/lang/String;[D[D[D)Lhep/aida/IDataPointSet;");
    if (createYOLjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createY" << "(Ljava/lang/String;[D[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }

    createXOLjava_lang_StringELjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createY", "(Ljava/lang/String;Ljava/lang/String;[D[D)Lhep/aida/IDataPointSet;");
    if (createXOLjava_lang_StringELjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createX" << "(Ljava/lang/String;Ljava/lang/String;[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }
        
    createXOLjava_lang_StringELjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createY", "(Ljava/lang/String;Ljava/lang/String;[D[D[D)Lhep/aida/IDataPointSet;");
    if (createXOLjava_lang_StringELjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createX" << "(Ljava/lang/String;Ljava/lang/String;[D[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }
        
    createXOLjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createY", "(Ljava/lang/String;[D[D)Lhep/aida/IDataPointSet;");
    if (createXOLjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createX" << "(Ljava/lang/String;[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }
        
    createXOLjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createY", "(Ljava/lang/String;[D[D[D)Lhep/aida/IDataPointSet;");
    if (createXOLjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createX" << "(Ljava/lang/String;[D[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }


    createXYOLjava_lang_StringELjava_lang_StringEADADADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createXY", "(Ljava/lang/String;Ljava/lang/String;[D[D[D[D)Lhep/aida/IDataPointSet;");
    if (createXYOLjava_lang_StringELjava_lang_StringEADADADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createXY" << "(Ljava/lang/String;Ljava/lang/String;[D[D[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }
        
    createXYOLjava_lang_StringELjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createXY", "(Ljava/lang/String;Ljava/lang/String;[D[D[D[D[D[D)Lhep/aida/IDataPointSet;");
    if (createXYOLjava_lang_StringELjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createXY" << "(Ljava/lang/String;Ljava/lang/String;[D[D[D[D[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }
        
    createXYOLjava_lang_StringEADADADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createXY", "(Ljava/lang/String;[D[D[D[D)Lhep/aida/IDataPointSet;");
    if (createXYOLjava_lang_StringEADADADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createXY" << "(Ljava/lang/String;[D[D[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }
        
    createXYOLjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createXY", "(Ljava/lang/String;[D[D[D[D[D[D)Lhep/aida/IDataPointSet;");
    if (createXYOLjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createXY" << "(Ljava/lang/String;[D[D[D[D[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }


    createXYZOLjava_lang_StringELjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createXYZ", "(Ljava/lang/String;Ljava/lang/String;[D[D[D[D[D[D)Lhep/aida/IDataPointSet;");
    if (createXYZOLjava_lang_StringELjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createXYZ" << "(Ljava/lang/String;Ljava/lang/String;[D[D[D[D[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }
        
    createXYZOLjava_lang_StringELjava_lang_StringEADADADADADADADADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createXYZ", "(Ljava/lang/String;Ljava/lang/String;[D[D[D[D[D[D[D[D[D)Lhep/aida/IDataPointSet;");
    if (createXYZOLjava_lang_StringELjava_lang_StringEADADADADADADADADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createXYZ" << "(Ljava/lang/String;Ljava/lang/String;[D[D[D[D[D[D[D[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }
        
    createXYZOLjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createXYZ", "(Ljava/lang/String;[D[D[D[D[D[D)Lhep/aida/IDataPointSet;");
    if (createXYZOLjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createXYZ" << "(Ljava/lang/String;[D[D[D[D[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }
        
    createXYZOLjava_lang_StringEADADADADADADADADADCLhep_aida_IDataPointSetEMethod = env->GetMethodID(cls, "createXYZ", "(Ljava/lang/String;[D[D[D[D[D[D[D[D[D)Lhep/aida/IDataPointSet;");
    if (createXYZOLjava_lang_StringEADADADADADADADADADCLhep_aida_IDataPointSetEMethod == NULL) {
        std::cerr << "IDataPointSetFactory" << ": Could not find method: " << "createXYZ" << "(Ljava/lang/String;[D[D[D[D[D[D[D[D[D)Lhep/aida/IDataPointSet;" << std::endl;
    }
}

JNIEXPORT JIDataPointSetFactory::~JIDataPointSetFactory() {
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::create(const std::string & name, const std::string & title, int dimOfPoints) {
   jstring jname;
   NEWSTRING(jname, name)
   jstring jtitle;
   NEWSTRING(jtitle, title)
   jobject obj = env->CallObjectMethod(ref, createOLjava_lang_StringELjava_lang_StringEICLhep_aida_IDataPointSetEMethod, jname, jtitle, dimOfPoints);
   DELSTRING(jname);
   DELSTRING(jtitle);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::create(const std::string & nameAndTitle, int dimOfPoints) {
   jstring jname;
   NEWSTRING(jname, nameAndTitle)
   jobject obj = env->CallObjectMethod(ref, createOLjava_lang_StringEICLhep_aida_IDataPointSetEMethod, jname, dimOfPoints);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createY(const std::string & path, const std::string & title, const std::vector<double>  & y, const std::vector<double>  & ey) {
    jstring jpath, jtitle;
    jdoubleArray jy, jey;
    NEWSTRING(jpath, path)
    NEWSTRING(jtitle, title)
    NEWDOUBLEARRAY(jy, y)
    NEWDOUBLEARRAY(jey, ey)
    jobject obj = env->CallObjectMethod(ref, createYOLjava_lang_StringELjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod, jpath, jtitle, jy, jey);
    DELSTRING(jpath)
    DELSTRING(jtitle)
    DELDOUBLEARRAY(jy)
    DELDOUBLEARRAY(jey)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createY(const std::string & path, const std::string & title, const std::vector<double>  & y, const std::vector<double>  & eyp, const std::vector<double>  & eym) {
    jstring jpath, jtitle;
    jdoubleArray jy, jeyp, jeym;
    NEWSTRING(jpath, path)
    NEWSTRING(jtitle, title)
    NEWDOUBLEARRAY(jy, y)
    NEWDOUBLEARRAY(jeyp, eyp)
    NEWDOUBLEARRAY(jeym, eym)
    jobject obj = env->CallObjectMethod(ref, createYOLjava_lang_StringELjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod, jpath, jtitle, jy, jeyp, jeym);
    DELSTRING(jpath)
    DELSTRING(jtitle)
    DELDOUBLEARRAY(jy)
    DELDOUBLEARRAY(jeyp)
    DELDOUBLEARRAY(jeym)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createY(const std::string & pathAndTitle, const std::vector<double>  & y, const std::vector<double>  & ey) {
    jstring jpathAndTitle;
    jdoubleArray jy, jey;
    NEWSTRING(jpathAndTitle, pathAndTitle)
    NEWDOUBLEARRAY(jy, y)
    NEWDOUBLEARRAY(jey, ey)
    jobject obj = env->CallObjectMethod(ref, createYOLjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod, jpathAndTitle, jy, jey);
    DELSTRING(jpathAndTitle)
    DELDOUBLEARRAY(jy)
    DELDOUBLEARRAY(jey)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createY(const std::string & pathAndTitle, const std::vector<double>  & y, const std::vector<double>  & eyp, const std::vector<double>  & eym) {
    jstring jpathAndTitle;
    jdoubleArray jy, jeyp, jeym;
    NEWSTRING(jpathAndTitle, pathAndTitle)
    NEWDOUBLEARRAY(jy, y)
    NEWDOUBLEARRAY(jeyp, eyp)
    NEWDOUBLEARRAY(jeym, eym)
    jobject obj = env->CallObjectMethod(ref, createYOLjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod, jpathAndTitle, jy, jeyp, jeym);
    DELSTRING(jpathAndTitle)
    DELDOUBLEARRAY(jy)
    DELDOUBLEARRAY(jeyp)
    DELDOUBLEARRAY(jeym)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createX(const std::string & path, const std::string & title, const std::vector<double>  & x, const std::vector<double>  & ex) {
    jstring jpath, jtitle;
    jdoubleArray jx, jex;
    NEWSTRING(jpath, path)
    NEWSTRING(jtitle, title)
    NEWDOUBLEARRAY(jx, x)
    NEWDOUBLEARRAY(jex, ex)
    jobject obj = env->CallObjectMethod(ref, createXOLjava_lang_StringELjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod, jpath, jtitle, jx, jex);
    DELSTRING(jpath)
    DELSTRING(jtitle)
    DELDOUBLEARRAY(jx)
    DELDOUBLEARRAY(jex)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createX(const std::string & path, const std::string & title, const std::vector<double>  & x, const std::vector<double>  & exp, const std::vector<double>  & exm) {
    jstring jpath, jtitle;
    jdoubleArray jx, jexp, jexm;
    NEWSTRING(jpath, path)
    NEWSTRING(jtitle, title)
    NEWDOUBLEARRAY(jx, x)
    NEWDOUBLEARRAY(jexp, exp)
    NEWDOUBLEARRAY(jexm, exm)
    jobject obj = env->CallObjectMethod(ref, createXOLjava_lang_StringELjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod, jpath, jtitle, jx, jexp, jexm);
    DELSTRING(jpath)
    DELSTRING(jtitle)
    DELDOUBLEARRAY(jx)
    DELDOUBLEARRAY(jexp)
    DELDOUBLEARRAY(jexm)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createX(const std::string & pathAndTitle, const std::vector<double>  & x, const std::vector<double>  & ex) {
    jstring jpathAndTitle;
    jdoubleArray jx, jex;
    NEWSTRING(jpathAndTitle, pathAndTitle)
    NEWDOUBLEARRAY(jx, x)
    NEWDOUBLEARRAY(jex, ex)
    jobject obj = env->CallObjectMethod(ref, createXOLjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod, jpathAndTitle, jx, jex);
    DELSTRING(jpathAndTitle)
    DELDOUBLEARRAY(jx)
    DELDOUBLEARRAY(jex)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createX(const std::string & pathAndTitle, const std::vector<double>  & x, const std::vector<double>  & exp, const std::vector<double>  & exm) {
    jstring jpathAndTitle;
    jdoubleArray jx, jexp, jexm;
    NEWSTRING(jpathAndTitle, pathAndTitle)
    NEWDOUBLEARRAY(jx, x)
    NEWDOUBLEARRAY(jexp, exp)
    NEWDOUBLEARRAY(jexm, exm)
    jobject obj = env->CallObjectMethod(ref, createXOLjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod, jpathAndTitle, jx, jexp, jexm);
    DELSTRING(jpathAndTitle)
    DELDOUBLEARRAY(jx)
    DELDOUBLEARRAY(jexp)
    DELDOUBLEARRAY(jexm)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}



JNIEXPORT IDataPointSet * JIDataPointSetFactory::createXY(const std::string & path, const std::string & title, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & ex, const std::vector<double>  & ey) {
    jstring jpath, jtitle;
    jdoubleArray jx, jy, jex, jey;
    NEWSTRING(jpath, path)
    NEWSTRING(jtitle, title)
    NEWDOUBLEARRAY(jx, x)
    NEWDOUBLEARRAY(jy, y)
    NEWDOUBLEARRAY(jex, ex)
    NEWDOUBLEARRAY(jey, ey)
    jobject obj = env->CallObjectMethod(ref, createXYOLjava_lang_StringELjava_lang_StringEADADADADCLhep_aida_IDataPointSetEMethod, jpath, jtitle, jx, jy, jex, jey);
    DELSTRING(jpath)
    DELSTRING(jtitle)
    DELDOUBLEARRAY(jx)
    DELDOUBLEARRAY(jy)
    DELDOUBLEARRAY(jex)
    DELDOUBLEARRAY(jey)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createXY(const std::string & path, const std::string & title, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & exp, const std::vector<double>  & eyp, const std::vector<double>  & exm, const std::vector<double>  & eym) {
    jstring jpath, jtitle;
    jdoubleArray jx, jy, jexp, jeyp, jexm, jeym;
    NEWSTRING(jpath, path)
    NEWSTRING(jtitle, title)
    NEWDOUBLEARRAY(jx, x)
    NEWDOUBLEARRAY(jy, y)
    NEWDOUBLEARRAY(jexp, exp)
    NEWDOUBLEARRAY(jeyp, eyp)
    NEWDOUBLEARRAY(jexm, exm)
    NEWDOUBLEARRAY(jeym, eym)
    jobject obj = env->CallObjectMethod(ref, createXYOLjava_lang_StringELjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod, jpath, jtitle, jx, jy, jexp, jeyp, jexm, jeym);
    DELSTRING(jpath)
    DELSTRING(jtitle)
    DELDOUBLEARRAY(jx)
    DELDOUBLEARRAY(jy)
    DELDOUBLEARRAY(jexp)
    DELDOUBLEARRAY(jeyp)
    DELDOUBLEARRAY(jexm)
    DELDOUBLEARRAY(jeym)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createXY(const std::string & pathAndTitle, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & ex, const std::vector<double>  & ey) {
    jstring jpathAndTitle;
    jdoubleArray jx, jy, jex, jey;
    NEWSTRING(jpathAndTitle, pathAndTitle)
    NEWDOUBLEARRAY(jx, x)
    NEWDOUBLEARRAY(jy, y)
    NEWDOUBLEARRAY(jex, ex)
    NEWDOUBLEARRAY(jey, ey)
    jobject obj = env->CallObjectMethod(ref, createXYOLjava_lang_StringEADADADADCLhep_aida_IDataPointSetEMethod, jpathAndTitle, jx, jy, jex, jey);
    DELSTRING(jpathAndTitle)
    DELDOUBLEARRAY(jx)
    DELDOUBLEARRAY(jy)
    DELDOUBLEARRAY(jex)
    DELDOUBLEARRAY(jey)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createXY(const std::string & pathAndTitle, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & exp, const std::vector<double>  & eyp, const std::vector<double>  & exm, const std::vector<double>  & eym) {
    jstring jpathAndTitle;
    jdoubleArray jx, jy, jexp, jeyp, jexm, jeym;
    NEWSTRING(jpathAndTitle, pathAndTitle)
    NEWDOUBLEARRAY(jx, x)
    NEWDOUBLEARRAY(jy, y)
    NEWDOUBLEARRAY(jexp, exp)
    NEWDOUBLEARRAY(jeyp, eyp)
    NEWDOUBLEARRAY(jexm, exm)
    NEWDOUBLEARRAY(jeym, eym)
    jobject obj = env->CallObjectMethod(ref, createXYOLjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod, jpathAndTitle, jx, jy, jexp, jeyp, jexm, jeym);
    DELSTRING(jpathAndTitle)
    DELDOUBLEARRAY(jx)
    DELDOUBLEARRAY(jy)
    DELDOUBLEARRAY(jexp)
    DELDOUBLEARRAY(jeyp)
    DELDOUBLEARRAY(jexm)
    DELDOUBLEARRAY(jeym)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createXYZ(const std::string & path, const std::string & title, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & z, const std::vector<double>  & ex, const std::vector<double>  & ey, const std::vector<double>  & ez) {
    jstring jpath, jtitle;
    jdoubleArray jx, jy, jz, jex, jey, jez;
    NEWSTRING(jpath, path)
    NEWSTRING(jtitle, title)
    NEWDOUBLEARRAY(jx, x)
    NEWDOUBLEARRAY(jy, y)
    NEWDOUBLEARRAY(jz, z)
    NEWDOUBLEARRAY(jex, ex)
    NEWDOUBLEARRAY(jey, ey)
    NEWDOUBLEARRAY(jez, ez)
    jobject obj = env->CallObjectMethod(ref, createXYZOLjava_lang_StringELjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod, jpath, jtitle, jx, jy, jz, jex, jey, jey, jez);
    DELSTRING(jpath)
    DELSTRING(jtitle)
    DELDOUBLEARRAY(jx)
    DELDOUBLEARRAY(jy)
    DELDOUBLEARRAY(jz)
    DELDOUBLEARRAY(jex)
    DELDOUBLEARRAY(jey)
    DELDOUBLEARRAY(jez)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createXYZ(const std::string & path, const std::string & title, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & z, const std::vector<double>  & exp, const std::vector<double>  & eyp, const std::vector<double>  & ezp, const std::vector<double>  & exm, const std::vector<double>  & eym, const std::vector<double>  & ezm) {
    jstring jpath, jtitle;
    jdoubleArray jx, jy, jz, jexp, jeyp, jezp, jexm, jeym, jezm;
    NEWSTRING(jpath, path)
    NEWSTRING(jtitle, title)
    NEWDOUBLEARRAY(jx, x)
    NEWDOUBLEARRAY(jy, y)
    NEWDOUBLEARRAY(jz, z)
    NEWDOUBLEARRAY(jexp, exp)
    NEWDOUBLEARRAY(jeyp, eyp)
    NEWDOUBLEARRAY(jezp, ezp)
    NEWDOUBLEARRAY(jexm, exm)
    NEWDOUBLEARRAY(jeym, eym)
    NEWDOUBLEARRAY(jezm, ezm)
    jobject obj = env->CallObjectMethod(ref, createXYZOLjava_lang_StringELjava_lang_StringEADADADADADADADADADCLhep_aida_IDataPointSetEMethod, jpath, jtitle, jx, jy, jz, jexp, jeyp, jezp, jexm, jeym, jezm);
    DELSTRING(jpath)
    DELSTRING(jtitle)
    DELDOUBLEARRAY(jx)
    DELDOUBLEARRAY(jy)
    DELDOUBLEARRAY(jz)
    DELDOUBLEARRAY(jexp)
    DELDOUBLEARRAY(jeyp)
    DELDOUBLEARRAY(jezp)
    DELDOUBLEARRAY(jexm)
    DELDOUBLEARRAY(jeym)
    DELDOUBLEARRAY(jezm)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createXYZ(const std::string & pathAndTitle, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & z, const std::vector<double>  & ex, const std::vector<double>  & ey, const std::vector<double>  & ez) {
    jstring jpathAndTitle;
    jdoubleArray jx, jy, jz, jex, jey, jez;
    NEWSTRING(jpathAndTitle, pathAndTitle)
    NEWDOUBLEARRAY(jx, x)
    NEWDOUBLEARRAY(jy, y)
    NEWDOUBLEARRAY(jz, z)
    NEWDOUBLEARRAY(jex, ex)
    NEWDOUBLEARRAY(jey, ey)
    NEWDOUBLEARRAY(jez, ez)
    jobject obj = env->CallObjectMethod(ref, createXYZOLjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod, jpathAndTitle, jx, jy, jz, jex, jey, jez);
    DELSTRING(jpathAndTitle)
    DELDOUBLEARRAY(jx)
    DELDOUBLEARRAY(jy)
    DELDOUBLEARRAY(jz)
    DELDOUBLEARRAY(jex)
    DELDOUBLEARRAY(jey)
    DELDOUBLEARRAY(jez)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createXYZ(const std::string & pathAndTitle, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & z, const std::vector<double>  & exp, const std::vector<double>  & eyp, const std::vector<double>  & ezp, const std::vector<double>  & exm, const std::vector<double>  & eym, const std::vector<double>  & ezm) {
    jstring jpathAndTitle;
    jdoubleArray jx, jy, jz, jexp, jeyp, jezp, jexm, jeym, jezm;
    NEWSTRING(jpathAndTitle, pathAndTitle)
    NEWDOUBLEARRAY(jx, x)
    NEWDOUBLEARRAY(jy, y)
    NEWDOUBLEARRAY(jz, z)
    NEWDOUBLEARRAY(jexp, exp)
    NEWDOUBLEARRAY(jeyp, eyp)
    NEWDOUBLEARRAY(jezp, ezp)
    NEWDOUBLEARRAY(jexm, exm)
    NEWDOUBLEARRAY(jeym, eym)
    NEWDOUBLEARRAY(jezm, ezm)
    jobject obj = env->CallObjectMethod(ref, createXYZOLjava_lang_StringEADADADADADADADADADCLhep_aida_IDataPointSetEMethod, jpathAndTitle, jx, jy, jz, jexp, jeyp, jezp, jexm, jeym, jezm);
    DELSTRING(jpathAndTitle)
    DELDOUBLEARRAY(jx)
    DELDOUBLEARRAY(jy)
    DELDOUBLEARRAY(jz)
    DELDOUBLEARRAY(jexp)
    DELDOUBLEARRAY(jeyp)
    DELDOUBLEARRAY(jezp)
    DELDOUBLEARRAY(jexm)
    DELDOUBLEARRAY(jeym)
    DELDOUBLEARRAY(jezm)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::createCopy(const std::string & name, const IDataPointSet & dataPointSet) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jdataPointSet = factory->create(env, dataPointSet);
   jobject obj = env->CallObjectMethod(ref, createCopyOLjava_lang_StringELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod, jname, jdataPointSet);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT bool JIDataPointSetFactory::destroy(IDataPointSet * dataPointSet) {
   jobject jdataPointSet = factory->create(env, *dataPointSet);
   env->CallObjectMethod(ref, destroyOLhep_aida_IDataPointSetECVMethod, jdataPointSet);
   delete(jdataPointSet);
   if (JNIUtil::exceptions(env)) return false;
   else return true;
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::create(const std::string & name, const IHistogram1D & hist, const std::string & options) {
   jstring jname, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(joptions, options)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, createOLjava_lang_StringELhep_aida_IHistogram1DELjava_lang_StringECLhep_aida_IDataPointSetEMethod, jname, jhist, joptions);
   DELSTRING(jname);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::create(const std::string & name, const IHistogram2D & hist, const std::string & options) {
   jstring jname, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(joptions, options)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, createOLjava_lang_StringELhep_aida_IHistogram2DELjava_lang_StringECLhep_aida_IDataPointSetEMethod, jname, jhist, joptions);
   DELSTRING(jname);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::create(const std::string & name, const IHistogram3D & hist, const std::string & options) {
   jstring jname, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(joptions, options)
   jobject jhist = factory->create(env, hist);
   jobject obj = env->CallObjectMethod(ref, createOLjava_lang_StringELhep_aida_IHistogram3DELjava_lang_StringECLhep_aida_IDataPointSetEMethod, jname, jhist, joptions);
   DELSTRING(jname);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::create(const std::string & name, const ICloud1D & cloud, const std::string & options) {
   jstring jname, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(joptions, options)
   jobject jcloud = factory->create(env, cloud);
   jobject obj = env->CallObjectMethod(ref, createOLjava_lang_StringELhep_aida_ICloud1DELjava_lang_StringECLhep_aida_IDataPointSetEMethod, jname, jcloud, joptions);
   DELSTRING(jname);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::create(const std::string & name, const ICloud2D & cloud, const std::string & options) {
   jstring jname, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(joptions, options)
   jobject jcloud = factory->create(env, cloud);
   jobject obj = env->CallObjectMethod(ref, createOLjava_lang_StringELhep_aida_ICloud2DELjava_lang_StringECLhep_aida_IDataPointSetEMethod, jname, jcloud, joptions);
   DELSTRING(jname);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::create(const std::string & name, const ICloud3D & cloud, const std::string & options) {
   jstring jname, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(joptions, options)
   jobject jcloud = factory->create(env, cloud);
   jobject obj = env->CallObjectMethod(ref, createOLjava_lang_StringELhep_aida_ICloud3DELjava_lang_StringECLhep_aida_IDataPointSetEMethod, jname, jcloud, joptions);
   DELSTRING(jname);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::create(const std::string & name, const IProfile1D & profile, const std::string & options) {
   jstring jname, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(joptions, options)
   jobject jprofile = factory->create(env, profile);
   jobject obj = env->CallObjectMethod(ref, createOLjava_lang_StringELhep_aida_IProfile1DELjava_lang_StringECLhep_aida_IDataPointSetEMethod, jname, jprofile, joptions);
   DELSTRING(jname);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::create(const std::string & name, const IProfile2D & profile, const std::string & options) {
   jstring jname, joptions;
   NEWSTRING(jname, name)
   NEWSTRING(joptions, options)
   jobject jprofile = factory->create(env, profile);
   jobject obj = env->CallObjectMethod(ref, createOLjava_lang_StringELhep_aida_IProfile2DELjava_lang_StringECLhep_aida_IDataPointSetEMethod, jname, jprofile, joptions);
   DELSTRING(jname);
   DELSTRING(joptions);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::add(const std::string & name, const IDataPointSet & dataPointSet1, const IDataPointSet & dataPointSet2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jdataPointSet1 = factory->create(env, dataPointSet1);
   jobject jdataPointSet2 = factory->create(env, dataPointSet2);
   jobject obj = env->CallObjectMethod(ref, addOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod, jname, jdataPointSet1, jdataPointSet2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::subtract(const std::string & name, const IDataPointSet & dataPointSet1, const IDataPointSet & dataPointSet2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jdataPointSet1 = factory->create(env, dataPointSet1);
   jobject jdataPointSet2 = factory->create(env, dataPointSet2);
   jobject obj = env->CallObjectMethod(ref, subtractOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod, jname, jdataPointSet1, jdataPointSet2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::multiply(const std::string & name, const IDataPointSet & dataPointSet1, const IDataPointSet & dataPointSet2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jdataPointSet1 = factory->create(env, dataPointSet1);
   jobject jdataPointSet2 = factory->create(env, dataPointSet2);
   jobject obj = env->CallObjectMethod(ref, multiplyOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod, jname, jdataPointSet1, jdataPointSet2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::divide(const std::string & name, const IDataPointSet & dataPointSet1, const IDataPointSet & dataPointSet2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jdataPointSet1 = factory->create(env, dataPointSet1);
   jobject jdataPointSet2 = factory->create(env, dataPointSet2);
   jobject obj = env->CallObjectMethod(ref, divideOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod, jname, jdataPointSet1, jdataPointSet2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}

JNIEXPORT IDataPointSet * JIDataPointSetFactory::weightedMean(const std::string & name, const IDataPointSet & dataPointSet1, const IDataPointSet & dataPointSet2) {
   jstring jname;
   NEWSTRING(jname, name)
   jobject jdataPointSet1 = factory->create(env, dataPointSet1);
   jobject jdataPointSet2 = factory->create(env, dataPointSet2);
   jobject obj = env->CallObjectMethod(ref, weightedMeanOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod, jname, jdataPointSet1, jdataPointSet2);
   DELSTRING(jname);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIDataPointSet(env, obj);
}
