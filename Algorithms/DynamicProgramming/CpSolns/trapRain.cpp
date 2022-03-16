// Leetcode #42 - Trapping rain water

#include<iostream>
#include<vector>

using std::cout; using std::endl;
using std::vector; using std::max;

class Solution{
    public:
        int trapRain(vector<int>& heights){
            int rain = 0, n = heights.size();
            // cannot hold water
            if(n <= 2) return 0;
            int maxLeft = heights[0], maxRight = heights[n-1];
            int left = 1, right = n-2;

            // traverse the map
            while(left <= right){
                //
                if(maxLeft < maxRight){
                    if(heights[left] < maxLeft)
                        // add rain
                        rain += maxLeft - heights[left];
                    else
                        maxLeft = heights[left];
                    left++;
                }else{ // maxRight < maxLeft
                    if(heights[right] < maxRight)
                        // add rain
                        rain += maxRight - heights[right];
                    else
                        maxRight = heights[right];
                    right--;
                }
            }
            return rain;
        }
};

int main(){
    Solution soln;
    vector<int> h = {4, 2, 0, 3, 2, 5}; // 9
    vector<int> h1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // 6
    vector<int> h2 = {2, 0, 2}; // 2
    cout << soln.trapRain(h) << endl;
    cout << soln.trapRain(h1) << endl;
    cout << soln.trapRain(h2) << endl;
    return 0;
}
