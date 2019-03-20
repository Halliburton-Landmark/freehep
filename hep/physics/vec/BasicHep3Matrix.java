package hep.physics.vec;


/**
 * 3x3 matrices for Hep3Vector operations.
 *
 * @author Gary Bower
 * @version 5/23/00
 */

public class BasicHep3Matrix implements Hep3Matrix
{
   private double[][] m_dmat;
   //
   public BasicHep3Matrix()
   {
      m_dmat = new double[3][3];
   }
   public BasicHep3Matrix(double e11, double e12, double e13,
                          double e21, double e22, double e23,
                          double e31, double e32, double e33)
   {
      m_dmat = new double[3][3];
      m_dmat[0][0] = e11;
      m_dmat[0][1] = e12;
      m_dmat[0][2] = e13;
      m_dmat[1][0] = e21;
      m_dmat[1][1] = e22;
      m_dmat[1][2] = e23;
      m_dmat[2][0] = e31;
      m_dmat[2][1] = e32;
      m_dmat[2][2] = e33;
   }
   /**
    * Returns the (row, column) element
    */
   public double e(int row, int column)
   {
      return m_dmat[row][column];
   }
   /**
    * Returns the determinent of the matrix.
    */
   public double det()
   {
      double cofact1 = m_dmat[1][1]*m_dmat[2][2] - m_dmat[1][2]*m_dmat[2][1];
      double cofact2 = m_dmat[0][1]*m_dmat[2][2] - m_dmat[0][2]*m_dmat[2][1];
      double cofact3 = m_dmat[0][1]*m_dmat[1][2] - m_dmat[0][2]*m_dmat[1][1];
      return m_dmat[0][0]*cofact1 - m_dmat[1][0]*cofact2 + m_dmat[2][0]*cofact3;
   }
   /**
    * Returns the trace of the matrix.
    */
   public double trace()
   {
      return m_dmat[0][0] + m_dmat[1][1] + m_dmat[2][2];
   }
   /**
    * Sets the (row, column) element 
    */
   public void setElement( int row, int column, int value)
   {
      m_dmat[row][column] = value;
   }
   /**
    * Defines a rotation matrix via Euler angles. A "passive" rotation
    * matrix rotates the coordinate system, an "active" one rotates the
    * vector(body). The angles are defined for a right handed coordinate
    * system. They are defined by counterclockwise rotations about an
    * axis by the right hand rule, ie, looking down the axis in the
    * negative direction the transvers axes are seen to rotate
    * counterclockwise. To define passive(active) angles first rotate the
    * coordinates(body) about the z-axis by phi, then about the new x-axis
    * by theta then about the new z-axis by psi.
    * Angles in radians.
    */
   public void setPassiveEuler( double phi, double theta, double psi)
   {
      double cth = Math.cos(theta);
      double sth = Math.sin(theta);
      double cphi = Math.cos(phi);
      double sphi = Math.sin(phi);
      double cpsi = Math.cos(psi);
      double spsi = Math.sin(psi);
      m_dmat[0][0] =  cpsi*cphi - cth*sphi*spsi;
      m_dmat[0][1] =  cpsi*sphi + cth*cphi*spsi;
      m_dmat[0][2] =  spsi*sth;
      m_dmat[1][0] = -spsi*cphi - cth*sphi*cpsi;
      m_dmat[1][1] = -spsi*sphi + cth*cphi*cpsi;
      m_dmat[1][2] =  cpsi*sth;
      m_dmat[2][0] =  sth*sphi;
      m_dmat[2][1] = -sth*cphi;
      m_dmat[2][2] =  cth;
   }
   /**
    * Defines a rotation matrix via Euler angles. A "passive" rotation
    * matrix rotates the coordinate system, an "active" one rotates the
    * vector(body). The angles are defined for a right handed coordinate
    * system. They are defined by counterclockwise rotations about an
    * axis by the right hand rule, ie, looking down the axis in the
    * negative direction the transvers axes are seen to rotate
    * counterclockwise. To define passive(active) angles first rotate the
    * coordinates(body) about the z-axis by phi, then about the new x-axis
    * by theta then about the new z-axis by psi.
    * Angles in radians.
    */
   public void setActiveEuler( double phi, double theta, double psi)
   {
      double cth = Math.cos(theta);
      double sth = Math.sin(theta);
      double cphi = Math.cos(phi);
      double sphi = Math.sin(phi);
      double cpsi = Math.cos(psi);
      double spsi = Math.sin(psi);
      m_dmat[0][0] =  cpsi*cphi - cth*sphi*spsi;
      m_dmat[1][0] =  cpsi*sphi + cth*cphi*spsi;
      m_dmat[2][0] =  spsi*sth;
      m_dmat[0][1] = -spsi*cphi - cth*sphi*cpsi;
      m_dmat[1][1] = -spsi*sphi + cth*cphi*cpsi;
      m_dmat[2][1] =  cpsi*sth;
      m_dmat[0][2] =  sth*sphi;
      m_dmat[1][2] = -sth*cphi;
      m_dmat[2][2] =  cth;
   }
}
