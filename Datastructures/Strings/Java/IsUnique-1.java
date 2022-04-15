// Algorithm to determine if a string has only unique characters
// String is ASCII
class IsUnique{
    static boolean unique(String str){ // Time: O(n) n = string.length(), Space: O(1)
        int n = str.length();
        if(n > 128) return false; // 128 char set
        boolean[] charset = new boolean[128]; // track character occurrences
        for(int i = 0; i < n; i++){
            int curr = str.charAt(i);
            if(charset[curr]) return false; // character seen again
            charset[curr] = true; // set character boolen in array
        }
        return true; // all conditions succeed
    }

    static boolean unique1(String str){ // Time: O(n) Space: O(1)
        int checker = 0, n = str.length();
        for(int i = 0; i < n; i++){
            int curr = str.charAt(i) - 'a';
            if((checker & (1 << curr)) > 0) return false; // duplicates
            checker |= (1 << curr);
        }
        return true;
    }

    public static void main(String[] args){
        String s = "abcdffgijk";
        String s1 = "dfgjkflom";
        String s2 = "jklzxcvnm";
        System.out.println(unique1(s));
        System.out.println(unique1(s1));
        System.out.println(unique1(s2));
    }
}

// Other solutions.
// 1. Use two loops and compare every string with each other - O(n^2) time O(1) space
// 2. Sort the string and compare adjacent characters - O(n log(n)) O(1) space
