#include<iostream>
#include "./treeStructure.cpp"
#include "./levelOrder.cpp"

using std::cout;
using std::endl;

/*
 * PROBLEM STATEMENT:
 * Given the root of a binary tree, invert the tree and return its root.
 *
 * Sample:
 * Input: root = [4, 2, 7, 1, 3, 6, 9]
 * Output: [4, 7, 2, 9, 6, 3, 1]
 *
 * Approach:
 * store right subtree in temp
 * make inverted left subtree to be the right subtree of root.
 * make inverted right subtree to be left subtree of root.
 * return root
 */



class Solution {
    public:
        TreeNode* invertTree(TreeNode* root){
            if(!root) return root;
            TreeNode* left = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(left);
            return root;
        }
};

int main(){
    Solution soln;
    TraverseTree traverse;
    TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(9);
    TreeNode* invRoot = soln.invertTree(root);
    vector<vector<int>> result = traverse.levelOrder(root);
    traverse.printVec(result);
    return 0;
}
