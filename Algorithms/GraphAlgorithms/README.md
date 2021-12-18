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

## Directed Acyclic Graphs.
- A directed graph is a graph where edges have direction, that is, start and end vertices.

- Applications:
    -> Followers on social networks
    -> Tasks dependancies
    -> Links between webpages

- For directed DFS we follow directed edges only, pre and post orederings can also be
  computed.
- A cycle -> A sequence of vertices v1,v2,v3 such that they are also edges of a graph G.
- If G contains a cycle it cannot be linearly ordered.
- A graph is a directed acyclic graph iff there are no cycles.
- *DAG* -> a directed graph without cycles. therefore can be linearly ordered.
- In a DAG the last vertex should have incoming edges but no outgoing edges.
- *Source* is a vertex without incoming edges
- *Sink* is a vertex without outgoing edges.

***Getting a linear ordering***
* Find sink
* Place it at the end of the ordering
* Remove it from the graph
* Repeat

*Finding a sink*
- Follow a path as far as possible eventually either we can have a cycle or reach a vertex
  that cannot be extended(sink).

*PSEUDOCODE*
LinearOrder(G): --> dfs ordering
    while G is not empty:
        Follow path until no extension
        Find sink v
        Place v at the end of ordering
        Remove v from G

O(V^2) time complexity.

*PSEUDOCODE*
TopologicalSort(G):
    DFS(G)
    sort vertices by reverse post order

### Connectivity in directed graphs.
- Two vertices u, v are connected either is reachable from the other.
- A directed graph can be partitioned into strongly connected components where two vertices
  are connected iff they are in the same component.
- *metagraph* -> shows how strongly connected components are connected to one another.
- A metagraph is a DAG.


### Computing Stongly Connected Components.
- Input: Directed graph G
- Output: Strongly connected components.

*PSEUDOCODE*
NaiveSCC(G):
    for each vertex v:
        explore(v) to determine vertices reachable from v
    for each vertex v:
        find u reachable from v that is can also reach v
    return SCCs.

O(|V|^2 + |V||E|) -> not otpimal

**Optimal Algorithm**
- Find a sink v in SCC
- Exploring v explore(v) will find vertices reachbale from v
- This is the strongly connected component of v.

*Finding a sink in a SCC*
- If C and C' are SCCs with an edge from vertex C to vertex C', the largest post in C is
  larger than the largest postorder in C'.
- The vertex with the largest postorder number will be in the source component.

- *Reverse Graph* --> the graph obtained by reversing all edges.
- Both Graph G and reverse graph have the same SCCs.
- Source components of reverse graph are the sink componentes of G.
- Run DFS on reverse graph to find sink component.
- The vertex with the largest post-order number from the reverse graph is the sink of a SCC in G.

*PSEUDOCODE*
SCCs(G):
    run DFS(reverse graph)
    let v have the largest post number
    explore(v)
    vertices found are the first SCCs
    remove vertex from G and repeat

- DFS is run repeatedely which is not efficient

*Optimizing*
- Run DFS on reverse graph and record the post-order numbers
- Largest remaining post number will come from sink compoenent.
- Explore in descending order of post-numbers marking compoenents as SCCs.

*PSEUDOCODE*
SCCs(G):
    DFS(reverse graph)
    for v in Vertices in reverse postorder
        if not visited(v):
            explore(v)
            mark visited vertices as SCCs

- DFS on reverse graph and graph G
- O(|V||E|) time complexity.

























