# Segment Trees
- Given an array implement a data structure that
    1. Finds the sum of elements from index l to r where 0 <= l <= r <= n-1
    2. Change values of a specified element of the array to a new value x.
         That is arr[i] = x where 0 <= i <= n-1

## Representation with segment tree
    1. Leaf nodes are elements of array
    2. Each internal node representes a merging of leaf nodes.(sum of leaves uder a node)
    - For node at index i, left child = (2*i+1) and right child = (2*i+2) parent = (i-1) / 2


## Construction
- Given an array [0,...,n-1], We divide the array into two halves and call the same division procedure on both halves for each segment and store the corresponding node.
- All levels will be completely filled(full binary tree), therefore there are 2^n -1 nodes exculding dummy nodes.

**Size of array representing the segment tree**
- If n is a power of 2, the size is 2n-1(n leaves and n-1 internal nodes) exculding dummy nodes
- If n is not a power of 2, size is 2^x - 1(x is the smallest power of 2 greater than n. eg n = 10, smallest is 2^4 = 16 ... 2 * 16 - 1 = 31.
- In terms of height, size of tree is log2n, and thus size of memory allocated to segment tree is 2 * 2^log2n - 1

#### Querying
- Get sum from the constrcuted tree.

**Pseudocode**
    getSum(node, l, r){
        if range of node is within l - r
            return value of node
        else if range is outside l - r
            return 0
        else
            return getSum(nodeLeftChild, l, r) + getSum(nodeRightChild, l, r)
    }


#### Updateing
- Updates are dine recursively, Given an index that needs updation, let x be the value to be updated.
- Start from root of tree and add x to all nodes which have the given index in their range.
- If node does not have the given index, continue.
