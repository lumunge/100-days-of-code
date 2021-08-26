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
