## TREES

- Are hierarchial datastructures.

* Root --> Top most node of a tree
* Children --> elements directly under root
* Stores information that might form a hierarchy, ie computer file system
* Moderate Insertion and deletion, access(quicker than linked lists)
* Use cases:
        - manipulate hierarchial data
        - Search information easily
        - router algorithms
        - mulitstage decision making

* Binary trees --> Has at most two children.

            tree
            -----
            root
           /     \
        child1   child2
        /     \
      child3  child4     --> leaves 
      
##### Tree Respresentation
    - Data
    - Pointer to left child
    - Pointer to right child

* Properties:
    - Max nodes at level l is 2^l
    - Max nodes in binary tree of height h is 2^h+1 - 1

##### Types:
    - Full binary tree --> Every node has 0 or 2 children
    - Complete binary tree --> All levels are completeley filled except possibly last level, keys as left as possible
    - Perfect binary tree --> All nodes have two chidren and leaf nodes are at same level
    - Balanced binary tree --> Difference between height of left subtree and rights subtree is at most 1. O(logn) search, insert, delete operations
    - Degenerate tree --> every node has one child, same as a linked list

##### Tree traversal:
        
        1
       /  \
      2    3
     /  \
    4    5
    
    * Depth First Traversals
        - Inorder (left -> root -> right) --> 4, 2, 5, 1, 3
            `Algorithm:
                - traverse left subtree, inorder(left_subtree)
                - root, print(root)
                - traverse right subtree, inorder(right_subtree) 
            `
            - Usecases:
                - print nodes of a tree in increasing order in binary search tree where elements smaller than root are to left
                  and element greater than root are to the right of the tree.

        - Preorder (root -> left -> right) --> 1, 2, 4, 5, 3
            `Algorithm:
                - root, print(root)
                - traverse left subtree, preorder(left_subtree)
                - traverse right subtree, preorder(right_subtree)
            `
            - Usecases:
                - Create copy of a tree.

        - Postorder (left -> right -> root) --> 4, 5, 2, 3, 1
            `Algorithm:
                - traverse left subtree, postorder(left_subtree)
                - traverse right subtree, postorder(right_subtree)
                - root, print(root)
            `
            - Usecase:
                - delete a tree
    * Breadth First Traversals
        - Level order traversal(level by level) --> 1, 2, 3, 4, 5




