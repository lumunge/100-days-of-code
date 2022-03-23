// Leetcode #152 - maximum product subarray

#include<iostream>
#include<vector>
#include<limits.h>

using std::vector; 
using std::max; using std::min;
using std::cout; using std::endl;

class Solution{
    public:
        int maxProd(vector<int> arr){
            int maxProd = INT_MIN;
            int max1 = 1, max2 = 1;
            for(int n : arr){
                int temp = max(n, max(n * max1, n * max2));
                max2 = min(n, min(n * max1, n * max2));
                max1 = temp;
                maxProd = max(maxProd, max1);
            }
            return maxProd;
        }
};

int main(){
    Solution soln;
    vector<int> a = {2, 3, -2, 4};
    vector<int> a1 = {-2,0,-1};
    vector<int> a2 = {3, -1, -1};
    cout << soln.maxProd(a) << endl;
    cout << soln.maxProd(a1) << endl;
    cout << soln.maxProd(a2) << endl;
    return 0;
}
