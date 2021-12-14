#include<iostream>
#include<cmath>

using std::cout;
using std::endl;

/*
 * PROBLEM STATEMENT:
 * Given an array arr[0,...,n-1] write a data structure that can perform the operations optimally
 * 1. Find sum of elements from index l to r where 0 <= l <= r <= n-1
 * 2. Update value of specified element in the array
 * All this without using loops or assigning an element ie arr[i] = element;
 */

class RangeSum{
    private:
        int getMid(int l, int r){
            return l + (r - l) / 2;
        }

        int buildTreeUtil(int arr[], int *tree, int stSg, int edSg, int currIdx){
            if(stSg == edSg){
                tree[currIdx] = arr[stSg];
                return arr[stSg];
            }
            int mid = getMid(stSg, edSg);
            tree[currIdx] = buildTreeUtil(arr, tree, stSg, mid, 2*currIdx+1) + buildTreeUtil(arr, tree, mid+1, edSg, 2*currIdx+2);
            return tree[currIdx];
        }

        int getSumUtil(int *tree, int stSg, int edSg, int stQr, int edQr, int currIdx){
            if(stQr <= stSg && edQr >= edSg)
                return tree[currIdx];
            if(stSg > edQr || edSg < stQr)
                return 0;
            int mid = getMid(stSg, edSg);
            return getSumUtil(tree, stSg, mid, stQr, edQr, 2*currIdx+1) + getSumUtil(tree, mid+1, edSg, stQr, edQr, 2*currIdx+2);
        }

        void updateValUtil(int *tree, int stSg, int edSg, int i, int x, int currIdx){
            if(i < stSg || i > edSg)
                return;
            tree[currIdx] = tree[currIdx] + x;
            if(stSg != edSg){
                int mid = getMid(stSg, edSg);
                updateValUtil(tree, stSg, mid, i, x, 2*currIdx+1);
                updateValUtil(tree, edSg, mid+1, i, x, 2*currIdx+2);
            }
        }
        
    public:
        void update(int arr[], int *tree, int n, int i, int newVal){
            if(i < 0 || i > n-1){
                cout << "invalid" << endl;
                return;
            }
            
            int x = newVal - arr[i];
            
            arr[i] = newVal;
            updateValUtil(tree, 0, n-1, i, x, 0);
        }

        int getSum(int *tree, int n, int stQr, int edQr){
            if(stQr < 0 || edQr > n-1 || stQr > edQr){
                cout << "invalid";
                return -1;
            }
            return getSumUtil(tree, 0, n-1, stQr, edQr, 0);
        }

        int *buildTree(int arr[], int n){
            int x = (int)(ceil(log2(n)));
            int maxSz = 2*(int)pow(2, x) - 1;
            int *tree = new int[maxSz];
            buildTreeUtil(arr, tree, 0, n-1, 0);
            return tree;
        }
};

int main(){
    RangeSum rs;
    int arr[] = {90, 1, 34, 21, 78, 11, 34, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *tree = rs.buildTree(arr, n);
    //sum range between 3rd and 6th index
    cout << rs.getSum(tree, n, 3, 6) << endl;
    //replace the 1st index element with 10
    rs.update(arr, tree, n, 1, 10);
    //sum range between 1 and 3
    cout << rs.getSum(tree, n, 1, 3) << endl;
    return 0;
}
