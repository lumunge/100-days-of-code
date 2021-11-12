#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

/* PROBLEM STATEMENT:
 * Given an integer array nums, positioned at the first index and each element represents
 * maximum jump from that position.
 * Return true if you can reach the last index, false otherwise.
 *
 * Approach:
 * Initialize max jump
 * Traverse the list of nums while updating max jump to current value + index
 * If the index equals the max jump break out of the loop
 * Return true if the max jump is greater thaan size of list.
 */

class Solution{
    private:
        bool canJump(vector<int> &nums){
            int maxJump = 0;
            int n = nums.size();
            for(int i = 0; i < n; i++){
                if(nums[i] + i > maxJump)
                    maxJump = nums[i] + i;
                if(i == maxJump)
                    break;
            }
            return maxJump >= n-1;
        }
    public:
        vector<int> nums;
        void read(){
            int n, val;
            cout << "vector size ", cin >> n;
            for(int i = 0; i < n; i++){
                cin >> val;
                nums.push_back(val);
            }
        }
        void run(){
            cout << canJump(nums) << endl;
        }
};

int main(){
    Solution soln;
    soln.read();
    soln.run();
}
