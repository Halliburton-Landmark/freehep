package org.freehep.graphics3d;

/**
 * Original ArcBall C code from Ken Shoemake, Graphics Gems IV, 1993.
 *
 * @author Mark Donszelmann
 * @version $Id: ArcBallMath.java,v 1.3 2002/12/13 17:40:48 duns Exp $
 */

public class ArcBallMath {

    /**
     * static methods only
     */
    private ArcBallMath() {
    }

    /**
     * Project an x,y pair onto a sphere of radius r OR a hyperbolic sheet
     * if we are away from the center of the sphere. Return a vector.
     */
    public static Vector3 projectToSphere(double r, double x, double y, Vector3 v) {
        if (v == null) v = new Vector3();
        double d = Math.sqrt(x*x + y*y);
        double z;
        if (d < r * 0.70710678118654752440) {
            /* Inside sphere */
            z = Math.sqrt(r*r - d*d);
        } else {
            /* On hyperbola */
            double t = r / 1.41421356237309504880;
            z = t*t / d;
        }
        return v.set(x, y, z);
    }

    private static Vector3 ctaAxis = new Vector3();
    private static Vector3 ctaLoose = new Vector3();
    private static Vector3 ctaScale = new Vector3();

    /**
     * return sphere point to be perpendicular to axis.
     */
    public static Vector3 constrainToAxis(Vector3 loose, Vector3 axis, Vector3 onPlane) {
        if (onPlane == null) onPlane = new Vector3();

        axis.normalize(ctaAxis);
        loose.normalize(ctaLoose);
        ctaAxis.scale(ctaAxis.dot(ctaLoose), ctaScale);
        ctaLoose.sub(ctaScale, onPlane);
        double length = onPlane.length();
        if (length > 0.0) {
    	    if (onPlane.z < 0.0) {
    	        onPlane.negate(onPlane);
    	    }
    	    onPlane.scale(1/length, onPlane);
        } else {
            if (ctaAxis.z == 1.0) {
    	        onPlane.set(1.0, 0.0, 0.0);
            } else {
    	        onPlane.set(-ctaAxis.y, ctaAxis.x, 0.0);
    	        onPlane.normalize(onPlane);
            }
        }
        return onPlane;
    }

    private static Vector3 ncaLoose = new Vector3();
    private static Vector3 ncaOnPlane = new Vector3();

    /**
     * @return the index of nearest arc of axis set, or -1 if no axes supplied
     */
    public static int nearestConstraintAxis(Vector3 loose, Vector3[] axes) {
        double max = -1.0;
        int nearest = -1;
        loose.normalize(ncaLoose);
        for (int i=0; i<axes.length; i++) {
            if (axes[i] != null) {
            	constrainToAxis(loose, axes[i], ncaOnPlane);
            	double dot = ncaOnPlane.dot(ncaLoose);
            	if (dot > max) {
            	    max = dot; nearest = i;
            	}
            }
        }
        return nearest;
    }

    private static Vector3 bqAxis = new Vector3();
    private static Vector3 bqDiff = new Vector3();

    /**
     * Ok, simulate a track-ball.  Project the points onto the virtual
     * trackball, then figure out the axis of rotation, which is the cross
     * product of P1 P2 and O P1 (O is the center of the ball, 0,0,0)
     * Note:  This is a deformed trackball-- is a trackball in the center,
     * but is deformed into a hyperbolic sheet of rotation away from the
     * center.  This particular function was chosen after trying out
     * several variations.
     * <p>
     * It is assumed that the arguments to this routine are in the range
     * (-1.0 ... 1.0)
     * <p>
     * @return quaternion or null, if axis length equals 0;
     */
    public static Quaternion buildQuaternion(double size, Vector3 from, Vector3 to, Quaternion r) {
        if (r == null) r = new Quaternion();
        //  Now, we want the cross product of "from" and "to"
        to.cross(from, bqAxis);

        //  Figure out how much to rotate around that axis.
        from.sub(to, bqDiff);
        double t = bqDiff.length() / (2.0*size);

        // Avoid problems with out-of-control values...
        if (t > 1.0) t = 1.0;
        if (t < -1.0) t = -1.0;
        double phi = 2.0 * Math.asin(t);

        return axisToQuaternion(bqAxis, phi, r);
    }

    private static Vector3 atqAxis = new Vector3();

    /**
     *  Given an axis and angle, compute quaternion, return null if axis cannot be normalized
     */
    public static Quaternion axisToQuaternion(Vector3 axis, double phi, Quaternion r) {
        if (r == null) r = new Quaternion();
        axis.normalize(atqAxis);
        if (atqAxis == null) return null;
        atqAxis.scale(Math.sin(phi/2.0), atqAxis);
        return r.set(atqAxis.x, atqAxis.y, atqAxis.z, Math.cos(phi/2.0));
    }
}
