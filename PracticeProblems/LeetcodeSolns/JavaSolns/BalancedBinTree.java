// Leetcode #110 - balanced binary tree

class BalancedBinTree{
    static int helper(TreeNode root){
        if(root == null) return 0;
        int left = helper(root.left);
        int right = helper(root.right);
        if(left == -1 || right == -1) return -1;
        if(Math.abs(left - right) > 1) return -1;
        return 1 + Math.max(left, right);
    }

    static boolean isBalanced(TreeNode root){
        int bool = helper(root);
        return bool < 0 ? false : true;
    }
}
