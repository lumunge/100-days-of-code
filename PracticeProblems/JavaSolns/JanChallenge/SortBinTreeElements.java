//Leetcode 1305

import java.util.Collections;
import java.util.ArrayList;
import java.util.List;

class SortBinTreeElements{
    List<Integer> res = new ArrayList<>();
    private void helper(TreeNode root){
        if(root == null) return;
        res.add(root.val);
        helper(root.left);
        helper(root.right);
    }
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        if(root1 == null && root2 == null) return res;
        helper(root1);
        helper(root2);
        Collections.sort(res);
        return res;
    }
}
