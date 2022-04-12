// Leetcode #95 - Unique Binary Search Trees

class Solution {
    private:
        vector<TreeNode*> helper(int l, int r){
            if(l > r) return {NULL};
            vector<TreeNode*> res;
            for(int i = l; i <= r; i++){
                vector<TreeNode*> left = helper(l, i-1);
                vector<TreeNode*> right = helper(i+1, r);
                for(auto Node_l : left){
                    for(auto Node_r : right){
                        TreeNode* newNode = new TreeNode(i);
                        newNode->left = Node_l;
                        newNode->right = Node_r;
                        res.push_back(newNode);
                    }
                }
            }
            return res;
        }
    public:
        vector<TreeNode*> generateTrees(int n) {
            return helper(1, n);
        }
};
