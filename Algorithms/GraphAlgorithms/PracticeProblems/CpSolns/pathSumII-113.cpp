// Leetcode #113 - Path sum II

class Solution{
    private:
        vector<vector<int>> res;
        void helper(TreeNode* root, vector<int> path, int target, int current){
            if(!root) return;
            current += root->val;
            path.push_back(root->val);
            if(current == target && !root->left && !root->right) // leaf node
                res.push_back(path); // add path to result vector
            helper(root->left, path, target, current); // traverse left
            helper(root->right, path, target, current); // traverse right
            path.pop_back(); // invalid path, remove node value
        }
    public:
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<int> path;
            helper(root, path, targetSum, 0);
            return res;
        }
};
