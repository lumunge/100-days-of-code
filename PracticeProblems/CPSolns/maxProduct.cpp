#include<iostream>
#include<vector>
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

class MaxProduct{
    public:
        vector<int> arr;
        void getMax(vector<int> arr){
            int n = arr.size();
            if(arr[0] * arr[1] > arr[n-1] * arr[n-2]){
                cout << arr[0] << " " << arr[1] << endl;
            }else{
                cout << arr[n-1] << " " << arr[n-2] << endl;
            }
        }

        //Soln 2
        //Get maximum 1 and maximum2, minimum1 and minimum2
        //Return the greater of the two       
        int compareGetMax(vector<int> arr){
            int n = arr.size();
            int max1 = arr[0];
            int max2 = INT_MIN; //-2m
            int min1 = arr[0];
            int min2 = INT_MAX; //2m
            //iterate from 2nd element
            for(int i = 1; i < n; i++){
                //if current element > max element
                //update max and second max
                if(arr[i] > max1){
                    max2 = max1;
                    max1 = arr[i];
                }else if(arr[i] > max2){ //if current element < max element 
                    max2 = arr[i];       //but greater than max2, update max2
                }
                //if current element < minimum
                //update min1 and min2
                if(arr[i] < min1){
                    min2 = min1;
                    min1 = arr[i];
                }else if(arr[i] < min2){ //if current element < minimum element
                    min2 = arr[i];       //but greater than minimum element update min2
                }
            }
            //Comparison
            if(max1*max2 > min1 * min2){
                return max1, max2;
            }else{
                return min1, min2;
            }
        }
};


int main(){
    Sort sort;
    MaxProduct max;
    vector<int> arr;
    int n;
    int x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr.push_back(x);
    }
    sort.quickSort(arr, 0, n-1);
    int a, b = max.compareGetMax(arr);
    cout << a << " " << b << endl;
    return 0;
}
