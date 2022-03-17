// Leetcode #119 - Pascal's triangle II

#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

class Solution{
    public:
        vector<int> getRow(int rowIndex){
            vector<vector<int>> res;
            res.push_back({1});
            for(int i = 0; i < rowIndex; i++){
                vector<int> temp = res[res.size() - 1];
                temp.insert(temp.begin(), {0});
                temp.push_back({0});
                vector<int> nextRow;
                for(int j = 0; j < res[res.size() - 1].size()+1; j++){
                    nextRow.push_back(temp[j] + temp[j+1]);
                }
                res.push_back(nextRow);
            }
            int n = res.size();
            return res[n-1];
        }

        void printVec(vector<int> vec){
            for(int i = 0; i < vec.size(); i++)
                cout << vec[i] << " ";
            cout << endl;
        }
};

int main(){
    Solution soln;
    vector<int> r1 = soln.getRow(3);
    vector<int> r2 = soln.getRow(0);
    soln.printVec(r1);
    soln.printVec(r2);
    return 0;
}
