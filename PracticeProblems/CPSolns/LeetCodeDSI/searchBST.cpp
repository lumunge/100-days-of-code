#include<iostream>
#include "./treeStructure.cpp"
#include "./dfTreeTraversal.cpp"

using std::cout;
using std::endl;

/* 
 * PROBLEM STATEMENT:
 * Given a root of a binary search tree and a target value.
 * Find the node in the BST equal to the target and return subtree rooted with that node
 * otherwise return false.
 *
 * Sample:
 * Input: root = [4, 2, 7, 1, 3], target = 2                4
 * Output: [2, 1, 3]                                       /  \
 *                                                         2   7
 *                                                        /  \
 *                                                        1   3
 *
 *
 * Approach:
 * In a bst, values less than root are stored in left side and value greater than root 
 * are stored in right side.
 * If target is greater than root traverse the left tree, once found return the node
 * Otherwise traverse the left subtree.
 */

class Solution{
    public:
        TreeNode* searchBstRec(TreeNode* root, int target){
            if(!root) return {};
            if(root->data == target)
                return root;
            else if(root->data > target)
                return searchBstRec(root->left, target);
            else
                return searchBstRec(root->right, target);
        }

        TreeNode* searchBstIter(TreeNode* root, int target){
            if(!root) return {};
            if(root->data == target)
                return root;
            else if(root->data > target)
                root = root->left;
            else
                root = root->right;
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
    TreeNode* resRoot = soln.searchBstRec(root, 2);
    vector<int> resRec = traverse.preOrder(resRoot);
    traverse.printArr(resRec);
    return 0;   
}







