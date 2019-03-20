// -*- C++ -*-
#ifndef JAIDA_JIPLOTTERREGION_H
#define JAIDA_JIPLOTTERREGION_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IBaseHistogram.h"
#include "AIDA/IDataPointSet.h"
#include "AIDA/IFunction.h"
#include "AIDA/IInfo.h"
#include "AIDA/IPlotterLayout.h"
#include "AIDA/IPlotterRegion.h"
#include "AIDA/IPlotterStyle.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * User level interface to a plotter region.
 * A region is managed by a plotter.
 * A region must be seen as a scene manager handling
 * a custome "plotting" scene. In general this kind of scene
 * may be in 2D or 3D. In 2D, the scene have "coarse graining parts"
 * like two axis, data representations within the axis. It may have
 * various other parts like a grid, a title, an info area. In 3D,
 * the scene have in general three axis,
 * a different global layout, some data representations within the
 * axis area and also scene parts like title, grid, etc...
 *
 *  To customize all these, some "style" interfaces had been introduced.
 * In general there is one style interface per "scene part" ; then
 * IAxisStyle, IDataStyle, ITitleStyle, IInfoStyle. Oftenly
 * a "scene part" contains text, line, fill area, etc.... For example
 * an "axis" have a line, ticks, text for tick labels, text for
 * the label of the axis, the magnitude, etc... A "coarse graining scene part"
 * style contains various accessor to "atomic" styles like IMarkerStyle,
 * ILineStyle, IFillStyle that permits to build a "customization block"
 * to modify a scene part.
 *
 *  A global style "block", the IPlotterStyle, could be retreived
 * from a plotting region. This global style block have accessors
 * to the various "coarse graining scene parts" of the plotting scene.
 * Through it, we hope to offer a lot of customization in a convenient
 * way...
 *
 *  The keywords "scene" and "part" had been borrowed from the
 * OpenInventor terminology.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIPlotterRegion: public JProxy, public virtual AIDA::IPlotterRegion {

private:
    jmethodID availableParameterOptionsOLjava_lang_StringECALjava_lang_StringEMethod;
    jmethodID plotOLhep_aida_IDataPointSetELhep_aida_IPlotterStyleELjava_lang_StringECVMethod;
    jmethodID availableParametersOCALjava_lang_StringEMethod;
    jmethodID plotOLhep_aida_IDataPointSetELjava_lang_StringECVMethod;
    jmethodID setParameterOLjava_lang_StringELjava_lang_StringECVMethod;
    jmethodID setStyleOLhep_aida_IPlotterStyleECVMethod;
    jmethodID removeOLhep_aida_IBaseHistogramECVMethod;
    jmethodID setLayoutOLhep_aida_IPlotterLayoutECVMethod;
    jmethodID removeOLhep_aida_IFunctionECVMethod;
    jmethodID setYLimitsODDCVMethod;
    jmethodID removeOLhep_aida_IDataPointSetECVMethod;
    jmethodID plotOLhep_aida_IBaseHistogramELjava_lang_StringECVMethod;
    jmethodID plotOLhep_aida_IFunctionELjava_lang_StringECVMethod;
    jmethodID styleOCLhep_aida_IPlotterStyleEMethod;
    jmethodID layoutOCLhep_aida_IPlotterLayoutEMethod;
    jmethodID setXLimitsODDCVMethod;
    jmethodID parameterValueOLjava_lang_StringECLjava_lang_StringEMethod;
    jmethodID applyStyleOLhep_aida_IPlotterStyleECVMethod;
    jmethodID infoOCLhep_aida_IInfoEMethod;
    jmethodID setTitleOLjava_lang_StringECVMethod;
    jmethodID setZLimitsODDCVMethod;
    jmethodID plotOLhep_aida_IFunctionELhep_aida_IPlotterStyleELjava_lang_StringECVMethod;
    jmethodID plotOLhep_aida_IBaseHistogramELhep_aida_IPlotterStyleELjava_lang_StringECVMethod;
    jmethodID clearOCVMethod;
    AIDA::IPlotterStyle* iPlotterStyle;
    AIDA::IPlotterLayout* iLayout;
    AIDA::IInfo* iInfo;

protected:
    inline JIPlotterRegion() { };
    inline JIPlotterRegion(const JIPlotterRegion& r):JProxy(r) { };
    inline JIPlotterRegion& operator=(const JIPlotterRegion&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIPlotterRegion(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIPlotterRegion();

  /**
   * Add a data analysis object (histogram, function, cloud,...)
   * in the list of things to plot in the region.
   * Activate the underlying graphic toolkit in order to bring
   * something in the screen window(s) attached to the plotter.
   * It assumes that the plotter had been mapped on the
   * screen with its show method.
   */
    JNIEXPORT virtual bool plot(const AIDA::IBaseHistogram & histogram, const std::string & options);

    JNIEXPORT virtual bool plot(const AIDA::IBaseHistogram & histogram, const AIDA::IPlotterStyle & style, const std::string & options);

    JNIEXPORT virtual bool plot(const AIDA::IFunction & function, const std::string & options);

    JNIEXPORT virtual bool plot(const AIDA::IFunction & function, const AIDA::IPlotterStyle & style, const std::string & options);

    JNIEXPORT virtual bool plot(const AIDA::IDataPointSet & dataPointSet, const std::string & options);

    JNIEXPORT virtual bool plot(const AIDA::IDataPointSet & dataPointSet, const AIDA::IPlotterStyle & style, const std::string & options);

  /**
   *  Remove a data analysis object in the list of things to plot in the region.
   *  Activate the graphic layer to update the screen window.
   */
    JNIEXPORT virtual bool remove(const AIDA::IBaseHistogram & histogram);

    JNIEXPORT virtual bool remove(const AIDA::IFunction & function);

    JNIEXPORT virtual bool remove(const AIDA::IDataPointSet & dataPointSet);

  /**
   * Clear the list of things to plot in the region.
   * Clear the corresponding area on screen window(s).
   */
    JNIEXPORT virtual void clear();

  /**
   * Set various plotting paramters for the region.
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

  /**
   * Get the style of the region.
   */
    JNIEXPORT virtual AIDA::IPlotterStyle & style();

  /**
   * Set the style of a region.
   */
    JNIEXPORT virtual bool setStyle(const AIDA::IPlotterStyle & style);

  /**
   * Set the style of a region and apply it to scene objects.
   */
    JNIEXPORT virtual bool applyStyle(const AIDA::IPlotterStyle & style);

  /**
   * Set the title of a region.
   */
    JNIEXPORT virtual void setTitle(const std::string & title);

  /**
   * Set limit of an axis representation the region area.
   */
    JNIEXPORT virtual bool setXLimits(double min, double max);

    JNIEXPORT virtual bool setYLimits(double min, double max);

    JNIEXPORT virtual bool setZLimits(double min, double max);

  /**
   * To customize axis position,etc...
   * Change object position in the scence.
   */
    JNIEXPORT virtual AIDA::IPlotterLayout & layout();

    JNIEXPORT virtual bool setLayout(const AIDA::IPlotterLayout & layout);

  /**
   * Return an IInfo object describing the info area.
   */
    JNIEXPORT virtual AIDA::IInfo & info();
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIPLOTTERREGION_H */
