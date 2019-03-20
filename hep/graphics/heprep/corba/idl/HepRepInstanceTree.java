package hep.graphics.heprep.corba.idl;


/**
* hep/graphics/heprep/corba/idl/HepRepInstanceTree.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRep.idl
* Tuesday, June 10, 2003 10:19:15 AM PDT
*/


// InstanceTree
public final class HepRepInstanceTree implements org.omg.CORBA.portable.IDLEntity
{
  public hep.graphics.heprep.corba.idl.HepRepTreeID id = null;
  public hep.graphics.heprep.corba.idl.HepRepTreeID typeTreeID = null;
  public hep.graphics.heprep.corba.idl.HepRepTreeID instanceTreeIDs[] = null;
  public hep.graphics.heprep.corba.idl.HepRepInstance instances[] = null;

  public HepRepInstanceTree ()
  {
  } // ctor

  public HepRepInstanceTree (hep.graphics.heprep.corba.idl.HepRepTreeID _id, hep.graphics.heprep.corba.idl.HepRepTreeID _typeTreeID, hep.graphics.heprep.corba.idl.HepRepTreeID[] _instanceTreeIDs, hep.graphics.heprep.corba.idl.HepRepInstance[] _instances)
  {
    id = _id;
    typeTreeID = _typeTreeID;
    instanceTreeIDs = _instanceTreeIDs;
    instances = _instances;
  } // ctor

} // class HepRepInstanceTree
