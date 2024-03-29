package hep.graphics.heprep.corba.idl;


/**
* hep/graphics/heprep/corba/idl/HepRepHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRep.idl
* Tuesday, June 10, 2003 10:19:16 AM PDT
*/


// HepRep
abstract public class HepRepHelper
{
  private static String  _id = "IDL:HepRep:1.0";

  public static void insert (org.omg.CORBA.Any a, hep.graphics.heprep.corba.idl.HepRep that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static hep.graphics.heprep.corba.idl.HepRep extract (org.omg.CORBA.Any a)
  {
    return read (a.create_input_stream ());
  }

  private static org.omg.CORBA.TypeCode __typeCode = null;
  synchronized public static org.omg.CORBA.TypeCode type ()
  {
    if (__typeCode == null)
    {
      __typeCode = org.omg.CORBA.ORB.init ().create_interface_tc (hep.graphics.heprep.corba.idl.HepRepHelper.id (), "HepRep");
    }
    return __typeCode;
  }

  public static String id ()
  {
    return _id;
  }

  public static hep.graphics.heprep.corba.idl.HepRep read (org.omg.CORBA.portable.InputStream istream)
  {
    return narrow (istream.read_Object (_HepRepStub.class));
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, hep.graphics.heprep.corba.idl.HepRep value)
  {
    ostream.write_Object ((org.omg.CORBA.Object) value);
  }

  public static hep.graphics.heprep.corba.idl.HepRep narrow (org.omg.CORBA.Object obj)
  {
    if (obj == null)
      return null;
    else if (obj instanceof hep.graphics.heprep.corba.idl.HepRep)
      return (hep.graphics.heprep.corba.idl.HepRep)obj;
    else if (!obj._is_a (id ()))
      throw new org.omg.CORBA.BAD_PARAM ();
    else
    {
      org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl)obj)._get_delegate ();
      hep.graphics.heprep.corba.idl._HepRepStub stub = new hep.graphics.heprep.corba.idl._HepRepStub ();
      stub._set_delegate(delegate);
      return stub;
    }
  }

}
