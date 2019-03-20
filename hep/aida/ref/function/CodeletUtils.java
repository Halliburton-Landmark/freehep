package hep.aida.ref.function;

/**
 *
 * @author The FreeHEP team @ SLAC.
 *
 */
abstract class CodeletUtils {
    
    private static String EMPTY_STRING = "";
    
    protected static String modelFromCodelet(String codeletString) {
        int index = codeletString.indexOf(":", FunctionCatalog.prefix.length());
        if ( index < 0 )
            return EMPTY_STRING;
	return codeletString.substring(FunctionCatalog.prefix.length(), index).trim();
    }
    
    protected static String locationFromCodelet(String codeletString) {
        int index = codeletString.indexOf(":", FunctionCatalog.prefix.length());
        if ( index < 0 )
            return EMPTY_STRING;
	return codeletString.substring(index+1);
    }
    
    protected static boolean isCodeletFromCatalog(String codeletString) {
	return (locationFromCodelet(codeletString).trim().toLowerCase().startsWith("catalog"));
    }

    protected static boolean isCodeletFromScript(String codeletString) {
	return (locationFromCodelet(codeletString).trim().toLowerCase().startsWith("verbatim:jel "));
    }
    
    protected static boolean isCodeletFromFile(String codeletString) {
	return (locationFromCodelet(codeletString).trim().toLowerCase().startsWith("file:"));
    }
}
