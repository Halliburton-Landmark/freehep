package hep.aida.ref.remote.corba.generated;

/**
* hep/aida/ref/remote/corba/generated/StatisticsHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/aida/ref/remote/corba/idl/InterfaceDef.idl
* Thursday, August 14, 2003 7:33:29 PM PDT
*/

public final class StatisticsHolder implements org.omg.CORBA.portable.Streamable
{
  public hep.aida.ref.remote.corba.generated.Statistics value = null;

  public StatisticsHolder ()
  {
  }

  public StatisticsHolder (hep.aida.ref.remote.corba.generated.Statistics initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = hep.aida.ref.remote.corba.generated.StatisticsHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    hep.aida.ref.remote.corba.generated.StatisticsHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return hep.aida.ref.remote.corba.generated.StatisticsHelper.type ();
  }

}
