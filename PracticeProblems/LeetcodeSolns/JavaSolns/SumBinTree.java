/* PROBLEM STATEMENT:
 * Given root of binary tree.
 * For all leaves in the tree consider the binary numbers
 * represented by the path from the root to the leaf.
 * Return the sum of this numbers.
 *
 * Sample:
 * Input: root = [1,0,1,0,1,0,1]
 * Output: 22
 * Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 *
 * Approach.
 * Traverse the tree from root to the leaf nodes recursively adding node values.
 * Add node values by left shifting the current sum with 1 and adding node value.
 */

class SumBinTree{
    static TreeNode root;

    SumBinTree(int data){
        root = new TreeNode(data);
    }

    SumBinTree(){
        root = null;
    }

    static int getSum(TreeNode root, int sum){
        if(root == null) return 0;
        sum = (sum << 1) + root.data;
        //at leaf node
        if(root.left == null && root.right == null)
            return sum;
        return getSum(root.left, sum) + getSum(root.right, sum);
    }

    static int sumRootToLeaf(TreeNode root){
        return getSum(root, 0);
    }

    public static void main(String[] args){
        SumBinTree tree = new SumBinTree();
        tree.root = new TreeNode(1);
        root.left = new TreeNode(0);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(0);
        root.left.right = new TreeNode(1);
        root.right.left = new TreeNode(0);
        root.right.right = new TreeNode(1);
        System.out.println(sumRootToLeaf(root));
    }
}
