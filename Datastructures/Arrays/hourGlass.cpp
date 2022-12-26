#include<iostream>
#include<limits.h>
#include<vector>

using std::max;
using std::vector;
using std::cout;
using std::endl;

int hour(vector<vector<int>> arr){
    int r = arr.size(), c = arr[0].size();
    int maxSum = INT_MIN;
    for(int i = 0; i < r-2; i++){
        for(int j = 0; j < c-2; j++){
            int currSum = ((arr[i][j] + arr[i][j+1] + arr[i][j+2]) + 
                      (arr[i+1][j+1]) + 
                      (arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]));
            maxSum = max(maxSum, currSum);
        }
    }
    return maxSum;
}

int main(){
    vector<vector<int>> arr = {{-9, -9, -9,  1, 1, 1},
                               {0,  -9,  0,  4, 3, 2},
                               {-9, -9, -9,  1, 2, 3},
                               {0,   0,  8,  6, 6, 0},
                               {0,   0,  0, -2, 0, 0},
                               {0,   0,  1,  2, 4, 0}};
    cout << hour(arr) << endl;
    return 0;
}
