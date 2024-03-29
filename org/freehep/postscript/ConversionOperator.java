// Copyright 2001-2004, FreeHEP.
package org.freehep.postscript;

/**
 * Type, Attribute and Conversion Operators for PostScript Processor
 *
 * @author Mark Donszelmann
 * @version $Id: ConversionOperator.java,v 1.7 2004/01/12 20:19:13 duns Exp $
 */
public class ConversionOperator extends PSOperator {
    
    public static Class[] operators = {
        Type.class, CvLit.class, CvX.class, XCheck.class, 
        ExecuteOnly.class, NoAccess.class, ReadOnly.class, 
        RCheck.class, WCheck.class, CvI.class, CvN.class,
        CvR.class, CvRS.class, CvS.class
    };

    public boolean execute(OperandStack os) {
        throw new RuntimeException("Cannot execute class: "+getClass());
    }
}

class Type extends ConversionOperator {
    { operandTypes = new Class[] {PSObject.class}; }

    public boolean execute(OperandStack os) {
        PSObject o = os.popObject();
        os.push(new PSName(o.getType()));
        return true;
    }
}

class CvLit extends ConversionOperator {
    { operandTypes = new Class[] {PSObject.class}; }

    public boolean execute(OperandStack os) {
        PSObject o = os.popObject();
        o.setLiteral();
        os.push(o);
        return true;
    }
}

class CvX extends ConversionOperator {
    { operandTypes = new Class[] {PSObject.class}; }

    public boolean execute(OperandStack os) {
        PSObject o = os.popObject();
        o.setExecutable();
        os.push(o);
        return true;
    }
}

class XCheck extends ConversionOperator {
    { operandTypes = new Class[] {PSObject.class}; }

    public boolean execute(OperandStack os) {
        PSObject o = os.popObject();
        os.push(o.isExecutable());
        return true;
    }
}

class ExecuteOnly extends ConversionOperator {
    { operandTypes = new Class[] {PSComposite.class}; }

    public boolean execute(OperandStack os) {
        PSComposite o = os.popComposite();
        o.changeAccess(PSComposite.EXECUTE_ONLY);
        os.push(o);
        return true;
    }
}

class NoAccess extends ConversionOperator {
    { operandTypes = new Class[] {PSComposite.class}; }

    public boolean execute(OperandStack os) {
        PSComposite o = os.popComposite();
        // FIXME: handle dictionary case
        // FIXME: handle InvalidAccess
        o.changeAccess(PSComposite.NONE);
        os.push(o);
        return true;
    }
}

class ReadOnly extends ConversionOperator {
    { operandTypes = new Class[] {PSComposite.class}; }

    public boolean execute(OperandStack os) {
        PSComposite o = os.popComposite();
        // FIXME: handle dictionary case
        o.changeAccess(PSComposite.READ_ONLY);
        os.push(o);
        return true;
    }
}

class RCheck extends ConversionOperator {
    { operandTypes = new Class[] {PSComposite.class}; }

    public boolean execute(OperandStack os) {
        PSComposite o = os.popComposite();
        os.push(o.accessRead());
        return true;
    }
}

class WCheck extends ConversionOperator {
    { operandTypes = new Class[] {PSComposite.class}; }

    public boolean execute(OperandStack os) {
        PSComposite o = os.popComposite();
        os.push(o.accessWrite());
        return true;
    }
}

class CvI extends ConversionOperator {
    { operandTypes = new Class[] {PSObject.class}; }

    public boolean execute(OperandStack os) {
        try {
            if (os.checkType(PSNumber.class)) {
                PSNumber n = os.popNumber();
                os.push(n.getInt());
            } else if (os.checkType(PSString.class)) {
                PSString s = os.popString();
                PSNumber n = PSUtils.parseNumber(s.getValue());
                os.push(n.getInt());
            } else {
                error(os, new TypeCheck());
            }
        } catch (NumberFormatException e) {
            error(os, new UndefinedResult());
        } catch (RangeException e) {
            error(os, new RangeCheck());
        }

        return true;
    }
}

class CvN extends ConversionOperator {
    { operandTypes = new Class[] {PSString.class}; }

    public boolean execute(OperandStack os) {
        PSString s = os.popString();
        os.push(new PSName(s.getValue(), s.isLiteral()));
        return true;
    }
}

class CvR extends ConversionOperator {
    { operandTypes = new Class[] {PSObject.class}; }

    public boolean execute(OperandStack os) {
        if (os.checkType(PSNumber.class)) {
            PSNumber n = os.popNumber();
            os.push(n.getDouble());
        } else if (os.checkType(PSString.class)) {
            PSString s = os.popString();
            try {
                PSNumber n = PSUtils.parseNumber(s.getValue());
                os.push(n.getDouble());
            } catch (NumberFormatException e) {
                error(os, new UndefinedResult());
            }
        } else {
            error(os, new TypeCheck());
        }
        return true;
    }
}

class CvRS extends ConversionOperator {
    { operandTypes = new Class[] {PSNumber.class, PSInteger.class, PSString.class}; }

    public boolean execute(OperandStack os) {
        try {
            PSString s = os.popString();
            PSInteger r = os.popInteger();
            PSNumber n = os.popNumber();
            byte[] b;
            if (r.getValue() == 10) {
                b = n.cvs().getBytes();
            } else {
                b = Integer.toString(n.getInt(), r.getValue()).getBytes();
            }
            if (b.length > s.size()) {
                error(os, new RangeCheck());
            } else {
                for (int i=0; i<b.length; i++) {
                    s.set(i, b[i]);
                }
                os.push(s.subString(0, b.length));
            }
        } catch (RangeException e) {
            error(os, new RangeCheck());
        }
        
        return true;
    }
}

class CvS extends ConversionOperator {
    { operandTypes = new Class[] {PSObject.class, PSString.class}; }

    public boolean execute(OperandStack os) {
        PSString s = os.popString();
        PSObject o = os.popObject();
        byte[] b = o.cvs().getBytes();
        if (b.length > s.size()) {
            error(os, new RangeCheck());
        } else {
            for (int i=0; i<b.length; i++) {
                s.set(i, b[i]);
            }
            os.push(s.subString(0, b.length));
        }
        return true;
    }
}
    