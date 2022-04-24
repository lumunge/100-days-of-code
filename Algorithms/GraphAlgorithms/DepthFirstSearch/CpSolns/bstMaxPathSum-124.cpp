// Leetcode #124 - Binary tree maximum path sum

class Solution {
    private:
        vector<int> res;
    
        int dfs(TreeNode* root){
            if(!root) return 0;
            int leftMax = dfs(root->left);
            int rightMax = dfs(root->right);
            leftMax = max(leftMax, 0);
            rightMax = max(rightMax, 0);
            // path with split
            res[0] = max(res[0], root->val + leftMax + rightMax);
            // path without split
            return root->val + max(leftMax, rightMax);
        }
    public:
        int maxPathSum(TreeNode* root){
            res.push_back(root->val);
            dfs(root);
            return res[0];
        }
};
