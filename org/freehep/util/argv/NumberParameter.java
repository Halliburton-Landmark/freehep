// Copyright 2004, FreeHEP.
package org.freehep.util.argv;

import java.util.*;
import java.io.PrintWriter;
import java.math.BigDecimal;

/**
 * A Number Parameter for use with ArgumentParser.
 *
 * @author Mark Donszelmann
 * @version $Id: NumberParameter.java,v 1.1 2004/01/12 20:19:26 duns Exp $
 */ 

public class NumberParameter implements Parameter {
    private String name;
    private String desc;
    private BigDecimal value = null;

    /**
     * Initialize a new Number parameter.
     */

    public NumberParameter( String name, String description ) {
        this.name = name;
        this.desc = description;
    }

    /**
     * Return the value of this argument, which may be null. Returns the
     * default value if the value was not set when the command line was parsed.
     */

    public BigDecimal getValue() {
        return value;
    }

    /**
     * Parsing method invoked by ArgumentParser.
     */

    public int parse( List values ) throws MissingArgumentException, ArgumentFormatException {
        if( values.size() < 1 ) {
            throw new MissingArgumentException( "Parameter '"+name+"' of type <number> expected" );
        }

        try {
            value = new BigDecimal((String)values.get( 0 ));
        } catch (NumberFormatException nfe) {
            throw new ArgumentFormatException( "For parameter '"+name+"' '"+values.get(1)+"' is not a <number>" );
        }
        return 1;
    }

    public String getName() {
        return "<"+name+">";
    }
    
    /**
     * Usage method invoked by ArgumentParser.
     */

    public String getUsage() {
        return desc;
    }
}
