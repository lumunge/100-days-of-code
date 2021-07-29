import networkx as nx
# This function takes as input a graph g and a list of vertices of the cycle.
# (Each vertex given by its index starting from 0.)
# The graph is complete (i.e., each pair of distinct vertices is connected by an edge),

def convertTuple(tup):
    delimiter = ', '
    string = delimiter.join([str(val) for val in tup])
    return string


def cycle_length(g, cycle):
    # Checking that the number of vertices in the graph equals the number of vertices in the cycle.
    assert len(cycle) == g.number_of_nodes()
    weight = 0
    paths = {
            "0, 1": 2,
            "1, 0": 2,
            "0, 2": 1,
            "2, 0": 1,
            "0, 3": 2,
            "3, 0": 2,
            "1, 2": 2,
            "2, 1": 2,
            "1, 3": 1,
            "3, 1": 1,
            "2, 3": 2,
            "3, 2": 2,
        }
    path = list(zip(cycle, cycle[1:] + cycle[:1]))
    for i in path:
        r = convertTuple(i)
        for j in paths:
            if(j == r):
                weight += paths[j]
    return weight
    
# Here is a test case:
# Create an empty graph. 
g = nx.Graph()
# Now we will add 6 edges between 4 vertices
g.add_edge(0, 1, weight = 2)
# We work with undirected graphs, so once we add an edge from 0 to 1,
#it automatically creates an edge of the same weight from 1 to 0.

g.add_edge(1, 2, weight = 2)
g.add_edge(2, 3, weight = 2)
g.add_edge(3, 0, weight = 2)
g.add_edge(0, 2, weight = 1)
g.add_edge(1, 3, weight = 1)

# Now we want to compute the lengths of two cycles:
cycle1 = [0, 1, 2, 3]
cycle2 = [0, 2, 1, 3]
assert(cycle_length(g, cycle1) == 8)
assert(cycle_length(g, cycle2) == 6)
print(cycle_length(g, cycle1))
print(cycle_length(g, cycle2))

