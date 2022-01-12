class InsertBST{
    static TreeNode insertBst(TreeNode root, int data){
        TreeNode newNode = new TreeNode(data);
        // if tree is empty newNode is root of tree
        if(root == null) return newNode;
        TreeNode currNode = root;
        TreeNode parent = null;
        // traverse tree upto the rightful position.
        while(currNode != null){
            parent = currNode;
            if(currNode.data >= data)
                currNode = currNode.left;
            else
                currNode = currNode.right;
        }
        // place newNode in its right position
        if(parent.data >= data)
            parent.left = newNode;
        else
            parent.right = newNode;
        return root;
}
