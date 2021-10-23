#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* PROBLEM STATEMENT:
 * Counting Sort
 *  find largest element --> max
 *  initialize count array with zeros
 *  find total count of each unque element
 *  find cumulative sum of the counts in count array
 *  restore element to array while decrementing count
 *  
 *  Sample:
 *  arr [4, 2, 2, 8, 3, 3, 1]
 *  max = 8
 *  count[max] = count[0, 0, 0, 0, 0, 0, 0, 0, 0]
 *  count = 0 1 2 3 4 5 6 7 8
 *          0 1 2 2 1 0 0 0 1
 *  cumulative count = 0 1 3 5 6 6 6 6 7
 * 
 *               arr: 4 2 2 8 3 3 1
 *  restore elements: 0 1 2 3 4 5 6 7 8
 *                    0 1 3 5 6 6 6 6 7
*                   
*                     4 @ position 6 --> 6 - 1 = 5
*                     2 @ position 3 --> 3 - 1 = 2
*                     2 @ position 3 --> 2 - 1 = 1
*                     8 @ position 7 --> 7 - 1 = 6
*                     3 @ position 5 --> 5 - 1 = 4
*                     3 @ position 5 --> 4 - 1 = 3
*                     1 @ position 1 --> 1 - 1 = 0
*
*           Final Arr: 0 1 2 3 4 5 6
*                      1 2 2 3 3 4 8
*
 */

class Sorting{
public:
    void printArr(vector<int> arr){
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void countingSort(vector<int>& arr){
        //Get max and min element
        int max = *max_element(arr.begin(), arr.end());
        int min = *min_element(arr.begin(), arr.end());
        int n = max - min + 1; //range for count array
        //Initialize count array and results array
        vector<int> count(n), result(arr.size());

        //Get count of elements in array
        for(int i = 0; i < arr.size(); i++){
            count[arr[i] - min]++;
        }

        //Get cumulative count array
        for(int i = 1; i < n; i++){
            count[i] += count[i-1];
        }

        //Find index of element of array in count array 
        //place element in result array
        for(int i = arr.size() - 1; i >= 0; i--){
            result[count[arr[i] - min] - 1] = arr[i];
            count[arr[i] - min]--;
        }
        
        //Copy elements in array to result array
        for(int i = 0; i < arr.size(); i++){
            arr[i] = result[i];
        }   
    }
};

int main(){
    Sorting sort;
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    sort.printArr(arr);
    sort.countingSort(arr);
    sort.printArr(arr);
    return 0;
}
