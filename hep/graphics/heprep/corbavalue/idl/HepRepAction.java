package hep.graphics.heprep.corbavalue.idl;


/**
* hep/graphics/heprep/corbavalue/idl/HepRepAction.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRepValue.idl
* Tuesday, June 10, 2003 10:19:18 AM PDT
*/


// Action
public abstract class HepRepAction implements org.omg.CORBA.portable.StreamableValue
{
  public String name = null;
  public String expression = null;

  private static String[] _truncatable_ids = {
    hep.graphics.heprep.corbavalue.idl.HepRepActionHelper.id ()
  };

  public String[] _truncatable_ids() {
    return _truncatable_ids;
  }

  public void _read (org.omg.CORBA.portable.InputStream istream)
  {
    this.name = istream.read_string ();
    this.expression = istream.read_string ();
  }

  public void _write (org.omg.CORBA.portable.OutputStream ostream)
  {
    ostream.write_string (this.name);
    ostream.write_string (this.expression);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return hep.graphics.heprep.corbavalue.idl.HepRepActionHelper.type ();
  }
} // class HepRepAction
