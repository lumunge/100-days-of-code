class MinHeap{
    private static void siftDown(int arr[], int i, int n){
        //parent, left and right child
        int min = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if(l < n && arr[l] < arr[min])
            min = l;

        if(r < n && arr[r] < arr[min])
            min = r;

        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            siftDown(arr, min, n);
        }
    }

    static void buildMinHeap(int arr[], int n){
        for(int i = n; i >= 0; i--)
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
        buildMinHeap(arr, n);
        printArr(arr);
    }
}
