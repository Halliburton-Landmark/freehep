// -*- C++ -*-
#ifndef JAIDA_PROXYFACTORY_H
#define JAIDA_PROXYFACTORY_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include "FreeHepTypes.h"

#include <jni.h>

#include "AIDA/AIDA.h"

#include "Registry.h"

namespace JAIDA {

/**
 * The Proxy factory to create Proxies for Java and C++ objects.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 */

class ProxyFactory {

private:
    mutable jclass      cloud1Dclass;
    mutable jclass      cloud2Dclass;
    mutable jclass      cloud3Dclass;
    mutable jclass      dataPointSetClass;
    mutable jclass      dataPointClass;
    mutable jclass      functionClass;
    mutable jclass      modelFunctionClass;
    mutable jclass      measurementClass;
    mutable jclass      histogram1Dclass;
    mutable jclass      histogram2Dclass;
    mutable jclass      histogram3Dclass;
    mutable jclass      profile1Dclass;
    mutable jclass      profile2Dclass;
    mutable jclass      tupleClass;
    
protected:
    mutable jclass      classCIAnnotation;
    mutable jfieldID    crefCIAnnotation;
    mutable jmethodID   ctorCIAnnotation;
    
    mutable jclass      classCIAxis;
    mutable jfieldID    crefCIAxis;
    mutable jmethodID   ctorCIAxis;
    
    mutable jclass      classCIAxisStyle;
    mutable jfieldID    crefCIAxisStyle;
    mutable jmethodID   ctorCIAxisStyle;
    
    mutable jclass      classCIBaseHistogram;
    mutable jfieldID    crefCIBaseHistogram;
    mutable jmethodID   ctorCIBaseHistogram;
    
    mutable jclass      classCICloud1D;
    mutable jfieldID    crefCICloud1D;
    mutable jmethodID   ctorCICloud1D;
    
    mutable jclass      classCICloud2D;
    mutable jfieldID    crefCICloud2D;
    mutable jmethodID   ctorCICloud2D;
    
    mutable jclass      classCICloud3D;
    mutable jfieldID    crefCICloud3D;
    mutable jmethodID   ctorCICloud3D;
    
    mutable jclass      classCIDataPoint;
    mutable jfieldID    crefCIDataPoint;
    mutable jmethodID   ctorCIDataPoint;
    
    mutable jclass      classCIDataPointSet;
    mutable jfieldID    crefCIDataPointSet;
    mutable jmethodID   ctorCIDataPointSet;
    
    mutable jclass      classCIDataPointSetFactory;
    mutable jfieldID    crefCIDataPointSetFactory;
    mutable jmethodID   ctorCIDataPointSetFactory;
    
    mutable jclass      classCIDataStyle;
    mutable jfieldID    crefCIDataStyle;
    mutable jmethodID   ctorCIDataStyle;
    
    mutable jclass      classCIEvaluator;
    mutable jfieldID    crefCIEvaluator;
    mutable jmethodID   ctorCIEvaluator;
    
    mutable jclass      classCIFillStyle;
    mutable jfieldID    crefCIFillStyle;
    mutable jmethodID   ctorCIFillStyle;
    
    mutable jclass      classCIFilter;
    mutable jfieldID    crefCIFilter;
    mutable jmethodID   ctorCIFilter;
    
    mutable jclass      classCIFitData;
    mutable jfieldID    crefCIFitData;
    mutable jmethodID   ctorCIFitData;
    
    mutable jclass      classCIFitFactory;
    mutable jfieldID    crefCIFitFactory;
    mutable jmethodID   ctorCIFitFactory;
    
    mutable jclass      classCIFitParameterSettings;
    mutable jfieldID    crefCIFitParameterSettings;
    mutable jmethodID   ctorCIFitParameterSettings;
    
    mutable jclass      classCIFitResult;
    mutable jfieldID    crefCIFitResult;
    mutable jmethodID   ctorCIFitResult;
    
    mutable jclass      classCIFitter;
    mutable jfieldID    crefCIFitter;
    mutable jmethodID   ctorCIFitter;
    
    mutable jclass      classCIFunction;
    mutable jfieldID    crefCIFunction;
    mutable jmethodID   ctorCIFunction;
    
    mutable jclass      classCIFunctionCatalog;
    mutable jfieldID    crefCIFunctionCatalog;
    mutable jmethodID   ctorCIFunctionCatalog;
    
    mutable jclass      classCIFunctionFactory;
    mutable jfieldID    crefCIFunctionFactory;
    mutable jmethodID   ctorCIFunctionFactory;
    
