// Leetcode #105 - Contruct binary tree from preorder and inorder traversal

class Solution {
    public:
        int n = 0, idx = 0;
        unordered_map<int, int> map;
        
        TreeNode * helper(vector<int>& pre, vector<int>& in, int start, int end){
            if(start > end){
                return NULL;
            }
            TreeNode * curr_node = new TreeNode(pre[idx++]);
            int nxt_root_idx = map[curr_node->val];
            curr_node->left = helper(pre, in, start, nxt_root_idx - 1);
            curr_node->right = helper(pre, in, nxt_root_idx + 1, end);
            return curr_node;
        }
        
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            n = preorder.size();
            for(int i = 0; i < inorder.size(); i++)
                map[inorder[i]] = i;
            return helper(preorder, inorder, 0, n-1);
        }
};

