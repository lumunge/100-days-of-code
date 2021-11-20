// Given root of a binary tree invert the tree and return its root
// Leet code 226

import java.util.List;
import java.util.ArrayList;

class InvertBinTree{
    static TreeNode root;
    static TreeNode root1;

    InvertBinTree(int data){
        root = new TreeNode(data);
    }

    InvertBinTree(){
        root = null;
    }

    static TreeNode invertTree(TreeNode root){
        if(root == null) return root;
        TreeNode left = root.left;
        root.left = invertTree(root.right);
        root.right = invertTree(left);
        return root;
    }

    public static void main(String[] args){
        InvertBinTree tree = new InvertBinTree();
        tree.root = new TreeNode(4);
        tree.root.left = new TreeNode(2);
        tree.root.right = new TreeNode(7);
        tree.root.left.left = new TreeNode(1);
        tree.root.left.right = new TreeNode(3);
        tree.root.right.left = new TreeNode(6);
        tree.root.right.right = new TreeNode(9);
        //old tree = [4, 2, 7, 1, 3, 6, 9]
        LevelOrderTraversal lOrder = new LevelOrderTraversal(); 
        //root = invertTree(root);
        List<List<Integer>> treeList = lOrder.levelOrder(root);
        System.out.println("Before Inversion");
        lOrder.printList(treeList);
        tree.root1 = invertTree(root);
        List<List<Integer>> invertedTree = lOrder.levelOrder(root1);
        System.out.println("After Inversion");
        lOrder.printList(invertedTree);
    }
}
