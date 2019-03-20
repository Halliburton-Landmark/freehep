// -*- C++ -*-
#ifndef JAIDA_JIFITTER_H
#define JAIDA_JIFITTER_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>
#include <map>

#include "AIDA/IBaseHistogram.h"
#include "AIDA/IDataPointSet.h"
#include "AIDA/IFitData.h"
#include "AIDA/IFitParameterSettings.h"
#include "AIDA/IFitResult.h"
#include "AIDA/IFitter.h"
#include "AIDA/IFunction.h"

#include "JProxy.h"

namespace JAIDA {

/** @interface IFitter
 *
 * Fitter performs fits, scans and computes contours.
 *
 * Fitter never stores association to the data and functions which are
 * used for fitting. Results of the fit are availabe in the IFitResult
 * object, which also remebers the initial fit configuration.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIFitter: public JProxy, public virtual AIDA::IFitter {

private:
    jmethodID createScan1DOLhep_aida_IFitDataELhep_aida_IFunctionELjava_lang_StringEIDDCLhep_aida_IDataPointSetEMethod;
    jmethodID fitMethodNameOCLjava_lang_StringEMethod;
    jmethodID setFitMethodOLjava_lang_StringECVMethod;
    jmethodID resetParameterSettingsOCVMethod;
    jmethodID fitOLhep_aida_IFitDataELjava_lang_StringEADCLhep_aida_IFitResultEMethod;
    jmethodID fitOLhep_aida_IFitDataELhep_aida_IFunctionECLhep_aida_IFitResultEMethod;
    jmethodID setEngineOLjava_lang_StringECVMethod;
    jmethodID fitOLhep_aida_IBaseHistogramELjava_lang_StringEADCLhep_aida_IFitResultEMethod;
    jmethodID useFunctionGradientOCZMethod;
    jmethodID fitOLhep_aida_IDataPointSetELhep_aida_IFunctionECLhep_aida_IFitResultEMethod;
    jmethodID constraintsOCALjava_lang_StringEMethod;
    jmethodID fitOLhep_aida_IFitDataELjava_lang_StringECLhep_aida_IFitResultEMethod;
    jmethodID setUseFunctionGradientOZCVMethod;
    jmethodID fitOLhep_aida_IDataPointSetELjava_lang_StringECLhep_aida_IFitResultEMethod;
    jmethodID createContourOLhep_aida_IFitDataELhep_aida_IFitResultELjava_lang_StringELjava_lang_StringEIDCLhep_aida_IDataPointSetEMethod;
    jmethodID engineNameOCLjava_lang_StringEMethod;
    jmethodID fitOLhep_aida_IDataPointSetELjava_lang_StringEADCLhep_aida_IFitResultEMethod;
    jmethodID fitOLhep_aida_IBaseHistogramELhep_aida_IFunctionECLhep_aida_IFitResultEMethod;
    jmethodID fitOLhep_aida_IBaseHistogramELjava_lang_StringECLhep_aida_IFitResultEMethod;
    jmethodID setConstraintOLjava_lang_StringECVMethod;
    jmethodID resetConstraintsOCVMethod;
    jmethodID listParameterSettingsOCALjava_lang_StringEMethod;
    jmethodID fitParameterSettingsOLjava_lang_StringECLhep_aida_IFitParameterSettingsEMethod;
    mutable std::map<std::string, AIDA::IFitParameterSettings*> fitParameterSettingsMap;
    
protected:
    inline JIFitter() { };
    inline JIFitter(const JIFitter& r):JProxy(r) { };
    inline JIFitter& operator=(const JIFitter&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIFitter(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIFitter();

    /**
     * Fit an IFunction to an IFitData.
     * The result of the fit is an IFitResult.
     * @param fitData The IFitData to be fitted.
     * @param func    The IFunction to fit on the data.
     * @return        The IFitResult containing the results of the fit.
     *
     */
    JNIEXPORT virtual AIDA::IFitResult * fit(AIDA::IFitData & fitData, AIDA::IFunction & func);

