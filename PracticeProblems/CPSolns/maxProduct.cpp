#include<iostream>
#include<vector>
#include<time.h>
#include<limits.h>
using namespace std;

//soln 1
//Sort and compare the first two or the last two
//return the max product of the two

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArr(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int partition(vector<int> arr, int l, int r){
    int x = arr[l];
    int j = l;
    for(int i = l+1; i <= r; i++){
        if(arr[i] <= x){
            j++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[j], &arr[l]);
    return j;
}
void quickSort(vector<int> arr, int l, int r){
    if(l < r){
        srand(time(NULL));
        int k = l + rand() % (r-1);
        swap(&arr[l], &arr[k]);
        cout << k << endl;
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
    }
}

int main(){
    vector<int> arr;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    printArr(arr);
    //quickSort(arr, 0, n-1);
    //cout << maxProduct(arr);
    return 0;
}
