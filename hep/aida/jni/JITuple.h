// -*- C++ -*-
#ifndef JAIDA_JITUPLE_H
#define JAIDA_JITUPLE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IAnnotation.h"
#include "AIDA/ICloud1D.h"
#include "AIDA/ICloud2D.h"
#include "AIDA/ICloud3D.h"
#include "AIDA/IEvaluator.h"
#include "AIDA/IFilter.h"
#include "AIDA/IHistogram1D.h"
#include "AIDA/IHistogram2D.h"
#include "AIDA/IHistogram3D.h"
#include "AIDA/IProfile1D.h"
#include "AIDA/IProfile2D.h"
#include "AIDA/ITuple.h"
#include "AIDA/ITupleEntry.h"

#include "JProxy.h"
#include "JIManagedObject.h"

namespace JAIDA {

/**
 * User level interface to a Tuple.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JITuple: public JProxy, public JIManagedObject, public virtual AIDA::ITupleEntry, public virtual AIDA::ITuple {

private:
    jmethodID columnMeanOICDMethod;
    jmethodID fillOADCVMethod;
    jmethodID projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID skipOICVMethod;
    jmethodID getBooleanOICZMethod;
    jmethodID getIntOICIMethod;
    jmethodID projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID findColumnOLjava_lang_StringECIMethod;
    jmethodID projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID startOCVMethod;
    jmethodID projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod;
    jmethodID projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod;
    jmethodID projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod;
    jmethodID projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod;
    jmethodID projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID fillOIJCVMethod;
    jmethodID getFloatOICFMethod;
    jmethodID getShortOICSMethod;
    jmethodID getCharOICCMethod;
    jmethodID getStringOICLjava_lang_StringEMethod;
    jmethodID columnsOCIMethod;
    jmethodID titleOCLjava_lang_StringEMethod;
    jmethodID projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod;
    jmethodID projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod;
    jmethodID columnMaxOICDMethod;
    jmethodID projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod;
    jmethodID fillOILhep_aida_ITupleEntryECVMethod;
    jmethodID fillOILjava_lang_StringECVMethod;
    jmethodID annotationOCLhep_aida_IAnnotationEMethod;
    jmethodID projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID fillOIICVMethod;
    jmethodID fillOISCVMethod;
    jmethodID projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod;
    jmethodID getTupleOICLhep_aida_ITupleEMethod;
    jmethodID projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID addRowOCVMethod;
    jmethodID columnNameOICLjava_lang_StringEMethod;
    jmethodID projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod;
    jmethodID projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorECVMethod;
    jmethodID fillOAFCVMethod;
    jmethodID getLongOICJMethod;
    jmethodID projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID resetOCVMethod;
    jmethodID projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod;
    jmethodID projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod;
    jmethodID resetRowOCVMethod;
    jmethodID columnMinOICDMethod;
    jmethodID projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID nextOCZMethod;
    jmethodID setTitleOLjava_lang_StringECVMethod;
    jmethodID columnRmsOICDMethod;
    jmethodID projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorECVMethod;
    jmethodID projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod;
    jmethodID projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID fillOIDCVMethod;
    jmethodID projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod;
    jmethodID setRowOICVMethod;
    jmethodID projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod;
    jmethodID getDoubleOICDMethod;
    jmethodID projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod;
    jmethodID columnTypeOICLhep_aida_StringClassEMethod;
    jmethodID fillOIZCVMethod;
    jmethodID fillOIFCVMethod;
    jmethodID getObjectOICLhep_aida_ITupleEntryEMethod;
    jmethodID rowsOCIMethod;
    jmethodID fillOICCVMethod;
    jmethodID projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod;
    jmethodID projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod;
    jmethodID columnNamesOCALjava_lang_StringEMethod;
    jmethodID columnTypesOCALjava_lang_ClassEMethod;
    
    std::string emptyString;
    AIDA::IAnnotation* iAnnotation;

protected:
    inline JITuple() { };
    inline JITuple(const JITuple& r):JProxy(r), JIManagedObject(r) { };
    inline JITuple& operator=(const JITuple&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JITuple(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JITuple();

    /**
     * Get the title of this ITuple.
     * @return The ITuple's title.
     *
     */
    JNIEXPORT virtual std::string title() const;

    /**
     * Set the title of the ITuple.
     * @param title The new ITuple's title.
     * @return false If title cannot be changed.
     *
     */
    JNIEXPORT virtual bool setTitle(const std::string & title);

    /**
     * Get the IAnnotation corresponding to this ITuple.
     * @return The ITuple's IAnnotation.
     *
     */
    JNIEXPORT virtual AIDA::IAnnotation & annotation();

