package hep.aida.ref.remote.corba.generated;


/**
* hep/aida/ref/remote/corba/generated/DataPointData.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/aida/ref/remote/corba/idl/InterfaceDef.idl
* Thursday, August 14, 2003 7:33:29 PM PDT
*/

public final class DataPointData implements org.omg.CORBA.portable.IDLEntity
{
  public int dimension = (int)0;
  public hep.aida.ref.remote.corba.generated.MeasurementData measurements[] = null;

  public DataPointData ()
  {
  } // ctor

  public DataPointData (int _dimension, hep.aida.ref.remote.corba.generated.MeasurementData[] _measurements)
  {
    dimension = _dimension;
    measurements = _measurements;
  } // ctor

} // class DataPointData
