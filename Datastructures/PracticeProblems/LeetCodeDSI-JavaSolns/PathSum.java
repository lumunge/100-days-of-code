// Give root of binary tree and target sum, return true if targetSum exists in tree 
// otherwise false
// Leet code 112

class PathSum{
    static TreeNode root;

    PathSum(int data){
        root = new TreeNode(data);
    }

    PathSum(){
        root = null;
    }

    static boolean hasPathSum(TreeNode root, int targetSum){
        if(root == null)
            return false;
        else if(root.left == null && root.right == null && targetSum - root.data == 0)
            return true;
        else
            return hasPathSum(root.right, targetSum - root.data) || hasPathSum(root.left, targetSum - root.data);
    }

    public static void main(String[] args){
        PathSum tree = new PathSum();
        tree.root = new TreeNode(5);
        root.left = new TreeNode(4);
        root.right = new TreeNode(8);
        root.left.left = new TreeNode(11);
        root.left.left.left = new TreeNode(7);
        root.left.left.right = new TreeNode(2);
        root.right.left = new TreeNode(13);
        root.right.right = new TreeNode(4);
        root.right.right.right = new TreeNode(1);
        System.out.println(hasPathSum(root, 22));
        System.out.println(hasPathSum(root, 89));
    }
}
