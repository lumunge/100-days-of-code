// Leetcode #118 - Pascal's triangle

#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

class Solution{
    public:
        vector<vector<int>> generate(int numRows){
            vector<vector<int>> res;
            res.push_back({1});
            for(int i = 0; i < numRows - 1; i++){
                vector<int> temp = res[res.size() - 1];
                temp.insert(temp.begin(), {0});
                temp.push_back({0});
                vector<int> nextRow;
                for(int j = 0; j < res[res.size() - 1].size()+1; j++){
                    nextRow.push_back(temp[j] + temp[j+1]);
                }
                res.push_back(nextRow);
            }
            return res;
        }

        void printVec(vector<vector<int>> vec){
            for(int i = 0; i < vec.size(); i++){
                for(int j = 0; j < vec[i].size(); j++){
                    cout << vec[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    Solution soln;
    vector<vector<int>> r1 = soln.generate(5);
    vector<vector<int>> r2 = soln.generate(1);
    soln.printVec(r1);
    soln.printVec(r2);
    return 0;
}
