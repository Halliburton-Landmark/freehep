package hep.physics.vec;

/**
 * Hep 3x3 matrices
 * @author Gary Bower
 * @version 5/23/00
 */

public interface Hep3Matrix
{
   double e(int row, int column); // return element.
   double det(); // return determinant.
   double trace(); // return trace of matrix.
}
