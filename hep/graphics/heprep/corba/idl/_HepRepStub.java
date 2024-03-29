package hep.graphics.heprep.corba.idl;


/**
* hep/graphics/heprep/corba/idl/_HepRepStub.java .
* Generated by the IDL-to-Java compiler (portable), version "3.1"
* from hep/graphics/heprep/HepRep.idl
* Tuesday, June 10, 2003 10:19:16 AM PDT
*/


// HepRep
public class _HepRepStub extends org.omg.CORBA.portable.ObjectImpl implements hep.graphics.heprep.corba.idl.HepRep
{

  public hep.graphics.heprep.corba.idl.HepRepInstanceTree getInstanceTreeTop (String instanceTreeName, String instanceTreeVersion)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("getInstanceTreeTop", true);
                $out.write_string (instanceTreeName);
                $out.write_string (instanceTreeVersion);
                $in = _invoke ($out);
                hep.graphics.heprep.corba.idl.HepRepInstanceTree $result = hep.graphics.heprep.corba.idl.HepRepInstanceTreeHelper.read ($in);
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return getInstanceTreeTop (instanceTreeName, instanceTreeVersion        );
            } finally {
                _releaseReply ($in);
            }
  } // getInstanceTreeTop

  public hep.graphics.heprep.corba.idl.HepRepTypeTree getTypeTree (String typeTreeName, String typeTreeVersion)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("getTypeTree", true);
                $out.write_string (typeTreeName);
                $out.write_string (typeTreeVersion);
                $in = _invoke ($out);
                hep.graphics.heprep.corba.idl.HepRepTypeTree $result = hep.graphics.heprep.corba.idl.HepRepTypeTreeHelper.read ($in);
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return getTypeTree (typeTreeName, typeTreeVersion        );
            } finally {
                _releaseReply ($in);
            }
  } // getTypeTree

  public hep.graphics.heprep.corba.idl.HepRepInstanceTree getInstances (String instanceTreeName, String instanceTreeVersion, String[] typeNames)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("getInstances", true);
                $out.write_string (instanceTreeName);
                $out.write_string (instanceTreeVersion);
                hep.graphics.heprep.corba.idl.StringArrayHelper.write ($out, typeNames);
                $in = _invoke ($out);
                hep.graphics.heprep.corba.idl.HepRepInstanceTree $result = hep.graphics.heprep.corba.idl.HepRepInstanceTreeHelper.read ($in);
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return getInstances (instanceTreeName, instanceTreeVersion, typeNames        );
            } finally {
                _releaseReply ($in);
            }
  } // getInstances

  public hep.graphics.heprep.corba.idl.HepRepInstanceTree getInstancesAfterAction (String instanceTreeName, String instanceTreeVersion, String[] typeNames, hep.graphics.heprep.corba.idl.HepRepAction[] actions, boolean getPoints, boolean getDrawAtts, boolean getNonDrawAtts, String[] invertAtts)
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("getInstancesAfterAction", true);
                $out.write_string (instanceTreeName);
                $out.write_string (instanceTreeVersion);
                hep.graphics.heprep.corba.idl.StringArrayHelper.write ($out, typeNames);
                hep.graphics.heprep.corba.idl.HepRepActionListHelper.write ($out, actions);
                $out.write_boolean (getPoints);
                $out.write_boolean (getDrawAtts);
                $out.write_boolean (getNonDrawAtts);
                hep.graphics.heprep.corba.idl.StringArrayHelper.write ($out, invertAtts);
                $in = _invoke ($out);
                hep.graphics.heprep.corba.idl.HepRepInstanceTree $result = hep.graphics.heprep.corba.idl.HepRepInstanceTreeHelper.read ($in);
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return getInstancesAfterAction (instanceTreeName, instanceTreeVersion, typeNames, actions, getPoints, getDrawAtts, getNonDrawAtts, invertAtts        );
            } finally {
                _releaseReply ($in);
            }
  } // getInstancesAfterAction

  public String[] getLayerOrder ()
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("getLayerOrder", true);
                $in = _invoke ($out);
                String $result[] = hep.graphics.heprep.corba.idl.StringArrayHelper.read ($in);
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return getLayerOrder (        );
            } finally {
                _releaseReply ($in);
            }
  } // getLayerOrder

  public String checkForException ()
  {
            org.omg.CORBA.portable.InputStream $in = null;
            try {
                org.omg.CORBA.portable.OutputStream $out = _request ("checkForException", true);
                $in = _invoke ($out);
                String $result = $in.read_string ();
                return $result;
            } catch (org.omg.CORBA.portable.ApplicationException $ex) {
                $in = $ex.getInputStream ();
                String _id = $ex.getId ();
                throw new org.omg.CORBA.MARSHAL (_id);
            } catch (org.omg.CORBA.portable.RemarshalException $rm) {
                return checkForException (        );
            } finally {
                _releaseReply ($in);
            }
  } // checkForException

  // Type-specific CORBA::Object operations
  private static String[] __ids = {
    "IDL:HepRep:1.0"};

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
} // class _HepRepStub
