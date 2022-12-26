/* PROBLEM STATEMENT:
 * An implementation of Cs atio() function
 */

class StrToIntAtoi{
    static int convert(String s){
        int i = 0, sign = 1, result = 0;

        //skip white spaces
        while (i < s.length() && s.charAt(i) == ' ') {
			i++;
		}
        
        //check if negative
        if(i < s.length() && (s.charAt(i) == '-' || s.charAt(i) == '+' )){
            if(s.charAt(i) == '-')
                sign = -1;
            i++;
        }
        
        //traverse string
        while(i < s.length() && s.charAt(i) >= '0' && s.charAt(i) <= '9'){
            //check limits
            if(result > Integer.MAX_VALUE/10 || (result == Integer.MAX_VALUE/10 && s.charAt(i) - '0' > 7)){
                if(sign == -1)
                    return Integer.MIN_VALUE;
                return Integer.MAX_VALUE;
            }
            //valid number add to result
            result = result * 10 + (s.charAt(i) - '0');
            i++;
        }
        return result * sign;
    }

    public static void main(String[] args){
        String s1 = "42";
        System.out.println(convert(s1));
        System.out.println(convert("   +0 123"));
        System.out.println(convert("+1"));
        System.out.println(convert("words and 987"));
        System.out.println(convert("4193 with words"));
        System.out.println(convert("   -42"));
    }
}
