#include<iostream>
#include<vector>
using namespace std;

/* 
 * PROBLEM STATEMENT:
 * Given a string s, transform every letter individually to lowercase or uppercase
 * to create another string.
 * Return all possible permutations of the string.
 *
 * Sample:
 * Input: s = "3z4"
 * Output: ["3Z4", "3z4"]
 */

class Solution{
    public:
        //hold result
        vector<string> result;
        
        void backtrack(string s, string current, int index){
            //base case --> if current string length == input string length
            //if so we have reached end of string, push to result vector and return
            if(s.length() == current.length()){
                result.push_back(current);
                return;
            }

            //check for numbers and append to current, and increase index
            if(s[index] >= '0' && s[index] <= '9'){
                backtrack(s, current + s[index], index+1);
            }else{
                //convert both to upper and lower case and append to current
                backtrack(s, current + (char)tolower(s[index]), index+1);
                backtrack(s, current + (char)toupper(s[index]), index+1);
            }
            return;
        }

        vector<string> letterCasePermutation(string s){
            string current = "";
            backtrack(s, current, 0);
            return result;
        }
        
        void printVector(vector<string> arr){
            for(int i = 0; i < arr.size(); i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Solution soln;
    string s = "a1b2";
    vector<string> result = soln.letterCasePermutation(s);
    soln.printVector(result);
    return 0;
}
