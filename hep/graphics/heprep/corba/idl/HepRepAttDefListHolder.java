package hep.graphics.heprep.corba.idl;


/**
* hep/graphics/heprep/corba/idl/HepRepAttDefListHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRep.idl
* Tuesday, June 10, 2003 10:19:15 AM PDT
*/

public final class HepRepAttDefListHolder implements org.omg.CORBA.portable.Streamable
{
  public hep.graphics.heprep.corba.idl.HepRepAttDef value[] = null;

  public HepRepAttDefListHolder ()
  {
  }

  public HepRepAttDefListHolder (hep.graphics.heprep.corba.idl.HepRepAttDef[] initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = hep.graphics.heprep.corba.idl.HepRepAttDefListHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    hep.graphics.heprep.corba.idl.HepRepAttDefListHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return hep.graphics.heprep.corba.idl.HepRepAttDefListHelper.type ();
  }

}
