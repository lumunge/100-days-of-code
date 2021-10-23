#include<iostream>
#include<vector>
using namespace std;

/* PROBLEM STATEMENT
 * Given a sorted array and keys to search
 * Return the index of the keys in the array else return -1
 */

int binarySearch(vector<int> arr, int target){
    int max = arr.size() - 1;
    int min = 0;
    while(min <= max){
        int guess = (max + min) / 2;
        if(arr[guess] == target){
            return guess;
        }else if(arr[guess] < target){
            min = guess + 1;
        }else{
            max = guess - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr;
    vector<int> searchElements;
    int m;
    int n;
    int x;
    int y;
    cout << "Number of Array elements: ", cin >> m;
    cout << "Array Element:" << endl;
    for(int i = 0; i < m; i++){
        cin >> x;
        arr.push_back(x);
    }
    cout << "Number of search keys: ", cin >> n;
    cout << "Search keys: " << endl;
    for(int i = 0; i < n; i++){
        cin >> y;
        searchElements.push_back(y);
    }
    for(int i = 0; i < searchElements.size(); i++){
        cout << binarySearch(arr, searchElements[i]) << endl;
    }
    return 0;
}
