
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "AIDA/IDataPointSetFactory.h"
#include "AIDA/IFitFactory.h"
#include "AIDA/IFunctionFactory.h"
#include "AIDA/IHistogramFactory.h"
#include "AIDA/IPlotterFactory.h"
#include "AIDA/ITree.h"
#include "AIDA/ITreeFactory.h"
#include "AIDA/ITupleFactory.h"
#include "JIAnalysisFactory.h"
#include "JITreeFactory.h"
#include "JIHistogramFactory.h"
#include "JIDataPointSetFactory.h"
#include "JIFunctionFactory.h"
#include "JIFitFactory.h"
#include "JITupleFactory.h"
#include "JIPlotterFactory.h"
#include "JITree.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;

JNIEXPORT JIAnalysisFactory::JIAnalysisFactory() {

    // allocate JVM, since it GetCreatedJVMs seems to fail if not. Fixed AIDAJNI-52 
    jvm = (JavaVM *)malloc(sizeof(JavaVM));

    // Start JVM
    int rc = JNIUtil::createJVM(&env, &jvm);
    if (rc < 0) {
        error((char*)"JIAnalysisFactory: Failed to create Java VM");
    }
    if (rc == 1) {
        error((char*)"JIAnalysisFactory: CLASSPATH or JVM_CLASSPATH not set");
    }

    // Get the java Analysis factory
    jclass cls;
    GETCLASS("IAnalysisFactory", cls, "hep/aida/IAnalysisFactory")
    if (cls == NULL) {
        error((char*)"JIAnalysisFactory: Could not find class hep.aida.IAnalysisFactory");
    }

    jmethodID factoryMethod;
    GETSTATICMETHOD("IAnalysisFactory", factoryMethod, "create", "()Lhep/aida/IAnalysisFactory;")
    if (factoryMethod == NULL) {
        error((char*)"JIAnalysisFactory: Could not find method create() in hep.aida.IAnalysisFactory");
    }

    ref = env->CallStaticObjectMethod(cls, factoryMethod);
    if (ref == NULL) {
        error((char*)"JIAnalysisFactory: Could not create AnalysisFactory");
    }

    createDataPointSetFactoryOLhep_aida_ITreeECLhep_aida_IDataPointSetFactoryEMethod = env->GetMethodID(cls, "createDataPointSetFactory", "(Lhep/aida/ITree;)Lhep/aida/IDataPointSetFactory;");
    if (createDataPointSetFactoryOLhep_aida_ITreeECLhep_aida_IDataPointSetFactoryEMethod == NULL) {
        std::cerr << "IAnalysisFactory" << ": Could not find method: " << "createDataPointSetFactory" << "(Lhep/aida/ITree;)Lhep/aida/IDataPointSetFactory;" << std::endl;
    }

    createFunctionFactoryOLhep_aida_ITreeECLhep_aida_IFunctionFactoryEMethod = env->GetMethodID(cls, "createFunctionFactory", "(Lhep/aida/ITree;)Lhep/aida/IFunctionFactory;");
    if (createFunctionFactoryOLhep_aida_ITreeECLhep_aida_IFunctionFactoryEMethod == NULL) {
        std::cerr << "IAnalysisFactory" << ": Could not find method: " << "createFunctionFactory" << "(Lhep/aida/ITree;)Lhep/aida/IFunctionFactory;" << std::endl;
    }

    createHistogramFactoryOLhep_aida_ITreeECLhep_aida_IHistogramFactoryEMethod = env->GetMethodID(cls, "createHistogramFactory", "(Lhep/aida/ITree;)Lhep/aida/IHistogramFactory;");
    if (createHistogramFactoryOLhep_aida_ITreeECLhep_aida_IHistogramFactoryEMethod == NULL) {
        std::cerr << "IAnalysisFactory" << ": Could not find method: " << "createHistogramFactory" << "(Lhep/aida/ITree;)Lhep/aida/IHistogramFactory;" << std::endl;
    }

    createPlotterFactoryOCLhep_aida_IPlotterFactoryEMethod = env->GetMethodID(cls, "createPlotterFactory", "()Lhep/aida/IPlotterFactory;");
    if (createPlotterFactoryOCLhep_aida_IPlotterFactoryEMethod == NULL) {
        std::cerr << "IAnalysisFactory" << ": Could not find method: " << "createPlotterFactory" << "()Lhep/aida/IPlotterFactory;" << std::endl;
    }

    createFitFactoryOCLhep_aida_IFitFactoryEMethod = env->GetMethodID(cls, "createFitFactory", "()Lhep/aida/IFitFactory;");
    if (createFitFactoryOCLhep_aida_IFitFactoryEMethod == NULL) {
        std::cerr << "IAnalysisFactory" << ": Could not find method: " << "createFitFactory" << "()Lhep/aida/IFitFactory;" << std::endl;
    }

    createTupleFactoryOLhep_aida_ITreeECLhep_aida_ITupleFactoryEMethod = env->GetMethodID(cls, "createTupleFactory", "(Lhep/aida/ITree;)Lhep/aida/ITupleFactory;");
    if (createTupleFactoryOLhep_aida_ITreeECLhep_aida_ITupleFactoryEMethod == NULL) {
        std::cerr << "IAnalysisFactory" << ": Could not find method: " << "createTupleFactory" << "(Lhep/aida/ITree;)Lhep/aida/ITupleFactory;" << std::endl;
    }

    createTreeFactoryOCLhep_aida_ITreeFactoryEMethod = env->GetMethodID(cls, "createTreeFactory", "()Lhep/aida/ITreeFactory;");
    if (createTreeFactoryOCLhep_aida_ITreeFactoryEMethod == NULL) {
        std::cerr << "IAnalysisFactory" << ": Could not find method: " << "createTreeFactory" << "()Lhep/aida/ITreeFactory;" << std::endl;
    }
    
    new ProxyFactory(env);
}

