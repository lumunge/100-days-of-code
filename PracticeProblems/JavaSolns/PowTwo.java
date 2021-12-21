/*
 * PROBLEM STATEMENT:
 * Given integer n, return true if it is a power of 2, false otherwise
 * Without using loops or recursion.
 *
 * Approach(bitwise manipultion)
 * Given n, (n & n-1) is 0 if n is a power of 2.
 */

class PowTwo{
    static boolean isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        return ((n & (n-1)) == 0);
    }
}
