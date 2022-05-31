// Leetcode #654 - Maximum binary tree

class Solution {
    private:
        int max(vector<int>& nums, int l, int r){
            int mx = l;
            for(int i = l; i < r; i++)
                if(nums[mx] < nums[i]) mx = i;
            return mx;
        }
        TreeNode* helper(vector<int>& nums, int l, int r){
            if(l == r) return nullptr;
            int mx = max(nums, l, r);
            TreeNode* root = new TreeNode(nums[mx]);
            root->left = helper(nums, l, mx);
            root->right = helper(nums, mx+1, r);
            return root;
        }
    public:
        TreeNode* constructMaximumBinaryTree(vector<int>& nums){
            int n = nums.size();
            return helper(nums, 0, n);
        }
};
