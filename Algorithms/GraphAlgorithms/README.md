# Introduction. 
- Used to represent connections between objects
    -> Internet
    -> Maps
    -> Social Networks
    -> Configuration spaces

#### Connected Compoenents.
-  Connected compoenents whereby v and w vertices are reachable from each other.
- Proof of equivalence.
    -> v is reachable from v
    -> if v is reachable from w, w is reachable from v
    -> if v is reachable from u and w is reachable from v, w is reachable from u.

- Problem Statement: Give a graph G, find the connected compoenents of G.
    -> Input: Graph G.
    -> Output: Connected components.
- Idea, modify dfs, while traversing the graph label vertices.

- PSUDOCODE:
    Explore(v):
        visited(v) <- true
        CCNum(v) <- cc
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
    previsit(v)
        pre(v) <- clock
        clock <- clock + 1

    postvisit(v)
        post(v) <- clock
        clock <- clock + 1

- Previsit and Post visit number give information about the execution of the DFS.
- For any vertices u, v in the inttervals [pre(v), post(u)] and [pre(v), post(v)] are
  either nested or disjoint.
    -> If u is explored while exploring v, the subroutine cannot finish until v is done
       being explored, post(v) > post(v), nested case.
    -> Explore v after u is done being explored, post(u) < pre(v), disjoint case.



















