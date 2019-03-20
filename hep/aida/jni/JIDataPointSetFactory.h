// -*- C++ -*-
#ifndef JAIDA_JIDATAPOINTSETFACTORY_H
#define JAIDA_JIDATAPOINTSETFACTORY_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/ICloud1D.h"
#include "AIDA/ICloud2D.h"
#include "AIDA/ICloud3D.h"
#include "AIDA/IDataPointSet.h"
#include "AIDA/IDataPointSetFactory.h"
#include "AIDA/IHistogram1D.h"
#include "AIDA/IHistogram2D.h"
#include "AIDA/IHistogram3D.h"
#include "AIDA/IProfile1D.h"
#include "AIDA/IProfile2D.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * Basic user-level interface for creating a factory
 * of IDataPointSet.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIDataPointSetFactory: public JProxy, public virtual AIDA::IDataPointSetFactory {

private:
    jmethodID createOLjava_lang_StringELhep_aida_IHistogram3DELjava_lang_StringECLhep_aida_IDataPointSetEMethod;
    jmethodID createOLjava_lang_StringELhep_aida_IHistogram2DELjava_lang_StringECLhep_aida_IDataPointSetEMethod;
    jmethodID createOLjava_lang_StringELhep_aida_ICloud2DELjava_lang_StringECLhep_aida_IDataPointSetEMethod;
    jmethodID createOLjava_lang_StringEICLhep_aida_IDataPointSetEMethod;
    jmethodID createOLjava_lang_StringELhep_aida_IProfile2DELjava_lang_StringECLhep_aida_IDataPointSetEMethod;
    jmethodID createCopyOLjava_lang_StringELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod;
    jmethodID createOLjava_lang_StringELhep_aida_ICloud1DELjava_lang_StringECLhep_aida_IDataPointSetEMethod;
    jmethodID createOLjava_lang_StringELjava_lang_StringEICLhep_aida_IDataPointSetEMethod;
    jmethodID divideOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod;
    jmethodID createOLjava_lang_StringELhep_aida_IHistogram1DELjava_lang_StringECLhep_aida_IDataPointSetEMethod;
    jmethodID createOLjava_lang_StringELhep_aida_IProfile1DELjava_lang_StringECLhep_aida_IDataPointSetEMethod;
    jmethodID createOLjava_lang_StringELhep_aida_ICloud3DELjava_lang_StringECLhep_aida_IDataPointSetEMethod;
    jmethodID subtractOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod;
    jmethodID addOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod;
    jmethodID weightedMeanOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod;
    jmethodID multiplyOLjava_lang_StringELhep_aida_IDataPointSetELhep_aida_IDataPointSetECLhep_aida_IDataPointSetEMethod;
    jmethodID destroyOLhep_aida_IDataPointSetECVMethod;

    jmethodID createYOLjava_lang_StringELjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod;
    jmethodID createYOLjava_lang_StringELjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod;
    jmethodID createYOLjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod;
    jmethodID createYOLjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod;

    jmethodID createXOLjava_lang_StringELjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod;
    jmethodID createXOLjava_lang_StringELjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod;
    jmethodID createXOLjava_lang_StringEADADCLhep_aida_IDataPointSetEMethod;
    jmethodID createXOLjava_lang_StringEADADADCLhep_aida_IDataPointSetEMethod;

    jmethodID createXYOLjava_lang_StringELjava_lang_StringEADADADADCLhep_aida_IDataPointSetEMethod;
    jmethodID createXYOLjava_lang_StringELjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod;
    jmethodID createXYOLjava_lang_StringEADADADADCLhep_aida_IDataPointSetEMethod;
    jmethodID createXYOLjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod;

    jmethodID createXYZOLjava_lang_StringELjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod;
    jmethodID createXYZOLjava_lang_StringELjava_lang_StringEADADADADADADADADADCLhep_aida_IDataPointSetEMethod;
    jmethodID createXYZOLjava_lang_StringEADADADADADADCLhep_aida_IDataPointSetEMethod;
    jmethodID createXYZOLjava_lang_StringEADADADADADADADADADCLhep_aida_IDataPointSetEMethod;

protected:
    inline JIDataPointSetFactory() { };
    inline JIDataPointSetFactory(const JIDataPointSetFactory& r):JProxy(r) { };
    inline JIDataPointSetFactory& operator=(const JIDataPointSetFactory&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIDataPointSetFactory(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIDataPointSetFactory();

    /**
     * Create an empty IDataPointSet.
     * @param name        The name of the IDataPointSet.
     * @param title       The title of the IDataPointSet.
     * @param dimOfPoints The dimension of the IDataPoints that can be stored in the set.
     * @return            The newly created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * create(const std::string & name, const std::string & title, int dimOfPoints);

    /**
     * Create an empty IDataPointSet.
     * @param nameAndTitle The name and the title of the IDataPointSet.
     * @param dimOfPoints  The dimension of the IDataPoints that can be stored in the set.
     * @return             The newly created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * create(const std::string & nameAndTitle, int dimOfPoints);

    /**
     * Create a two dimensional IDataPointSet providing the data along y (the x value is 
     * the index of the y value in the array).
     * @param path  The path of the IDataPointSet. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param title The title of the IDataPointSet.
     * @param y     The array of the y values
     * @param ey    The array with the symmetric errors on y
     * @return      The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createY(const std::string & path, const std::string & title, const std::vector<double>  & y, const std::vector<double>  & ey);

    /**
     * Create a two dimensional IDataPointSet providing the data along y (the x value is 
     * the index of the y value in the array).
     * @param path  The path of the IDataPointSet. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param title The title of the IDataPointSet.
     * @param y     The array of the y values
     * @param eyp   The array with the plus errors on y
     * @param eym   The array with the minus errors on y
     * @return      The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createY(const std::string & path, const std::string & title, const std::vector<double>  & y, const std::vector<double>  & eyp, const std::vector<double>  & eym);

    /**
     * Create a two dimensional IDataPointSet providing the data along y (the x value is 
     * the index of the y value in the array).
     * @param pathAndTitle The path of the IDataPointSet. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param y            The array of the y values
     * @param ey           The array with the symmetric errors on y
     * @return             The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createY(const std::string & pathAndTitle, const std::vector<double>  & y, const std::vector<double>  & ey);

    /**
     * Create a two dimensional IDataPointSet providing the data along y (the x value is 
     * the index of the y value in the array).
     * @param pathAndTitle The path of the IDataPointSet. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param y            The array of the y values
     * @param eyp          The array with the plus errors on y
     * @param eym          The array with the minus errors on y
     * @return             The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createY(const std::string & pathAndTitle, const std::vector<double>  & y, const std::vector<double>  & eyp, const std::vector<double>  & eym);

    /**
     * Create a two dimensional IDataPointSet providing the data along x (the y value is 
     * the index of the x value in the array).
     * @param path  The path of the IDataPointSet. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param title The title of the IDataPointSet.
     * @param x     The array of the x values
     * @param ex    The array with the symmetric errors on x
     * @return      The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createX(const std::string & path, const std::string & title, const std::vector<double>  & x, const std::vector<double>  & ex);

    /**
     * Create a two dimensional IDataPointSet providing the data along x (the y value is 
     * the index of the x value in the array).
     * @param path  The path of the IDataPointSet. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param title The title of the IDataPointSet.
     * @param x     The array of the x values
     * @param exp   The array with the plus errors on x
     * @param exm   The array with the minus errors on x
     * @return      The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createX(const std::string & path, const std::string & title, const std::vector<double>  & x, const std::vector<double>  & exp, const std::vector<double>  & exm);

    /**
     * Create a two dimensional IDataPointSet providing the data along x (the y value is 
     * the index of the x value in the array).
     * @param pathAndTitle The path of the IDataPointSet. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param x            The array of the x values
     * @param ex           The array with the symmetric errors on x
     * @return             The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createX(const std::string & pathAndTitle, const std::vector<double>  & x, const std::vector<double>  & ex);

    /**
     * Create a two dimensional IDataPointSet providing the data along x (the y value is 
     * the index of the x value in the array).
     * @param pathAndTitle The path of the IDataPointSet. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param x            The array of the x values
     * @param exp          The array with the plus errors on x
     * @param exm          The array with the minus errors on x
     * @return             The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createX(const std::string & pathAndTitle, const std::vector<double>  & x, const std::vector<double>  & exp, const std::vector<double>  & exm);

    /**
     * Create a two dimensional IDataPointSet providing the data.
     * @param path  The path of the IDataPointSet. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param title The title of the IDataPointSet.
     * @param x     The array of the x values
     * @param y     The array of the y values
     * @param exp   The array with the plus errors on x
     * @param eyp   The array with the plus errors on y
     * @param exm   The array with the minus errors on x
     * @param eym   The array with the minus errors on y
     * @return      The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createXY(const std::string & path, const std::string & title, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & exp, const std::vector<double>  & eyp, const std::vector<double>  & exm, const std::vector<double>  & eym);

    /**
     * Create a two dimensional IDataPointSet providing the data.
     * @param path  The path of the IDataPointSet. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param title The title of the IDataPointSet.
     * @param x     The array of the x values
     * @param y     The array of the y values
     * @param ex    The array with the symmetric errors on x
     * @param ey    The array with the symmetric errors on y
     * @return      The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createXY(const std::string & path, const std::string & title, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & ex, const std::vector<double>  & ey);

    /**
     * Create a two dimensional IDataPointSet providing the data.
     * @param pathAndTitle The path of the IDataPointSet. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param x            The array of the x values
     * @param y            The array of the y values
     * @param exp          The array with the plus errors on x
     * @param eyp          The array with the plus errors on y
     * @param exm          The array with the minus errors on x
     * @param eym          The array with the minus errors on y
     * @return             The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createXY(const std::string & pathAndTitle, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & exp, const std::vector<double>  & eyp, const std::vector<double>  & exm, const std::vector<double>  & eym);

    /**
     * Create a two dimensional IDataPointSet providing the data.
     * @param pathAndTitle The path of the IDataPointSet. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param x            The array of the x values
     * @param y            The array of the y values
     * @param ex           The array with the symmetric errors on x
     * @param ey           The array with the symmetric errors on y
     * @return             The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createXY(const std::string & pathAndTitle, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & ex, const std::vector<double>  & ey);

    /**
     * Create a three dimensional IDataPointSet providing the data.
     * @param path  The path of the IDataPointSet. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param title The title of the IDataPointSet.
     * @param x     The array of the x values
     * @param y     The array of the y values
     * @param z     The array of the z values
     * @param exp   The array with the plus errors on x
     * @param eyp   The array with the plus errors on y
     * @param ezp   The array with the plus errors on z
     * @param exm   The array with the minus errors on x
     * @param eym   The array with the minus errors on y
     * @param ezm   The array with the minus errors on z
     * @return      The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createXYZ(const std::string & path, const std::string & title, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & z, const std::vector<double>  & exp, const std::vector<double>  & eyp, const std::vector<double>  & ezp, const std::vector<double>  & exm, const std::vector<double>  & eym, const std::vector<double>  & ezm);

    /**
     * Create a three dimensional IDataPointSet providing the data.
     * @param path  The path of the IDataPointSet. The path can either be a relative or full path.
     *              ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *              All the directories in the path must exist. The characther `/` cannot be used
     *              in names; it is only used to delimit directories within paths.
     * @param title The title of the IDataPointSet.
     * @param x     The array of the x values
     * @param y     The array of the y values
     * @param z     The array of the z values
     * @param ex    The array with the symmetric errors on x
     * @param ey    The array with the symmetric errors on y
     * @param ez    The array with the symmetric errors on z
     * @return      The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createXYZ(const std::string & path, const std::string & title, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & z, const std::vector<double>  & ex, const std::vector<double>  & ey, const std::vector<double>  & ez);

    /**
     * Create a two dimensional IDataPointSet providing the data.
     * @param pathAndTitle The path of the IDataPointSet. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param x            The array of the x values
     * @param y            The array of the y values
     * @param z            The array of the z values
     * @param exp          The array with the plus errors on x
     * @param eyp          The array with the plus errors on y
     * @param ezp          The array with the plus errors on z
     * @param exm          The array with the minus errors on x
     * @param eym          The array with the minus errors on y
     * @param ezm          The array with the minus errors on z
     * @return             The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createXYZ(const std::string & pathAndTitle, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & z, const std::vector<double>  & exp, const std::vector<double>  & eyp, const std::vector<double>  & ezp, const std::vector<double>  & exm, const std::vector<double>  & eym, const std::vector<double>  & ezm);

    /**
     * Create a two dimensional IDataPointSet providing the data.
     * @param pathAndTitle The path of the IDataPointSet. The path can either be a relative or full path.
     *                     The last part of the path is used as the title.
     *                     ("/folder1/folder2/dataTitle" and "../folder/dataTitle" are valid paths).
     *                     All the directories in the path must exist. The characther `/` cannot be used
     *                     in names; it is only used to delimit directories within paths.
     * @param x            The array of the x values
     * @param y            The array of the y values
     * @param z            The array of the z values
     * @param exp          The array with the symmetric errors on x
     * @param eyp          The array with the symmetric errors on y
     * @param ezp          The array with the symmetric errors on z
     * @return             The created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createXYZ(const std::string & pathAndTitle, const std::vector<double>  & x, const std::vector<double>  & y, const std::vector<double>  & z, const std::vector<double>  & ex, const std::vector<double>  & ey, const std::vector<double>  & ez);

    /**
     * Make a copy of a given IDataPointSet.
     * @param name         The name of the copy IDataPointSet.
     * @param dataPointSet The IDataPointSet to be copied.
     * @return             The copy of the given IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * createCopy(const std::string & name, const AIDA::IDataPointSet & dataPointSet);

    /**
     * Destroy a given IDataPointSet.
     * @param dataPointSet The IDataPointSet to be destroyed.
     * @return false If dataPointSet cannot be destroyed.
     *
     */
    JNIEXPORT virtual bool destroy(AIDA::IDataPointSet * dataPointSet);

    /**
     * Create an IDataPointSet from an IHistogram1D.
     * @param name The name of the IDataPointSet.
     * @param hist The IHistogram1D from which the data is taken.
     * @return     The newly created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * create(const std::string & name, const AIDA::IHistogram1D & hist, const std::string & options);

    /**
     * Create an IDataPointSet from an IHistogram2D.
     * @param name The name of the IDataPointSet.
     * @param hist The IHistogram2D from which the data is taken.
     * @return     The newly created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * create(const std::string & name, const AIDA::IHistogram2D & hist, const std::string & options);

    /**
     * Create an IDataPointSet from an IHistogram3D.
     * @param name The name of the IDataPointSet.
     * @param hist The IHistogram3D from which the data is taken.
     * @return     The newly created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * create(const std::string & name, const AIDA::IHistogram3D & hist, const std::string & options);

    /**
     * Create an IDataPointSet from an ICloud1D.
     * @param name  The name of the IDataPointSet.
     * @param cloud The ICloud1D from which the data is taken.
     * @return      The newly created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * create(const std::string & name, const AIDA::ICloud1D & cloud, const std::string & options);

    /**
     * Create an IDataPointSet from an ICloud2D.
     * @param name  The name of the IDataPointSet.
     * @param cloud The ICloud2D from which the data is taken.
     * @return      The newly created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * create(const std::string & name, const AIDA::ICloud2D & cloud, const std::string & options);

    /**
     * Create an IDataPointSet from an ICloud3D.
     * @param name  The name of the IDataPointSet.
     * @param cloud The ICloud3D from which the data is taken.
     * @return      The newly created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * create(const std::string & name, const AIDA::ICloud3D & cloud, const std::string & options);

    /**
     * Create an IDataPointSet from an IProfile1D.
     * @param name    The name of the IDataPointSet.
     * @param profile The IProfile1D from which the data is taken.
     * @return        The newly created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * create(const std::string & name, const AIDA::IProfile1D & profile, const std::string & options);

    /**
     * Create an IDataPointSet from an IProfile2D.
     * @param name    The name of the IDataPointSet.
     * @param profile The IProfile2D from which the data is taken.
     * @return        The newly created IDataPointSet.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * create(const std::string & name, const AIDA::IProfile2D & profile, const std::string & options);

    /**
     * Add two IDataSetPoint, point by point and measurement by measurement.
     * @param name          The name of the resulting IDataPointSet
     * @param dataPointSet1 The first member of the addition.
     * @param dataPointSet2 The second member of the addition.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * add(const std::string & name, const AIDA::IDataPointSet & dataPointSet1, const AIDA::IDataPointSet & dataPointSet2);

    /**
     * Subtract two IDataSetPoint, point by point and measurement by measurement.
     * @param name          The name of the resulting IDataPointSet
     * @param dataPointSet1 The first member of the subtraction.
     * @param dataPointSet2 The second member of the subtraction.
     * @param strategy      The strategy of how to perform the subtraction. The default corresponds to
     *                      uncorrelated Gaussian error propagation.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * subtract(const std::string & name, const AIDA::IDataPointSet & dataPointSet1, const AIDA::IDataPointSet & dataPointSet2);

    /**
     * Multiply two IDataSetPoint, point by point and measurement by measurement.
     * @param name          The name of the resulting IDataPointSet
     * @param dataPointSet1 The first member of the multiplication.
     * @param dataPointSet2 The second member of the multiplication.
     * @param strategy      The strategy of how to perform the multiplication. The default corresponds to
     *                      uncorrelated Gaussian error propagation.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * multiply(const std::string & name, const AIDA::IDataPointSet & dataPointSet1, const AIDA::IDataPointSet & dataPointSet2);

    /**
     * Divide two IDataSetPoint, point by point and measurement by measurement.
     * @param name          The name of the resulting IDataPointSet
     * @param dataPointSet1 The first member of the division.
     * @param dataPointSet2 The second member of the division.
     * @param strategy      The strategy of how to perform the division. The default corresponds to
     *                      uncorrelated Gaussian error propagation.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * divide(const std::string & name, const AIDA::IDataPointSet & dataPointSet1, const AIDA::IDataPointSet & dataPointSet2);

    /**
     * Calculate weighted means of two IDataSetPoint, point by point and measurement by measurement.
     * @param name          The name of the resulting IDataPointSet
     * @param dataPointSet1 The first IDataPointSet.
     * @param dataPointSet2 The second IDataPointSet.
     * @param strategy      The strategy of how to calculate the weighted means. The default corresponds to
     *                      uncorrelated Gaussian error propagation.
     *
     */
    JNIEXPORT virtual AIDA::IDataPointSet * weightedMean(const std::string & name, const AIDA::IDataPointSet & dataPointSet1, const AIDA::IDataPointSet & dataPointSet2);
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIDATAPOINTSETFACTORY_H */

