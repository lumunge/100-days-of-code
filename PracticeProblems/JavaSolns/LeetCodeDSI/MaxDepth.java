// Give root of tree, return its maximum depth
// Leet code 104

class MaxDepth{
    static TreeNode root;

    MaxDepth(int data){
        root = new TreeNode(data);
    }

    MaxDepth(){
        root = null;
    }

    public static void main(String[] args){
        MaxDepth tree = new MaxDepth();
        tree.root = new TreeNode(3);
    }
}