    /**
     * Shortcut to fit an IBaseHistogram directly with an IFunction.
     * The dimension of the IBaseHistogram must match the dimension of the IFunction.
     * IHistograms and IProfiles are for binned fits only, IClouds only for unbinned fits.
     * @param hist The IBaseHistogram to be fitted.
     * @param func The IFunction to fit on the data.
     * @return     The IFitResult containing the result of the fit.
     *
     */
    JNIEXPORT virtual AIDA::IFitResult * fit(AIDA::IBaseHistogram & hist, AIDA::IFunction & func);

    /**
     * Shortcut to fit an IBaseHistogram directly with an IFunction.
     * The dimension of the IBaseHistogram must match the dimension of the IFunction.
     * IHistograms and IProfiles are for binned fits only, IClouds only for unbinned fits.
     * @param hist  The IBaseHistogram to be fitted.
     * @param model The string defining the function to be used.
     * @return      The IFitResult containing the result of the fit.
     *
     */
    JNIEXPORT virtual AIDA::IFitResult * fit(AIDA::IBaseHistogram & hist, const std::string & model);

    /**
     * Shortcut to fit an IBaseHistogram directly with an IFunction.
     * The dimension of the IBaseHistogram must match the dimension of the IFunction.
     * IHistograms and IProfiles are for binned fits only, IClouds only for unbinned fits.
     * @param hist              The IBaseHistogram to be fitted.
     * @param model             The string defining the function to be used.
     * @param initialParameters The array of the initial parameter values; its size must match the number of
     *                          parameters in the function.
     * @return                  The IFitResult containing the result of the fit.
     *
     */
    JNIEXPORT virtual AIDA::IFitResult * fit(AIDA::IBaseHistogram & hist, const std::string & model, const std::vector<double> & initialParameters);

    /**
     * Shortcut to fit an IDataPointSet directly with an IFunction.
     * The dimension of the IDataPointSet must be equal the dimension of the IFunction + 1.
     * This are binned fits only; the last coordinate of the IDataPointSet is used as
     * the "height" in a fit to an IBaseHistogram.
     * @param dataPointSet The IDataPointSet to be fitted.
     * @param func         The IFunction to fit on the data.
     * @return             The IFitResult containing the result of the fit.
     *
     */
    JNIEXPORT virtual AIDA::IFitResult * fit(AIDA::IDataPointSet & dataPointSet, AIDA::IFunction & f);

    /**
     * Shortcut to fit an IDataPointSet directly with an IFunction.
     * The dimension of the IDataPointSet must be equal the dimension of the IFunction + 1.
     * This are binned fits only; the last coordinate of the IDataPointSet is used as
     * the "height" in a fit to an IBaseHistogram.
     * @param dataPointSet The IDataPointSet to be fitted.
     * @param model        The string defining the function to be used.
     * @return             The IFitResult containing the result of the fit.
     *
     */
    JNIEXPORT virtual AIDA::IFitResult * fit(AIDA::IDataPointSet & dataPointSet, const std::string & model);

    /**
     * Shortcut to fit an IDataPointSet directly with an IFunction.
     * The dimension of the IDataPointSet must be equal the dimension of the IFunction + 1.
     * This are binned fits only; the last coordinate of the IDataPointSet is used as
     * the "height" in a fit to an IBaseHistogram.
     * @param dataPointSet      The IDataPointSet to be fitted.
     * @param model             The string defining the function to be used.
     * @param initialParameters The array of the initial parameter values; its size must match the number of
     *                          parameters in the function.
     * @return                  The IFitResult containing the result of the fit.
     *
     */
    JNIEXPORT virtual AIDA::IFitResult * fit(AIDA::IDataPointSet & dataPointSet, const std::string & model, const std::vector<double> & initialParameters);

    /// Shortcut for the predefined models.
    JNIEXPORT virtual AIDA::IFitResult * fit(AIDA::IFitData & d, const std::string & model);

    JNIEXPORT virtual AIDA::IFitResult * fit(AIDA::IFitData & d, const std::string & model, const std::vector<double> & initialParameters);

