#include<vector>
#include<iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution{
    public:
        vector<int> rotateLeft(vector<int> arr, int d){
            int n = arr.size();
            vector<int> res(n);
            for(int i = 0; i < n; i++){
                res[i] = arr[(i + d) % n];
            } 
            return res;

        }

        void printVec(vector<int> arr){
            for(int i = 0; i < arr.size(); i++)
                cout << arr[i] << " ";
            cout << endl;
        }
};

int main(){
    Solution soln;
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr1 = {41, 73, 89, 7, 10, 1, 59, 58, 84, 77, 77, 97, 58, 1, 86, 58, 26, 10, 86, 51};
    vector<int> res = soln.rotateLeft(arr, 4);
    vector<int> res1 = soln.rotateLeft(arr1, 10);
    soln.printVec(res);
    soln.printVec(res1);
    return 0;
}