    mutable jclass      classCIHistogramFactory;
    mutable jfieldID    crefCIHistogramFactory;
    mutable jmethodID   ctorCIHistogramFactory;
    
    mutable jclass      classCIHistogram1D;
    mutable jfieldID    crefCIHistogram1D;
    mutable jmethodID   ctorCIHistogram1D;
    
    mutable jclass      classCIHistogram2D;
    mutable jfieldID    crefCIHistogram2D;
    mutable jmethodID   ctorCIHistogram2D;
    
    mutable jclass      classCIHistogram3D;
    mutable jfieldID    crefCIHistogram3D;
    mutable jmethodID   ctorCIHistogram3D;
    
    mutable jclass      classCIInfo;
    mutable jfieldID    crefCIInfo;
    mutable jmethodID   ctorCIInfo;
    
    mutable jclass      classCIInfoStyle;
    mutable jfieldID    crefCIInfoStyle;
    mutable jmethodID   ctorCIInfoStyle;
    
    mutable jclass      classCILineStyle;
    mutable jfieldID    crefCILineStyle;
    mutable jmethodID   ctorCILineStyle;
    
    mutable jclass      classCIMarkerStyle;
    mutable jfieldID    crefCIMarkerStyle;
    mutable jmethodID   ctorCIMarkerStyle;
    
    mutable jclass      classCIManagedObject;
    mutable jfieldID    crefCIManagedObject;
    mutable jmethodID   ctorCIManagedObject;
    
    mutable jclass      classCIMeasurement;
    mutable jfieldID    crefCIMeasurement;
    mutable jmethodID   ctorCIMeasurement;
    
    mutable jclass      classCIModelFunction;
    mutable jfieldID    crefCIModelFunction;
    mutable jmethodID   ctorCIModelFunction;
    
    mutable jclass      classCIPlotter;
    mutable jfieldID    crefCIPlotter;
    mutable jmethodID   ctorCIPlotter;
    
    mutable jclass      classCIPlotterFactory;
    mutable jfieldID    crefCIPlotterFactory;
    mutable jmethodID   ctorCIPlotterFactory;
    
    mutable jclass      classCIPlotterLayout;
    mutable jfieldID    crefCIPlotterLayout;
    mutable jmethodID   ctorCIPlotterLayout;
    
    mutable jclass      classCIPlotterRegion;
    mutable jfieldID    crefCIPlotterRegion;
    mutable jmethodID   ctorCIPlotterRegion;
    
    mutable jclass      classCIPlotterStyle;
    mutable jfieldID    crefCIPlotterStyle;
    mutable jmethodID   ctorCIPlotterStyle;
    
    mutable jclass      classCIProfile1D;
    mutable jfieldID    crefCIProfile1D;
    mutable jmethodID   ctorCIProfile1D;
    
    mutable jclass      classCIProfile2D;
    mutable jfieldID    crefCIProfile2D;
    mutable jmethodID   ctorCIProfile2D;
    
    mutable jclass      classCIRangeSet;
    mutable jfieldID    crefCIRangeSet;
    mutable jmethodID   ctorCIRangeSet;
    
    mutable jclass      classCITextStyle;
    mutable jfieldID    crefCITextStyle;
    mutable jmethodID   ctorCITextStyle;
    
    mutable jclass      classCITitleStyle;
    mutable jfieldID    crefCITitleStyle;
    mutable jmethodID   ctorCITitleStyle;
    
    mutable jclass      classCITree;
    mutable jfieldID    crefCITree;
    mutable jmethodID   ctorCITree;
    
    mutable jclass      classCITreeFactory;
    mutable jfieldID    crefCITreeFactory;
    mutable jmethodID   ctorCITreeFactory;
    
    mutable jclass      classCITuple;
    mutable jfieldID    crefCITuple;
    mutable jmethodID   ctorCITuple;
    
    mutable jclass      classCITupleFactory;
    mutable jfieldID    crefCITupleFactory;
    mutable jmethodID   ctorCITupleFactory;
    
    static jlong crefIDcount;
    static ProxyFactory* factory;
    
public:

    JNIEXPORT ProxyFactory(JNIEnv *env);
    JNIEXPORT virtual ~ProxyFactory();
    JNIEXPORT static inline ProxyFactory* getFactory() {
        if (factory == NULL) {
            std::cerr << "FATAL: create JIAnalysisFactory first, before calling ProxyFactory::getFactory()" << std::endl;
            abort();
        }
        return factory;
    }

