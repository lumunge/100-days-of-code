#include<iostream>
#include<vector>
using namespace std;

void maxWindow(vector<int> arr, int k){
    int max;
    for(int i = 0; i <= arr.size()-k; i++){
        int max = arr[i];
        for(int j = 1; j < k; j++){
            if(arr[i+j] > max)
                max = arr[i+j];
        }
        cout << max << " ";
    }
}


int main(){
    vector<int> arr = {2, 7, 3, 1, 5, 2, 6, 2};
    int k = 4;
    maxWindow(arr, k);
    cout << endl;
    return 0;
}
