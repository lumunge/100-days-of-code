#include<unordered_map>
#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

class Solution{
    private:
        string get_key_chars(int n){
            unordered_map<int, string> map;
            map[0] = "0";   map[1] = "1";    map[2] = "abc";
            map[3] = "def"; map[4] = "ghi";  map[5] = "jkl";
            map[6] = "mno"; map[7] = "pqrs"; map[8] = "tuv";
            map[9] = "wxyz";

            return map[n];
        }

        void helper(string str, int i, string str_res, vector<string> &vec_res){
            if(i == str.length()){
                vec_res.push_back(str_res);
                return;
            }

            string str1 = get_key_chars(str[i] - '0');

            for(int j = 0; j < str1.length(); j++){
                str_res += str1[j];
                helper(str, i+1, str_res, vec_res);
                str_res.pop_back();
            }
        }
    public:
        vector<string> letterCombinations(string digits){
            vector<string> vec_res;
            if(digits.length() == 0) return vec_res;
            string str_res = "";
            helper(digits, 0, str_res, vec_res);
            return vec_res;
        }

        void printVec(vector<string> vec){
            int n = vec.size();
            for(int i = 0; i < n; i++)
                cout << vec[i] << " ";
            cout << endl;
        }
};

int main(){
    Solution soln;
    vector<string> vec = soln.letterCombinations("23");
    soln.printVec(vec);
    return 0;
}
