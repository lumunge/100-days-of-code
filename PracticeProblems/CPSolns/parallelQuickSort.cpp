#include<iostream>
#include<omp.h>

using std::cout;
using std::endl;


class ParallelQuickSort{
    int k = 0;

    private:    
        int partition(int arr[], int l, int r){
            int i = l + 1;
            int j = r;
            int key = arr[l];
            int temp;
            while(true){
                while(i < r && key >= arr[i])
                    i++;
                while(key < arr[j])
                    j--;
                if(i < j){
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }else{
                    temp = arr[l];
                    arr[l] = arr[j];
                    arr[j] = temp;
                    return j;
                }
            }
        }

    public:
        void quickSort(int arr[], int l, int r){
            if(l < r){
                int p = partition(arr, l, r);
                cout << "pivot " << p << " found by thread " << k << endl; 

                #pragma omp parallel sections
                {
                    #pragma omp section
                    {
                        k = k + 1;
                        quickSort(arr, l, p-1);
                    }
                    #pragma omp section
                    {
                        k = k + 1;
                        quickSort(arr, p+1, r);
                    }
                }
            }
        }

        void printArr(int arr[], int n){
            for(int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        void run(){
            int arr[] = {45, 6, 2, 11, 7, 10, 4, 8, 12, 1};
            int n = sizeof(arr) / sizeof(arr[0]);
            quickSort(arr, 0, n-1);
            printArr(arr, n);
        }

};

int main(){
    ParallelQuickSort pqs;
    pqs.run();
    return 0;
}
