package hep.aida.ref.remote.corba.generated;


/**
* hep/aida/ref/remote/corba/generated/DataPointSetDataHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/aida/ref/remote/corba/idl/InterfaceDef.idl
* Thursday, August 14, 2003 7:33:29 PM PDT
*/

abstract public class DataPointSetDataHelper
{
  private static String  _id = "IDL:hep/aida/ref/remote/corba/generated/DataPointSetData:1.0";

  public static void insert (org.omg.CORBA.Any a, hep.aida.ref.remote.corba.generated.DataPointSetData that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static hep.aida.ref.remote.corba.generated.DataPointSetData extract (org.omg.CORBA.Any a)
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
            "name",
            _tcOf_members0,
            null);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_long);
          _members0[1] = new org.omg.CORBA.StructMember (
            "dimension",
            _tcOf_members0,
            null);
          _tcOf_members0 = hep.aida.ref.remote.corba.generated.AnnotationItemHelper.type ();
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_sequence_tc (0, _tcOf_members0);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_alias_tc (hep.aida.ref.remote.corba.generated.AnnotationHelper.id (), "Annotation", _tcOf_members0);
          _members0[2] = new org.omg.CORBA.StructMember (
            "annotation",
            _tcOf_members0,
            null);
          _tcOf_members0 = hep.aida.ref.remote.corba.generated.DataPointDataHelper.type ();
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_sequence_tc (0, _tcOf_members0);
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_alias_tc (hep.aida.ref.remote.corba.generated.DataPointDataListHelper.id (), "DataPointDataList", _tcOf_members0);
          _members0[3] = new org.omg.CORBA.StructMember (
            "points",
            _tcOf_members0,
            null);
          __typeCode = org.omg.CORBA.ORB.init ().create_struct_tc (hep.aida.ref.remote.corba.generated.DataPointSetDataHelper.id (), "DataPointSetData", _members0);
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

  public static hep.aida.ref.remote.corba.generated.DataPointSetData read (org.omg.CORBA.portable.InputStream istream)
  {
    hep.aida.ref.remote.corba.generated.DataPointSetData value = new hep.aida.ref.remote.corba.generated.DataPointSetData ();
    value.name = istream.read_string ();
    value.dimension = istream.read_long ();
    value.annotation = hep.aida.ref.remote.corba.generated.AnnotationHelper.read (istream);
    value.points = hep.aida.ref.remote.corba.generated.DataPointDataListHelper.read (istream);
    return value;
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, hep.aida.ref.remote.corba.generated.DataPointSetData value)
  {
    ostream.write_string (value.name);
    ostream.write_long (value.dimension);
    hep.aida.ref.remote.corba.generated.AnnotationHelper.write (ostream, value.annotation);
    hep.aida.ref.remote.corba.generated.DataPointDataListHelper.write (ostream, value.points);
  }

}