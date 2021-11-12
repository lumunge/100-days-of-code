#include<bits/stdc++.h>

/* PROBLEM STATEMENT:
 * Given an array of integers and a target num, return indices of two numbers that add
 * up to target.
 * Sample:
 * Input: nums = [2, 7, 11, 15], target = 9
 * Output: [0, 1] = 2, 7
 * 
 * Approach:
 * 1. Initialize a map and a result vector.
 * 2. Go through the input vector elements.
 * 3. Do an if check, if the difference between target and vector element exists in
 *    map, append the index and map[difference] to result vector.
 *    Otherwise insert the vector element key with its value as index to map.
 * 4. Return result vector.
 *
 * The above approach takes O(n) time.
 */

class Solution{
    public:
        //print vector
        void printVector(std::vector<int> nums){
            for(auto i : nums)
                std::cout << i << " ";
            std::cout << std::endl;
        }
        
        //Implementation
        std::vector<int> twoSum(std::vector<int> nums, int target){
            std::map<int, int> resMap;
            std::vector<int> resVec;
            for(int i = 0; i < nums.size(); i++){
                if(resMap.find(target - nums[i]) != resMap.end()){
                    resVec.push_back(resMap[target - nums[i]]);
                    resVec.push_back(i);
                }else{
                    resMap[nums[i]] = i;
                }
            }
            return resVec;
        }
};

int main(){
    Solution soln;
    std::vector<int> nums = {3, 3};
    int target = 6;
    std::vector<int> result = soln.twoSum(nums, target);
    soln.printVector(result);
    return 0;
}
