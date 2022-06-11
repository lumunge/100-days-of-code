// Making Anagrams --> https://www.hackerrank.com/challenges/ctci-making-anagrams/

class Solution{
    public:
        int makeAnagram(string a, string b){
            int c[26] = {0}, c1[26] = {};
            
            for(int i=0; i < a.length(); i++)
                if(97 <= a[i] && a[i] <= 123) c[a[i] - 97] += 1;
            
            for(int i = 0; i < b.length(); i++)
                if(97 <= b[i] && b[i] <= 123) c1[b[i]-97] += 1;
            
            int n = 0;
            for(int i = 0; i < 26; i++)
                n += + abs(c[i] - c1[i]);
            
            return n;
        }
};
