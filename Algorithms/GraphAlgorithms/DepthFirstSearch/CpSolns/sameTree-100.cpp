// Leetcode #100 - Same tree

class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if(!p && !q) return true; // both null
            if(!p || !q) return false; // one not null
            if(p->val != q->val) return false; // not equal values
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); // recurse on left,right subtrees
        }
};
