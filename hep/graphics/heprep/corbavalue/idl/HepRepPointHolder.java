package hep.graphics.heprep.corbavalue.idl;

/**
* hep/graphics/heprep/corbavalue/idl/HepRepPointHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRepValue.idl
* Tuesday, June 10, 2003 10:19:18 AM PDT
*/


// Point
public final class HepRepPointHolder implements org.omg.CORBA.portable.Streamable
{
  public hep.graphics.heprep.corbavalue.idl.HepRepPoint value = null;

  public HepRepPointHolder ()
  {
  }

  public HepRepPointHolder (hep.graphics.heprep.corbavalue.idl.HepRepPoint initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = hep.graphics.heprep.corbavalue.idl.HepRepPointHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    hep.graphics.heprep.corbavalue.idl.HepRepPointHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return hep.graphics.heprep.corbavalue.idl.HepRepPointHelper.type ();
  }

}