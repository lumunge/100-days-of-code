#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;

class InterPolationSearch{
    private:
        int probePosition(vector<int> arr, int target, int low, int high){
            return (low + ((target - arr[low]) * (high - low) / (arr[high] - arr[low])));
        }
    public:
        int search(vector<int> arr, int target){
            int n = arr.size();

            if(n == 0)
                return -1;

            //search space
            int low = 0, high = n - 1, mid;

            while(arr[high] != arr[low] && target >= arr[low] && target <= arr[high]){
                mid = probePosition(arr, target, low, high);
                if(target == arr[mid])
                    return mid;
                else if(target < arr[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return -1;
        }
};

int main(){
    InterPolationSearch is;
    vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21,
                 22, 23, 24, 33, 35, 42, 47};
    int target = 33;
    cout << is.search(arr, target) << endl;
    return 0;
}
