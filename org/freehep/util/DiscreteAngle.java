// Copyright 2003, SLAC, Stanford, U.S.A.
package org.freehep.util;

import java.util.Iterator;
import java.util.SortedSet;
import java.util.TreeSet;

/**
 * Calculates a discrete angle from an arbitrary angle, based on a set of
 * given angles.
 *
 * The class calculates the angle by dividing 360 degrees into segments
 * based on the discrete angles. It then will calculate the closest discrete angle
 * for a given angle. Discrete angles can be added and removed.
 *
 * This class can be used to constrain the mouse movement (or its result) if one
 * wants to draw under certain angles only.
 *
 * @author Mark Donszelmann
 * @version $Id: DiscreteAngle.java,v 1.1 2003/06/10 18:26:16 duns Exp $
 */
public class DiscreteAngle {

    private SortedSet angles;

    public DiscreteAngle() {
        angles = new TreeSet();
    }

    /**
     * Returns the closest angle to any discrete angle in the set. Returns itself
     * if the set is empty. Returns the only discrete angle if the set only contains
     * one angle.
     */
    public double getAngle(double angle) {
        if (angles.isEmpty()) return angle;

        Iterator i = angles.iterator();
        Double prev = (Double)i.next();
        if (!i.hasNext()) return prev.doubleValue();

        while (i.hasNext()) {
            Double cur = (Double)i.next();
            double cutoff = (cur.doubleValue() - prev.doubleValue()) / 2.0 + prev.doubleValue();
            if (angle <= cutoff) return prev.doubleValue();
            prev = cur;
        }
        return prev.doubleValue();
    }

    /**
     * Adds a discrete angle to the set.
     */
    public Double addAngle(double angle) {
        Double a = new Double(angle);
        angles.add(a);
        return a;
    }

    /**
     * Removes a discrete angle from the set.
     */
    public boolean removeAngle(double angle) {
        for (Iterator i = angles.iterator(); i.hasNext(); ) {
            Double r = (Double)i.next();
            if (r.doubleValue() == angle) {
                return removeAngle(r);
            }
        }
        return false;
    }

    /**
     * Removes a discrete angle from the set.
     */
    public boolean removeAngle(Double angle) {
        return (angle != null) ? angles.remove(angle) : false;
    }

    public String toString() {
        StringBuffer s = new StringBuffer();
        s.append("Angles: ");
        for (Iterator i = angles.iterator(); i.hasNext(); ) {
            Double r = (Double)i.next();
            s.append(r.doubleValue());
            if (i.hasNext()) s.append(", ");
        }
        return s.toString();
    }

    public static void main(String[] args) {
        DiscreteAngle da = new DiscreteAngle();
        da.addAngle(0);
        da.addAngle(90);
        da.addAngle(180);
        da.addAngle(270);
        da.addAngle(360);

        da.addAngle(10);
        da.addAngle(190);

        System.out.println("  0 results in "+da.getAngle(  0));
        System.out.println("  1 results in "+da.getAngle(  1));
        System.out.println("  5 results in "+da.getAngle(  5));
        System.out.println(" 80 results in "+da.getAngle( 80));
        System.out.println(" 90 results in "+da.getAngle( 90));
        System.out.println("170 results in "+da.getAngle(170));
        System.out.println("185 results in "+da.getAngle(185));
        System.out.println("186 results in "+da.getAngle(186));
        System.out.println("231 results in "+da.getAngle(231));
        System.out.println("359 results in "+da.getAngle(359));

    }
}
