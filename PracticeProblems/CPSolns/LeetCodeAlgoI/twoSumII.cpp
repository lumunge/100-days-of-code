#include<iostream>
#include<vector>
using namespace std;

/*
 * PROBLEM STATMENT:
 * Given an 1-indexed array of intergers sorted in increasing order,
 * Find two numbers that add up to target
 * Return indices of the numbers
 *
 * Sample:
 * Input: arr[2, 7, 11, 15], target = 9;
 * Output: 1, 2 --> 2+7 = 9;
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) { // O(n^2) --> slow
        vector<int> result;
        for(int i = 0; i < numbers.size(); i++){
            for(int j = i+1; j < numbers.size(); j++){
                if(numbers[i] + numbers[j] == target){
                    result.push_back(i+1);
                    result.push_back(j+1);
                }
            }
        }
        return result;
    }

    vector<int> twoSumFast(vector<int>& numbers, int target){ // O(n) --> one loop
        vector<int> result;
        //Two pointers
        int i = 0; //start of array
        int j = numbers.size() - 1; // end of array
        while(i < j){
            if(numbers[i] + numbers[j] < target) //if first and last < target
                i++;                             //Move to second index
            else if(numbers[i] + numbers[j] > target) //if they are > target
                j--;                                  //Move to second last element and first
            else{                                     //They add up to target, push to result array
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }
        }
        return {}; //No soln after while loop, return empty array;
    }
};

int main(){
    Solution soln;
    vector<int> numbers = {2, 3, 4};
    vector<int> result = soln.twoSumFast(numbers, 6);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
