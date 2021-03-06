# QuickSort
Uses divide and conquer and so its is recursive
Work happens during partitioning of the array
Works in-place(sorting)
Worst Case O(n^2)
Average Case (Onlogn)

QuickSort(arr, l, r);

### Dividing and conquering:
    1: Divide by choosing pivot element: pivot;
    2: rearrange so that elements < pivot go to left;
                         elements > pivot go right;
    3: Conquer by recursively sorting subarrays(left and right of pivot);
    4: Combine by doing nothing, all elements are sorted at this point.
    5: Base case: if l < r

    quickSort(arr, l, r):
        if(p < r):
            //partitioning index
            pi = partition(arr, l, r);
            //recursive steps
            quickSort(arr, l, pi-1);
            quickSort(arr, pi+1, r);

### Linear Partitioning
    1: Choose pivot as array[r];
    2: declare q and assign it to p(first index in array);
    3: Loop through array for j = p; j < r; j++;
    4: if an element is less than or equal to pivot if arr[j] < arr[r];
    5: swap the element with q(q is at first position of array)
    6: Increment q(q is now at second position)
    7: Repeat process until all elements < pivot(arr[r]) are on left side
    8:                      all elements > pivot(arr[r]) are on right side
    9: In the end swap the pivot with q to place the pivot at its rightful place in array
   10: return q -> q is now the pivot(last element in array)
   11: Recurse

    partition(arr, l, r):
        q = l;
        for j = l; j < r; j++:
           if arr[j] < arr[r]:
               swap(arr[j], arr[q]);
               q++;
        swap(arr[r], arr[q]);
        return q;

### Analysis
    1: O(n2) Worst case -> When the pivot does not balace the array
        -> Could be the largest or it could be the smallest, therefore on part
            will have no elements while the other will have n-1 elements.
    2: O(nlogn) Best case -> When the pivot element balances the array, meaning equal 
            elements less than pivot and equal elements greater than pivot.
    3: O(nlogn) Average case -> when pivot lies between two unbalanced array ie between 1/4 
            and 3/4 of the array.
    
    Randomized quicksort    -> Choose a random pivot element
                            -> Choose three and select the median element
                            -> Choose 5 and select median element and so on to improve algorithm
    3-Way Partitioning procedure: Deals with equal elements in an array, escapes their comparision 
                                  and therefore improves running time on an array with equal elements.
    
    3Way(arr, l, r):
        mid = l;
        pivot = arr[r];
        while(mid < r){
            if(arr[mid] < pivot):
                swap(arr[l], arr[mid])
                l++;
                mid++
            else if(arr[mid] == pivot)
                mid++;
            else:
                swap(arr[mid], arr[r])
                r--
        m1 = l - 1;
        m2 = mid;

    quickSort(arr, l, r):
        m1, m2 = 3Way(arr, l, r);
        quickSort(arr, l, m1)
        quickSort(arr, m2, r)

# Merge Sort
    Take an array of elements and divide it up down to single elements and start merging while comparing 
    elements.

    Merge Procedure:
    1: take an array [12, 11, 13, 5, 6, 7]
    2: merge(arr, l, r, mid)
    3: l = 0; r = 6; mid = 3;
    4: create array duplicates copies of arrays to be sorted
    5: m1 = mid - l + 1 = 3 + 0 + 1 == 4;
    6: m2 = r - mid = 5 - 3 = 2
    7: arr1[0, 1, 2, 3, 4](< m1) --> [12, 11, 13, 5], arr2[5, 6](< m2) --> [6, 7];
    8: Maintain indices 
                        For first array  i = 0;
                        For Second array j = 0;
                        For final array  k = p;
    9: Until we reach end of arr1, or arr2, pick larger element and place at correct position
        While(i < m1 && j < m2):
            if(arr1[i] <= arr2[j]) 
                arr[k] = arr1[i]; 
                i++;             
            else:
                arr[k] = arr2[j];
                j++;            
        end while;
    10: When elements run out in either of arrays fill the ramaining elements to the ramaining positions
        While(i < m1):
            arr[k] = arr1[i];
            i++;
            k++;

        While(j < m2):
            arr[k] = arr1[j];
            j++;
            k++;
    
    Mergesort(arr, l, r, mid):                                     
        if l < r 1; return arr;                                 
        mid = n/2;                                          
        mergeSort(arr, l, mid);                           
        mergeSort(arr, mid+1, r);                    
                                                    
        merge(arr, l, r, mid);   

    T(n/2) -- > to calls to merge sort on two halves of array
    n --> Merge procedure
    T(n) = 2T(n/2) + n
    Time Complexity: O(nlogn) -> worst case
