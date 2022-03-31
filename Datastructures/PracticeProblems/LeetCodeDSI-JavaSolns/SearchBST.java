// Give root of binary search tree and target, return subtree rooted with the target node
// otherwise return null
// Leet code 700

import java.util.List;

class SearchBST{
    static TreeNode root;
    static TreeNode root1;

    SearchBST(int data){
        root = new TreeNode(data);
    }

    SearchBST(){
        root = null;
    }

    static TreeNode searchBst(TreeNode root, int target){
        if(root == null) return null;
        while(root != null){
            if(root.data > target)
                root = root.left;
            else if(root.data < target)
                root = root.right;
            else
                return root;
        }
        return null;
    }

    void printList(List<Integer> arr){
        for(Integer i : arr)
            System.out.print(i + " ");
        System.out.println();
    }

    public static void main(String[] args){
        LevelOrderTraversal lOrder = new LevelOrderTraversal();
        SearchBST tree = new SearchBST();
        tree.root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        root.right = new TreeNode(7);

        List<List<Integer>> treeList = lOrder.levelOrder(root);
        System.out.println("Tree");
        lOrder.printList(treeList);
        System.out.println("target: 2");

        tree.root1 = searchBst(root, 2);
        List<List<Integer>> subTreeList = lOrder.levelOrder(root1);
        System.out.println("Found sub tree");
        lOrder.printList(subTreeList);
    }
}


