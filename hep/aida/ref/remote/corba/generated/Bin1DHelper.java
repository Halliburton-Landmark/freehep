package hep.aida.ref.remote.corba.generated;


/**
* hep/aida/ref/remote/corba/generated/Bin1DHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/aida/ref/remote/corba/idl/InterfaceDef.idl
* Thursday, August 14, 2003 7:33:29 PM PDT
*/

abstract public class Bin1DHelper
{
  private static String  _id = "IDL:hep/aida/ref/remote/corba/generated/Bin1D:1.0";

  public static void insert (org.omg.CORBA.Any a, hep.aida.ref.remote.corba.generated.Bin1D that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static hep.aida.ref.remote.corba.generated.Bin1D extract (org.omg.CORBA.Any a)
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
          org.omg.CORBA.StructMember[] _members0 = new org.omg.CORBA.StructMember [8];
          org.omg.CORBA.TypeCode _tcOf_members0 = null;
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_long);
          _members0[0] = new org.omg.CORBA.StructMember (
            "binNum",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_double);
          _members0[1] = new org.omg.CORBA.StructMember (
            "weightedMean",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_double);
          _members0[2] = new org.omg.CORBA.StructMember (
            "weightedRms",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_double);
          _members0[3] = new org.omg.CORBA.StructMember (
            "height",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_double);
          _members0[4] = new org.omg.CORBA.StructMember (
            "error",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_double);
          _members0[5] = new org.omg.CORBA.StructMember (
            "error2",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_long);
          _members0[6] = new org.omg.CORBA.StructMember (
            "entries",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_double);
          _members0[7] = new org.omg.CORBA.StructMember (
            "rms",
            _tcOf_members0,
            null);
          __typeCode = org.omg.CORBA.ORB.init ().create_struct_tc (hep.aida.ref.remote.corba.generated.Bin1DHelper.id (), "Bin1D", _members0);
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

  public static hep.aida.ref.remote.corba.generated.Bin1D read (org.omg.CORBA.portable.InputStream istream)
  {
    hep.aida.ref.remote.corba.generated.Bin1D value = new hep.aida.ref.remote.corba.generated.Bin1D ();
    value.binNum = istream.read_long ();
    value.weightedMean = istream.read_double ();
    value.weightedRms = istream.read_double ();
    value.height = istream.read_double ();
    value.error = istream.read_double ();
    value.error2 = istream.read_double ();
    value.entries = istream.read_long ();
    value.rms = istream.read_double ();
    return value;
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, hep.aida.ref.remote.corba.generated.Bin1D value)
  {
    ostream.write_long (value.binNum);
    ostream.write_double (value.weightedMean);
    ostream.write_double (value.weightedRms);
    ostream.write_double (value.height);
    ostream.write_double (value.error);
    ostream.write_double (value.error2);
    ostream.write_long (value.entries);
    ostream.write_double (value.rms);
  }

}
