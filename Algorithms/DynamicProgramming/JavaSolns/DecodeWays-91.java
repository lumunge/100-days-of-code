// Leetcode #91 - Decode ways

class DecodeWays{
    public int numDecodings(String s) {
        int n = s.length();
        // length is 0 or first digit is zero
        if(n == 0 || s.charAt(0) == '0') return 0;
        // one decoding possible
        if(n == 1) return 1;
        // pointers
        int p1 = 1, p2 = 1;
        
        for(int i = 1; i < n; i++){
            int d = s.charAt(i) - '0'; // single digit
            int dd = (s.charAt(i-1) - '0') * 10 + d; // previous - now two digit num
            int count = 0;
            // check if d between 1 - 9
            if(d > 0) count += p2;
            // check if dd less than 26 and greater than 10
            if(dd <= 26 && dd >= 10) count += p1;
            // move pointers
            p1 = p2;
            p2 = count;
        }
        return p2;
    }
}
