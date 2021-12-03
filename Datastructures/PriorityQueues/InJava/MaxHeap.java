class MaxHeap{
    private static void siftDown(int arr[], int i, int n){
        //parent, left and right child
        int max = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if(l < n && arr[l] > arr[max])
            max = l;

        if(r < n && arr[r] > arr[max])
            max = r;

        if(max != i){
            //swap
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
            siftDown(arr, max, n);
        }
    }

    static void buildMaxHeap(int arr[], int n){
        int start = n/2;
        for(int i = start; i >= 0; i--)
            siftDown(arr, i, n);
    }

    static void printArr(int arr[]){
        for(int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String[] args){
        int arr[] = {13, 29, 18, 14, 11, 18, 42, 7, 12};
        int n = arr.length;

        printArr(arr);
        buildMaxHeap(arr, n);
        printArr(arr);
    }
}
