### PRIORITY QUEUES
    - Stored in a complete binary tree-> stored as an array.
    - Generalization of queue datastructure, each element is assigned a priority and 
      elements come out in order of priority, (Extractmax(elem)).
    - Applications, job scheduling.
    - Operations:
                * Insert(x) - O(treeheight)
                * Extractmax(x) - O(treeheight)
                * Remove(x) - O(treeheigt)
                * Getmax(x) - O(1)
                * Changepriority(x) - O(treeheight)
    - Algos using priority queues:
        * Dijkstra's algorithm -> finding shortest path in graph.
        * Prim's algorithm -> constructing minimum spanning tree
        * Huffman's algorthim -> constructing optimum prefix-free encoding of string(mp3)
        * Heap sort -> inplace (nlogn)
    - Max binary heap -> a binary tree where value fo each node is at least value of
      its children.
    - Operations:
                * Insert(x)         -> attach element to leaf and SIFTUP(move closer to root ->
                                       replace with parent) if heap property is violated. 
                * Extractmax(x)     -> max stored at root, select any leaf and replace with 
                                       root, if heap property is violated, SIFTDOWN(move down
                                       the tree -> replace with children(largest of two children).
                * ChangePriority(x) -> either decrease or increase priority, if element is large
                                       and heap property is violated, SIFTUP else SIFTDOWN.
                * Remove(x)         -> Change element priority to +infinity, element with be SIFTEDUP
                                       than call EXTRACTMAX, root node will be replaced with any leaf,
                                       SIFTDOWN if heap property is violated.
    
##### KEEPING TREE SHALLOW TO IMPROVE TIME: -> Complete Binary trees(low height, stored ar array)
    - A tree is complete if all its levels are filled except possible the last one which
      is filled from left to right.
    - (adv1) Complete binary tree has at most (logn) height.
    - (adv2) Complete binary tree can be stored as an array(1-based Arrays)
             - parent(i)      = floor(i/2)
             - leftChild(i)   = 2i
             - rightChilde(i) = 2i + 1
    - Sample:
       1   2   3   4   5  6   7   8   9
    - [42, 29, 18, 14, 7, 18, 12, 11, 13]
                        
                        42
                       /   \
                      29   18
                         .
                         .
                         .
    - ie: parent of 18    = 3/2   = 1(42)
          children of 18  = 3*2   = 6(18)
                          = 3*2+1 = 7(12)

    - Cost of these advantages is keeping tree complete, 
    - insert(), extractmax(), remove() --> change structure of tree therefore modify
      to preserve tree completeness of tree.
    - Insert() -> insert in left most(l | r) vacant position and SIFTUP.
    - Extractmax() -> replace root with last leaf at last level and SIFTDOWN.
    
##### PSEUDOCODE:
    - maxSize -> max number of elements in heap
    - size -> size of heap
    - h[size] -> an array of length maxsize

    - SIFTUP(i)
        while(i > 1 && h[parent(i)] < h[i])
            swap (h[parent(i),  h[i])
            i <-- parent(i)
            
    - SIFTDOWN(i)
        maxIndex <-- i;                       
        l <-- leftChild(i)                     
        if(l.size() && h[l] > h[maxIndex])      
            maxIndex <-- l
        r <-- rightChild(i)
        if(r.size() && h[r] > h[maxIndex])
            maxIndex <-- r
        if(i != maxIndex)
            swap(h[i], h[maxIndex])
            SIFTDOWN(maxIndex)

    - INSERT(x)
        if(size == maxSize)
            return ERROR
        size <-- size + 1
        h[size] <-- x;
        SIFTUP(size)

    - EXTRACTMAX()
        result <-- H[1]
        H[1] <-- H[size]
        size <-- size - 1
        SIFTDOWN(1)
        return result
    
    - REMOVE(x)
        h[i] <-- +infinity
        SIFTUP(x)
        EXTRACTMAX()

    - CHANGEPRIORITY(x, p)
        oldP <-- h[x]
        h[x] <-- p
        if(p > oldP)
            SIFTUP(x)
        else
            SIFTDOWN(x)
    
    - All operations work O(logn), getmax(O(1))
    - Space efficient -> computing on the fly, array storage

##### SORTING USING PRIORITY QUEUES O(nlogn)
    - PSEUDOCODE:
        Create empty priority queue
        for i from 1 to n:
            INSERT(A[i])
        for i from n downto 1:
            A[i] <-- EXTRACTMAX()

    - Uses additional space to store the priority queue
    - Solution to additional space problem.
    - Turn array to a heap //inplace sorting
        * repair heap property going from bottom to top
        * initially heap property is satisfied in all leaves of depth 0
        * start repairing heap ppt in subtrees of depth 1 till root and whole tree will
          satify heap property

        PSEUDOCODE: buildHeap(A)
            size <-- n
            for i from floor(n/2) downto 1:
                SIFTDOWN(i)

        PSEUDOCODE: heapSort(A[1...n])
            buildHeap(A) //size = n
            repeat(n - 1) times:
                swap(A[1] and A[size]
                size <-- size - 1
                SIFTDOWN(1)

    - Quicksort average case of O(nlogn) faster than heap sort
    - Heapsort worst case of O(nlogn) relatively fast
    - IntroSort = an implementation of both sorting algos switching to heap sort when
                  quick sort shifts to a running time larger than nlogn

##### BUILDING A HEAP {buildHeap(A)}
    - Running time of O(nlogn) since we call SIFTDOWN for O(n) nodes however most nodes 
      are closer to leaves except root, ie root = O(nlogn) its children O(nlogn) - 1 ...
      running time decreases as we go down the tree and therefore the running time comes
      down to O(n) linear time.
    - This however doesnt change running time for heap sort algorithm
    - Applications include,
        Partial Sorting:
        Input:  An array A[1...n], 
                An integer k
        Output: The last k elements of a sorted version of A

    - Approach: No need to sort the entire array of elements just to get last k elements
        PSEUDOCODE:
            buildHeap(A)         O(n)
            for i from i to k:
                Extractmax()     O(klogn)
        
    - if k <= n/logn --> running time is O(n) linear
    
##### Summary:
    - Binary min heap can be implemented in same way, whereby the value of each node is at
      most the values of its two children. Useful for extractMin priority.
    - D-ary heap -> nodes on all levels except possibly the last one have exactly d children
                    height = log base d n
                    SIFTUP = O(log base d n)
                    SIFTDOWN = O(d log base d n)
