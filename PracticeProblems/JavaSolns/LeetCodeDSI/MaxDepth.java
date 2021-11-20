// Give root of tree, return its maximum depth
// Leet code 104

import java.util.Queue;
import java.util.LinkedList;

class MaxDepth{
    static TreeNode root;

    MaxDepth(int data){
        root = new TreeNode(data);
    }

    MaxDepth(){
        root = null;
    }
    
    static int maxDepth(TreeNode root){
        if(root == null) return 0;
        int height = 0;
        TreeNode currNode;
        Queue<TreeNode> q = new LinkedList<>();
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

    public static void main(String[] args){
        MaxDepth tree = new MaxDepth();
        tree.root = new TreeNode(3);
        tree.root.left = new TreeNode(9);
        tree.root.right = new TreeNode(20);
        tree.root.right.left = new TreeNode(15);
        tree.root.right.right = new TreeNode(7);
        System.out.println(maxDepth(root));
    }
}

