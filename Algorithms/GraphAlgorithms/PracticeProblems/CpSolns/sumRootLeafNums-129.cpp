// Leetcode #129 - Sum root to leaf numbers

class Solution {
    private:
        void dfs(TreeNode* root, long long curr){
            if(!root) return;
            curr *= 10;
            curr += root->val;
            if(!root->left && !root->right){ // leaf node
                sum += curr;
                return;
            }
            dfs(root->left, curr); // traverse left subtree
            dfs(root->right, curr); // traverse right subtree
        }
    public:
        long long sum = 0;
        int sumNumbers(TreeNode* root) {
            if(!root) return NULL;
            dfs(root, 0);
            return sum;
        }
};
