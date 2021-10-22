### BINARY SEARCH TREES:
    - Local Search Data Structure -> stores a number of elements each with a key coming
      from an orderd set.
      Operations:
        -> RangeSearch(x, y) - return elements with keys between x and y
        -> NearestNeighbour(z) - return element with keys on either side
        -> Insert(x)
        -> Delete(x)
      
      Sample:
        [1, 5, 7, 9, 11, 15, 27, 30]
        RangeSearch(8, 20) -> [9, 11, 15]
        NearestNeighbor(11) -> [9, 15]

    - Consider the datastructures for local search
        
            data structure     | hash table | arrays | sorted arrays | linked lists |
operations  rangeSearch()      | impossible |  O(n)  |  O(log(n)) b/s|     O(n)     | 
            nearestNeighbors() | impossible |  O(n)  |  O(log(n)) b/s|     O(n)     |
            insertion          |    O(1)    |  O(1)  |     O(n)      |     O(1)     |
            deletion           |    O(1)    |  O(1)  |     O(n)      |     O(1)     |
    
    - These data structures dont work well enough for local search.

### Binary Search Trees:
    - Array Search
        [1, 4, 6, 7, 10, 13, 15]

                    tree
                      7             -> easier insertion and deletions
                    /   \
                   4     13
                  /  \   /  \
                 1    6 10   15

    - Tree structure
            -> root node
            -> left subtree(smaller keys) than root/parent
            -> right subtree(larger keys) than root/parent

#### BASIC OPERATIONS:
    - Find:
        input: key k, root r
        output: node in tree with key k

        PSEUDOCODE:
            find(k, r):
                if(r.key == k):
                    return r
                else if(r.key > k):             // key is less, search left subtree
                    if(r.left != null):
                        return find(k, r.left)
                    return r                    // k is missing in tree return position it should be
                else if(r.key < k):
                    if(r.right != null):
                        rveturn find(k, r.right)  //key is larger searh right subtree
                    return r

    - Adjacent Elements:
        input: node n
        output: node in tree with next largest key
        
        Case I:
            -> has right child
            -> go right and then keep going left till you hit null
        Case II:
            -> has no right child
            -> go up the tree checking parents until ancestor

        PSEUDOCODE:
            Next(n):
                if(n.right != null):
                    return leftDescendant(n.right)  // go left till null 
                else:
                    return rightAncestor(n)         // go up till first right or first larger number
            
            leftDescendant(n):
                if(n.left == null)
                    return n
                else
                    return leftDescentand(n.left)

            rightAncestor(n):
                if(n == null)
                    return null
                else if(n.key < n.parent.key):
                    return n.parent
                else
                    return rightAncestor(n.parent)

    - Search:
        input: numbers x, y, root r
        output: list of nodes with key between x and y (range search)

        PSEUDOCODE:
            RangeSearch(x, y, r):
                l <- list() 
                n <- find(x, r)
                while(n.key <= y):
                    if(n.key >= y)
                        l <- l.append(n)
                    n <- next(n)
                return L

    - Insert:
        input: key k, root r
        output: add node with key k to tree

        PSEUDOCODE:
            Insert(k, r):
                p <- find(k, r)
                add node with key k as child of p

    - Delete:
        input: node n
        output: remove node from tree

        PSEUDOCODE:
            Delete(n):
                if(n.right == null):
                    remove n, promote n.left
                else:
                    x <- next(n)  // x has no left child
                    replace n by x, promote x.right
    
#### Balanced Trees:
    - Find O(depth) -> the shallow the depth the better the running time
    - depth can be n -> O(n)
    - We need left and right subtree to have same size
    - For balanced trees -> O(log(n)) time
    - Insertions can destroy balance

    - ROTATIONS:
        -> Rearrange tree to maintain balance while maintaining bst order
        
        PSEUDOCODE:
            RotetRight(x):
                p <- x.parent
                y <- x.left
                b <- y.right
                y.parent <- p
                p.appropriateChild <- y
                x.parent < y, y.right <- x
                b.parent < x, x.left <- b