    JNIEXPORT virtual const AIDA::IAnnotation & annotation() const;

    /**
     * Fill a given column with a double.
     * @param column The column's index within the ITuple.
     * @param value  The double.
     * @return false If the column is of the wrong type.
     *
     */
    JNIEXPORT virtual bool fill(int column, double value);

    /**
     * Fill a given column with a float.
     * @param column The column's index within the ITuple.
     * @param value  The float.
     * @return false If the column is of the wrong type.
     *
     */
    JNIEXPORT virtual bool fill(int column, float value);

    /**
     * Fill a given column with an integer.
     * @param column The column's index within the ITuple.
     * @param value  The integer.
     * @return false If the column is of the wrong type.
     *
     */
    JNIEXPORT virtual bool fill(int column, int value);

    /**
     * Fill a given column with a short.
     * @param column The column's index within the ITuple.
     * @param value  The short.
     * @return false If the column is of the wrong type.
     *
     */
    JNIEXPORT virtual bool fill(int column, short value);

    /**
     * Fill a given column with a long.
     * @param column The column's index within the ITuple.
     * @param value  The long.
     * @return false If the column is of the wrong type.
     *
     */
    JNIEXPORT virtual bool fill(int column, long value);

    /**
     * Fill a given column with a char.
     * @param column The column's index within the ITuple.
     * @param value  The char.
     * @return false If the column is of the wrong type.
     *
     */
    JNIEXPORT virtual bool fill(int column, char value);

    /**
     * Fill a given column with a boolean.
     * @param column The column's index within the ITuple.
     * @param value  The boolean.
     * @return false If the column is of the wrong type.
     *
     */
    JNIEXPORT virtual bool fill(int column, bool value);

    /**
     * Fill a given column with a string.
     * @param column The column's index within the ITuple.
     * @param value  The string.
     * @return false If the column is of the wrong type.
     *
     */
    JNIEXPORT virtual bool fill(int column, const std::string & value);

    /**
     * Fill a given column with an object.
     * @param column The column's index within the ITuple.
     * @param value  The object.
     * @return false If the column is of the wrong type.
     *
     */
    JNIEXPORT virtual bool fill(int column, const AIDA::ITupleEntry & value);

    /**
     * Fill all the columns at once with doubles.
     * @param values The array of doubles.
     * @return false If any column is not of type double or if
     *               the array has the wrong dimension.
     *
     */
    JNIEXPORT virtual bool fill(const std::vector<double>  & values);

    /**
     * Fill all the columns at once with floats.
     * @param values The array of floats.
     * @return false If any column is not of type float or if
     *               the array has the wrong dimension.
     *
     */
    JNIEXPORT virtual bool fill(const std::vector<float>  & values);

    /**
     * Add the current row to the ITuple. This method should be called after
     * fill has been called for the columns; unfilled columns will be filled
     * with their default value.
     * @return false When the ITuple runs out of storage space.
     *
     */
    JNIEXPORT virtual bool addRow();

    /**
     * Clear the current(not yet added) row.
     *
     */
    JNIEXPORT virtual void resetRow();

    /**
     * Reset the ITuple. All the rows are reset.
     * The ITuple is as just created.
     *
     */
    JNIEXPORT virtual void reset();

    /**
     * Get the number of rows currently filled in the ITuple.
     * @return The number of rows. -1 if empty or if it cannot be determined.
     *
     */
    JNIEXPORT virtual int rows() const;

    /**
     * Positions the read cursor immediately before the first row.
     *
     */
    JNIEXPORT virtual void start();

    /**
     * Skips a given number of rows.
     * @param rows The number of rows to skip.
     * @return false If rows is less than zero or
     *             if it is not possible to perform the jump.
     *
     */
    JNIEXPORT virtual bool skip(int rows);

    /**
     * Positions the cursor at the next row.
     * @return false if there is no next row.
     *
     */
    JNIEXPORT virtual bool next();

    /**
     * Position the cursor at a give row.
     * @param rowIndex The row where the cursor has to be positioned.
     * @return false If the cursor cannot be positioned
     *                 at the give row.
     *
     */
    JNIEXPORT virtual bool setRow(int rowIndex);

    /**
     * Get the index within the ITuple of a given column.
     * @param name The colum's name.
     * @return The corresponding column's index. Note: in C++ -1 may
     *         be returned if the column does not exist.
     */
    JNIEXPORT virtual int findColumn(const std::string & name) const;

    /**
     * Get the double stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The double.
     *
     */
    JNIEXPORT virtual double getDouble(int column) const;

    /**
     * Get the float stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The float.
     *
     */
    JNIEXPORT virtual float getFloat(int column) const;

