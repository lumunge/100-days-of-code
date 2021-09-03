#include<iostream>
#include<vector>
using namespace std;

class ZigZag{
    public:
    
    void printArr(vector<int> arr){
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    vector<int> getZigZag(vector<int> arr){
        vector<int> finals;
        for(int i = 0; i < arr.size()-1; i++){
            finals.push_back(arr[i+1] - arr[i]);
        }
        return finals;
    }
/*
    int checkZigZag(vector<int> arr){
        int count = 0;
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return count;
    }
*/
};


int main(){
    ZigZag zigzag;
    vector<int> arr = { 1, 7, 4, 9, 2, 5};
    zigzag.printArr(arr);
    //vector<int> result = zigzag.getZigZag(arr);
    //zigzag.printArr(result);
    cout << zigzag.checkZigZag(result) << endl;
    return 0;
}