    JNIEXPORT static inline void addRef(jlong ID, const void* cobj, jobject jobj, jclass jcls) {
        Registry::getRegistry()->add(ID, cobj, jobj, jcls);
    }

    JNIEXPORT static inline const void* getCRef(jlong ID) {
        const void* cobj = Registry::getRegistry()->lookup(ID);
        if (cobj == NULL) {
            std::cerr << "FATAL: getCRef for ID=" << ID << " not found." << std::endl; 
            abort();
        }
        return cobj;
    }

    JNIEXPORT static inline jobject getJRef(const void* cobj) {
        return Registry::getRegistry()->lookup(cobj);
    }

    JNIEXPORT static inline jclass getJClass(const void* cobj) {
        return Registry::getRegistry()->lookupClass(cobj);
    }

//
// C++ proxies for Java Objects
//
    JNIEXPORT virtual AIDA::IAnnotation*             createIAnnotation          (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IAxis*                   createIAxis                (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IAxisStyle*              createIAxisStyle           (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IBaseHistogram*          createIBaseHistogram       (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::ICloud1D*                createICloud1D             (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::ICloud2D*                createICloud2D             (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::ICloud3D*                createICloud3D             (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IDataPoint*              createIDataPoint           (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IDataPointSet*           createIDataPointSet        (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IDataPointSetFactory*    createIDataPointSetFactory (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IDataStyle*              createIDataStyle           (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IEvaluator*              createIEvaluator           (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IFillStyle*              createIFillStyle           (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IFilter*                 createIFilter              (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IFitData*                createIFitData             (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IFitFactory*             createIFitFactory          (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IFitParameterSettings*   createIFitParameterSettings(JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IFitResult*              createIFitResult           (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IFitter*                 createIFitter              (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IFunction*               createIFunction            (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IFunctionCatalog*        createIFunctionCatalog     (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IFunctionFactory*        createIFunctionFactory     (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IHistogramFactory*       createIHistogramFactory    (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IHistogram1D*            createIHistogram1D         (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IHistogram2D*            createIHistogram2D         (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IHistogram3D*            createIHistogram3D         (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IInfo*                   createIInfo                (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IInfoStyle*              createIInfoStyle           (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::ILineStyle*              createILineStyle           (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IManagedObject*          createIManagedObject       (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IMarkerStyle*            createIMarkerStyle         (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IMeasurement*            createIMeasurement         (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IModelFunction*          createIModelFunction       (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IPlotter*                createIPlotter             (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IPlotterFactory*         createIPlotterFactory      (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IPlotterLayout*          createIPlotterLayout       (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IPlotterRegion*          createIPlotterRegion       (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IPlotterStyle*           createIPlotterStyle        (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IProfile1D*              createIProfile1D           (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IProfile2D*              createIProfile2D           (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::IRangeSet*               createIRangeSet            (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::ITextStyle*              createITextStyle           (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::ITitleStyle*             createITitleStyle          (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::ITree*                   createITree                (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::ITreeFactory*            createITreeFactory         (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::ITuple*                  createITuple               (JNIEnv *env, jobject object) const;
    JNIEXPORT virtual AIDA::ITupleFactory*           createITupleFactory        (JNIEnv *env, jobject object) const;

//
// Java Proxies for C++
//
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IAnnotation & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IAxis & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IAxisStyle & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IBaseHistogram & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::ICloud & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::ICloud1D & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::ICloud2D & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::ICloud3D & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IDataPoint & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IDataPointSet & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IDataPointSetFactory & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IDataStyle & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IEvaluator & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IFillStyle & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IFilter & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IFitData & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IFitFactory & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IFitParameterSettings & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IFitResult & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IFitter & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IFunction & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IFunctionCatalog & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IFunctionFactory & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IHistogram & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IHistogramFactory & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IHistogram1D & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IHistogram2D & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IHistogram3D & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IInfo & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IInfoStyle & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::ILineStyle & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IManagedObject & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IMarkerStyle & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IMeasurement & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IModelFunction & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IPlotter & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IPlotterFactory & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IPlotterLayout & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IPlotterRegion & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IPlotterStyle & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IProfile & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IProfile1D & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IProfile2D & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::IRangeSet & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::ITextStyle & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::ITitleStyle & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::ITree & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::ITreeFactory & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::ITuple & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env,       AIDA::ITuple & obj) const;
    JNIEXPORT virtual jobject create(JNIEnv *env, const AIDA::ITupleFactory & obj) const;
    
}; // class
} // namespace JAIDA

#endif /* ifndef JAIDA_PROXYFACTORY_H */

