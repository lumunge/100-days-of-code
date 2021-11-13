import java.util.Arrays;

class ArrayIntersection{
    public static int[] intersection(int[] arr1, int[] arr2){
        Arrays.sort(arr1); Arrays.sort(arr2);
        int i = 0, j = 0, k = 0;
        int a1 = arr1.length, a2 = arr2.length;
        while(i < a1 && j < a2){
            if(arr1[i] < arr2[j])
                i++;
            else if(arr1[i] > arr2[j])
                j++;
            else{
                arr1[k] = arr1[i];
                k++;
                i++;
                j++;
            }
        }
        return Arrays.copyOfRange(arr1, 0, k);
    }
    public static void printArr(int arr[]){
        for(int i = 0; i < arr.length; i++)
            System.out.println(arr[i]);
    }

    public static void main(String[] args){
        int[] arr1 = {4, 9, 5};
        int[] arr2 = {9, 4, 9, 8, 4};
        int[] res = intersection(arr1, arr2);
        printArr(res);
    }
}
