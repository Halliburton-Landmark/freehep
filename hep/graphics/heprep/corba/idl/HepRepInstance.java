package hep.graphics.heprep.corba.idl;


/**
* hep/graphics/heprep/corba/idl/HepRepInstance.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRep.idl
* Tuesday, June 10, 2003 10:19:15 AM PDT
*/


// Instance
public final class HepRepInstance implements org.omg.CORBA.portable.IDLEntity
{
  public String typeName = null;

  // but that sort of recursion doesn't work.
  public hep.graphics.heprep.corba.idl.HepRepInstance instances[] = null;
  public hep.graphics.heprep.corba.idl.HepRepPoint points[] = null;
  public hep.graphics.heprep.corba.idl.HepRepAttValue attValues[] = null;

  public HepRepInstance ()
  {
  } // ctor

  public HepRepInstance (String _typeName, hep.graphics.heprep.corba.idl.HepRepInstance[] _instances, hep.graphics.heprep.corba.idl.HepRepPoint[] _points, hep.graphics.heprep.corba.idl.HepRepAttValue[] _attValues)
  {
    typeName = _typeName;
    instances = _instances;
    points = _points;
    attValues = _attValues;
  } // ctor

} // class HepRepInstance
