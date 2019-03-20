package hep.graphics.heprep.corba.idl;


/**
* hep/graphics/heprep/corba/idl/HepRepInstanceHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRep.idl
* Tuesday, June 10, 2003 10:19:15 AM PDT
*/


// Instance
abstract public class HepRepInstanceHelper
{
  private static String  _id = "IDL:HepRepInstance:1.0";

  public static void insert (org.omg.CORBA.Any a, hep.graphics.heprep.corba.idl.HepRepInstance that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static hep.graphics.heprep.corba.idl.HepRepInstance extract (org.omg.CORBA.Any a)
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
          org.omg.CORBA.StructMember[] _members0 = new org.omg.CORBA.StructMember [4];
          org.omg.CORBA.TypeCode _tcOf_members0 = null;
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_string_tc (0);
          _members0[0] = new org.omg.CORBA.StructMember (
            "typeName",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_recursive_tc ("");
          _members0[1] = new org.omg.CORBA.StructMember (
            "instances",
            _tcOf_members0,
            null);
          _tcOf_members0 = hep.graphics.heprep.corba.idl.HepRepPointHelper.type ();
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_sequence_tc (0, _tcOf_members0);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_alias_tc (hep.graphics.heprep.corba.idl.HepRepPointListHelper.id (), "HepRepPointList", _tcOf_members0);
          _members0[2] = new org.omg.CORBA.StructMember (
            "points",
            _tcOf_members0,
            null);
          _tcOf_members0 = hep.graphics.heprep.corba.idl.HepRepAttValueHelper.type ();
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_sequence_tc (0, _tcOf_members0);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_alias_tc (hep.graphics.heprep.corba.idl.HepRepAttValueListHelper.id (), "HepRepAttValueList", _tcOf_members0);
          _members0[3] = new org.omg.CORBA.StructMember (
            "attValues",
            _tcOf_members0,
            null);
          __typeCode = org.omg.CORBA.ORB.init ().create_struct_tc (hep.graphics.heprep.corba.idl.HepRepInstanceHelper.id (), "HepRepInstance", _members0);
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

  public static hep.graphics.heprep.corba.idl.HepRepInstance read (org.omg.CORBA.portable.InputStream istream)
  {
    hep.graphics.heprep.corba.idl.HepRepInstance value = new hep.graphics.heprep.corba.idl.HepRepInstance ();
    value.typeName = istream.read_string ();
    int _len0 = istream.read_long ();
    value.instances = new hep.graphics.heprep.corba.idl.HepRepInstance[_len0];
    for (int _o1 = 0;_o1 < value.instances.length; ++_o1)
      value.instances[_o1] = hep.graphics.heprep.corba.idl.HepRepInstanceHelper.read (istream);
    value.points = hep.graphics.heprep.corba.idl.HepRepPointListHelper.read (istream);
    value.attValues = hep.graphics.heprep.corba.idl.HepRepAttValueListHelper.read (istream);
    return value;
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, hep.graphics.heprep.corba.idl.HepRepInstance value)
  {
    ostream.write_string (value.typeName);
    ostream.write_long (value.instances.length);
    for (int _i0 = 0;_i0 < value.instances.length; ++_i0)
      hep.graphics.heprep.corba.idl.HepRepInstanceHelper.write (ostream, value.instances[_i0]);
    hep.graphics.heprep.corba.idl.HepRepPointListHelper.write (ostream, value.points);
    hep.graphics.heprep.corba.idl.HepRepAttValueListHelper.write (ostream, value.attValues);
  }

}