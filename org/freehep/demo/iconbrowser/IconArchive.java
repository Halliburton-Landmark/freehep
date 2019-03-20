/*
 * IconArchive.java
 *
 * Created on March 15, 2001, 12:23 PM
 */


package org.freehep.demo.iconbrowser;

/**
 * An interface to be implemented by an IconArchive
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: IconArchive.java,v 1.1 2001/03/20 06:59:55 tonyj Exp $
 */
interface IconArchive extends IconDirectory
{
    void close();
}