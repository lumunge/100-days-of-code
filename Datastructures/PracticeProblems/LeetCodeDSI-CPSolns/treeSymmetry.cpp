#include<iostream>
#include "./treeStructure.cpp"

using std::cout;
using std::endl;

/*
 * PROBLEM STATEMENT:
 * Given the root of a binary tree, check wheather it is a mirror of itself,
 * Return true if it is symetrical otherwise false
 *
 * Sample:
 * Input: [1, 2, 2, 3, 4, 4, 3]
 * Output: true
 *
 * Input: 1, 2, 2, null, 3, null, 3]
 * Output: false
 *
 * Approach:
 * If the tree is empty return true
 * If either of the subtrees left or right is null, return false
 * If root nodes data for left and right tree or subtree is not equal return false
 * Recurse for left and right subtrees
 */

class Solution{
    private:
        bool checker(TreeNode* root1, TreeNode* root2){
            if(!root1 && !root2)
                return true;
            else if(!root1 || !root2)
                return false;
            if(root1->data != root2->data)
                return false;
            bool lt = checker(root1->right, root2->left);
            bool rt = checker(root1->left, root2->right);
            if(!lt || !rt) return false;
            return true;
        }
    public:
        bool isSymmetric(TreeNode* root){
            return checker(root, root);
        }

};

int main(){
    Solution soln;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << soln.isSymmetric(root) << endl;
    return 0;
}




