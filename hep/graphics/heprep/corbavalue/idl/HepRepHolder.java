package hep.graphics.heprep.corbavalue.idl;

/**
* hep/graphics/heprep/corbavalue/idl/HepRepHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRepValue.idl
* Tuesday, June 10, 2003 10:19:18 AM PDT
*/


// HepRep
public final class HepRepHolder implements org.omg.CORBA.portable.Streamable
{
  public hep.graphics.heprep.corbavalue.idl.HepRep value = null;

  public HepRepHolder ()
  {
  }

  public HepRepHolder (hep.graphics.heprep.corbavalue.idl.HepRep initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = hep.graphics.heprep.corbavalue.idl.HepRepHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    hep.graphics.heprep.corbavalue.idl.HepRepHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return hep.graphics.heprep.corbavalue.idl.HepRepHelper.type ();
  }

}
