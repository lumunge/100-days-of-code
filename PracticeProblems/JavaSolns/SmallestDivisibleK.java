/* 
 * PROBLEM STATEMENT:
 * Given a positive integer k, find the length of the smallest positive integr n such that
 * n is divisible by k and n only contains the digit 1.
 * Return length of n, otherwise return -1.
 *
 * Sample:
 * Input: k = 3
 * Output: 3
 * Explanation: 111 / 3 
 *
 * Input: k = 7
 * Output: 6
 * Explanation: 111111 / 7
 *
 * Approach.
 * Initialize n as 0.
 * Intitialize i, represents how many times we add 1 to find a divisible number
 * also this is the length of n.
 * While int i is less than or equal to k:
 *      add '1's to n and divide by k,
 *      if result is divisible by k, return i
 *      otherwise increment i
 */

class SmallestDivisibleK{
    static int smallestIntK(int k){
        int n = 0, i = 1;
        while(i <= k){
            //add '1's and check divisibility
            n = (n * 10 + 1) % k;
            if(n == 0)
                return i;
            else
                i++;
        }
        return -1;
    }

    public static void main(String[] args){
        System.out.println(smallestIntK(1));
        System.out.println(smallestIntK(3));
        System.out.println(smallestIntK(7));
        System.out.println(smallestIntK(9));
    }
}
