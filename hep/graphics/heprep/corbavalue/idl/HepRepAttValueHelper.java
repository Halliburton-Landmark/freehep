package hep.graphics.heprep.corbavalue.idl;


/**
* hep/graphics/heprep/corbavalue/idl/HepRepAttValueHelper.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRepValue.idl
* Tuesday, June 10, 2003 10:19:18 AM PDT
*/


// Attribute Value
abstract public class HepRepAttValueHelper
{
  private static String  _id = "IDL:HepRepAttValue:1.0";


  public static void insert (org.omg.CORBA.Any a, hep.graphics.heprep.corbavalue.idl.HepRepAttValue that)
  {
    org.omg.CORBA.portable.OutputStream out = a.create_output_stream ();
    a.type (type ());
    write (out, that);
    a.read_value (out.create_input_stream (), type ());
  }

  public static hep.graphics.heprep.corbavalue.idl.HepRepAttValue extract (org.omg.CORBA.Any a)
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
          org.omg.CORBA.ValueMember[] _members0 = new org.omg.CORBA.ValueMember[3];
          org.omg.CORBA.TypeCode _tcOf_members0 = null;
          // ValueMember instance for name
          _tcOf_members0 = org.omg.CORBA.ORB.init ().create_string_tc (0);
          _members0[0] = new org.omg.CORBA.ValueMember ("name", 
              "", 
              _id, 
              "", 
              _tcOf_members0, 
              null, 
              org.omg.CORBA.PUBLIC_MEMBER.value);
          // ValueMember instance for value
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_any);
          _members0[1] = new org.omg.CORBA.ValueMember ("value", 
              "", 
              _id, 
              "", 
              _tcOf_members0, 
              null, 
              org.omg.CORBA.PUBLIC_MEMBER.value);
          // ValueMember instance for showLabel
          _tcOf_members0 = org.omg.CORBA.ORB.init ().get_primitive_tc (org.omg.CORBA.TCKind.tk_long);
          _members0[2] = new org.omg.CORBA.ValueMember ("showLabel", 
              "", 
              _id, 
              "", 
              _tcOf_members0, 
              null, 
              org.omg.CORBA.PUBLIC_MEMBER.value);
          __typeCode = org.omg.CORBA.ORB.init ().create_value_tc (_id, "HepRepAttValue", org.omg.CORBA.VM_NONE.value, null, _members0);
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

  public static hep.graphics.heprep.corbavalue.idl.HepRepAttValue read (org.omg.CORBA.portable.InputStream istream)
  {
    return (hep.graphics.heprep.corbavalue.idl.HepRepAttValue)((org.omg.CORBA_2_3.portable.InputStream) istream).read_value (id ());
  }

  public static void write (org.omg.CORBA.portable.OutputStream ostream, hep.graphics.heprep.corbavalue.idl.HepRepAttValue value)
  {
    ((org.omg.CORBA_2_3.portable.OutputStream) ostream).write_value (value, id ());
  }


}
