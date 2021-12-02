#include<iostream>

using std::swap;
using std::cout;
using std::endl;

// An implementation of heaps, min and max heaps

class Heaps{
    private:
        void siftDownMaxHeap(int arr[], int i, int n){
            // parent
            int max = i;
            // left child
            int l = 2 * i + 1;
            // right child
            int r = 2 * i + 2;
            
            // left child larger than root
            if(l <= n && arr[l] > arr[max])
                max = l;
            
            // right child larger than root
            if(r < n && arr[r] > arr[max])
                max = r;
            
            // neither left or right larger
            if(i != max){
                swap(arr[i], arr[max]);
                //recursively siftdown in affected subtree
                siftDownMaxHeap(arr, max, n);
            }
        }

        void siftDownMinHeap(int arr[], int i, int n){
            int min = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            
            // left child smaller than parent
            if(l < n && arr[l] < arr[min])
                min = l;
            
            //right child smaller tha parent
            if(r < n && arr[r] < arr[min])
                min = r;
            
            // neither is smal enough
            if(min != i){
                swap(arr[i], arr[min]);
                // recursively siftDown affected subtree
                siftDownMinHeap(arr, min, n);
            }
        }

        

    public:
        void buildMaxHeap(int arr[], int n){
            int start = (n/2) - 1;
            for(int i = start; i >= 0; i--)
                siftDownMaxHeap(arr, i, n);
        }

        void buildMinHeap(int arr[], int n){
            for(int i = n; i >= 0; i--)
                siftDownMinHeap(arr, i, n);
        }

        void printArr(int arr[], int n){
            for(int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
};

int main(){
    Heaps hp;
    int arr[] = {13, 29, 18, 14, 11, 18, 42, 7, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "min heap" << endl;
    hp.printArr(arr, n);
    hp.buildMinHeap(arr, n);
    hp.printArr(arr, n);
    /*
    cout << "max heap " << endl;
    hp.printArr(arr, n);
    hp.buildMaxHeap(arr, n);
    hp.printArr(arr, n);
    */

    return 0;
}

