//Depth first tree traversals (preorder, inorder, postorder)
//Leetcode 144, 94, 145

import java.util.List;
import java.util.ArrayList;
import java.util.Stack;

public class DFTreeTraversals{
    static TreeNode root;

    DFTreeTraversals(int data){
        root = new TreeNode(data);
    }
    DFTreeTraversals(){
        root = null;
    }

    static List<Integer> preOrder(TreeNode root){
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> counter = new Stack<>();
        
        if(root == null)
                return result;
        
        counter.push(root);
        TreeNode currNode = root;

        while(!counter.empty()){
            if(currNode != null){
                result.add(currNode.data);
                if(currNode.right != null)
                    counter.push(currNode.right);
                currNode = currNode.left;
            }else{
                currNode = counter.peek();
                counter.pop();
            }
        }
        return result;
    }
    static List<Integer> inOrder(TreeNode root){
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> counter = new Stack<>();
        
        if(root == null)
            return result;

        TreeNode currNode = root;

        while(!counter.empty() || currNode != null){
            if(currNode != null){
                counter.push(currNode);
                currNode = currNode.left;
            }else{
                currNode = counter.peek();
                result.add(currNode.data);
                counter.pop();
                currNode = currNode.right;
            }
        }
        return result;
    }
    static List<Integer> postOrder(TreeNode root){
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> counter1 = new Stack<>();
        Stack<Integer> counter2 = new Stack<>();
        
        if(root == null)
                return result;

        counter1.push(root);

        while(!counter1.empty()){
            TreeNode currNode = counter1.peek();
            counter1.pop();
            counter2.push(currNode.data);
            if(currNode.left != null) counter1.push(currNode.left);
            if(currNode.right != null) counter1.push(currNode.right);
        }

        while(!counter2.empty()){
            result.add(counter2.peek());
            counter2.pop();
        }
        return result;
    }
    
    static void printList(List<Integer> arr){
        for(Integer i : arr)
            System.out.print(i + " ");
        System.out.println();
    }

    public static void main(String[] args){
        DFTreeTraversals tree = new DFTreeTraversals();
        tree.root = new TreeNode(1);
        root.right = new TreeNode(2);
        root.right.left = new TreeNode(3);
        
        List<Integer> preOrder = preOrder(root);
        List<Integer> inOrder = inOrder(root);
        List<Integer> postOrder = postOrder(root);

        System.out.println("Pre Order df tree traversal");
        printList(preOrder);

        System.out.println("In Order df tree traversal");
        printList(inOrder);

        System.out.println("Post Order df tree traversal");
        printList(postOrder);
    }
}
