/* PROBLEM STATEMENT:
 * Given two binary strings, return their sum.
 *
 * Sample:
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Approach.
 * Initialize carry variable which will store carried bits
 * Traverse the strings in reverse order.
 * Get sum by adding bits and add to carry
 * mod the sum by 2 to obtain a binary number
 * update carry by dividing sum by 2
 * If carry is greater than zero, add it to the front of result.
 */

class AddBinary{
    static String add(String a, String b){
        StringBuilder result = new StringBuilder();
        int aLen = a.length() - 1, bLen = b.length() - 1;
        int carry = 0;
        while(aLen >= 0 || bLen >= 0){
            int total = carry;
            if(aLen >= 0)
                total += a.charAt(aLen--) - '0';
            if(bLen >= 0)
                total += b.charAt(bLen--) - '0';
            //add bit to result
            result.insert(0, total % 2);
            //update carry
            carry = total / 2;
        }
        if(carry > 0)
            result.insert(0, 1);
        return result.toString();
    }

    public static void main(String[] args){
        System.out.println(add("11", "1"));
        System.out.println(add("1010", "1011"));
    }
}