#### AVL Trees
    - A way to maintain balance in bst
    - Height of node is max depth of its subtree
    - height of tree = 1 + max(leftHeight, rightHeight)
    - Tree structure will be adjusted to cater for node height
        -> Parent
        -> Height
        -> Left
        -> Right
    - AVL Property -> |leftHeight - rightHeight| <= 1
    - This will ensure balance, height = O(log(n))
    - Operations will be O(log(n)) time

    - OPERATIONS:
        -> Insertion - will require new algorithms to cater for the rebalancing to maintain
                       AVL property

                        PSEUDOCODE:
                            AVLInsert(k, r):
                                Insert(k, r)
                                N <- find(k, r)
                                rebalance(n)

                            Rebalance(n):
                                p <- n.parent                           // store pointer to parent, for later rebalancing
                                if(n.left.height > n.right.height + 1)  // if leftheight is bigger 
                                    RebalanceRight(n)                   // rebalance rightwards
                                if(n.right.height > n.left.height + 1)  // if rightHeight is bigger
                                    RebalanceLeft(n)                    // rebalance leftwards
                                AdjustHeight(n)                         // readjust stored height of n
                                if(p != null)                           // if pointer to parent is not null, rebalance at parent
                                    Rebalance(p)
                            
                           
                            AdjustHeight(n):
                                n.height <- 1 + max(n.left.height, n.right.height)

                            

                            RebalanceRight(n):
                                m <- n.left
                                if(m.right.height > m.left.height)
                                    RotateLeft(m)
                                RotateRight(n)
                                AdjustHeight on affected nodes


                            AVLDelete(n)
                                Delete(n)
                                m <- parent of replacement node
                                Rebalance(m)

    - All operations will be O(log(n)) time

    - ADDITIONAL OPERATIONS:
        -> Merge - Combining two binary search trees to single one 
        -> Split - Break up a bst to two bsts

    - MERGE
        - O(n) for merging two sorted lists, merge is faster when they are separated
        input: roots, r1, r2, whereby r1's keys are all smaller then r2's keys
        ouput: root of new tree with elements from both bsts

        PSEUDOCODE:
            MergeWithRoot(r1, r2, t):  O(1)
                t.left <- r1
                t.right <- r2
                r1.parent <- t
                r2.parent <- t
                return t

            Merge(r1, r2):              O(h) time
                t <- find(inf, r1) //find largest in left subtree
                Delete(t)
                MergeWithRoot(r1, r2, t)
                return t

    - merge does not preserve balance

            AVLMergeWithRoot(r1, r2, t): O(|r1.height - r2.height| + 1)
                if(r1.height - r2.height <= 1)
                    MergeWithRoot(r1, r2, t)
                    t.ht <- max(r1.height, r2.height) + 1
                    return t
                else if(r1.height > r2.height)
                    r1^ <- AVLMergeWithRoot(r1.right, r2, t)
                    r1.right <- r^
                    r^.parent <- r1
                    Rebalance(r1)
                    return root
                else if(r1.height < r2.height)
                    Same on the opposite side

    - SPLIT
        input: root r of tree, key x
        output: two trees, tree1 - elements < key x, tree2 - elements > key x

        PSEUDOCODE:
            Split(r, x):                O(log(n)) time
                if(r.null):
                    return(null, null)
                if(x < r.key)                           // everything on right > x
                    (r1, r2) <- Split(r.left, x)        // split on left, r1 all are smaller than x
                    r3 <- AVLMergeWithRoot(r2, r.right, r) // r2 to be combined with whole right subtree of original tree
                    return(r1, r3)                  
                if(x > r.key):
                    same thing on opposite side
            

##### BST APPLICATIONS: 
    - ORDER STATISTICS:
        -> Return 5th largest element
        -> Median element
        -> 25th percentile

        input: root r, number k
        ouput: kth smallest element in r

        -> need to know subtree to search
        -> need to know number of element in subtree
    
    - Number of elements in subtree of N ==>  N.size = N.left.size + n.right.size + 1

    - Maintining sizes

    PSEUDOCODE:
        RecomputeSize(n):
             N.size = N.left.size + n.right.size + 1

        Rotate:
            same pseudocode
            RecomputeSize(old root)
            RecomputeSize(new roor)
        
        // kth smallest element
        OrderStatistics(r, k):  O(h) time
            s <- r.left.size                                // s left subtree size
            if(k = s + 1)                                   
                return r
            else if(k < s + 1)                              // kth smallest element in left subtree
                return OrderStatistics(r.left, k)
            else if(k > s + 1)
                return OrderStatistics(r.right, k - s - 1)

        

    - COLOR FLIPS:
        -> Given an array of squares, black & white
        -> Flip colors of all squares after index x

        Sample:
            [w, w, w, b, b, w, w, b, w]   index = 5
                         .
                         .
                         .
                         v
            [w, w, w, b, b, b, b, w, b]
        
        -> OPERATIONS
            NewArray(n) - creates an array with n white squares
            Color(m) - Return color of mth square
            Flip(x) - Flips the color of all squares of index > x 

            Datastructures:
                Array -> slow flipping O(n)

            BSTS
                - Store elements in sorted order
                - Use two trees, normal colors and opposite colors
                - When we need to flip, swap elements of opposite trees
                
                    PSEUDOCODE:
                        NewArray(n):
                            Create two trees t1, t2, with keys 1...n
                            Give nodes extra color field in their structure
                            t1 color is white
                            t2 color is black

                        Color(m):
                            n <- find(m, t1)
                            return n.color

                        Flip(x):
                            (l1, r1) <- Split(t1, x)
                            (l2, r2) <- Split(t2, x)
                            Merge(l1, r2) -> t1
                            Merge(l2, r1) -> t2

    - BSTs can also be used to store lists


##### SPLAY TREES
    - There are many bsts that give different ways to ensure balance
    - Splay trees are one of them
    - Non Uniform Inputs Search == O(log(n)) time
    - If some items are queried mostly, put them near root for faster search
    - 
                    
                




                                









































            
