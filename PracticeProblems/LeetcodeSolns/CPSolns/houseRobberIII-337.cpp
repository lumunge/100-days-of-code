class Solution{
    private:
        pair<int, int> helper(TreeNode* root){
            if(!root) return {0, 0};
            if(!root->left && !root->right) return {root->val, 0};
            auto left = helper(root->left), right = helper(root->right);
            pair<int, int> p;
            p.first = root->val + left.second + right.second;
            p.second = max(left.first, left.second) + max(right.first, right.second);
            return p;
        }
    public:
        int rob(TreeNode* root){
            pair<int, int> res = helper(root);
            return max(res.first, res.second);
        }
};
