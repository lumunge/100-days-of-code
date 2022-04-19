// Leetcode #99 - Recover binary search tree

class Solution {
    private:
        TreeNode *first, *last, *prev;
        
        void inorder(TreeNode *root){
            if(!root) return;
            inorder(root->left);
            if(prev && (root->val < prev->val)){
                if(!first){ // if first violation, mark the two nodes
                    first = prev;
                    last = root;
                }else // if second violation, mark node as last
                    last = root;
            }
            prev = root; // mark node as previous
            inorder(root->right);
        }
    public:
        void recoverTree(TreeNode* root) {
            inorder(root);
            if(first && last)
                swap(first->val, last->val);
        }
};
