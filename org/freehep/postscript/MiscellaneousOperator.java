// Copyright 2001, FreeHEP.
package org.freehep.postscript;

/**
 * Miscellaneous Operators for PostScript Processor
 *
 * @author Mark Donszelmann
 * @version $Id: MiscellaneousOperator.java,v 1.8 2004/01/12 20:19:14 duns Exp $
 */
public class MiscellaneousOperator extends PSOperator {
    
    public static Class[] operators = {
        Bind.class, Version.class, 
        RealTime.class, UserTime.class,
        Product.class, Revision.class, SerialNumber.class,
        Executive.class, Echo.class, Prompt.class
    };

    public boolean execute(OperandStack os) {
        throw new RuntimeException("Cannot execute class: "+getClass());
    }
}

class Bind extends MiscellaneousOperator {
    { operandTypes = new Class[] {PSPackedArray.class}; }

    public boolean execute(OperandStack os) {
        PSPackedArray p = os.popPackedArray();
        if (p.isLiteral()) {
            error(os, new TypeCheck());
        } else {
            bind(p, os.dictStack());
            os.push(p);
        }
        return true;
    }
    
    private void bind(PSPackedArray p, DictionaryStack ds) {
        if (p instanceof PSArray) {
            if (p.accessWrite()) {
                // Change access
                p.changeAccess(PSComposite.READ_ONLY);
            } else {
                // Do not change READ_ONLY Arrays
                return;
            }
        }
        
        // bind
        for (int i=0; i<p.size(); i++) {
            PSObject key = p.get(i);
            if ((key.isExecutable()) && (key instanceof PSName)) {
                PSObject value = ds.lookup(key);
                if (value instanceof PSOperator) {
                    // set operators
                    p.bind(i, (PSOperator)value);
                }
            } else if (key instanceof PackedArray) {
                // recurse into nested procedures
                bind((PSPackedArray)key, ds);
            }
        }
    }
}

class Version extends MiscellaneousOperator {
    public boolean execute(OperandStack os) {
        os.push(new PSString(2000));    // FIXME: look up what level we really support
        return true;
    }
}

class RealTime extends MiscellaneousOperator {
    public boolean execute(OperandStack os) {
        os.push(System.currentTimeMillis());
        return true;
    }
}

class UserTime extends MiscellaneousOperator {
    
    // FREEHEP-154: a better time measurement
    public boolean execute(OperandStack os) {
        os.push(System.currentTimeMillis());
        return true;
    }
}

class Product extends MiscellaneousOperator {
    public boolean execute(OperandStack os) {
        os.push(new PSString("FreeHEP Java PostScript Interpreter"));
        return true;
    }
}

class Revision extends MiscellaneousOperator {
    public boolean execute(OperandStack os) {
        os.push(new PSString("1.0.0"));
        return true;
    }
}

class SerialNumber extends MiscellaneousOperator {
    public boolean execute(OperandStack os) {
        // any number would do...
        os.push(9265294);
        return true;
    }
}

class Executive extends MiscellaneousOperator {
    public boolean execute(OperandStack os) {
        error(os, new Undefined());
        return true;
    }
}

class Echo extends MiscellaneousOperator {
    { operandTypes = new Class[] {PSBoolean.class}; }

    public boolean execute(OperandStack os) {
        error(os, new Undefined());
        return true;
    }
}

class Prompt extends MiscellaneousOperator {
    public boolean execute(OperandStack os) {
        error(os, new Undefined());
        return true;
    }
}