    /**
     * Set the optimization engine which is used internally for fitting.
     * @param name The name of the optimizer engine.
     *             Examples of predefined engines: "minuit". The engine name is case-insensitive.
     *             Different engines are provided by different implementations.
     * @return false If the name does not correspond to a valid engine.
     *
     */
    JNIEXPORT virtual bool setEngine(const std::string & name);

    /**
     * Get the name of the engine currently in use.
     * @return The name of the optimizer engine used by the IFitter.
     *
     */
    JNIEXPORT virtual std::string engineName();

    /**
     * Access to fit parameter settings. FitParameterSettings object belongs to
     * and is managed by the fitter. Fitter implementation takes care that the
     * returned reference is valid thru the lifetime of fitter.
     * User can set the settings of the parameters independently of the
     * parameters of the fitted function.
     * Setting for parameters unknown in the function and set in the
     * fitter are ignored in the fit.
     * If settings are not explicitly set in the fitter, their default
     * values are attached to function parameters during the fit.
     */
    JNIEXPORT virtual AIDA::IFitParameterSettings & fitParameterSettings(const std::string & name);

    /**
     * Get a vector of names of all parameter settings defined in the fitter.
     */
    JNIEXPORT virtual std::vector<std::string> listParameterSettings();

    /**
     * Reset all parameter settings which fitter remebers.
     */
    JNIEXPORT virtual void resetParameterSettings();

    /**
     * Set a general constraint in the parameter space. The constraint
     * is a parsed expression. PENDING: The syntax to be fixed.
     */
    JNIEXPORT virtual bool setConstraint(const std::string & expr);

    /// Get the list of all constraints.
    JNIEXPORT virtual std::vector<std::string> constraints();

    /**
     * Reset all the constraints.
     */
    JNIEXPORT virtual void resetConstraints();

    /**
     * Set the fit method type. Examples of pre-defined methods: "chi2", "ml".
     * The method names are case-insensitive.
     * @param name The name of the fit method.
     * @return false If the name does not correspond to a valid fit method.
     *
     */
    JNIEXPORT virtual bool setFitMethod(const std::string & name);

    /**
     * Get the name of the fit method currently in use.
     * @return The name of the fit method.
     *
     */
    JNIEXPORT virtual std::string fitMethodName();

    /// Create a 1D scan of the fit quality for given parameter 'par' of
    /// the function.
    /// User must make sure that the returned vector is properly deleted
    /// after use.
    /// The vector containes 'npts' points which are evenly sampled in the
    /// interval ('pmin','pmax').
    JNIEXPORT virtual AIDA::IDataPointSet * createScan1D(AIDA::IFitData & d, AIDA::IFunction & f, const std::string & par, int npts, double pmin, double pmax);

    /// Create a 2D contour spanned on 'par1' and 'par2',
    /// with given number of npts points. Contour is create using previously
    /// obtained fit results. Argument 'up' tells the vertical distance of
    /// the contour plane above the minimal fit quality value.
    JNIEXPORT virtual AIDA::IDataPointSet * createContour(AIDA::IFitData & d, AIDA::IFitResult & r, const std::string & par1, const std::string & par2, int npts, double up);

    /**
     * Choose between using or not using the
     * analytical derivatives if provided by the function.
     * @param useGrad If <code>true</code> the IFitter will use the
     *                analytical derivatives if provided by the IFunction.
     *
     */
    JNIEXPORT virtual void setUseFunctionGradient(bool useGrad);

    /**
     * Check if the IFitter is set to use the analytical derivatives provided
     * by the IFunction.
     * @return <code>true</code> if the IFitter uses the analytical derivatives.
     *
     */
    JNIEXPORT virtual bool useFunctionGradient();

    /**
     * @link association
     * @directed
     * @label <<create>>
     */
    /*#  IFitResult lnkIFitResult; */

    /** @link dependency */
    /*#  IFitData lnkIFitData; */

    /** @link aggregation
     * @supplierRole <<internal copy>>*/
    /*#  IFitParameterSettings lnkIFitParameter; */

    /** @link dependency
     * @label fitter uses function for fitting*/
    /*#  IFunction lnkIFunction; */
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIFITTER_H */
