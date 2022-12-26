/*
 * PROBLEM STATEMENT:
 * Given root of binary tree, find the maximum value v for which there exists different
 * nodes a and b where v = [a.val - b.val] and a is an ancestor of b.
 *
 * Sample:
 * Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
 * Output: 7
 *                              8
 *                          /       \
 *                         3        10
 *                       /    \       \
 *                      1     6        14 
 *                          /   \     /
 *                         4     7   13
 * Explanation: 8 - 1 = 7
 *
 * Approach:
 * Perform a dfs tree traversal while keeping track of max difference and updating it
 */

class MaximalDiffNodeAncestor{
    static TreeNode root;

    MaximalDiffNodeAncestor(int data){
        root = new TreeNode(data);
    }

    MaximalDiffNodeAncestor(){
        root = null;
    }

    private static int diff = Integer.MIN_VALUE;
    //dfs
    static void dfs(TreeNode node, TreeNode minNode, TreeNode maxNode){
        if(node == null) return;
        if(node.data > maxNode.data) maxNode = node;
        if(node.data < maxNode.data) minNode = node;
        diff = Math.max(diff, Math.abs(maxNode.data - minNode.data));
        //dfs traversal on left and right subtree
        dfs(node.left, minNode, maxNode);
        dfs(node.right, minNode, maxNode);
    }
    static int maxAncestorDiff(TreeNode root){
        if(root == null) return 0;
        dfs(root, root, root);
        return diff;
    }
    public static void main(String[] args){
        MaximalDiffNodeAncestor tree = new MaximalDiffNodeAncestor();
        tree.root = new TreeNode(8);
        root.left = new TreeNode(3);
        root.right = new TreeNode(10);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(6);
        root.right.right = new TreeNode(14);
        root.right.right.left = new TreeNode(13);
        System.out.println(maxAncestorDiff(root));
    }
}
