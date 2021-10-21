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
                        return find(k, r.right)  //key is larger searh right subtree
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
