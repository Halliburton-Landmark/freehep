package hep.graphics.heprep.corbavalue.idl;


/**
* hep/graphics/heprep/corbavalue/idl/StringArrayHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRepValue.idl
* Tuesday, June 10, 2003 10:19:18 AM PDT
*/

public final class StringArrayHelper implements org.omg.CORBA.portable.BoxedValueHelper
{
  private static String  _id = "IDL:StringArray:1.0";

  private static StringArrayHelper _instance = new StringArrayHelper ();


  public StringArrayHelper()
  {
  }

  public static void insert (org.omg.CORBA.Any a, String[] that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static String[] extract (org.omg.CORBA.Any a)
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
          __typeCode = org.omg.CORBA.ORB.init ().create_string_tc (0);
          __typeCode = org.omg.CORBA.ORB.init ().create_sequence_tc (0, __typeCode);
          __typeCode = org.omg.CORBA.ORB.init ().create_value_box_tc (_id, "StringArray", __typeCode);
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

  public static String[] read (org.omg.CORBA.portable.InputStream istream)
  {
    if (!(istream instanceof org.omg.CORBA_2_3.portable.InputStream)) {
      throw new org.omg.CORBA.BAD_PARAM(); }
    return (String[]) ((org.omg.CORBA_2_3.portable.InputStream) istream).read_value (_instance);
  }

  public java.io.Serializable read_value (org.omg.CORBA.portable.InputStream istream)
  {
    String[] tmp;
    int _len0 = istream.read_long ();
    tmp = new String[_len0];
    for (int _o1 = 0;_o1 < tmp.length; ++_o1)
      tmp[_o1] = istream.read_string ();
    return (java.io.Serializable) tmp;
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, String[] value)
  {
    if (!(ostream instanceof org.omg.CORBA_2_3.portable.OutputStream)) {
      throw new org.omg.CORBA.BAD_PARAM(); }
    ((org.omg.CORBA_2_3.portable.OutputStream) ostream).write_value (value, _instance);
  }

  public void write_value (org.omg.CORBA.portable.OutputStream ostream, java.io.Serializable value)
  {
    if (!(value instanceof String[])) {
      throw new org.omg.CORBA.MARSHAL(); }
    String[] valueType = (String[]) value;
    ostream.write_long (valueType.length);
    for (int _i0 = 0;_i0 < valueType.length; ++_i0)
      ostream.write_string (valueType[_i0]);
  }

  public String get_id ()
  {
    return _id;
  }

}
