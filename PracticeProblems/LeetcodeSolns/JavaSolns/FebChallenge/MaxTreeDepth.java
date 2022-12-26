// Leetcode #104 - maximum depth of a binary tree

class MaxTreeDepth{
    static int maxDepth(TreeNode root){
        if(root == null) return 0;
        int height = 0;
        TreeNode currNode = new TreeNode();
        Queue<TreeNode> q = new LinkedList();
        q.add(root);
        while(!q.isEmpty()){
            height++;
            int s = q.size();
            while(s > 0){
                currNode = q.peek();
                if(currNode.left != null) q.add(currNode.left);
                if(currNode.right != null) q.add(currNode.right);
                q.remove();
                s--;
            }
        }
        return height;
    }
}
