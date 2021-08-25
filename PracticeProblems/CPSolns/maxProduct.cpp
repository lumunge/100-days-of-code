#include<iostream>
#include<vector>
#include<time.h>
#include<limits.h>
using namespace std;

//soln 1
//Sort and compare the first two or the last two
//return the max product of the two
class Sort{
    public:
        vector<int> arr;

        int partition(vector<int> &arr, int l, int r){
            int x = r;
            int j = l;
            for(int i = l; i < r; i++){
                if(arr[i] < arr[x]){
                    swap(arr[i], arr[j]);
                    j++;
                }
            }
            swap(arr[j], arr[x]);
            return j;
        }
        void quickSort(vector<int> &arr, int l, int r){
            if(l < r){
                int pi = partition(arr, l, r);
                quickSort(arr, l, pi-1);
                quickSort(arr, pi+1, r);
            }
        }

        void printArr(vector<int> arr){
            for(int i = 0; i < arr.size(); i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    Sort obj;
    vector<int> arr;
    int n;
    int x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr.push_back(x);
    }
    obj.quickSort(arr, 0, n-1);
    obj.printArr(arr);
    //cout << maxProduct(arr);
    return 0;
}
