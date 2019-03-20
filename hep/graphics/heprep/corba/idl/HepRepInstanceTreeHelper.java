package hep.graphics.heprep.corba.idl;


/**
* hep/graphics/heprep/corba/idl/HepRepInstanceTreeHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRep.idl
* Tuesday, June 10, 2003 10:19:15 AM PDT
*/


// InstanceTree
abstract public class HepRepInstanceTreeHelper
{
  private static String  _id = "IDL:HepRepInstanceTree:1.0";

  public static void insert (org.omg.CORBA.Any a, hep.graphics.heprep.corba.idl.HepRepInstanceTree that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static hep.graphics.heprep.corba.idl.HepRepInstanceTree extract (org.omg.CORBA.Any a)
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
          _tcOf_members0 = hep.graphics.heprep.corba.idl.HepRepTreeIDHelper.type ();
          _members0[0] = new org.omg.CORBA.StructMember (
            "id",
            _tcOf_members0,
            null);
          _tcOf_members0 = hep.graphics.heprep.corba.idl.HepRepTreeIDHelper.type ();
          _members0[1] = new org.omg.CORBA.StructMember (
            "typeTreeID",
            _tcOf_members0,
            null);
          _tcOf_members0 = hep.graphics.heprep.corba.idl.HepRepTreeIDHelper.type ();
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_sequence_tc (0, _tcOf_members0);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_alias_tc (hep.graphics.heprep.corba.idl.HepRepTreeIDListHelper.id (), "HepRepTreeIDList", _tcOf_members0);
          _members0[2] = new org.omg.CORBA.StructMember (
            "instanceTreeIDs",
            _tcOf_members0,
            null);
          _tcOf_members0 = hep.graphics.heprep.corba.idl.HepRepInstanceHelper.type ();
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_sequence_tc (0, _tcOf_members0);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_alias_tc (hep.graphics.heprep.corba.idl.HepRepInstanceListHelper.id (), "HepRepInstanceList", _tcOf_members0);
          _members0[3] = new org.omg.CORBA.StructMember (
            "instances",
            _tcOf_members0,
            null);
          __typeCode = org.omg.CORBA.ORB.init ().create_struct_tc (hep.graphics.heprep.corba.idl.HepRepInstanceTreeHelper.id (), "HepRepInstanceTree", _members0);
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

  public static hep.graphics.heprep.corba.idl.HepRepInstanceTree read (org.omg.CORBA.portable.InputStream istream)
  {
    hep.graphics.heprep.corba.idl.HepRepInstanceTree value = new hep.graphics.heprep.corba.idl.HepRepInstanceTree ();
    value.id = hep.graphics.heprep.corba.idl.HepRepTreeIDHelper.read (istream);
    value.typeTreeID = hep.graphics.heprep.corba.idl.HepRepTreeIDHelper.read (istream);
    value.instanceTreeIDs = hep.graphics.heprep.corba.idl.HepRepTreeIDListHelper.read (istream);
    value.instances = hep.graphics.heprep.corba.idl.HepRepInstanceListHelper.read (istream);
    return value;
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, hep.graphics.heprep.corba.idl.HepRepInstanceTree value)
  {
    hep.graphics.heprep.corba.idl.HepRepTreeIDHelper.write (ostream, value.id);
    hep.graphics.heprep.corba.idl.HepRepTreeIDHelper.write (ostream, value.typeTreeID);
    hep.graphics.heprep.corba.idl.HepRepTreeIDListHelper.write (ostream, value.instanceTreeIDs);
    hep.graphics.heprep.corba.idl.HepRepInstanceListHelper.write (ostream, value.instances);
  }

}