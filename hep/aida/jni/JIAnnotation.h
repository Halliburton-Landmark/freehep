// -*- C++ -*-
#ifndef JAIDA_JIANNOTATION_H
#define JAIDA_JIANNOTATION_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <jni.h>
#include <string>

#include "AIDA/IAnnotation.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * The annotation holds arbitrary information represented with (key,value) pairs
 * of strings. A sticky bit is associated to every item to protect it (or not)
 * from a reset operation.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JIAnnotation: public JProxy, public virtual AIDA::IAnnotation {

private:
    jmethodID keyOICLjava_lang_StringEMethod;
    jmethodID valueOICLjava_lang_StringEMethod;
    jmethodID valueOLjava_lang_StringECLjava_lang_StringEMethod;
    jmethodID setValueOLjava_lang_StringELjava_lang_StringECVMethod;
    jmethodID removeItemOLjava_lang_StringECVMethod;
    jmethodID sizeOCIMethod;
    jmethodID addItemOLjava_lang_StringELjava_lang_StringEZCVMethod;
    jmethodID resetOCVMethod;
    jmethodID setStickyOLjava_lang_StringEZCVMethod;

protected:
    inline JIAnnotation() { };
    inline JIAnnotation(const JIAnnotation& r):JProxy(r) { };
    inline JIAnnotation& operator=(const JIAnnotation&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JIAnnotation(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JIAnnotation();

  /**
   * Add a key/value pair with a given sticky flag.
   * If key alredy exists, override its value ?
   * @param key    The key to be added.
   * @param value  The key's value.
   * @param sticky The key's sticky flag. If <code>true</code> the item will
   *               not be removed when the method reset or removeItem are invoked.
   *               The default value for the sticky flag is <code>false</code>.
   * @return false If the key already exists.
   *
   */
    JNIEXPORT virtual bool addItem(const std::string & key, const std::string & value, bool sticky);

  /**
   * Remove the item indicated by a given key.
   * @param key The key to be removed. If the key is flagged as "sticky" it
   *            will not be removed.
   * @return false If the key is sticky.
   *
   */
    JNIEXPORT virtual bool removeItem(const std::string & key);

  /**
   * Retrieve the value for a given key.
   * @param key The key.
   * @return    The corresponding value.
   *
   */
    JNIEXPORT virtual std::string value(const std::string & key) const;

  /**
   * Set the value for a given key.
   * @param key   The key whose vale is to be changed.
   * @param value The new value.
   *
   */
    JNIEXPORT virtual void setValue(const std::string & key, const std::string & value);

  /**
   * Set the sticky flag for a given key.
   * @param key    The key whose stick flag is to be set.
   * @param sticky The new sticky flag.
   *
   */
    JNIEXPORT virtual void setSticky(const std::string & key, bool sticky);

  /**
   * Get the size of the IAnnotation, i.e. the number of keys contained in it.
   * @return The size of the IAnnotation.
   *
   */
    JNIEXPORT virtual int size() const;

  /**
   * Get the key at a given position within the IAnnotation.
   * @param index The key's position within the IAnnotation.
   * @return      The corresponding key.
   *
   */
    JNIEXPORT virtual std::string key(int index) const;

  /**
   * Get the value at a given position within the IAnnotation.
   * @param index The value's position within the IAnnotation.
   * @return      The corresponding value.
   *
   */
    JNIEXPORT virtual std::string value(int index) const;

  /**
   * Remove all the non-sticky items.
   *
   */
    JNIEXPORT virtual void reset();
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JIANNOTATION_H */
