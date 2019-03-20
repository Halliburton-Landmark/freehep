package hep.graphics.heprep.corbavalue.idl;


/**
* hep/graphics/heprep/corbavalue/idl/HepRepPoint.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRepValue.idl
* Tuesday, June 10, 2003 10:19:18 AM PDT
*/


// Point
public abstract class HepRepPoint extends hep.graphics.heprep.corbavalue.idl.HepRepAttribute
{
  public hep.graphics.heprep.corbavalue.idl.HepRepInstance instance = null;
  public double x = (double)0;
  public double y = (double)0;
  public double z = (double)0;

  private static String[] _truncatable_ids = {
    hep.graphics.heprep.corbavalue.idl.HepRepPointHelper.id ()
  };

  public String[] _truncatable_ids() {
    return _truncatable_ids;
  }

  public void _read (org.omg.CORBA.portable.InputStream istream)
  {
    super._read (istream);
    this.instance = hep.graphics.heprep.corbavalue.idl.HepRepInstanceHelper.read (istream);
    this.x = istream.read_double ();
    this.y = istream.read_double ();
    this.z = istream.read_double ();
  }

  public void _write (org.omg.CORBA.portable.OutputStream ostream)
  {
    super._write (ostream);
    hep.graphics.heprep.corbavalue.idl.HepRepInstanceHelper.write (ostream, this.instance);
    ostream.write_double (this.x);
    ostream.write_double (this.y);
    ostream.write_double (this.z);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return hep.graphics.heprep.corbavalue.idl.HepRepPointHelper.type ();
  }
} // class HepRepPoint