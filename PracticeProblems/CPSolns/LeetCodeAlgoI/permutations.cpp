#include<iostream>
#include<vector>
#include "./PrintVector.cpp"
using namespace std;

/*
 * #backtracking
 * PROBLEM STATEMENT:
 * Given an array of distinct intergers, return all possible permutations
 * Sample:
 * Input: [1, 2, 3];
 * Output: [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]
 */


class Solution{
    public:
        vector<vector<int>> permute(vector<int>& nums){
            vector<vector<int>> result;
            int n = nums.size();
            if(n <= 1)
                return {nums};
            for(int i = 0; i < n; i++){
                //create a copy of original
                vector<int> v(nums.begin(), nums.end());
                //erase i from each copy increasingly
                v.erase(v.begin() + i);
                auto res = permute(v);
                int m = res.size();
                for(int j = 0; j < m; j++){
                    vector<int> _v = res[j];
                    _v.insert(_v.begin(), nums[i]);
                    result.push_back(_v);
                }
            }
            return result;
        }
        void printArr(vector<vector<int>> arr){
            for(int i = 0; i < arr.size(); i++){
                for(int j = 0; j < arr[0].size(); j++){
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
        
};

int main(){
    Solution soln;
    PrintVector print;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = soln.permute(nums);
    soln.printArr(result);
    return 0;
}
