package hep.aida.ref.remote.corba.generated;


/**
* hep/aida/ref/remote/corba/generated/EventFlags.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/aida/ref/remote/corba/idl/InterfaceDef.idl
* Thursday, August 14, 2003 7:33:29 PM PDT
*/


// Specify if IManagedObject or Directory has been changed
public class EventFlags implements org.omg.CORBA.portable.IDLEntity
{
  private        int __value;
  private static int __size = 2;
  private static hep.aida.ref.remote.corba.generated.EventFlags[] __array = new hep.aida.ref.remote.corba.generated.EventFlags [__size];

  public static final int _OBJECT_MASK = 0;
  public static final hep.aida.ref.remote.corba.generated.EventFlags OBJECT_MASK = new hep.aida.ref.remote.corba.generated.EventFlags(_OBJECT_MASK);
  public static final int _FOLDER_MASK = 1;
  public static final hep.aida.ref.remote.corba.generated.EventFlags FOLDER_MASK = new hep.aida.ref.remote.corba.generated.EventFlags(_FOLDER_MASK);

  public int value ()
  {
    return __value;
  }

  public static hep.aida.ref.remote.corba.generated.EventFlags from_int (int value)
  {
    if (value >= 0 && value < __size)
      return __array[value];
    else
      throw new org.omg.CORBA.BAD_PARAM ();
  }

  protected EventFlags (int value)
  {
    __value = value;
    __array[__value] = this;
  }
} // class EventFlags