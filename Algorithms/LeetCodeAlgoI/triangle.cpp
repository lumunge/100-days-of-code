#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
        int minimumTotal(vector<vector<int>>& triangle){
            int n = triangle.size();
            for(int i = 0; i < n; i++){
                for(int j = 0; j <= i; j++){
                    if(i == 0 && j == 0)
                        continue;
                    if(j == 0){
                        triangle[i][j] += triangle[i-1][j]; 
                    }else if(j == i){
                        triangle[i][j] += triangle[i-1][j-1];
                    }else{
                        triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
                    }
                }
            }
            return *min_element(begin(triangle.back()), end(triangle.back()));
        }
};

int main(){
    Solution soln;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    vector<vector<int>> triangle2 = {{-10}};
    cout << soln.minimumTotal(triangle) << endl;
    return 0;
}
