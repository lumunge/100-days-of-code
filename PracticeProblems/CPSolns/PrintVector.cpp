#include<iostream>
#include<vector>

using namespace std;

class PrintVector{
    public:
        void print2DVector(vector<vector<int>> arr){
            int r = arr.size();
            int c = arr[0].size();
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    cout << "[" << i << "][" << j << "]";
                    cout << " " << arr[i][j] << endl;
                }
            }
        }

        void printVector(vector<int> arr){
            for(int i = 0; i < arr.size(); i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};
