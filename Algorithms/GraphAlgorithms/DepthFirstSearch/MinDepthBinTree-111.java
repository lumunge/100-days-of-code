// Leetcode #111 - Minimum depth of binary tree

class MinDepthBinTree{
    int helper(TreeNode root, int depth){
        if(root == null) return 0;
        if(root.left == null && root.right == null) return depth; // no leaf nodes, return 1 - height of one node
        if(root.left == null) return helper(root.right, depth + 1); // traverse right
        if(root.right == null) return helper(root.left, depth + 1); // traverse left
        return Math.min(helper(root.left, depth + 1), helper(root.right, depth + 1)); // return minimum between the two
        
    }
    public int minDepth(TreeNode root){
        return helper(root, 1);            
    }
}