    /**
     * Get the integer stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The integer.
     *
     */
    JNIEXPORT virtual int getInt(int column) const;

    /**
     * Get the short stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The short.
     *
     */
    JNIEXPORT virtual short getShort(int column) const;

    /**
     * Get the long stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The long.
     *
     */
    JNIEXPORT virtual long getLong(int column) const;

    /**
     * Get the character stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The character.
     *
     */
    JNIEXPORT virtual char getChar(int column) const;

    /**
     * Get the boolean stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The boolean.
     *
     */
    JNIEXPORT virtual bool getBoolean(int column) const;

    /**
     * Get the string stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The string.
     *
     */
    JNIEXPORT virtual std::string getString(int column) const;

    /**
     * Get the object stored in a given column at the current cursor's position.
     * @param column The column's index within the ITuple.
     * @return       The object.
     *
     */
    JNIEXPORT virtual const AIDA::ITupleEntry * getObject(int column) const;

    /**
     * Return method for tuple variables of type ITuple for a given column.
     * This method can be used in order to fill a tuple variable in the master tuple.
     * @param column The column's index.
     * @return       The ITuple representing the structure of this column.
     *
     */
    JNIEXPORT virtual const AIDA::ITuple * getTuple(int column) const;

    JNIEXPORT virtual AIDA::ITuple * getTuple(int column);

   /**
    * Get the number of columns in the ITuple
    * @return The number of columns.
    *
    */
    JNIEXPORT virtual int columns() const;

   /**
    * Get the name of a column from its index.
    * @param column The column's index.
    * @return       The column's name.
    *
    */
    JNIEXPORT virtual std::string columnName(int column) const;

   /** 
    * Get the names of all the columns.
    * @return  The column names.
    *
    */
    JNIEXPORT virtual std::vector<std::string> columnNames() const;

   /**
    * Get the type of a give column.
    * @param column The column's type.
    * @return       The column's Class.
    *
    */
    JNIEXPORT virtual std::string columnType(int column) const;

   /** 
    * Get the types of all the columns.
    * @return  The column Classes.
    *
    */
    JNIEXPORT virtual std::vector<std::string>  columnTypes() const;

   /**
    * Get the minimum value of a given column (if it can be converted to a double).
    * @param column The column's index.
    * @return       The column's minimum value. In Java Double.NaN might be returned.
    *
    */
    JNIEXPORT virtual double columnMin(int column) const;

   /**
    * Get the maximum value of a given column (if it can be converted to a double).
    * @param column The column's index.
    * @return       The column's maximum value. In Java Double.NaN might be returned.
    *
    */
    JNIEXPORT virtual double columnMax(int column) const;

   /**
    * Get the mean value of a given column (if it can be converted to a double).
    * @param column The column's index.
    * @return       The column's mean value. In Java Double.NaN might be returned.
    *
    */
    JNIEXPORT virtual double columnMean(int column) const;

   /**
    * Get the RMS of a given column (if it can be converted to a double).
    * @param column The column's index.
    * @return       The column's RMS. In Java Double.NaN might be returned.
    *
    */
    JNIEXPORT virtual double columnRms(int column) const;

