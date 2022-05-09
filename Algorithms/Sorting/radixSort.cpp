/*
 * RADIX SORT
 * Used in occassions where the list ranges from 1 - n^2
 * Idea: Digit by digit sort from the least significant digit to the most significant
 * We use counting sort as a subroutine
 *
 * Given an array of nums, we first sort the array using the unit place value, then the tenth,
 * handredth... least significant value
 *
 * Algorithm:
 * For each digit i from least - most significant range:
 *      Sort input array using counting sort according to i
 * 
 * Pseudocode: Radix
 * 1. d <- max digits in largest element e.g (1000 = 4 digits)
 * 2. create d buckets[0 - 9]
 * 3. for i from 0 - d:
 * 4.   sort - (counting sort) according to ith place value
 *
 * Complexity:
 * Radix sort + counting sort subroutine = O(d(n+k)), b - complexity for counting sort
 *                                                    d - number cycle
 * Applications:
 * Card sorting machines
 *               
 */

#include<iostream>
#include<vector>


using std::cout; 
using std::endl;
using std::vector;
using std::max;

class Radix{
    private:
        void countingSort(int arr[], int sz, int plc){ // counting sort algorithm
            const int mx = 10;
            int out[sz];
            int count[mx];

            for(int i = 0; i < mx; i++) // fill with zeros
                count[i] = 0;

            for(int i = 0; i < sz; i++) // get element count
                count[(arr[i] / plc) % 10]++;

            for(int i = 1; i < mx; i++) // cumulative count
                count[i] += count[i-1];

            for(int i = sz - 1; i >= 0; i--){ // sort
                out[count[(arr[i] / plc) % 10] - 1] = arr[i];
                count[(arr[i] / plc) % 10]--;
            }

            for(int i = 0; i < sz; i++) // add to array
                arr[i] = out[i];
        }

        int getMax(int arr[], int n){ // get max val from array
            int mx = arr[0];
            for(int i = 1; i < n; i++)
                mx = max(i, mx);
            return mx;
        }
    public:
        void printArr(int arr[], int n){
            for(int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        void radixSort(int arr[], int sz){
            int mx = getMax(arr, sz);
            
            for(int i = 1; mx/i > 0; i *= 10)
                countingSort(arr, sz, i);
        }
};

int main(){
    Radix rad;
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    rad.radixSort(arr, n);
    rad.printArr(arr, n);

    return 0;
}
