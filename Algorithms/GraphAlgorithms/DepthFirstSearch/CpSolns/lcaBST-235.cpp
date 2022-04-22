// Leetcode #235 - Lowest common ancestor of a binary search tree

class Solution {
    private:
        // recursive implementation
        TreeNode* dfs(TreeNode* root, int p, int q){
            if(!root) return NULL;
            if(root->val > p && root->val > q) // go left
                return dfs(root->left, p, q);
            if(root->val < p && root->val < q) // go right
                return dfs(root->right, p, q);
            return root;
        }
    public:
        // iterative implementation
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(!p || !q)
                return root;
            while(root){
                if(root->val > p->val && root->val > q->val)
                    root = root->left;
                else if(root->val < p->val && root->val < q->val)
                    root = root->right;
                else
                    break;
            }
            return root;
        }
};
