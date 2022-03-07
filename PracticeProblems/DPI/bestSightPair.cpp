// Leetcode #1014 -  best sightseeing pair

#include<iostream>
#include<vector>
#include<limits.h>

using std::max;
using std::vector;
using std::cout;
using std::endl;

class Solution{
    public:
        // brute force
        int maxScoreI(vector<int>& points){
            int maxsc = 0;
            for(int i = 0; i < points.size(); i++){
                for(int j = i+1; j < points.size(); j++){
                    maxsc = max(((points[i] + points[j]) + (i - j)), maxsc);
                }
            }
            return maxsc;
        }
        // DP
        int maxScoreII(vector<int>& points){
            int maxsc = INT_MIN;
            int curr = points[0];
            for(int i = 1; i < points.size(); i++){
                curr--;
                maxsc = max(maxsc, curr+points[i]);
                if(points[i] >= curr) curr = points[i];
            }
            return maxsc;
        }

};

int main(){
    Solution soln;
    vector<int> n = {8, 1, 5, 2, 6};
    vector<int> n1 = {1, 2};
    cout << soln.maxScoreI(n) << endl;
    cout << soln.maxScoreI(n1) << endl;
    cout << soln.maxScoreII(n) << endl;
    cout << soln.maxScoreII(n1) << endl;
}
