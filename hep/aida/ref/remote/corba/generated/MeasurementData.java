package hep.aida.ref.remote.corba.generated;


/**
* hep/aida/ref/remote/corba/generated/MeasurementData.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/aida/ref/remote/corba/idl/InterfaceDef.idl
* Thursday, August 14, 2003 7:33:29 PM PDT
*/

public final class MeasurementData implements org.omg.CORBA.portable.IDLEntity
{
  public double value = (double)0;
  public double errorPlus = (double)0;
  public double errorMinus = (double)0;

  public MeasurementData ()
  {
  } // ctor

  public MeasurementData (double _value, double _errorPlus, double _errorMinus)
  {
    value = _value;
    errorPlus = _errorPlus;
    errorMinus = _errorMinus;
  } // ctor

} // class MeasurementData
