#include<iostream>
#include<vector>
using namespace std;

#define ROW 5
#define COL 10

int main(){
    vector<vector<int>> arr;
    int n = 7;

    for(int i = 0; i < ROW; i++){
        vector<int> v1;
        for(int j = 0; j < COL; j++){
            v1.push_back(n);
            n += 7;
        }
        arr.push_back(v1);
    }

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}
