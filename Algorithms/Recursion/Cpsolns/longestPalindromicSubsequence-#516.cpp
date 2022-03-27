// Leetcode #516 - Longest palindromic subsequence

#include<iostream>
#include<limits.h>
#include<cstring>

using std::string;
using std::max;
using std::cout;
using std::endl;

class Solution{
    private:
        int helper(string s, int l, int len){
            if(len == 0) return 0;
            if(len == 1) return 1;
            // check borders
            if(s[l] == s[l + len - 1])
                return 2 + helper(s, l+1, len - 2);
            else // get max 
                return max(helper(s, l+1, len - 1), helper(s, l, len - 1));
        }
    public:
        int longest(string s) {
            return helper(s, 0, s.length());
        }
};

int main(){
    Solution soln;
    cout << soln.longest("abcdef") << endl;
    cout << soln.longest("bbbab") << endl;
    cout << soln.longest("cbbd") << endl;
    cout << soln.longest("agbdba") << endl;
    cout << soln.longest("abac") << endl;
    // Not efficient for this input - alot of repeated work -> soln -> dynamic programming
    cout << soln.longest("gphyvqruxjmwhonjjrgumxjhfyupajxbjgthzdvrdqmdouuukeaxhjumkmmhdglqrrohydrmbvtuwstgkobyzjjtdtjroqpyusfsbjlusekghtfbdctvgmqzeybnwzlhdnhwzptgkzmujfldoiejmvxnorvbiubfflygrkedyirienybosqzrkbpcfidvkkafftgzwrcitqizelhfsruwmtrgaocjcyxdkovtdennrkmxwpdsxpxuarhgusizmwakrmhdwcgvfljhzcskclgrvvbrkesojyhofwqiwhiupujmkcvlywjtmbncurxxmpdskupyvvweuhbsnanzfioirecfxvmgcpwrpmbhmkdtckhvbxnsbcifhqwjjczfokovpqyjmbywtpaqcfjowxnmtirdsfeujyogbzjnjcmqyzciwjqxxgrxblvqbutqittroqadqlsdzihngpfpjovbkpeveidjpfjktavvwurqrgqdomiibfgqxwybcyovysydxyyymmiuwovnevzsjisdwgkcbsookbarezbhnwyqthcvzyodbcwjptvigcphawzxouixhbpezzirbhvomqhxkfdbokblqmrhhioyqubpyqhjrnwhjxsrodtblqxkhezubprqftrqcyrzwywqrgockioqdmzuqjkpmsyohtlcnesbgzqhkalwixfcgyeqdzhnnlzawrdgskurcxfbekbspupbduxqxjeczpmdvssikbivjhinaopbabrmvscthvoqqbkgekcgyrelxkwoawpbrcbszelnxlyikbulgmlwyffurimlfxurjsbzgddxbgqpcdsuutfiivjbyqzhprdqhahpgenjkbiukurvdwapuewrbehczrtswubthodv") << endl;
    return 0;
}
