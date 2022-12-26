/*
 * True if there is a pythagorean triplet otherwise false
 */

import java.util.Arrays;

class PythagoreanTriplet{
    public static boolean isTriplet(int arr[]){
        int n = arr.length;
        
        //square all elements and sort
        for(int i = 0; i < n; i++)
            arr[i] = arr[i] * arr[i];

        Arrays.sort(arr);
        
        //start from the back, keep a segment of 3 elements
        for(int i = n-1; i >= 2; i--){
            //left & right pointers
            int l = 0, r = i - 1;

            while(l < r){
                if(arr[l] + arr[r] == arr[i])
                    return true;
                else if(arr[l] + arr[r] > arr[i])
                    r--;
                else
                    l++;
            }
        }
        return false;
    }
    
    public static void main(String[] args){
        int arr[] = {3, 1, 4, 6, 13, 8};
        System.out.println(isTriplet(arr));
    }
}
