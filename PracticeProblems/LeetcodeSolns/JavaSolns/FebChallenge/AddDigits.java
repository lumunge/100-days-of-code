// Leetcode #258 - Add digits

class AddDigits{
    // recursive approach
    static int helper(int num){
        char[] numArr = Integer.toString(num).toCharArray();
        int sum = 0;
        for(int i = 0; i < numArr.length; i++){
            sum += Character.getNumericValue(numArr[i]);
        } 
        return sum;
    }
    static int addDigits(int num){
        if(num <= 9) return num;
        return addDigits(helper(num));
    }
    
    // mathematical approach
    static int addDigitsMath(int num){
        if(num == 0) return 0;
        if(num % 9 == 0) return 9;
        return num % 9;
    }

    public static void main(String[] args){
        int num = 38;
        System.out.println(addDigits(38));
        System.out.println(addDigitsMath(38));
    }
}