    /**
     * Fill an IHistogram1D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram. The value is computed
     *                   from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IHistogram1D & histogram, AIDA::IEvaluator & evaluatorX);

    /**
     * Fill an IHistogram1D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram. The value is computed
     *                   from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the histogram is not filled.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IHistogram1D & histogram, AIDA::IEvaluator & evaluatorX, AIDA::IFilter & filter);

    /**
     * Fill an IHistogram1D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram. The value is computed
     *                   from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IHistogram1D & histogram, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & weight);

    /**
     * Fill an IHistogram1D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram. The value is computed
     *                   from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the histogram is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IHistogram1D & histogram, AIDA::IEvaluator & evaluatorX, AIDA::IFilter & filter, AIDA::IEvaluator & weight);

    /**
     * Fill an IHistogram2D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IHistogram2D & histogram, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY);

    /**
     * Fill an IHistogram2D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the histogram is not filled.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IHistogram2D & histogram, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IFilter & filter);

    /**
     * Fill an IHistogram2D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IHistogram2D & histogram, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & weight);

    /**
     * Fill an IHistogram2D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the histogram is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IHistogram2D & histogram, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IFilter & filter, AIDA::IEvaluator & weight);

    /**
     * Fill an IHistogram3D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the histogram along the z axis.
     *                   The value is computed from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IHistogram3D & histogram, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & evaluatorZ);

    /**
     * Fill an IHistogram3D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the histogram along the z axis.
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the histogram is not filled.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IHistogram3D & histogram, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & evaluatorZ, AIDA::IFilter & filter);

    /**
     * Fill an IHistogram3D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the histogram along the z axis.
     *                   The value is computed from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IHistogram3D & histogram, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & evaluatorZ, AIDA::IEvaluator & weight);

    /**
     * Fill an IHistogram3D from the tuple.
     * @param histogram  The histogram to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the histogram along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the histogram along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the histogram along the z axis.
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the histogram is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IHistogram3D & histogram, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & evaluatorZ, AIDA::IFilter & filter, AIDA::IEvaluator & weight);

    /**
     * Fill an ICloud1D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud. The value is computed
     *                   from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::ICloud1D & cloud, AIDA::IEvaluator & evaluatorX);

    /**
     * Fill an ICloud1D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud. The value is computed
     *                   from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the cloud is not filled.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::ICloud1D & cloud, AIDA::IEvaluator & evaluatorX, AIDA::IFilter & filter);

    /**
     * Fill an ICloud1D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud. The value is computed
     *                   from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::ICloud1D & cloud, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & weight);

    /**
     * Fill an ICloud1D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud. The value is computed
     *                   from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the cloud is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::ICloud1D & cloud, AIDA::IEvaluator & evaluatorX, AIDA::IFilter & filter, AIDA::IEvaluator & weight);

    /**
     * Fill an ICloud2D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::ICloud2D & cloud, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY);

    /**
     * Fill an ICloud2D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the cloud is not filled.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::ICloud2D & cloud, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IFilter & filter);

    /**
     * Fill an ICloud2D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::ICloud2D & cloud, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & weight);

    /**
     * Fill an ICloud2D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the cloud is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::ICloud2D & cloud, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IFilter & filter, AIDA::IEvaluator & weight);

    /**
     * Fill an ICloud3D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the cloud along the z axis.
     *                   The value is computed from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::ICloud3D & cloud, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & evaluatorZ);

    /**
     * Fill an ICloud3D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the cloud along the z axis.
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the cloud is not filled.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::ICloud3D & cloud, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & evaluatorZ, AIDA::IFilter & filter);

    /**
     * Fill an ICloud3D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the cloud along the z axis.
     *                   The value is computed from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::ICloud3D & cloud, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & evaluatorZ, AIDA::IEvaluator & weight);

    /**
     * Fill an ICloud3D from the tuple.
     * @param cloud      The cloud to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the cloud along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the cloud along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the cloud along the z axis.
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the cloud is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::ICloud3D & cloud, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & evaluatorZ, AIDA::IFilter & filter, AIDA::IEvaluator & weight);

    /**
     * Fill an IProfile1D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IProfile1D & profile, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY);

    /**
     * Fill an IProfile1D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the profile is not filled.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IProfile1D & profile, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IFilter & filter);

    /**
     * Fill an IProfile1D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IProfile1D & profile, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & weight);

    /**
     * Fill an IProfile1D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the profile is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IProfile1D & profile, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IFilter & filter, AIDA::IEvaluator & weight);

    /**
     * Fill an IProfile2D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the profile along the z axis.
     *                   The value is computed from the current row of the tuple.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IProfile2D & profile, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & evaluatorZ);

    /**
     * Fill an IProfile2D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the profile along the z axis.
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the profile is not filled.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IProfile2D & profile, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & evaluatorZ, AIDA::IFilter & filter);

    /**
     * Fill an IProfile2D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the profile along the z axis.
     *                   The value is computed from the current row of the tuple.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IProfile2D & profile, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & evaluatorZ, AIDA::IEvaluator & weight);

    /**
     * Fill an IProfile2D from the tuple.
     * @param profile    The profile to fill.
     * @param evaluatorX The evaluator used to compute the value
     *                   to be filled in the profile along the x axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorY The evaluator used to compute the value
     *                   to be filled in the profile along the y axis.
     *                   The value is computed from the current row of the tuple.
     * @param evaluatorZ The evaluator used to compute the value
     *                   to be filled in the profile along the z axis.
     *                   The value is computed from the current row of the tuple.
     * @param filter     The filter object used to accept or not the current row.
     *                   If rejected, the profile is not filled.
     * @param weight     The evaluator which determines the weight which is used during the filling.
     * @return false If something goes wrong.
     *
     */
    JNIEXPORT virtual bool project(AIDA::IProfile2D & profile, AIDA::IEvaluator & evaluatorX, AIDA::IEvaluator & evaluatorY, AIDA::IEvaluator & evaluatorZ, AIDA::IFilter & filter, AIDA::IEvaluator & weight);

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
    JNIEXPORT virtual void * cast(const std::string & className) const;


}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JITUPLE_H */



