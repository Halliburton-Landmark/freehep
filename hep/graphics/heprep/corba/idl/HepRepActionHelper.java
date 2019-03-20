package hep.graphics.heprep.corba.idl;


/**
* hep/graphics/heprep/corba/idl/HepRepActionHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRep.idl
* Tuesday, June 10, 2003 10:19:15 AM PDT
*/


// Action
abstract public class HepRepActionHelper
{
  private static String  _id = "IDL:HepRepAction:1.0";

  public static void insert (org.omg.CORBA.Any a, hep.graphics.heprep.corba.idl.HepRepAction that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static hep.graphics.heprep.corba.idl.HepRepAction extract (org.omg.CORBA.Any a)
  {
    return read (a.create_input_stream ());
  }

  private static org.omg.CORBA.TypeCode __typeCode = null;
  private static boolean __active = false;
  synchronized public static org.omg.CORBA.TypeCode type ()
  {
    if (__typeCode == null)
    {
      synchronized (org.omg.CORBA.TypeCode.class)
      {
        if (__typeCode == null)
        {
          if (__active)
          {
            return org.omg.CORBA.ORB.init().create_recursive_tc ( _id );
          }
          __active = true;
          org.omg.CORBA.StructMember[] _members0 = new org.omg.CORBA.StructMember [2];
          org.omg.CORBA.TypeCode _tcOf_members0 = null;
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_string_tc (0);
          _members0[0] = new org.omg.CORBA.StructMember (
            "name",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_string_tc (0);
          _members0[1] = new org.omg.CORBA.StructMember (
            "expression",
            _tcOf_members0,
            null);
          __typeCode = org.omg.CORBA.ORB.init ().create_struct_tc (hep.graphics.heprep.corba.idl.HepRepActionHelper.id (), "HepRepAction", _members0);
          __active = false;
        }
      }
    }
    return __typeCode;
  }

  public static String id ()
  {
    return _id;
  }

  public static hep.graphics.heprep.corba.idl.HepRepAction read (org.omg.CORBA.portable.InputStream istream)
  {
    hep.graphics.heprep.corba.idl.HepRepAction value = new hep.graphics.heprep.corba.idl.HepRepAction ();
    value.name = istream.read_string ();
    value.expression = istream.read_string ();
    return value;
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, hep.graphics.heprep.corba.idl.HepRepAction value)
  {
    ostream.write_string (value.name);
    ostream.write_string (value.expression);
  }

}
