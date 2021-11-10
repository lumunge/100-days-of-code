#include<iostream>
#include "./treeStructure.cpp"

using std::cout;
using std::endl;

/* 
 * PROBLEM STATEMENT:
 * Given the root of a binary tree, invert the tree and return its root.
 */

class Solution {
    public:
        TreeNode* invertTree(TreeNode* root){
            
        }
};

int main(){
    TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->rigth = newNode(9);
    return 0;
}
