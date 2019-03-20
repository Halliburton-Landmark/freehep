// -*- C++ -*-
#ifndef JAIDA_JIPLOTTER_H
#define JAIDA_JIPLOTTER_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IPlotter.h"
#include "AIDA/IPlotterRegion.h"
#include "AIDA/ITitleStyle.h"

#include "JProxy.h"

namespace JAIDA {

/**
 *  User level interface to plotter.
 *
 * This IPlotter interface assumes the handling of
 * multiple plotting regions. Then the IPlotter should
 * be seen as a "page" managing multiple drawing region.
 * It assumes that a "current" region mechanism is used.
 *
 *  The keyword "region" is borrowed from the OpenInventor
 * terminology (viewing region).
 *
 *  See also the IPlotterRegion for more comments.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIPlotter: public JProxy, public virtual AIDA::IPlotter {

private:
    jmethodID availableParameterOptionsOLjava_lang_StringECALjava_lang_StringEMethod;
    jmethodID currentRegionOCLhep_aida_IPlotterRegionEMethod;
    jmethodID availableParametersOCALjava_lang_StringEMethod;
    jmethodID titleStyleOCLhep_aida_ITitleStyleEMethod;
    jmethodID createRegionsOIIICVMethod;
    jmethodID setParameterOLjava_lang_StringELjava_lang_StringECVMethod;
    jmethodID createRegionODDDDCLhep_aida_IPlotterRegionEMethod;
    jmethodID setTitleStyleOLhep_aida_ITitleStyleECVMethod;
    jmethodID setCurrentRegionNumberOICVMethod;
    jmethodID regionOICLhep_aida_IPlotterRegionEMethod;
    jmethodID clearRegionsOCVMethod;
    jmethodID nextOCLhep_aida_IPlotterRegionEMethod;
    jmethodID hideOCVMethod;
    jmethodID destroyRegionsOCVMethod;
    jmethodID parameterValueOLjava_lang_StringECLjava_lang_StringEMethod;
    jmethodID showOCVMethod;
    jmethodID setTitleOLjava_lang_StringECVMethod;
    jmethodID writeToFileOLjava_lang_StringELjava_lang_StringECVMethod;
    jmethodID numberOfRegionsOCIMethod;
    jmethodID currentRegionNumberOCIMethod;
    jmethodID refreshOCVMethod;
    jmethodID interactOCVMethod;
    AIDA::ITitleStyle* iTitleStyle;

protected:
    inline JIPlotter() { };
    inline JIPlotter(const JIPlotter& r):JProxy(r) { };
    inline JIPlotter& operator=(const JIPlotter&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIPlotter(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIPlotter();

  /**
   * Region management methods.
   */

  /**
   * Create a new region.
   * @param x, y, w, h Position and size in normal coordinates
   *                   that is to say between 0 and 1.
   *                   Then a region with (x=0,y=0,w=1,h=1) maps
   *                   the full page. "x" goes left to right. "y" bottom
   *                   to top.
   * @return The newly created region. Return null in case not failure.
   *         Note that the plotter manages the regions ; user does not
   *         have to delete a region object directly.
   */
    JNIEXPORT virtual AIDA::IPlotterRegion * createRegion(double x, double y, double w, double h);

  /**
   * Create a grid of regions.
   * By default the current region is the top left one (with index 0).
   * Region are indexed from zero, with increasing order
   * left to right, top to bottom.
   * @param index Set the current region.
   */
    JNIEXPORT virtual bool createRegions(int columns, int rows, int index);

  /**
   * @return The current region.
   */
    JNIEXPORT virtual AIDA::IPlotterRegion & currentRegion() const;

  /**
   * @return The current region index.
   */
    JNIEXPORT virtual int currentRegionNumber() const;

  /**
   * @return The number of regions.
   */
    JNIEXPORT virtual int numberOfRegions() const;

  /**
   * Set current region by giving its index [0,n-1]
   */
    JNIEXPORT virtual bool setCurrentRegionNumber(int index);

  /**
   * Set current region to be the "next" one.
   * If exceeding the number of regions,
   * the current region index return to 0.
   * @return The new current region.
   */
    JNIEXPORT virtual AIDA::IPlotterRegion & next();

  /**
   * @return A region, knowing its index.
   */
    JNIEXPORT virtual AIDA::IPlotterRegion * region(int index) const;

  /**
   *  Destroy regions.
   */
    JNIEXPORT virtual void destroyRegions();

  /**
   * Clear all regions. It does not reset the number
   * and position of regions. This can be done through
   * a destroyRegions.
   */
    JNIEXPORT virtual void clearRegions();

  /*
   * Set various plotting paramters for the whole page.
   * Activate the graphic layer and update the screen window(s)
   * if needed.
   */
    JNIEXPORT virtual bool setParameter(const std::string & parameter, const std::string & options);

  /**
   * Get value of a parameter.
   * @param paramName Name of the parameter.
   * @return the value.
   */
    JNIEXPORT virtual std::string parameterValue(const std::string & parameter) const;

    JNIEXPORT virtual std::vector<std::string>  availableParameterOptions(const std::string & parameter) const;

    JNIEXPORT virtual std::vector<std::string>  availableParameters() const;

  /*
   * GUI related methods :
   */

  /**
   * Map the plotter on the screen.
   */
    JNIEXPORT virtual bool show();

  /**
   * Refresh the screen window(s).
   * Used when a plotted data analysis object
   * received new data.
   */
    JNIEXPORT virtual bool refresh();

  /**
   * Unmap the plotter on the screen.
   */
    JNIEXPORT virtual bool hide();

  /**
   * Give control to the plotter GUI. The plotter must be able
   * to return from this function from a user action in its GUI.
   */
    JNIEXPORT virtual bool interact();

  /*
   * Other methods.
   */

  /**
   * Produce an output file.
   * @param type  A string to describe the type of the output :
   *  "PS"  or "PostScript" for PostScript, "JPEG" for JPEG.
   *  If nothing is given, the type is guessed
   *  from the given file name suffix (.ps for PostScript,
   *  .jpg for JPEG, etc...).
   */
    JNIEXPORT virtual bool writeToFile(const std::string & filename, const std::string & type);

  /**
   * Set the global title of the plotter (page).
   */
    JNIEXPORT virtual void setTitle(const std::string & title);

  /**
   * Get/set title style.
   */
    JNIEXPORT virtual AIDA::ITitleStyle & titleStyle();

    JNIEXPORT virtual void setTitleStyle(const AIDA::ITitleStyle & style);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIPLOTTER_H */
