class TreeSymmetry{
    static TreeNode root;

    TreeSymmetry(int data){
        root = new TreeNode(data);
    }

    TreeSymmetry(){
        root = null;
    }

    static boolean checker(TreeNode root1, TreeNode root2){
        if(root1 == null && root2 == null)
            return true;
        else if(root1 == null || root2 == null)
            return false;
        if(root1.data != root2.data)
            return false;
        boolean lt = checker(root1.right, root2.left);
        boolean rt = checker(root1.left, root2.right);
        if(!lt || !rt) return false;
        return true;
    }

    static boolean isSymmetric(TreeNode root){
        return checker(root, root);
    }

    public static void main(String[] args){
        TreeSymmetry tree = new TreeSymmetry();
        tree.root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(3);

        System.out.println(isSymmetric(root));
    }
}
