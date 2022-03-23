/* Naive max subarray of contiguous elements
 * 
 * Sample:
 * Input: [-3, -4, 5, -1, 2, -4, 6, -1]
 * Output: [5, -1, 2, -4, 6] ==> 8
 *
 * Input: [-2, 3, -1, 2]
 * Output: [3, -1, 2] ==> 4
 *
 * Complexity Analysis:
 * Two loops -> O(n^2) quadratic time, O(1) constant space.
 *
 * Kadane's algorithm:
 * -> Two variables:
 *      currSum -> store max sum ending at specified position in arr
 *              -> initialized with 0
 *      maxSum -> overall maximum so far
 *             -> initializes as INT_MIN
 * -> Iterate over array and do the following:
 *      -> If currSum > maxSum, maxSum = currSum
 *      -> if currSum < 0, currSum = 0
 * -> return maxSum
 *
 *  Complexity analysis:
 *  1 array traversal -> O(n) linear time, O(1) constant space.
 */

#include<vector>
#include<limits.h>
#include<iostream>

using std::vector; using std::max;
using std::cout; using std::endl;

class Solution{
    public:
        int naive(vector<int> arr){
            int maxVal = INT_MIN;
            int n = arr.size();
            for(int i = 0; i < n; i++){
                int currMax = 0;
                for(int j = i; j < n; j++){
                    currMax += arr[j];
                    maxVal = max(maxVal, currMax);
                }
            }
            return maxVal;
        }

        int kadane(vector<int> arr){
            int currSum = 0, maxSum = INT_MIN;
            int n = arr.size();
            for(int i = 0; i < n; i++){
                currSum += arr[i];
                if(currSum > maxSum) maxSum = currSum;
                if(currSum < 0) currSum = 0;
            }
            return maxSum;
        }
};

int main(){
    Solution soln;
    vector<int> a = {-3, -4, 5, -1, 2, -4, 6, -1};
    vector<int> a1 = {-2, 3, -1, 2};
    cout << soln.naive(a) << endl;
    cout << soln.naive(a1) << endl;
    // kadane's
    cout << soln.kadane(a) << endl;
    cout << soln.kadane(a1) << endl;

    return 0;
}
