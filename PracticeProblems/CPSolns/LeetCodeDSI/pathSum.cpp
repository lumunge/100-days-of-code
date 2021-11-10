#include<iostream>
#include "./treeStructure.cpp"
#include "./levelOrder.cpp"

using std::cout;
using std::endl;

/* 
 * PROBLEM STATEMENT:
 * Given root of binary tree and interger targetSum, return true if tree has
 * root-leaf path adding up to targetSum otherwise false;
 *
 * Approach:
 * Bases case if root is null
 * Traverse the left and right subtrees subtracting node values from target sum recursively
 * If leaf node is reached when target sum is 0, return true otherwise return false.
 */

class Solution {
    public:
        bool hasPathSum(TreeNode* root, int targetSum){
            if(!root)
                return false;
            else if(!root->left && !root->right && targetSum - root->data == 0)
                return true;
            else
                return hasPathSum(root->right, targetSum - root->data) || hasPathSum(root->left, targetSum - root->data);
        }
};

int main(){
    Solution soln;
    TraverseTree traverse;
    TreeNode* root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);
    root->left->left = newNode(11);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(2);
    root->right = newNode(8);
    root->right->left = newNode(13);
    root->right->right = newNode(4);
    root->right->right->right = newNode(1);
    cout << soln.hasPathSum(root, 2) << endl;
    return 0;
}
