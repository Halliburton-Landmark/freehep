package hep.aida.ref.remote.corba.generated;


/**
* hep/aida/ref/remote/corba/generated/HistInfo1DHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/aida/ref/remote/corba/idl/InterfaceDef.idl
* Thursday, August 14, 2003 7:33:29 PM PDT
*/

abstract public class HistInfo1DHelper
{
  private static String  _id = "IDL:hep/aida/ref/remote/corba/generated/HistInfo1D:1.0";

  public static void insert (org.omg.CORBA.Any a, hep.aida.ref.remote.corba.generated.HistInfo1D that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static hep.aida.ref.remote.corba.generated.HistInfo1D extract (org.omg.CORBA.Any a)
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
          org.omg.CORBA.StructMember[] _members0 = new org.omg.CORBA.StructMember [7];
          org.omg.CORBA.TypeCode _tcOf_members0 = null;
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_long);
          _members0[0] = new org.omg.CORBA.StructMember (
            "entries",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_long);
          _members0[1] = new org.omg.CORBA.StructMember (
            "allEntries",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_double);
          _members0[2] = new org.omg.CORBA.StructMember (
            "equivalentBinEntries",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_double);
          _members0[3] = new org.omg.CORBA.StructMember (
            "maxBinHeight",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_double);
          _members0[4] = new org.omg.CORBA.StructMember (
            "minBinHeight",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_double);
          _members0[5] = new org.omg.CORBA.StructMember (
            "sumBinHeights",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_double);
          _members0[6] = new org.omg.CORBA.StructMember (
            "sumAllBinHeights",
            _tcOf_members0,
            null);
          __typeCode = org.omg.CORBA.ORB.init ().create_struct_tc (hep.aida.ref.remote.corba.generated.HistInfo1DHelper.id (), "HistInfo1D", _members0);
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

  public static hep.aida.ref.remote.corba.generated.HistInfo1D read (org.omg.CORBA.portable.InputStream istream)
  {
    hep.aida.ref.remote.corba.generated.HistInfo1D value = new hep.aida.ref.remote.corba.generated.HistInfo1D ();
    value.entries = istream.read_long ();
    value.allEntries = istream.read_long ();
    value.equivalentBinEntries = istream.read_double ();
    value.maxBinHeight = istream.read_double ();
    value.minBinHeight = istream.read_double ();
    value.sumBinHeights = istream.read_double ();
    value.sumAllBinHeights = istream.read_double ();
    return value;
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, hep.aida.ref.remote.corba.generated.HistInfo1D value)
  {
    ostream.write_long (value.entries);
    ostream.write_long (value.allEntries);
    ostream.write_double (value.equivalentBinEntries);
    ostream.write_double (value.maxBinHeight);
    ostream.write_double (value.minBinHeight);
    ostream.write_double (value.sumBinHeights);
    ostream.write_double (value.sumAllBinHeights);
  }

}
