// Leetcode #230 - Kth smallest element in a BST

class Solution {
    private:
        vector<int> nums;
        void inorder(TreeNode* root){
            if(root == NULL)
                return;
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);           
        }
    public:
        int kthSmallest(TreeNode* root, int k) {
            inorder(root);
            sort(nums.begin(), nums.end());
            return nums[k-1];
        }
};
