// -*- C++ -*-
#ifndef JAIDA_JIANALYSISFACTORY_H
#define JAIDA_JIANALYSISFACTORY_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include "FreeHepTypes.h"

#include <jni.h>

#include "AIDA/IAnalysisFactory.h"
#include "AIDA/IDataPointSetFactory.h"
#include "AIDA/IFitFactory.h"
#include "AIDA/IFunctionFactory.h"
#include "AIDA/IHistogramFactory.h"
#include "AIDA/IPlotterFactory.h"
#include "AIDA/ITree.h"
#include "AIDA/ITreeFactory.h"
#include "AIDA/ITupleFactory.h"
#include "JAID/JAIDRef.h"

#include "ProxyFactory.h"

namespace JAIDA {

/**
 * The "master" factory from which other factories are obtained.
 * Typically accessed by:
 * <pre>
 *   IAnalysisFactory af =(IAnalysisFactory) ServiceManager.create("hep.aida.IAnalysisFactory");
 * </pre>
 *
 * In C++ IAnalysisFactory* af = AIDA_createAnalysisFactory();
 *
 * @author The AIDA team (http://aida.freehep.org/)
 */

class JIAnalysisFactory: public JAID::JAIDRef, public virtual AIDA::IAnalysisFactory {

private:
    jmethodID createDataPointSetFactoryOLhep_aida_ITreeECLhep_aida_IDataPointSetFactoryEMethod;
    jmethodID createFunctionFactoryOLhep_aida_ITreeECLhep_aida_IFunctionFactoryEMethod;
    jmethodID createHistogramFactoryOLhep_aida_ITreeECLhep_aida_IHistogramFactoryEMethod;
    jmethodID createPlotterFactoryOCLhep_aida_IPlotterFactoryEMethod;
    jmethodID createFitFactoryOCLhep_aida_IFitFactoryEMethod;
    jmethodID createTupleFactoryOLhep_aida_ITreeECLhep_aida_ITupleFactoryEMethod;
    jmethodID createTreeFactoryOCLhep_aida_ITreeFactoryEMethod;

protected:
    JNIEnv *env;
    JavaVM *jvm;
    inline JIAnalysisFactory(const JIAnalysisFactory& r):JAIDRef(r) { };
    inline JIAnalysisFactory& operator=(const JIAnalysisFactory&) { return *this; };

public:
    JNIEXPORT JIAnalysisFactory();
    /// Destructor.
    JNIEXPORT virtual ~JIAnalysisFactory();

    virtual JNIEnv* getEnv();
    void error(char* message, ...);

  /**
   * Create an ITreeFactory.
   * @return The ITreeFactory.
   *
   */
   JNIEXPORT virtual AIDA::ITreeFactory * createTreeFactory();

  /**
   * Create an IHistogramFactory.
   * @param tree The ITree which created histograms will be associated to.
   * @return     The IHistogramFactory.
   *
   */
   JNIEXPORT virtual AIDA::IHistogramFactory * createHistogramFactory(AIDA::ITree & tree);

  /**
   * Create an IDataPointSetFactory.
   * @param tree The ITree which created IDataPointSet will be associated to.
   * @return     The IDataPointSetFactory.
   *
   */
   JNIEXPORT virtual AIDA::IDataPointSetFactory * createDataPointSetFactory(AIDA::ITree & tree);

  /**
   * Create an ITupleFactory.
   * @param tree The ITree which created tuples will be associated to.
   * @return     The ITupleFactory.
   *
   */
   JNIEXPORT virtual AIDA::ITupleFactory * createTupleFactory(AIDA::ITree & tree);

  /**
   * Create an IFunctionFactory.
   * @param tree The ITree which created functions will be associated to.
   * @return     The IFunctionFactory.
   *
   */
   JNIEXPORT virtual AIDA::IFunctionFactory * createFunctionFactory(AIDA::ITree & tree);

    /**
     * Create an IPlotterFactory.
     * Due to the fact that the plotter factory may activate a GUI
     * tookit, the process arguments (passed to the main function)
     * could be passed to the plotter factory. Most of the GUI
     * toolkit ask for them (Motif, gtk, Qt, FLTK).
     */




   JNIEXPORT virtual AIDA::IPlotterFactory * createPlotterFactory(int argc, char * * args, const std::string & imp = "", const std::string & lib = "");

  /**
   * Create an IFitFactory.
   * @return     The IFitFactory.
   *
   */
   JNIEXPORT virtual AIDA::IFitFactory * createFitFactory();
}; // class
} // namespace JAIDA



/**
 * To hook an AIDA implementation.
 * For example :
 *   #include <AIDA/IAnalysisFactory.h>
 *   ...
 *   IAnalysisFactory* analysisFactory = AIDA_createAnalysisFactory();
 *   ...
 */

extern "C" {
    JNIEXPORT AIDA::IAnalysisFactory* AIDA_createAnalysisFactory();
}
#endif /* ifndef JAIDA_JIANALYSISFACTORY_H */

