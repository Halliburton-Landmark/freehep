// -*- C++ -*-
#ifndef JAIDA_JIFITRESULT_H
#define JAIDA_JIFITRESULT_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IFitParameterSettings.h"
#include "AIDA/IFitResult.h"
#include "AIDA/IFunction.h"

#include "JProxy.h"

namespace JAIDA {

/** @interface
 *
 * Represents the result of the fit.
 *
 * Holds internal copies of fit parameter settings (set in IFitter) and the
 * fitted function (clone of original function). The value of the parameters
 * of the fitted function are obtained from the fitting.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIFitResult: public JProxy, public virtual AIDA::IFitResult {

private:
    jmethodID fitMethodNameOCLjava_lang_StringEMethod;
    jmethodID fittedParameterNamesOCALjava_lang_StringEMethod;
    jmethodID errorsPlusOCADMethod;
    jmethodID errorsOCADMethod;
    jmethodID ndfOCIMethod;
    jmethodID fittedFunctionOCLhep_aida_IFunctionEMethod;
    jmethodID covMatrixElementOIICDMethod;
    jmethodID fittedParametersOCADMethod;
    jmethodID fitStatusOCIMethod;
    jmethodID constraintsOCALjava_lang_StringEMethod;
    jmethodID fittedParameterOLjava_lang_StringECDMethod;
    jmethodID isValidOCZMethod;
    jmethodID dataDescriptionOCLjava_lang_StringEMethod;
    jmethodID qualityOCDMethod;
    jmethodID engineNameOCLjava_lang_StringEMethod;
    jmethodID errorsMinusOCADMethod;
    jmethodID fitParameterSettingsOLjava_lang_StringECLhep_aida_IFitParameterSettingsEMethod;
    mutable std::vector<double> fittedParametersVector;
    mutable std::vector<double> errorsVector;
    mutable std::vector<double> errorsPlusVector;
    mutable std::vector<double> errorsMinusVector;
    mutable AIDA::IFunction* fittedFunctionPtr;

protected:
    inline JIFitResult() { };
    inline JIFitResult(const JIFitResult& r):JProxy(r) { };
    inline JIFitResult& operator=(const JIFitResult&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIFitResult(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIFitResult();

    /// True if fit successful, otherwise false.
    JNIEXPORT virtual bool isValid();

    /// Status of the fit. PENDING: what are the suggested values?
    JNIEXPORT virtual int fitStatus();

    /// Fitted function. The parameters hold the results of the fit.
    JNIEXPORT virtual AIDA::IFunction & fittedFunction();

    /// Quality of the fit. Depending on the fit method this may be the value
    /// of Chi2 or Maximu Likelihood.
    JNIEXPORT virtual double quality();

    /// Number of degrees of freedom.
    JNIEXPORT virtual int ndf();

    /// Covariance matrix. PENDING: interface for matrix to be defined.
    JNIEXPORT virtual double covMatrixElement(int i, int j);

    /// Fit method name as set in the fitter.
    JNIEXPORT virtual std::string fitMethodName();

    /// Engine used to do fitting.
    JNIEXPORT virtual std::string engineName();

    /// Textual description of data - this is a hint for the user how to find
    /// the data in the tree if he wanted to repeat the fit later and lost
    /// the pointer to his orignal data object.
    /// PENDING: the contents and format of this string to be defined.
    /// PENDING: XML? stor name and path? ranges of DataPipe?
    JNIEXPORT virtual std::string dataDescription();

    /// Vector of constraints.
    JNIEXPORT virtual std::vector<std::string> constraints();

    /// Access to applied parameter settings.
    JNIEXPORT virtual AIDA::IFitParameterSettings * fitParameterSettings(const std::string & name);

    /**
     * Get the array of the fitted parameter values (including fixed and constrained ones).
     * @return The array containing the fitted values.
     *
     */
    JNIEXPORT virtual const std::vector<double>  & fittedParameters() const;

    /**
     * Get the names of the fitted parameters (including fixed and constrained ones).
     * @return The array containing the names of the fitted parameters.
     *
     */
    JNIEXPORT virtual std::vector<std::string> fittedParameterNames() const;

    /**
     * Get the value of a fitted parameter by name.
     * @return The value.
     *
     */
    JNIEXPORT virtual double fittedParameter(const std::string & name);

    /**
     * Get the parabolic errors on the fitted parameters. If a parameter was fixed
     * or constrained the error is zero.
     * @return The parabolic errors on the fitted parameters.
     *
     */
    JNIEXPORT virtual const std::vector<double>  & errors() const;

    /**
     * Get the positive part of the asymmetric errors on the fitted parameters. If a parameter was fixed
     * or constrained the error is zero.
     * @return The positive part of the asymmetric errors on the fitted parameters.
     *
     */
    JNIEXPORT virtual const std::vector<double>  & errorsPlus() const;

    /**
     * Get the negative part of the asymmetric errors on the fitted parameters. If a parameter was fixed
     * or constrained the error is zero.
     * @return The negative part of the asymmetric errors on the fitted parameters.
     *
     */
    JNIEXPORT virtual const std::vector<double>  & errorsMinus() const;

    /** @link aggregation
     * @supplierRole <<internal copy>>*/
    /*#  IFitParameterSettings lnkIFitParameterProperty; */
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIFITRESULT_H */
