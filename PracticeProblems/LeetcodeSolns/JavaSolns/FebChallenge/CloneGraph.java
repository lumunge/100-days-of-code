// Leetcode - #133 - clone graph.

class CloneGraph{
    private HashMap<Node, Node> hmap = new HashMap();
    
    private Node dfs(Node currNode){
        if(currNode == null) return currNode;
        
        if(hmap.containsKey(currNode)) return hmap.get(currNode);
        hmap.put(currNode, new Node(currNode.val));
        
        for(Node n : currNode.neighbors)
            hmap.get(currNode).neighbors.add(dfs(n));

        return hmap.get(currNode);
    }

    public Node cloneGraph(Node node) {
        return dfs(node);
    }
}
