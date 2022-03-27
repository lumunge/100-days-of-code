// Leetcode #516 - Longest palindromic subsequence

#include<iostream>
#include<limits.h>
#include<cstring>

using std::string; using std::max;
using std::cout; using std::endl;

class Solution{
    public:
        int longest(string s){
            int n = s.length();
                
            // create and fill dp table with zeros
            int dp[n][n];
            memset(dp, 0, sizeof(dp));
            
            // fill first diagonal - single chars are palindrome
            for(int i = 0; i < n; i++)
                dp[i][i] = 1;
            
            // start filling from 2nd
            for(int i = 2; i <= n; i++){
                for(int j = 0; j < n-i+1; j++){
                    int k = i + j - 1;
                    if(i == 2 && s[j] == s[k]){
                        // check two chars is palindrome
                        dp[j][k] = 2;
                    }else if(s[j] == s[k]){ // check boundaries if equal
                        dp[j][k] = dp[j + 1][k-1] + 2;
                    }else{ // get max between previous and current
                        dp[j][k] = max(dp[j + 1][k], dp[j][k - 1]);
                    }
                }
            }
            // soln stored in first row last cell
            return dp[0][n-1];
    }
};

int main(){
    Solution soln;
    cout << soln.longest("abcdef") << endl;
    cout << soln.longest("bbbab") << endl;
    cout << soln.longest("cbbd") << endl;
    cout << soln.longest("agbdba") << endl;
    cout << soln.longest("abac") << endl;
    cout << soln.longest("gphyvqruxjmwhonjjrgumxjhfyupajxbjgthzdvrdqmdouuukeaxhjumkmmhdglqrrohydrmbvtuwstgkobyzjjtdtjroqpyusfsbjlusekghtfbdctvgmqzeybnwzlhdnhwzptgkzmujfldoiejmvxnorvbiubfflygrkedyirienybosqzrkbpcfidvkkafftgzwrcitqizelhfsruwmtrgaocjcyxdkovtdennrkmxwpdsxpxuarhgusizmwakrmhdwcgvfljhzcskclgrvvbrkesojyhofwqiwhiupujmkcvlywjtmbncurxxmpdskupyvvweuhbsnanzfioirecfxvmgcpwrpmbhmkdtckhvbxnsbcifhqwjjczfokovpqyjmbywtpaqcfjowxnmtirdsfeujyogbzjnjcmqyzciwjqxxgrxblvqbutqittroqadqlsdzihngpfpjovbkpeveidjpfjktavvwurqrgqdomiibfgqxwybcyovysydxyyymmiuwovnevzsjisdwgkcbsookbarezbhnwyqthcvzyodbcwjptvigcphawzxouixhbpezzirbhvomqhxkfdbokblqmrhhioyqubpyqhjrnwhjxsrodtblqxkhezubprqftrqcyrzwywqrgockioqdmzuqjkpmsyohtlcnesbgzqhkalwixfcgyeqdzhnnlzawrdgskurcxfbekbspupbduxqxjeczpmdvssikbivjhinaopbabrmvscthvoqqbkgekcgyrelxkwoawpbrcbszelnxlyikbulgmlwyffurimlfxurjsbzgddxbgqpcdsuutfiivjbyqzhprdqhahpgenjkbiukurvdwapuewrbehczrtswubthodv") << endl;
    return 0;
}
