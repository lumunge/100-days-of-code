//Leet code 88

import java.util.Scanner;

class MergeSorted{
    public static void merge(int[] nums1, int m, int[] nums2, int n){
        //initialize pointers, point to end of each array
        int i = m - 1, j = n - 1;
        //pointer to new array, points to end of nums1
        int k = m + n - 1;

        while(i >= 0 && j >= 0){
            //if num1 element is greater
            if(nums1[i] >= nums2[j])
                //place at end of nums1 and decrement i
                nums1[k--] = nums1[i--];
            else
                //place element from nusm2 to end of nums1, decrement i
                nums1[k--] = nums2[j--];
        }
        //remainder elements from nusm2
        while(j >= 0){
            //place to end of nums1
            nums1[k--] = nums2[j--];
        }
    }

    public static void printArr(int[] arr){
        for(int i = 0; i < arr.length; i++){
            System.out.println(arr[i]);
        }
    }

    public static void main(String args[]){
        int[] nums1 = {1, 2, 3, 0, 0, 0};
        int[] nums2 = {2, 5, 6};
        merge(nums1, 3, nums2, 3);
        printArr(nums1);
    }
}








