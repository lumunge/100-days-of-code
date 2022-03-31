#include<iostream>
#include<vector>
using namespace std;

/*
 * #backtracking
 * PROBLEM STATEMENTS:
 * Given two integers n and k, return all possible combinations of k numbers out of the
 * range [1, n].
 *
 * Sample:
 * Input:
 * n = 4, k = 2
 * range: [1, 2, 3, 4]
 * k --> 2 values max per combination, no repeats
 * Output:
 *       {{2, 4}, {3, 4}, {2, 3}, {1, 2}, {1, 3}, {1, 4}}
 */

class Solution{
    public:
        vector<vector<int>> result;
        vector<int> comb;
        void printVector(vector<vector<int>> arr){
            for(int i = 0; i < arr.size(); i++){
                for(int j = 0; j < arr[i].size(); j++){
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        void backtrack(int start, int n, int k){
            if(comb.size() == k){
                result.push_back(comb);
                return;
            }
            for(int i = start; i <= n; i++){
                comb.push_back(i);
                backtrack(i+1, n, k);
                comb.pop_back();
            }
        }
        vector<vector<int>> combine(int n, int k){
            vector<vector<int>> result;
            backtrack(1, n, k);
            return this->result;
        }
};


int main(){
    Solution soln;
    PrintVector print;
    int n = 4, k = 2;
    //vector<vector<int>> arr = {{2, 4}, {3, 4}, {2, 3}, {1, 2}, {1, 3}, {1, 4}};
    vector<vector<int>> result = soln.combine(n, k);
    print.printVector(result);
    return 0;
}
