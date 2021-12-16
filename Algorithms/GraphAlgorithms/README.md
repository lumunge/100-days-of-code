# Introduction. 
- Used to represent connections between objects
    -> Internet
    -> Maps
    -> Social Networks
    -> Configuration spaces


#### Exploring graphs.
- Figuring out whether or not one vertex of a graph is reachable from another.
- Applications:
    -> Finding routes on maps.
    -> Ensuring connectivity, road connectivity
    -> Solving puzzles and mazes.

- Path -> sequence of vertices such that each vertex is connected to the next by an edge
          of the graph
- Input: Graph G
  Output: Collection of vertices v of G so there is a path from s to v.

- PSEUDOCODE:
    Components(s):
        DiscoveredNodes <- {s}
        while there are undiscovered nodes leaving edge e
            add vertex at the other end and add it to discoveredNodes
        return discoveredNodes

- It is required to keep track of visited vertices.
- An order of exploring edges is required.

- Approach
    - To keep track of vertices found, assign each vertex a boolean visited(v)
    - Keep a list of unprocessed vertices
    - Explore edges using depth first ordering, that is follow a long path and back track when reached a dead end.
        
        PSEUDOCODE:
            Explore(v):  (adjacency list graph representation)
                visited(v) <- true
                for(v, w) belongs E:
                    if not visited(w):
                        Explore(w)

#### Connected Components.
- Whereby vertices v and w are reachable from each other iff there are in a connected 
  component.
- Proof of equivalence for reachability.
    -> v is reachable from v
    -> if v is reachable from w, w is reachable from v
    -> if v is reachable from u and w is reachable from v, w is reachable from u.

- Problem Statement: Give a graph G, find the connected compoenents of G.
    -> Input: Graph G.
    -> Output: Connected components.
- Idea, modify dfs, while traversing the graph to label vertices.

- PSEUDOCODE:
    Explore(v):
        visited(v) <- true
        CCNum(v) <- cc //labelling
        for (v, w) in E:
            if not visited(w)
                Explore(w)

    DFS(G):
        for all v in V mark v unvisited
            cc <- 1
            for v in V:
                if not visited(v)
                    Explore(v)
                    cc <- cc + 1

- Proof of correctness
    -> Each call to Explore will find a new connected component and every vertex 
       in that component.
    -> O(|V| + |E|) time

#### Previsit and Postvisit orderings.
- Useful to compute the preorder and postorder numbers of dfs.
- Modify DFS to keep track of other data for other uses.

- PSEUDOCODE:
    Explore(v):
        visited(v) <- true
        previsit(v)
        for (v, w) in E:
            if not visited(w):
                Explore(w)
        postvisit(v)

- Keeping track of the order of visits.
    * Initialize clock to 1 at the start of the algorithm.
    * Use a clock that ticks for each pre and post vist to and from a vertex, it records
      for each vertex.

- PSEUDOCODE:
    //clock initialized to 1
    previsit(v)
        pre(v) <- clock
        clock <- clock + 1

    postvisit(v)
        post(v) <- clock
        clock <- clock + 1

- Previsit and Post visit number give information about the execution of the DFS.
- For any vertices u, v in the inttervals [pre(v), post(u)] and [pre(v), post(v)] are
  either nested or disjoint which will give information about how dfs traversed the vertices.
                
               Nested:
                        |-----------|
               |--------------------|

               Disjoint:
               |----------------|
                                  |--------------|
                
               Interleaved: (impossible)
               |-----------------------|
                            |---------------------|

    -> If u is explored while exploring v, the subroutine cannot finish until v is done
       being explored, post(v) > post(v), nested case.
    -> Explore v after u is done being explored, post(u) < pre(v), disjoint case.




















