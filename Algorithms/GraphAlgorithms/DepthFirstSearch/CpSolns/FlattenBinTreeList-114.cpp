// Leetcode #114 - Flatten binary tree to linked list

class Solution {
    private:
        vector<TreeNode*> vec; // vector to store nodes
    public:
        void preOrder(TreeNode *curr){ // perform a preorder traversal of tree
            if (curr == nullptr) return; 

            vec.push_back(curr); // root->left->right

            preOrder(curr->left);
            preOrder(curr->right);
        }

        void flatten(TreeNode* root){
            preOrder(root); // fill vector
            int n = vec.size();
        
            TreeNode* newRt = root; // new tree
            for(int i = 1; i < n; i++){ // fill tree using vector
                newRt->right = vec[i];
                newRt->left = nullptr;
                newRt = newRt->right;
           }
        }   
};
