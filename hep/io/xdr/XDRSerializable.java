package hep.io.xdr;

import java.io.IOException;

/**
 * An interface to be implemented by objects than
 * can be read and written using XDR
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: XDRSerializable.java,v 1.3 2003/09/16 23:11:55 tonyj Exp $
 */
public interface XDRSerializable
{
   public void read(XDRDataInput in) throws IOException;

   public void write(XDRDataOutput out) throws IOException;
}
