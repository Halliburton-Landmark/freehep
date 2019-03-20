package hep.aida.ref.remote.corba.generated;


/**
* hep/aida/ref/remote/corba/generated/EventID.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/aida/ref/remote/corba/idl/InterfaceDef.idl
* Thursday, August 14, 2003 7:33:29 PM PDT
*/


// Specify what kind of change happened in ITree
public class EventID implements org.omg.CORBA.portable.IDLEntity
{
  private        int __value;
  private static int __size = 3;
  private static hep.aida.ref.remote.corba.generated.EventID[] __array = new hep.aida.ref.remote.corba.generated.EventID [__size];

  public static final int _NODE_UPDATED = 0;
  public static final hep.aida.ref.remote.corba.generated.EventID NODE_UPDATED = new hep.aida.ref.remote.corba.generated.EventID(_NODE_UPDATED);
  public static final int _NODE_ADDED = 1;
  public static final hep.aida.ref.remote.corba.generated.EventID NODE_ADDED = new hep.aida.ref.remote.corba.generated.EventID(_NODE_ADDED);
  public static final int _NODE_DELETED = 2;
  public static final hep.aida.ref.remote.corba.generated.EventID NODE_DELETED = new hep.aida.ref.remote.corba.generated.EventID(_NODE_DELETED);

  public int value ()
  {
    return __value;
  }

  public static hep.aida.ref.remote.corba.generated.EventID from_int (int value)
  {
    if (value >= 0 && value < __size)
      return __array[value];
    else
      throw new org.omg.CORBA.BAD_PARAM ();
  }

  protected EventID (int value)
  {
    __value = value;
    __array[__value] = this;
  }
} // class EventID