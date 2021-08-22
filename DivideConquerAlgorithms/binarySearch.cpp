#include<iostream>
#include<vector>
using namespace std;

void printArr(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr;
    int n;
    int x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr.push_back(x);
    }
    return 0;
}
