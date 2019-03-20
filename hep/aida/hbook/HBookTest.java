package hep.aida.hbook;

/*
 * This example demonstrate how to call HBOOK-AIDA from java
 *
 */
public class HBookTest {

    public static void main(String[] args) {
    	int hid=1;

    	HBook.hbook1(hid,"some random distribution",20000,-4.0f,4.0f,0.0f);

	    for (int i=0;i<100000;i++){
	        float r = 0;
		    for (int j=0; j<10; j++) { 
		        r += Math.random()-0.5;
		    }
		    HBook.hfill(hid,r,0.0f,1.0f);
	    }
	}
}
