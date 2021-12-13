#include<iostream>
#include<cmath>

using std::cout;
using std::endl;

class RangeSum{
    private:
        int getMid(int l, int r){
            return l + (l-r) / 2;
        }

        int buildTreeUtil(int arr[], int *tree, int stSg, int edSg, int currIdx){
            if(stSg == edSg){
                tree[stSg] = arr[edSg];
                return arr[stSg];
            }
            int mid = getMid(stSg, edSg);
            tree[currIdx] = buildTreeUtil(arr, tree, stSg, mid, currIdx*2+1) + buildTreeUtil(arr, tree, mid+1, edSg, currIdx*2+2);
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
            tree[stSg] = tree[currIdx] + x;
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
