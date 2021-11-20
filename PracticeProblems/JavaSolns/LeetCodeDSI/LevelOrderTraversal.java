// Given root of a binary tree, return the level order traversal
// Leetcode 102

import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.LinkedList;

public class LevelOrderTraversal{

    static TreeNode root;

    LevelOrderTraversal(int data){
        root = new TreeNode(data);
    }

    LevelOrderTraversal(){
        root = null;
    }

    static List<List<Integer>> levelOrder(TreeNode root){
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if(root == null) return result;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int n = q.size();
            List<Integer> levelNodes = new ArrayList<>();
            for(int i = 0; i < n; i++){
                TreeNode currNode = q.peek();
                q.remove();
                if(currNode.left != null) q.add(currNode.left);
                if(currNode.right != null) q.add(currNode.right);
                levelNodes.add(currNode.data);
            }
            result.add(levelNodes);
        }
        return result;
    }

    static void printList(List<List<Integer>> arr){
        for(List<Integer> lst : arr){
            for(Integer i : lst){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        LevelOrderTraversal tree = new LevelOrderTraversal();
        tree.root = new TreeNode(3);
        tree.root.left = new TreeNode(9);
        tree.root.right = new TreeNode(20);
        tree.root.right.left = new TreeNode(15);
        tree.root.right.right = new TreeNode(7);

        List<List<Integer>> levelOrder = levelOrder(root);
        printList(levelOrder);
    }
}
