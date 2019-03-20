package hep.aida.ref.remote.test.remoteAida;

import java.util.Vector;

import hep.aida.*;

/**
 *
 * @author tonyj
 * @version $Id: TestRUtils.java,v 1.3 2005/06/15 04:20:00 chuli Exp $
 */
public class TestRUtils {
		
	public TestRUtils(){
	}
    
	/**
	 * Sleep for a while before proceeding;
	 * @param 	awhile	the period of time to wait (in miliseconds);
	 * @see 	Thread
	 */
	public static void waitForAWhile(long awhile){
		try{
			Thread.sleep(awhile);
		} catch (InterruptedException ie){
			ie.printStackTrace();
		}
	}

	/**
	 * Check whether the String key is in the provided array of Strings;
	 * @param 	names 	an array of Strings;
	 * @param 	key 	the String to be checked;
	 * @return  true if key is in the provided array; otherwise, false.
	 * @see 	Vector
	 */
	public static boolean contains(String[] names, String key){
		Vector v = new Vector();
		for(int i = 0; i < names.length; i ++) {
			v.add(names[i]);
		}
		return v.contains(key);
	}
}
