// -*- C++ -*-
#ifndef JAIDA_JIFUNCTION_H
#define JAIDA_JIFUNCTION_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IAnnotation.h"
#include "AIDA/IFunction.h"

#include "JProxy.h"

#include "JIManagedObject.h"

namespace JAIDA {

/** @interface IFunction
 *
 * Principal user-level function interface. Function is a self
 * contained object, which remembers the current value of its parameters
 * which are simple doubles. IFunction may be directly plotted or fitted.
 *
 * The standard convention of referring to variables by name:
 * "x[0]" corresponds to variable number 0 etc.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIFunction: public JProxy, public JIManagedObject, public virtual AIDA::IFunction {

private:
    jmethodID providesGradientOCZMethod;
    jmethodID annotationOCLhep_aida_IAnnotationEMethod;
    jmethodID parameterOLjava_lang_StringECDMethod;
    jmethodID variableNameOICLjava_lang_StringEMethod;
    jmethodID setParameterOLjava_lang_StringEDCVMethod;
    jmethodID isEqualOLhep_aida_IFunctionECZMethod;
    jmethodID parametersOCADMethod;
    jmethodID codeletStringOCLjava_lang_StringEMethod;
    jmethodID setParametersOADCVMethod;
    jmethodID numberOfParametersOCIMethod;
    jmethodID parameterNamesOCALjava_lang_StringEMethod;
    jmethodID indexOfParameterOLjava_lang_StringECIMethod;
    jmethodID variableNamesOCALjava_lang_StringEMethod;
    jmethodID gradientOADCADMethod;
    jmethodID dimensionOCIMethod;
    jmethodID valueOADCDMethod;
    jmethodID setTitleOLjava_lang_StringECVMethod;
    jmethodID titleOCLjava_lang_StringEMethod;

    mutable AIDA::IAnnotation* iAnnotation;
    mutable std::vector<double> gradientVector;
    mutable std::vector<double> parametersVector;

protected:
    inline JIFunction() { };
    inline JIFunction(const JIFunction& r):JProxy(r), JIManagedObject(r) { };
    inline JIFunction& operator=(const JIFunction&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIFunction(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIFunction();

    /**
     * Get the Function's title.
     * @return The Function's title.
     *
     */
    JNIEXPORT virtual std::string title() const;

    /**
     * Set	 the histogram title.
     * @param title The title.
     * @return false If title cannot be changed.
     *
     */
    JNIEXPORT virtual bool setTitle(const std::string & title);

    /**
     * Scalar value of the function.
     */
    JNIEXPORT virtual double value(const std::vector<double>  & x) const;

    /**
     * Dimensionality of the domain space.
     */
    JNIEXPORT virtual int dimension() const;

    /**
     * Compare if functions are the same.
     * PENDING: define exactly what it means ;)
     */
    JNIEXPORT virtual bool isEqual(const AIDA::IFunction & f) const;

    /**
     * Gradient of the function.
     * The result is valid only if providesGradient()==true.
     * Otherwise the result is some default (empty) vector.
     */
    JNIEXPORT virtual const std::vector<double> & gradient(const std::vector<double>  & x) const;

    /**
     * Determine whether function is able to compute gradient.
     */
    JNIEXPORT virtual bool providesGradient() const;

    /**
     * Get the symbolic name of i-th variable.
     */
    JNIEXPORT virtual std::string variableName(int i) const;

    /**
     * Get all the names in a vector.
     */
    JNIEXPORT virtual std::vector<std::string> variableNames() const;

    /**
      * Set new vector of parameters.
      */
    JNIEXPORT virtual bool setParameters(const std::vector<double>  & params);

    /**
     * Retrieve current vector of parameters.
     */
    JNIEXPORT virtual const std::vector<double> & parameters() const;

    /**
     * Number of parameters.
     */
    JNIEXPORT virtual int numberOfParameters() const;

    /**
     * Names of paramaters.
     * Names should be unique. Case-insensitive for comparison.
     * Case-sensitive for storage and output.
     * All or several names may be left blank "" if the implementation
     * does not want to provide them.
     */
    JNIEXPORT virtual std::vector<std::string> parameterNames() const;

    /**
     * Set parameter's value by name.
     * @param name The name of the parameter.
     * @param x    The new value of the parameter.
     * @return false If name does not correspond to a parameter.
     *
     */
    JNIEXPORT virtual bool setParameter(const std::string & name, double x);

    JNIEXPORT virtual double parameter(const std::string & name) const;

  /**
   * Return -1 if parameter not found (name undefined).
   * Leave it because there are use cases - some users prefer to use numbers.
   */
    JNIEXPORT virtual int indexOfParameter(const std::string & name) const;

    JNIEXPORT virtual AIDA::IAnnotation & annotation();

    JNIEXPORT virtual const AIDA::IAnnotation & annotation() const;

  /**
   * String describing the metatype and implementation of the function.
   *
   * Generic format of the string:
   *
   * codelet:TYPE:LOCATION
   *
   * TYPE part contains only a 'typename' string
   * which is a metatype identifier (used in plugins and catalogues)
   *
   * LOCATION may be: 'file', 'verbatim', or 'catalogue'
   *
   * Detailed description:
   *
   * codelet:typename - no location specified (using 'catalogue')
   *
   * codelet:typename:file:/filename.cpp    -  a c++ source file
   * codelet:typename:file:/filename.py     -  a python source file
   * codelet:typename:file:/filename.so     -  a shared library
   *
   * codelet:typename:catalogue        - entry in a catalogue repository
   *
   * codelet:typename:verbatim:cpp \n  - c++ source file included verbatim
   *                                     after \n
   *
   * codelet:typename:verbatim:py  \n  - python source file included
   *                                     verbatim aftern \n
   *
   *
   * Comments:
   *
   * file:/filename is a relative path to $AIDA_FUNCTION_DEFAULT_DIR
   * file://filename is an absolute path
   *
   * Examples:
   *
   * codelet:G:catalogue
   * codelet:userSinus:verbatim:cpp \n { return sin(x); }
   */
    JNIEXPORT virtual std::string codeletString() const;

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
    JNIEXPORT virtual void * cast(const std::string & className) const;

    /** @link aggregation */
    /*#  IAnnotation lnkIAnnotation; */
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIFUNCTION_H */
