package hep.graphics.heprep.corbavalue.idl;

/**
* hep/graphics/heprep/corbavalue/idl/HepRepInstanceHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRepValue.idl
* Tuesday, June 10, 2003 10:19:18 AM PDT
*/


// Instance
public final class HepRepInstanceHolder implements org.omg.CORBA.portable.Streamable
{
  public hep.graphics.heprep.corbavalue.idl.HepRepInstance value = null;

  public HepRepInstanceHolder ()
  {
  }

  public HepRepInstanceHolder (hep.graphics.heprep.corbavalue.idl.HepRepInstance initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = hep.graphics.heprep.corbavalue.idl.HepRepInstanceHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    hep.graphics.heprep.corbavalue.idl.HepRepInstanceHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return hep.graphics.heprep.corbavalue.idl.HepRepInstanceHelper.type ();
  }

}
