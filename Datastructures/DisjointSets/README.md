### DISJOINT SETS

#### OPERATIONS:
    - MakeSet(x) -  create a singleton set {x}
    - Find(x) - returns id of set containing x. 
        therefore if x and y lie in same set:
            find(x) == find(y) -> return same id
    - Union(x, y) - merges two sets containing x and y
    
    - Applications:
        * Building a Network(Kruskal's Aglo) -> check if two machines are in same network
        * Computing shorelines of terrain
        * Connected component labelling in image analysis

    - Sample Problem:
        In a maze find out if point A is reachable from point B
            * Algo:
                for each cell c in maze:
                    MakeSet(c)                  //creates a separate region for eahch cell
                for each cell c in maze:
                    for each neighbor n in c:   //If c and n are adjacent and there is no wall
                        Union(c, n)

#### IMPLEMENTATIONS
    - NAIVE:
        Arrays:
            - Use smallest element of set as its ID
            - Create new smallest[1-n] arr -> will store smallest element in the set i belongs to
            - Example:
                {9, 3, 2, 4, 7} -> 2
                {6, 1, 8}       -> 1
                {5}             -> 5

                            1  2  3  4  5  6  7  8  9 --> Set elements 
                smallest = [1, 2, 2, 2, 5, 1, 2, 1, 2]
        - OPERATIONS:
            - MakeSet(i)
                smallest[i] <- i  // O(1)

            - Find(i)
                return smallest[i] //O(1)

            - Union(1, j) // O(n)
                i_id <- Find(i)                         //Get ids of each
                j_id <- Find(j)
                if(i_id == j_id)                        //If they are equal, there in same set
                    return
                m <- min(i_id, j_id)                    //get min between the two
                for k from i to n:
                    if(smallest[k] in {i_id, j_id})     //Make a union of all smallest with i_id or j_id to min
                        smallest[k] <- m

               ** Union is a bottleneck, not efficient

        LINKEDLIST
            - Allows for efficient merging.
            - Represent set as a linked list, use tail as id of set
                Example:
                    9->3->2->4->7->  id == 7
                    6->1->8->        id == 8
            - Merging is appending one list to another, id of merged set is updated automatically
            - Pros:
                - Union(x, y) --> O(1)
                - Well-defined id(tail)
            - Cons:
                - Find(x) --> O(n) - need for traversal of the whole list to find element, lists get longer and longer
                - Union(x, y) - is only O(1) iff getting tails of list and head is O(1)

        TREES
            - Each set is represented as a rooted tree
            - ID of a set is root of tree
            - Create an array parents[1...n]: parents[i] == parent of i / i if it is root
            - Example:
               (1)     (2)      (3)
                5       6        4
                      /   \    / | \ 
                     8     1  2  3  9
                                    |
                                    7

                           1  2  3  4  5  6  7  8  9
                parents = [6, 4, 4, 4, 5, 6, 9, 6, 4] 

            - OPERATIONS:
                MakeSet(i) O(1)
                    parent[i] <- i
                
                Find(i)  O(treeHeight)
                    while (i != parent[i])  // while i is not root
                        i <- parent[i]      // replace i with its parent
                    return i
                
                Union 
                    - hang one tree under root on second tree
                    - Hang shorter to larger tree, keeps tree shallow, height influences 
                      running time also called union by rank heuristic
                    
                    UNION BY RANK:
                        - Always attach smaller depth tree under the root of depper tree.
                        - To quickly find tree height of subtree, create an array
                          rank[1...n]: rank[i] -> height of subtree whose root is i

                        MakeSet(i)
                            parent[i] <- i
                            rank[i] <- 0

                        Find(i) O(log n) --> remains same

                        Union(i, j)  O(log n)
                            i_id <- Find(i)
                            j_id <- Find(j)
                            if(i_id == j_id)
                                return
                            if(rank[i_id] > rank[j_id]) // check which height is larger
                                parent[j_id] <- i_id    // hang smaller to larger
                            else
                                parent[i_id] <- j_id   
                                if(rank[i_id] == rank[j_id])  // if both heights are equal
                                    rank[j_id] <- rank[j_id] + 1 // height increases under this case
                        
                            * Invariant --> for any node i, rank[i] == height of tree rooted at i
                    
                    PATH COMPRESSION:
                        - Flatten tree where find() is called, find() traverses up from node up to the root
                        - Make the found root as parent of node so no need to traverse immediate nodes again.
                        - If x is root of subtree, then path(to root) from all nodes under x is compressed.
                        - Find(i) will traverse path from i to root
                        - Not only will it find root of i but also finds all roots of
                          nodes its path
                        - Reattach all the nodes int path directly to root, saves time for future calls of find
                        - Path compression heuristic

                        Find(i)
                            if(i != parent[i])
                                parent[i] <- Find(parent[i])
                            return parent[i]

                        - Iterated Logarithm n, log* n, -> number of times the logarithm function
                          need to be applied to n before the result is less or equal to 1.
                                
                                n               log*n
                                n = 1               0
                                n = 2               1
                                n = 3-4             2
                                n = 5-16            3
                                n = 17-65536        4
                                n = 65537-2^65536   5

                        - For any practical value of n, the log*n is at most 5

                        - Using Union By rank && Path Compression heiristics,
                          m operations on n objects, n calls to MakeSet
                          Time = O(m log* n)






























