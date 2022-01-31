// Leetcode 1672

#include<iostream>
#include<vector>
#include<limits.h>

using std::vector;
using std::cout;
using std::endl;

class RichestCustomer{
    public:
        int maxWealth(vector<vector<int>>& accounts){
            int max = INT_MIN;
            for(int i = 0; i < accounts.size(); i++){
                int currMax = 0;
                for(int j = 0; j < accounts[i].size(); j++)
                    currMax += accounts[i][j];
                if(currMax > max) max = currMax;
            }
            return max;
        }
};

int main(){
    RichestCustomer soln;
    vector<vector<int>> acc1 = {{1, 2, 3}, {3, 2, 1}};
    vector<vector<int>> acc2 = {{1, 5}, {7, 3}, {3, 5}};
    vector<vector<int>> acc3 = {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
    cout << soln.maxWealth(acc1) << endl;
    cout << soln.maxWealth(acc2) << endl;
    cout << soln.maxWealth(acc3) << endl;
    return 0;
}

