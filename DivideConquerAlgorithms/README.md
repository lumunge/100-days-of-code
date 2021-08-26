#QuickSort
Uses divide and conquer and so its is recursive
Work happens during partitioning of the array
Works in-place(sorting)
Worst Case O(n^2)
Average Case (Onlogn)

QuickSort(arr, l, r);

Dividing and conquering:
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
