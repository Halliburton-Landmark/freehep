// -*- C++ -*-
#ifndef JAIDA_JIHISTOGRAMFACTORY_H
#define JAIDA_JIHISTOGRAMFACTORY_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IBaseHistogram.h"
#include "AIDA/ICloud1D.h"
#include "AIDA/ICloud2D.h"
#include "AIDA/ICloud3D.h"
#include "AIDA/IHistogram1D.h"
#include "AIDA/IHistogram2D.h"
#include "AIDA/IHistogram3D.h"
#include "AIDA/IHistogramFactory.h"
#include "AIDA/IProfile1D.h"
#include "AIDA/IProfile2D.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * User level interface for factory classes of Histograms (binned, unbinned, and profile)
 * The created objects are assumed to be managed by the tree which is associated to the factory.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIHistogramFactory: public JProxy, public virtual AIDA::IHistogramFactory {

private:
    jmethodID projectionYOLjava_lang_StringELhep_aida_IHistogram2DECLhep_aida_IHistogram1DEMethod;
    jmethodID createProfile2DOLjava_lang_StringEIDDIDDCLhep_aida_IProfile2DEMethod;
    jmethodID addOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod;
    jmethodID createProfile1DOLjava_lang_StringELjava_lang_StringEADLjava_lang_StringECLhep_aida_IProfile1DEMethod;
    jmethodID createProfile2DOLjava_lang_StringELjava_lang_StringEIDDIDDDDLjava_lang_StringECLhep_aida_IProfile2DEMethod;
    jmethodID projectionXZOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram2DEMethod;
    jmethodID createProfile2DOLjava_lang_StringEIDDIDDDDCLhep_aida_IProfile2DEMethod;
    jmethodID createProfile2DOLjava_lang_StringELjava_lang_StringEADADDDLjava_lang_StringECLhep_aida_IProfile2DEMethod;
    jmethodID createCopyOLjava_lang_StringELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod;
    jmethodID createHistogram1DOLjava_lang_StringELjava_lang_StringEADLjava_lang_StringECLhep_aida_IHistogram1DEMethod;
    jmethodID projectionYZOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram2DEMethod;
    jmethodID divideOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod;
    jmethodID sliceXOLjava_lang_StringELhep_aida_IHistogram2DEIICLhep_aida_IHistogram1DEMethod;
    jmethodID addOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod;
    jmethodID subtractOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod;
    jmethodID createCopyOLjava_lang_StringELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod;
    jmethodID createCopyOLjava_lang_StringELhep_aida_IProfile1DECLhep_aida_IProfile1DEMethod;
    jmethodID createHistogram2DOLjava_lang_StringEIDDIDDCLhep_aida_IHistogram2DEMethod;
    jmethodID divideOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod;
    jmethodID createCopyOLjava_lang_StringELhep_aida_ICloud3DECLhep_aida_ICloud3DEMethod;
    jmethodID createHistogram3DOLjava_lang_StringELjava_lang_StringEADADADLjava_lang_StringECLhep_aida_IHistogram3DEMethod;
    jmethodID createHistogram3DOLjava_lang_StringEIDDIDDIDDCLhep_aida_IHistogram3DEMethod;
    jmethodID multiplyOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod;
    jmethodID createCopyOLjava_lang_StringELhep_aida_ICloud2DECLhep_aida_ICloud2DEMethod;
    jmethodID createProfile1DOLjava_lang_StringEIDDDDCLhep_aida_IProfile1DEMethod;
    jmethodID projectionXYOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram2DEMethod;
    jmethodID subtractOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod;
    jmethodID createProfile1DOLjava_lang_StringELjava_lang_StringEADDDLjava_lang_StringECLhep_aida_IProfile1DEMethod;
    jmethodID createHistogram2DOLjava_lang_StringELjava_lang_StringEADADLjava_lang_StringECLhep_aida_IHistogram2DEMethod;
    jmethodID sliceXZOLjava_lang_StringELhep_aida_IHistogram3DEIICLhep_aida_IHistogram2DEMethod;
    jmethodID createCopyOLjava_lang_StringELhep_aida_ICloud1DECLhep_aida_ICloud1DEMethod;
    jmethodID createProfile1DOLjava_lang_StringEIDDCLhep_aida_IProfile1DEMethod;
    jmethodID sliceYZOLjava_lang_StringELhep_aida_IHistogram3DEIICLhep_aida_IHistogram2DEMethod;
    jmethodID destroyOLhep_aida_IBaseHistogramECVMethod;
    jmethodID createCloud1DOLjava_lang_StringELjava_lang_StringEILjava_lang_StringECLhep_aida_ICloud1DEMethod;
    jmethodID createHistogram3DOLjava_lang_StringELjava_lang_StringEIDDIDDIDDLjava_lang_StringECLhep_aida_IHistogram3DEMethod;
    jmethodID createCloud3DOLjava_lang_StringELjava_lang_StringEILjava_lang_StringECLhep_aida_ICloud3DEMethod;
    jmethodID createCloud3DOLjava_lang_StringECLhep_aida_ICloud3DEMethod;
    jmethodID createCloud1DOLjava_lang_StringECLhep_aida_ICloud1DEMethod;
    jmethodID createProfile1DOLjava_lang_StringELjava_lang_StringEIDDDDLjava_lang_StringECLhep_aida_IProfile1DEMethod;
    jmethodID divideOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod;
    jmethodID sliceXOLjava_lang_StringELhep_aida_IHistogram2DEICLhep_aida_IHistogram1DEMethod;
    jmethodID sliceYOLjava_lang_StringELhep_aida_IHistogram2DEIICLhep_aida_IHistogram1DEMethod;
    jmethodID createProfile1DOLjava_lang_StringELjava_lang_StringEIDDLjava_lang_StringECLhep_aida_IProfile1DEMethod;
    jmethodID subtractOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod;
    jmethodID sliceXYOLjava_lang_StringELhep_aida_IHistogram3DEIICLhep_aida_IHistogram2DEMethod;
    jmethodID createHistogram1DOLjava_lang_StringEIDDCLhep_aida_IHistogram1DEMethod;
    jmethodID sliceYOLjava_lang_StringELhep_aida_IHistogram2DEICLhep_aida_IHistogram1DEMethod;
    jmethodID createProfile2DOLjava_lang_StringELjava_lang_StringEADADLjava_lang_StringECLhep_aida_IProfile2DEMethod;
    jmethodID createCloud2DOLjava_lang_StringELjava_lang_StringEILjava_lang_StringECLhep_aida_ICloud2DEMethod;
    jmethodID createCopyOLjava_lang_StringELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod;
    jmethodID createProfile2DOLjava_lang_StringELjava_lang_StringEIDDIDDLjava_lang_StringECLhep_aida_IProfile2DEMethod;
    jmethodID multiplyOLjava_lang_StringELhep_aida_IHistogram2DELhep_aida_IHistogram2DECLhep_aida_IHistogram2DEMethod;
    jmethodID createHistogram2DOLjava_lang_StringELjava_lang_StringEIDDIDDLjava_lang_StringECLhep_aida_IHistogram2DEMethod;
    jmethodID projectionXOLjava_lang_StringELhep_aida_IHistogram2DECLhep_aida_IHistogram1DEMethod;
    jmethodID createCopyOLjava_lang_StringELhep_aida_IProfile2DECLhep_aida_IProfile2DEMethod;
    jmethodID addOLjava_lang_StringELhep_aida_IHistogram3DELhep_aida_IHistogram3DECLhep_aida_IHistogram3DEMethod;
    jmethodID createCloud2DOLjava_lang_StringECLhep_aida_ICloud2DEMethod;
    jmethodID multiplyOLjava_lang_StringELhep_aida_IHistogram1DELhep_aida_IHistogram1DECLhep_aida_IHistogram1DEMethod;
    jmethodID createHistogram1DOLjava_lang_StringELjava_lang_StringEIDDLjava_lang_StringECLhep_aida_IHistogram1DEMethod;

protected:
    inline JIHistogramFactory() { };
    inline JIHistogramFactory(const JIHistogramFactory& r):JProxy(r) { };
    inline JIHistogramFactory& operator=(const JIHistogramFactory&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIHistogramFactory(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIHistogramFactory();

    /**
     * Destroy an IBaseHistogram ogject.
     * @param hist The IBaseHistogram to be destroyed.
     * @return false If the histogram cannot be destroyed.
     *
     */
    JNIEXPORT virtual bool destroy(AIDA::IBaseHistogram * hist);

    /**
     * Create a ICloud1D, an unbinned 1-dimensioal histogram.
     * @param name    The name of the ICloud1D.
     * @param title   The title of the ICloud1D.
     * @param nMax    The maximum number of entries after which the ICloud1D
     *                will convert to an IHistogram1D. The default nMax = -1
     *                indicates no limit of entries before aoutoconversion to a IHistogram1D.
     * @param options The options for the ICloud1D. "autoconvert=true" to enable autoconversion
     *                to an IHistogram1D.
     * @return        The newly created ICloud1D.
     *
     */
    JNIEXPORT virtual AIDA::ICloud1D * createCloud1D(const std::string & name, const std::string & title, int nMax, const std::string & options);

    /**
     * Create a ICloud1D, an unbinned 1-dimensional histogram.
     * @param nameAndTitle The name of the ICloud1D; it is also its title.
     * @return             The newly created ICloud1D.
     *
     */
    JNIEXPORT virtual AIDA::ICloud1D * createCloud1D(const std::string & nameAndTitle);

    /**
     * Create a copy of an ICloud1D.
     * @param name  The name of the new copy.
     * @param cloud The ICloud1D to be copied.
     * @return      The copy of the ICloud1D.
     *
     */
    JNIEXPORT virtual AIDA::ICloud1D * createCopy(const std::string & name, const AIDA::ICloud1D & cloud);

    /**
     * Create a ICloud2D, an unbinned 2-dimensional histogram.
     * @param name    The name of the ICloud2D.
     * @param title   The title of the ICloud2D.
     * @param nMax    The maximum number of entries after which the ICloud2D
     *                will convert to an IHistogram2D. The default nMax = -1
     *                indicates no limit of entries before aoutoconversion to a IHistogram2D.
     * @param options The options for the ICloud2D. "autoconvert=true" to enable autoconversion
     *                to an IHistogram2D.
     * @return        The newly created ICloud2D.
     *
     */
    JNIEXPORT virtual AIDA::ICloud2D * createCloud2D(const std::string & name, const std::string & title, int nMax, const std::string & options);

    /**
     * Create a ICloud2D, an unbinned 2-dimensional histogram.
     * @param nameAndTitle The name of the ICloud2D; it is also its title.
     * @return             The newly created ICloud2D.
     *
     */
    JNIEXPORT virtual AIDA::ICloud2D * createCloud2D(const std::string & nameAndTitle);

    /**
     * Create a copy of an ICloud2D.
     * @param name  The name of the new copy.
     * @param cloud The ICloud2D to be copied.
     * @return      The copy of the ICloud2D.
     *
     */
    JNIEXPORT virtual AIDA::ICloud2D * createCopy(const std::string & name, const AIDA::ICloud2D & cloud);

    /**
     * Create a ICloud3D, an unbinned 3-dimensional histogram.
     * @param name    The name of the ICloud3D.
     * @param title   The title of the ICloud3D.
     * @param nMax    The maximum number of entries after which the ICloud3D
     *                will convert to an IHistogram3D. The default nMax = -1
     *                indicates no limit of entries before aoutoconversion to a IHistogram3D.
     * @param options The options for the ICloud3D. "autoconvert=true" to enable autoconversion
     *                to an IHistogram3D.
     * @return        The newly created ICloud3D.
     *
     */
    JNIEXPORT virtual AIDA::ICloud3D * createCloud3D(const std::string & name, const std::string & title, int nMax, const std::string & options);

    /**
     * Create a ICloud3D, an unbinned 3-dimensional histogram.
     * @param nameAndTitle The name of the ICloud3D; it is also its title.
     * @return             The newly created ICloud3D.
     *
     */
    JNIEXPORT virtual AIDA::ICloud3D * createCloud3D(const std::string & nameAndTitle);

    /**
     * Create a copy of an ICloud3D.
     * @param name  The name of the new copy.
     * @param cloud The ICloud3D to be copied.
     * @return      The copy of the ICloud3D.
     *
     */
    JNIEXPORT virtual AIDA::ICloud3D * createCopy(const std::string & name, const AIDA::ICloud3D & cloud);

    /**
     * Create a IHistogram1D.
     * @param name      The name of the IHistogram1D.
     * @param title     The title of the IHistogram1D.
     * @param nBins     The number of bins of the x axis.
     * @param lowerEdge The lower edge of the x axis.
     * @param upperEdge The upper edge of the x axis.
     * @param options   The options for the IHistogram1D. The default is "".
     *                  "type=efficiency" for an efficiency IHistogram1D.
     * @return          The newly created IHistogram1D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * createHistogram1D(const std::string & name, const std::string & title, int nBins, double lowerEdge, double upperEdge, const std::string & options);

    /**
     * Create a IHistogram1D.
     * @param nameAndTitle The name of the IHistogram1D; it is also the title.
     * @param nBins        The number of bins of the x axis.
     * @param lowerEdge    The lower edge of the x axis.
     * @param upperEdge    The upper edge of the x axis.
     * @return             The newly created IHistogram1D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * createHistogram1D(const std::string & nameAndTitle, int nBins, double lowerEdge, double upperEdge);

    /**
     * Create a IHistogram1D.
     * @param name      The name of the IHistogram1D.
     * @param title     The title of the IHistogram1D.
     * @param binEdges  The array of the bin edges for the x axis.
     * @param options   The options for the IHistogram1D. The default is "".
     *                  "type=efficiency" for an efficiency IHistogram1D.
     * @return          The newly created IHistogram1D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * createHistogram1D(const std::string & name, const std::string & title, const std::vector<double>  & binEdges, const std::string & options);

    /**
     * Create a copy of an IHistogram1D.
     * @param name The name of the new copy.
     * @param hist The IHistogram1D to be copied.
     * @return     The copy of the IHistogram1D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * createCopy(const std::string & name, const AIDA::IHistogram1D & hist);

    /**
     * Create a IHistogram2D.
     * @param name       The name of the IHistogram2D.
     * @param title      The title of the IHistogram2D.
     * @param nBinsX     The number of bins of the x axis.
     * @param lowerEdgeX The lower edge of the x axis.
     * @param upperEdgeX The upper edge of the x axis.
     * @param nBinsY     The number of bins of the y axis.
     * @param lowerEdgeY The lower edge of the y axis.
     * @param upperEdgeY The upper edge of the y axis.
     * @param options    The options for the IHistogram2D. The default is "".
     *                   "type=efficiency" for an efficiency IHistogram2D.
     * @return           The newly created IHistogram2D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * createHistogram2D(const std::string & name, const std::string & title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, const std::string & options);

    /**
     * Create a IHistogram2D.
     * @param nameAndTitle The name of the IHistogram2D; it is also the title.
     * @param nBinsX       The number of bins of the x axis.
     * @param lowerEdgeX   The lower edge of the x axis.
     * @param upperEdgeX   The upper edge of the x axis.
     * @param nBinsY       The number of bins of the y axis.
     * @param lowerEdgeY   The lower edge of the y axis.
     * @param upperEdgeY   The upper edge of the y axis.
     * @return             The newly created IHistogram2D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * createHistogram2D(const std::string & nameAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY);

    /**
     * Create a IHistogram2D.
     * @param name       The name of the IHistogram2D.
     * @param title      The title of the IHistogram2D.
     * @param binEdgesX  The array of the bin edges for the x axis.
     * @param binEdgesY  The array of the bin edges for the y axis.
     * @param options    The options for the IHistogram2D. The default is "".
     *                   "type=efficiency" for an efficiency IHistogram2D.
     * @return           The newly created IHistogram2D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * createHistogram2D(const std::string & name, const std::string & title, const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, const std::string & options);

    /**
     * Create a copy of an IHistogram2D.
     * @param name The name of the new copy.
     * @param hist The IHistogram2D to be copied.
     * @return     The copy of the IHistogram2D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * createCopy(const std::string & name, const AIDA::IHistogram2D & hist);

    /**
     * Create a IHistogram3D.
     * @param name       The name of the IHistogram3D.
     * @param title      The title of the IHistogram3D.
     * @param nBinsX     The number of bins of the x axis.
     * @param lowerEdgeX The lower edge of the x axis.
     * @param upperEdgeX The upper edge of the x axis.
     * @param nBinsY     The number of bins of the y axis.
     * @param lowerEdgeY The lower edge of the y axis.
     * @param upperEdgeY The upper edge of the y axis.
     * @param nBinsZ     The number of bins of the z axis.
     * @param lowerEdgeZ The lower edge of the z axis.
     * @param upperEdgeZ The upper edge of the z axis.
     * @param options    The options for the IHistogram3D. The default is "".
     *                   "type=efficiency" for an efficiency IHistogram3D.
     * @return           The newly created IHistogram3D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram3D * createHistogram3D(const std::string & name, const std::string & title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, int nBinsZ, double lowerEdgeZ, double upperEdgeZ, const std::string & options);

    /**
     * Create a IHistogram3D.
     * @param nameAndTitle The name of the IHistogram3D; it is also the title.
     * @param nBinsX       The number of bins of the x axis.
     * @param lowerEdgeX   The lower edge of the x axis.
     * @param upperEdgeX   The upper edge of the x axis.
     * @param nBinsY       The number of bins of the y axis.
     * @param lowerEdgeY   The lower edge of the y axis.
     * @param upperEdgeY   The upper edge of the y axis.
     * @param nBinsZ       The number of bins of the z axis.
     * @param lowerEdgeZ   The lower edge of the z axis.
     * @param upperEdgeZ   The upper edge of the z axis.
     * @return             The newly created IHistogram3D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram3D * createHistogram3D(const std::string & nameAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, int nBinsZ, double lowerEdgeZ, double upperEdgeZ);

    /**
     * Create a IHistogram3D.
     * @param name       The name of the IHistogram3D.
     * @param title      The title of the IHistogram3D.
     * @param binEdgesX  The array of the bin edges for the x axis.
     * @param binEdgesY  The array of the bin edges for the y axis.
     * @param binEdgesZ  The array of the bin edges for the z axis.
     * @param options    The options for the IHistogram3D. The default is "".
     *                   "type=efficiency" for an efficiency IHistogram3D.
     * @return           The newly created IHistogram3D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram3D * createHistogram3D(const std::string & name, const std::string & title, const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, const std::vector<double>  & binEdgesZ, const std::string & options);

    /**
     * Create a copy of an IHistogram3D.
     * @param name The name of the new copy.
     * @param hist The IHistogram3D to be copied.
     * @return     The copy of the IHistogram3D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram3D * createCopy(const std::string & name, const AIDA::IHistogram3D & hist);

    /**
     * Create a IProfile1D.
     * @param name      The name of the IProfile1D.
     * @param title     The title of the IProfile1D.
     * @param nBins     The number of bins of the x axis.
     * @param lowerEdge The lower edge of the x axis.
     * @param upperEdge The upper edge of the x axis.
     * @param options   The options for the IProfile1D. The default is "".
     * @return          The newly created IProfile1D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile1D * createProfile1D(const std::string & name, const std::string & title, int nBins, double lowerEdge, double upperEdge, const std::string & options);

    /**
     * Create a IProfile1D.
     * @param name       The name of the IProfile1D.
     * @param title      The title of the IProfile1D.
     * @param nBins      The number of bins of the x axis.
     * @param lowerEdge  The lower edge of the x axis.
     * @param upperEdge  The upper edge of the x axis.
     * @param lowerValue The lower value displayed along the y axis.
     * @param upperValue The upper value displayed along the y axis.
     * @param options    The options for the IProfile1D. The default is "".
     * @return           The newly created IProfile1D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile1D * createProfile1D(const std::string & name, const std::string & title, int nBins, double lowerEdge, double upperEdge, double lowerValue, double upperValue, const std::string & options);

    /**
     * Create a IProfile1D.
     * @param name      The name of the IProfile1D.
     * @param title     The title of the IProfile1D.
     * @param binEdges  The array of the bin edges for the x axis.
     * @param options   The options for the IProfile1D. The default is "".
     * @return          The newly created IProfile1D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile1D * createProfile1D(const std::string & name, const std::string & title, const std::vector<double>  & binEdges, const std::string & options);

    /**
     * Create a IProfile1D.
     * @param name       The name of the IProfile1D.
     * @param title      The title of the IProfile1D.
     * @param binEdges   The array of the bin edges for the x axis.
     * @param lowerValue The lower value displayed along the y axis.
     * @param upperValue The upper value displayed along the y axis.
     * @param options    The options for the IProfile1D. The default is "".
     * @return           The newly created IProfile1D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile1D * createProfile1D(const std::string & name, const std::string & title, const std::vector<double>  & binEdges, double lowerValue, double upperValue, const std::string & options);

    /**
     * Create a IProfile1D.
     * @param nameAndTitle The name of the IProfile1D; it is also the title.
     * @param nBins        The number of bins of the x axis.
     * @param lowerEdge    The lower edge of the x axis.
     * @param upperEdge    The upper edge of the x axis.
     * @return             The newly created IProfile1D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile1D * createProfile1D(const std::string & nameAndTitle, int nBins, double lowerEdge, double upperEdge);

    /**
     * Create a IProfile1D.
     * @param nameAndTitle The name of the IProfile1D; it is also the title.
     * @param nBins        The number of bins of the x axis.
     * @param lowerEdge    The lower edge of the x axis.
     * @param upperEdge    The upper edge of the x axis.
     * @param lowerValue   The lower value displayed along the y axis.
     * @param upperValue   The upper value displayed along the y axis.
     * @return             The newly created IProfile1D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile1D * createProfile1D(const std::string & nameAndTitle, int nBins, double lowerEdge, double upperEdge, double lowerValue, double upperValue);

    /**
     * Create a copy of an IProfile1D.
     * @param name    The name of the new copy.
     * @param profile The IProfile1D to be copied.
     * @return        The copy of the IProfile1D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile1D * createCopy(const std::string & name, const AIDA::IProfile1D & profile);

    /**
     * Create a IProfile2D.
     * @param name       The name of the IProfile2D.
     * @param title      The title of the IProfile2D.
     * @param nBinsX     The number of bins of the x axis.
     * @param lowerEdgeX The lower edge of the x axis.
     * @param upperEdgeX The upper edge of the x axis.
     * @param nBinsY     The number of bins of the y axis.
     * @param lowerEdgeY The lower edge of the y axis.
     * @param upperEdgeY The upper edge of the y axis.
     * @param options    The options for the IProfile2D. The default is "".
     * @return           The newly created IProfile2D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile2D * createProfile2D(const std::string & name, const std::string & title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, const std::string & options);

    /**
     * Create a IProfile2D.
     * @param name       The name of the IProfile2D.
     * @param title      The title of the IProfile2D.
     * @param nBinsX     The number of bins of the x axis.
     * @param lowerEdgeX The lower edge of the x axis.
     * @param upperEdgeX The upper edge of the x axis.
     * @param nBinsY     The number of bins of the y axis.
     * @param lowerEdgeY The lower edge of the y axis.
     * @param upperEdgeY The upper edge of the y axis.
     * @param lowerValue The lower value displayed along the z axis.
     * @param upperValue The upper value displayed along the z axis.
     * @param options    The options for the IProfile2D. The default is "".
     * @return           The newly created IProfile2D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile2D * createProfile2D(const std::string & name, const std::string & title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, double lowerValue, double upperValue, const std::string & options);

    /**
     * Create a IProfile2D.
     * @param name       The name of the IProfile2D.
     * @param title      The title of the IProfile2D.
     * @param binEdgesX  The array of the bin edges for the x axis.
     * @param binEdgesY  The array of the bin edges for the y axis.
     * @param options    The options for the IProfile2D. The default is "".
     * @return           The newly created IProfile2D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile2D * createProfile2D(const std::string & name, const std::string & title, const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, const std::string & options);

    /**
     * Create a IProfile2D.
     * @param name       The name of the IProfile2D.
     * @param title      The title of the IProfile2D.
     * @param binEdgesX  The array of the bin edges for the x axis.
     * @param binEdgesY  The array of the bin edges for the y axis.
     * @param lowerValue The lower value displayed along the y axis.
     * @param upperValue The upper value displayed along the y axis.
     * @param options    The options for the IProfile2D. The default is "".
     * @return           The newly created IProfile2D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile2D * createProfile2D(const std::string & name, const std::string & title, const std::vector<double>  & binEdgesX, const std::vector<double>  & binEdgesY, double lowerValue, double upperValue, const std::string & options);

    /**
     * Create a IProfile2D.
     * @param nameAndTitle The name of the IProfile2D; it is also the title.
     * @param nBinsX       The number of bins of the x axis.
     * @param lowerEdgeX   The lower edge of the x axis.
     * @param upperEdgeX   The upper edge of the x axis.
     * @param nBinsY       The number of bins of the y axis.
     * @param lowerEdgeY   The lower edge of the y axis.
     * @param upperEdgeY   The upper edge of the y axis.
     * @return             The newly created IProfile2D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile2D * createProfile2D(const std::string & nameAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY);

    /**
     * Create a IProfile2D.
     * @param nameAndTitle The name of the IProfile2D; it is also the title.
     * @param nBinsX       The number of bins of the x axis.
     * @param lowerEdgeX   The lower edge of the x axis.
     * @param upperEdgeX   The upper edge of the x axis.
     * @param nBinsY       The number of bins of the y axis.
     * @param lowerEdgeY   The lower edge of the y axis.
     * @param upperEdgeY   The upper edge of the y axis.
     * @param lowerValue   The lower value displayed along the z axis.
     * @param upperValue   The upper value displayed along the z axis.
     * @return             The newly created IProfile2D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile2D * createProfile2D(const std::string & nameAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, double lowerValue, double upperValue);

    /**
     * Create a copy of an IProfile2D.
     * @param name    The name of the new copy.
     * @param profile The IProfile2D to be copied.
     * @return        The copy of the IProfile2D.
     *
     */
    JNIEXPORT virtual AIDA::IProfile2D * createCopy(const std::string & name, const AIDA::IProfile2D & profile);

    /**
     * Create an IHistogram1D by adding two IHistogram1D.
     * @param name  The name of the resulting IHistogram1D.
     * @param hist1 The first member of the addition.
     * @param hist2 The second member of the addition.
     * @return      The sum of the two IHistogram1D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * add(const std::string & name, const AIDA::IHistogram1D & hist1, const AIDA::IHistogram1D & hist2);

    /**
     * Create an IHistogram1D by subtracting two IHistogram1D.
     * @param name  The name of the resulting IHistogram1D.
     * @param hist1 The first member of the subtraction.
     * @param hist2 The second member of the subtraction.
     * @return      The difference of the two IHistogram1D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * subtract(const std::string & name, const AIDA::IHistogram1D & hist1, const AIDA::IHistogram1D & hist2);

    /**
     * Create an IHistogram1D by multiplying two IHistogram1D.
     * @param name  The name of the resulting IHistogram1D.
     * @param hist1 The first member of the multiplication.
     * @param hist2 The second member of the multiplication.
     * @return      The product of the two IHistogram1D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * multiply(const std::string & name, const AIDA::IHistogram1D & hist1, const AIDA::IHistogram1D & hist2);

    /**
     * Create an IHistogram1D by dividing two IHistogram1D.
     * @param name  The name of the resulting IHistogram1D.
     * @param hist1 The first member of the division.
     * @param hist2 The second member of the division.
     * @return      The ration of the two IHistogram1D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * divide(const std::string & name, const AIDA::IHistogram1D & hist1, const AIDA::IHistogram1D & hist2);

    /**
     * Create an IHistogram2D by adding two IHistogram2D.
     * @param name  The name of the resulting IHistogram2D.
     * @param hist1 The first member of the addition.
     * @param hist2 The second member of the addition.
     * @return      The sum of the two IHistogram2D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * add(const std::string & name, const AIDA::IHistogram2D & hist1, const AIDA::IHistogram2D & hist2);

    /**
     * Create an IHistogram2D by subtracting two IHistogram2D.
     * @param name  The name of the resulting IHistogram2D.
     * @param hist1 The first member of the subtraction.
     * @param hist2 The second member of the subtraction.
     * @return      The difference of the two IHistogram2D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * subtract(const std::string & name, const AIDA::IHistogram2D & hist1, const AIDA::IHistogram2D & hist2);

    /**
     * Create an IHistogram2D by multiplying two IHistogram2D.
     * @param name  The name of the resulting IHistogram2D.
     * @param hist1 The first member of the multiplication.
     * @param hist2 The second member of the multiplication.
     * @return      The product of the two IHistogram2D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * multiply(const std::string & name, const AIDA::IHistogram2D & hist1, const AIDA::IHistogram2D & hist2);

    /**
     * Create an IHistogram2D by dividing two IHistogram2D.
     * @param name  The name of the resulting IHistogram2D.
     * @param hist1 The first member of the division.
     * @param hist2 The second member of the division.
     * @return      The ration of the two IHistogram2D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * divide(const std::string & name, const AIDA::IHistogram2D & hist1, const AIDA::IHistogram2D & hist2);

    /**
     * Create an IHistogram3D by adding two IHistogram3D.
     * @param name  The name of the resulting IHistogram3D.
     * @param hist1 The first member of the addition.
     * @param hist2 The second member of the addition.
     * @return      The sum of the two IHistogram3D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram3D * add(const std::string & name, const AIDA::IHistogram3D & hist1, const AIDA::IHistogram3D & hist2);

    /**
     * Create an IHistogram3D by subtracting two IHistogram3D.
     * @param name  The name of the resulting IHistogram3D.
     * @param hist1 The first member of the subtraction.
     * @param hist2 The second member of the subtraction.
     * @return      The difference of the two IHistogram3D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram3D * subtract(const std::string & name, const AIDA::IHistogram3D & hist1, const AIDA::IHistogram3D & hist2);

    /**
     * Create an IHistogram3D by multiplying two IHistogram3D.
     * @param name  The name of the resulting IHistogram3D.
     * @param hist1 The first member of the multiplication.
     * @param hist2 The second member of the multiplication.
     * @return      The product of the two IHistogram3D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram3D * multiply(const std::string & name, const AIDA::IHistogram3D & hist1, const AIDA::IHistogram3D & hist2);

    /**
     * Create an IHistogram3D by dividing two IHistogram3D.
     * @param name  The name of the resulting IHistogram3D.
     * @param hist1 The first member of the division.
     * @param hist2 The second member of the division.
     * @return      The ration of the two IHistogram3D.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram3D * divide(const std::string & name, const AIDA::IHistogram3D & hist1, const AIDA::IHistogram3D & hist2);

    /**
     * Create an IHistogram1D by projecting an IHistogram2D along its x axis.
     * This is equivalent to <tt>sliceX(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     * @param name The name of the resulting IHistogram1D.
     * @param hist The IHistogram2D to be projected.
     * @return     The resulting projection.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * projectionX(const std::string & name, const AIDA::IHistogram2D & hist);

    /**
     * Create an IHistogram1D by projecting an IHistogram2D along its y axis.
     * This is equivalent to <tt>sliceY(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     * @param name The name of the resulting IHistogram1D.
     * @param hist The IHistogram2D to be projected.
     * @return     The resulting projection.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * projectionY(const std::string & name, const AIDA::IHistogram2D & hist);

    /**
     * Create an IHistogram1D by slicing an IHistogram2D parallel to the y axis at a given bin.
     * This is equivalent to <tt>sliceX(indexY,indexY)</tt>.
     * @param name  The name of the resulting IHistogram1D.
     * @param hist  The IHistogram2D to be sliced.
     * @param index The index of the bin along the y axis where the IHistogram2D has to be sliced.
     * @return      The resulting slice.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * sliceX(const std::string & name, const AIDA::IHistogram2D & hist, int index);

    /**
     * Create an IHistogram1D by slicing an IHistogram2D parallel to the x axis at a given bin.
     * This is equivalent to <tt>sliceY(indexX,indexX)</tt>.
     * @param name  The name of the resulting IHistogram1D.
     * @param hist  The IHistogram2D to be sliced.
     * @param index The index of the bin along the x axis where the IHistogram2D has to be sliced.
     * @return      The resulting slice.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * sliceY(const std::string & name, const AIDA::IHistogram2D & hist, int index);

    /**
     * Create an IHistogram1D by slicing an IHistogram2D parallel to the y axis between two bins (inclusive).
     * @param name   The name of the resulting IHistogram1D.
     * @param hist   The IHistogram2D to be sliced.
     * @param index1 The index of the bin along the y axis that marks the lower edge of the slice.
     * @param index2 The index of the bin along the y axis that marks the upper edge of the slice.
     * @return       The resulting slice.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * sliceX(const std::string & name, const AIDA::IHistogram2D & hist, int index1, int index2);

    /**
     * Create an IHistogram1D by slicing an IHistogram2D parallel to the x axis between two bins (inclusive).
     * @param name   The name of the resulting IHistogram1D.
     * @param hist   The IHistogram2D to be sliced.
     * @param index1 The index of the bin along the x axis that marks the lower edge of the slice.
     * @param index2 The index of the bin along the x axis that marks the upper edge of the slice.
     * @return       The resulting slice.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram1D * sliceY(const std::string & name, const AIDA::IHistogram2D & hist, int index1, int index2);

    /**
     * Create an IHistogram2D by projecting an IHistogram3D on the x-y plane.
     * This is equivalent to <tt>sliceXY(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     * @param name The name of the resulting IHistogram2D.
     * @param hist The IHistogram3D to be projected.
     * @return     The resulting projection.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * projectionXY(const std::string & name, const AIDA::IHistogram3D & hist);

    /**
     * Create an IHistogram2D by projecting an IHistogram3D on the x-z plane.
     * This is equivalent to <tt>sliceXZ(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     * @param name The name of the resulting IHistogram2D.
     * @param hist The IHistogram3D to be projected.
     * @return     The resulting projection.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * projectionXZ(const std::string & name, const AIDA::IHistogram3D & hist);

    /**
     * Create an IHistogram2D by projecting an IHistogram3D on the y-z plane.
     * This is equivalent to <tt>sliceYZ(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     * @param name The name of the resulting IHistogram2D.
     * @param hist The IHistogram3D to be projected.
     * @return     The resulting projection.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * projectionYZ(const std::string & name, const AIDA::IHistogram3D & hist);

    /**
     * Create an IHistogram2D by slicing an IHistogram3D perpendicular to the Z axis,
     * between "index1" and "index2" (inclusive).
     * The X axis of the IHistogram2D corresponds to the X axis of this IHistogram3D.
     * The Y axis of the IHistogram2D corresponds to the Y axis of this IHistogram3D.
     * @param name   The name of the resulting IHistogram2D.
     * @param hist   The IHistogram3D to sliced.
     * @param index1 The index of the bin along the z axis that marks the lower edge of the slice.
     * @param index2 The index of the bin along the z axis that marks the upper edge of the slice.
     * @return       The resulting slice.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * sliceXY(const std::string & name, const AIDA::IHistogram3D & hist, int index1, int index2);

    /**
     * Create an IHistogram2D by slicing an IHistogram3D perpendicular to the Y axis,
     * between "index1" and "index2" (inclusive).
     * The X axis of the IHistogram2D corresponds to the X axis of this IHistogram3D.
     * The Z axis of the IHistogram2D corresponds to the Z axis of this IHistogram3D.
     * @param name   The name of the resulting IHistogram2D.
     * @param hist   The IHistogram3D to sliced.
     * @param index1 The index of the bin along the y axis that marks the lower edge of the slice.
     * @param index2 The index of the bin along the y axis that marks the upper edge of the slice.
     * @return       The resulting slice.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * sliceXZ(const std::string & name, const AIDA::IHistogram3D & hist, int index1, int index2);

    /**
     * Create an IHistogram2D by slicing an IHistogram3D perpendicular to the X axis,
     * between "index1" and "index2" (inclusive).
     * The Y axis of the IHistogram2D corresponds to the Y axis of this IHistogram3D.
     * The Z axis of the IHistogram2D corresponds to the Z axis of this IHistogram3D.
     * @param name   The name of the resulting IHistogram2D.
     * @param hist   The IHistogram3D to sliced.
     * @param index1 The index of the bin along the x axis that marks the lower edge of the slice.
     * @param index2 The index of the bin along the x axis that marks the upper edge of the slice.
     * @return       The resulting slice.
     *
     */
    JNIEXPORT virtual AIDA::IHistogram2D * sliceYZ(const std::string & name, const AIDA::IHistogram3D & hist, int index1, int index2);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIHISTOGRAMFACTORY_H */
