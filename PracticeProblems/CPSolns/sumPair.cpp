#include<iostream>
#include<vector>
using namespace std;

void printArr(vector<pair<int, int>> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i].first << " " << arr[i].second << endl;
    }
    cout << endl;
}

vector<pair<int, int>> sumPair(vector<int> arr, int target){
    vector<pair<int, int>> result;
    for(int i = 0; i < arr.size(); i++){
        for(int j = 1; j < arr.size(); j++){
            if(i != j && arr[i] + arr[j] == target){
                result.push_back(make_pair(arr[i], arr[j]));
            }else{
                cout << "Not found";
        }
    }
    printArr(result);
    return result;
}

int main(){
    vector<int> arr;
    int n;
    int target;
    int x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr.push_back(x);
    }
    cout << "Target: ", cin >> target;
    sumPair(arr, target);
    return 0;
}
