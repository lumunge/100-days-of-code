// Leetcode #112 - path sum

class Solution {
    public:
        bool hasPathSum(TreeNode* root, int targetSum) {
            if(!root) return false;
            else if(!root->left && !root->right && targetSum - root->val == 0) return true;
            else return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
        }
};
