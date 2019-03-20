package hep.aida.ref.remote.corba.generated;


/**
* hep/aida/ref/remote/corba/generated/_TreeServerStub.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/aida/ref/remote/corba/idl/InterfaceDef.idl
* Thursday, August 14, 2003 7:33:29 PM PDT
*/


// with only one TreeClient.
public class _TreeServerStub extends org.omg.CORBA.portable.ObjectImpl implements hep.aida.ref.remote.corba.generated.TreeServer
{


  // Return the name of the ITree it is connected to.
  public String treeName ()
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("treeName", true);
                $in = _invoke ($out);
                String $result = $in.read_string ();
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return treeName (        );
            } finally {
                _releaseReply ($in);
            }
  } // treeName


  // support "Duplex Mode".
  public boolean supportDuplexMode ()
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("supportDuplexMode", true);
                $in = _invoke ($out);
                boolean $result = $in.read_boolean ();
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return supportDuplexMode (        );
            } finally {
                _releaseReply ($in);
            }
  } // supportDuplexMode


  // returned by TreeServer.
  public hep.aida.ref.remote.corba.generated.TreeServant connectNonDuplex (String clientID)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("connectNonDuplex", true);
                $out.write_string (clientID);
                $in = _invoke ($out);
                hep.aida.ref.remote.corba.generated.TreeServant $result = hep.aida.ref.remote.corba.generated.TreeServantHelper.read ($in);
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return connectNonDuplex (clientID        );
            } finally {
                _releaseReply ($in);
            }
  } // connectNonDuplex

  public boolean disconnectNonDuplex (String clientID)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("disconnectNonDuplex", true);
                $out.write_string (clientID);
                $in = _invoke ($out);
                boolean $result = $in.read_boolean ();
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return disconnectNonDuplex (clientID        );
            } finally {
                _releaseReply ($in);
            }
  } // disconnectNonDuplex


  // Here reference to instance of TreeClient serves as a unique client ID.
  public hep.aida.ref.remote.corba.generated.TreeServant connectDuplex (hep.aida.ref.remote.corba.generated.TreeClient client)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("connectDuplex", true);
                hep.aida.ref.remote.corba.generated.TreeClientHelper.write ($out, client);
                $in = _invoke ($out);
                hep.aida.ref.remote.corba.generated.TreeServant $result = hep.aida.ref.remote.corba.generated.TreeServantHelper.read ($in);
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return connectDuplex (client        );
            } finally {
                _releaseReply ($in);
            }
  } // connectDuplex

  public boolean disconnectDuplex (hep.aida.ref.remote.corba.generated.TreeClient client)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("disconnectDuplex", true);
                hep.aida.ref.remote.corba.generated.TreeClientHelper.write ($out, client);
                $in = _invoke ($out);
                boolean $result = $in.read_boolean ();
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return disconnectDuplex (client        );
            } finally {
                _releaseReply ($in);
            }
  } // disconnectDuplex

  // Type-specific CORBA::Object operations
  private static String[] __ids = {
    "IDL:hep/aida/ref/remote/corba/generated/TreeServer:1.0"};

  public String[] _ids ()
  {
    return (String[])__ids.clone ();
  }

  private void readObject (java.io.ObjectInputStream s) throws java.io.IOException
  {
     String str = s.readUTF ();
     String[] args = null;
     java.util.Properties props = null;
     org.omg.CORBA.Object obj = org.omg.CORBA.ORB.init (args, props).string_to_object (str);
     org.omg.CORBA.portable.Delegate delegate = ((org.omg.CORBA.portable.ObjectImpl) obj)._get_delegate ();
     _set_delegate (delegate);
  }

  private void writeObject (java.io.ObjectOutputStream s) throws java.io.IOException
  {
     String[] args = null;
     java.util.Properties props = null;
     String str = org.omg.CORBA.ORB.init (args, props).object_to_string (this);
     s.writeUTF (str);
  }
} // class _TreeServerStub
