/* PROBLEM STATEMENT:
 * Given an integer, flip its bits to obtain its complement.
 *
 * Sample:
 * Input: num = 5
 * Output: 2
 * Explanation: 5 = 101 -> 010 -> 2
 *
 * Input: num1 = 1
 * Output: 0
 * Explanation: 1 = 1 -> 0 -> 0
 *
 * Approach: (bitwise XOR with mask)
 * 1 ^ 1 = 0
 * 0 ^ 1 = 1
 *
 * Get the mask and XOR it with the num
 */

class NumberComplement{
    public static int complement(int num){
        //base case
        if(num == 0) return 1;
        //get bits
        int bits = (int)(Math.log(num) / Math.log(2)) + 1;
        //get mask
        int mask = (1 << bits) - 1;
        return num ^ mask;
    }
    public static void main(String[] args){
        int a = 5, b = 1, c = 0;
        System.out.println(complement(a));
        System.out.println(complement(b));
        System.out.println(complement(c));
    }
}
