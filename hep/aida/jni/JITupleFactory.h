// -*- C++ -*-
#ifndef JAIDA_JITUPLEFACTORY_H
#define JAIDA_JITUPLEFACTORY_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IEvaluator.h"
#include "AIDA/IFilter.h"
#include "AIDA/ITuple.h"
#include "AIDA/ITupleFactory.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * A factory for creating ITuples.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 */

class JITupleFactory: public JProxy, public virtual AIDA::ITupleFactory {

private:
    jmethodID createFilterOLjava_lang_StringEIICLhep_aida_IFilterEMethod;
    jmethodID createChainedOLjava_lang_StringELjava_lang_StringEALjava_lang_StringECLhep_aida_ITupleEMethod;
    jmethodID createFilteredOLjava_lang_StringELhep_aida_ITupleELhep_aida_IFilterECLhep_aida_ITupleEMethod;
    jmethodID createOLjava_lang_StringELjava_lang_StringEALjava_lang_StringEAALhep_aida_ELjava_lang_StringECLhep_aida_ITupleEMethod;
    jmethodID createEvaluatorOLjava_lang_StringECLhep_aida_IEvaluatorEMethod;
    jmethodID createOLjava_lang_StringELjava_lang_StringELjava_lang_StringELjava_lang_StringECLhep_aida_ITupleEMethod;
    jmethodID createFilterOLjava_lang_StringECLhep_aida_IFilterEMethod;
    jmethodID createChainedOLjava_lang_StringELjava_lang_StringEAALhep_aida_ECLhep_aida_ITupleEMethod;
    jmethodID createFilteredOLjava_lang_StringELhep_aida_ITupleELhep_aida_IFilterEALjava_lang_StringECLhep_aida_ITupleEMethod;

    jclass intClass, shortClass, longClass, floatClass, doubleClass, booleanClass, byteClass, characterClass;
    jclass stringClass, objectClass, tupleClass;

protected:
    inline JITupleFactory() { };
    inline JITupleFactory(const JITupleFactory& r):JProxy(r) { };
    inline JITupleFactory& operator=(const JITupleFactory&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JITupleFactory(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JITupleFactory();

    /**
     * Creates an NTuple
     * @param name The persistency name of the n-tuple
     * @param title The title of the n-tuple
     * @param columnNames The names of the columns
     * @param columnType The types of  the columns
     * @param options NTuple options (currently undefined)
     *
     */
    JNIEXPORT virtual AIDA::ITuple * create(const std::string & name, const std::string & title, const std::vector<std::string>  & columnNames, const std::vector<std::string>  & columnType, const std::string & options);

    /**
     * Creates an NTuple
     * @param name The persistency name of the n-tuple
     * @param title The title of the n-tuple
     * @param columns The names and types of the columns e.g. "float px, py, pz, float energy, int charge"
     * @param options NTuple options (currently undefined)
     *
     */
    JNIEXPORT virtual AIDA::ITuple * create(const std::string & name, const std::string & title, const std::string & columns, const std::string & options);

    /**
     * Creates a logical chain of ITuples. All ITuples in the set must
     * have the same structure. Chained ITuple can not be filled.
     * Original n-tuple data is not copied.
     * @param name The persistency name of the new n-tuple
     * @param title The title of the new n-tuple
     * @param set The array of ITuples to chain
     *
     */
    JNIEXPORT virtual AIDA::ITuple * createChained(const std::string & name, const std::string & title, const std::vector<AIDA::ITuple *>  & set);

    /**
     * Creates a logical chain of ITuples. All ITuples in the set must
     * have the same structure. Chained ITuple can not be filled.
     * Original n-tuple data is not copied.
     * @param name  The persistency name of the new n-tuple
     * @param title The title of the new n-tuple
     * @param set   The array of the names of the ITuples to chain
     *
     */
    JNIEXPORT virtual AIDA::ITuple * createChained(const std::string & name, const std::string & title, const std::vector<std::string>  & set);

    /**
     * Creates a new reduced tuple (less rows) from an existing one
     * by applying a filter. Data is explicitly copied to a new n-tuple.
     * @param name  The persistency name of the new n-tuple
     * @param tuple Original n-tuple
     * @param filter IFilter to be used
     *
     */
    JNIEXPORT virtual AIDA::ITuple * createFiltered(const std::string & name, AIDA::ITuple & tuple, AIDA::IFilter & filter);

    /**
     * Creates a new reduced tuple (less rows) from an existing one
     * by applying a filter. Only subset of the variables (columns) is copied.
     * Data is explicitly copied to a new n-tuple.
     * @param name  The persistency name of the new n-tuple
     * @param tuple Original n-tuple
     * @param filter IFilter to be used
     * @param columns Names of columns to for a new n-tuple
     *
     */
    JNIEXPORT virtual AIDA::ITuple * createFiltered(const std::string & name, AIDA::ITuple & tuple, AIDA::IFilter & filter, const std::vector<std::string>  & columns);

    /**
     * Creates IFilter object given a string defining of the "cut" expression.
     * @param expression String defining of the "cut" expression.
     *
     */
    JNIEXPORT virtual AIDA::IFilter * createFilter(const std::string & expression);

    /**
     * Creates a filter object given a string defining the "cut" expression.
     * Filter processes only subset of data.
     * @param expression String defining of the "cut" expression.
     * @param rowsToProcess How many rows to process
     * @param startingRow Row number where to start
     *
     */
    JNIEXPORT virtual AIDA::IFilter * createFilter(const std::string & expression, int rowsToProcess, int startingRow);

    /**
     * Create IEvaluator object given its expression.
     * @param expression String defining of the evaluator expression.
     *
     */
    JNIEXPORT virtual AIDA::IEvaluator * createEvaluator(const std::string & expression);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JITUPLEFACTORY_H */
