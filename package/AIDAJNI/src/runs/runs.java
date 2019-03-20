
import java.util.Properties; 

public class runs {

{
    try {
        System.out.print("Loading application library for '"+libname+"' ...");
        System.loadLibrary(libname);
        System.out.println("done.");
    } catch (UnsatisfiedLinkError e) {
        System.out.println("failed.");
	System.out.println();
        System.out.println("Make sure the following environment variable path points to");
	System.out.println("the directory where '"+System.mapLibraryName(libname)+"' sits.");
        System.out.println("Unix:        LD_LIBRARY_PATH");
        System.out.println("Windows:     PATH");
        System.out.println("MacOS X:     DYLD_LIBRARY_PATH");
	System.out.println();
        System.exit(1);
    } 
}

    private static String libname;

    public native int main(int argc, String[] argv);

    public static void main(String[] args) {
	if (args.length < 1) {
            System.out.println("Usage: java runs <application>");
            System.exit(1);
        }

        libname = args[0];

	runs app = new runs();

	// Set application name on Mac OS X
        System.setProperty("com.apple.mrj.application.apple.menu.about.name", args[0]);

	// run main 
        int rc = app.main(args.length, args);
//	System.exit(rc);
    }
}
