package hep.aida.ref.remote.corba.generated;


/**
* hep/aida/ref/remote/corba/generated/TreeServerOperations.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/aida/ref/remote/corba/idl/InterfaceDef.idl
* Thursday, August 14, 2003 7:33:29 PM PDT
*/


// with only one TreeClient.
public interface TreeServerOperations 
{

  // Return the name of the ITree it is connected to.
  String treeName ();

  // support "Duplex Mode".
  boolean supportDuplexMode ();

  // returned by TreeServer.
  hep.aida.ref.remote.corba.generated.TreeServant connectNonDuplex (String clientID);
  boolean disconnectNonDuplex (String clientID);

  // Here reference to instance of TreeClient serves as a unique client ID.
  hep.aida.ref.remote.corba.generated.TreeServant connectDuplex (hep.aida.ref.remote.corba.generated.TreeClient client);
  boolean disconnectDuplex (hep.aida.ref.remote.corba.generated.TreeClient client);
} // interface TreeServerOperations