JNIEXPORT JIAnalysisFactory::~JIAnalysisFactory() {
    JNIUtil::destroyJVM(jvm);
}

JNIEXPORT ITreeFactory * JIAnalysisFactory::createTreeFactory() {
    jobject obj = env->CallObjectMethod(ref, createTreeFactoryOCLhep_aida_ITreeFactoryEMethod);
    if (JNIUtil::exceptions(env)) return NULL;
    else return ProxyFactory::getFactory()->createITreeFactory(env, obj);
}

JNIEXPORT IHistogramFactory * JIAnalysisFactory::createHistogramFactory(ITree & tree) {
    jobject jtree = ProxyFactory::getFactory()->create(env, tree);
    jobject obj = env->CallObjectMethod(ref, createHistogramFactoryOLhep_aida_ITreeECLhep_aida_IHistogramFactoryEMethod, jtree);
    if (JNIUtil::exceptions(env)) return NULL;
    else return ProxyFactory::getFactory()->createIHistogramFactory(env, obj);
}

JNIEXPORT IDataPointSetFactory * JIAnalysisFactory::createDataPointSetFactory(ITree & tree) {
    jobject jtree = ProxyFactory::getFactory()->create(env, tree);
    jobject obj = env->CallObjectMethod(ref, createDataPointSetFactoryOLhep_aida_ITreeECLhep_aida_IDataPointSetFactoryEMethod, jtree);
    if (JNIUtil::exceptions(env)) return NULL;
    else return ProxyFactory::getFactory()->createIDataPointSetFactory(env, obj);
}

JNIEXPORT ITupleFactory * JIAnalysisFactory::createTupleFactory(ITree & tree) {
    jobject jtree = ProxyFactory::getFactory()->create(env, tree);
    jobject obj = env->CallObjectMethod(ref, createTupleFactoryOLhep_aida_ITreeECLhep_aida_ITupleFactoryEMethod, jtree);
    if (JNIUtil::exceptions(env)) return NULL;
    else return ProxyFactory::getFactory()->createITupleFactory(env, obj);
}

JNIEXPORT IFunctionFactory * JIAnalysisFactory::createFunctionFactory(ITree & tree) {
    jobject jtree = ProxyFactory::getFactory()->create(env, tree);
    jobject obj = env->CallObjectMethod(ref, createFunctionFactoryOLhep_aida_ITreeECLhep_aida_IFunctionFactoryEMethod, jtree);
    if (JNIUtil::exceptions(env)) return NULL;
    else return ProxyFactory::getFactory()->createIFunctionFactory(env, obj);
}

JNIEXPORT IPlotterFactory * JIAnalysisFactory::createPlotterFactory(int argc, char * * args, const std::string & imp, const std::string & lib) {
    // Note argc, args, imp and lib are not used.
    jobject obj = env->CallObjectMethod(ref, createPlotterFactoryOCLhep_aida_IPlotterFactoryEMethod);
    if (JNIUtil::exceptions(env)) return NULL;
    else return ProxyFactory::getFactory()->createIPlotterFactory(env, obj);
}

JNIEXPORT IFitFactory * JIAnalysisFactory::createFitFactory() {
    jobject obj = env->CallObjectMethod(ref, createFitFactoryOCLhep_aida_IFitFactoryEMethod);
    if (JNIUtil::exceptions(env)) return NULL;
    else return ProxyFactory::getFactory()->createIFitFactory(env, obj);
}

void JIAnalysisFactory::error(char* msg, ...) {
    char* s = (char*)malloc(255);
    va_list v;
    va_start(v, msg);
    vsprintf(s, msg, v);
    va_end(v);
	env->FatalError(s);
	free(s);
}

JNIEnv* JIAnalysisFactory::getEnv() {
	return env;
}

extern "C" {
   JNIEXPORT IAnalysisFactory* AIDA_createAnalysisFactory()
   {
      return new JIAnalysisFactory();
   }
}
