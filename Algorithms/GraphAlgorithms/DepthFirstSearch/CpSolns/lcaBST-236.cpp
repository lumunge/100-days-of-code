// Lowest common ancestor of BST - #236

class Solution {
    private:
        TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
            if(!root) return NULL;
            if(root == p || root == q) return root; // or p or q
            TreeNode* left = dfs(root->left, p, q); // go left
            TreeNode* right = dfs(root->right, p, q); // go right
            if(left && right) return root; // left, right returned p, q -> return lca
            return left ? left : right; // special case (p, q are guaranteed to be in subtree)
        }
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
            return dfs(root, p, q);
        }
};
