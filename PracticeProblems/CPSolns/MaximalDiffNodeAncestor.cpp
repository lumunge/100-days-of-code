/*
 * PROBLEM STATEMENT:
 * Given root of binary tree, find the maximum value v for which there exists different
 * nodes a and b where v = [a.val - b.val] and a is an ancestor of b.
 *
 * Sample:
 * Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
 * Output: 7
 *                              8
 *                          /       \
 *                         3        10
 *                       /    \       \
 *                      1     6        14 
 *                          /   \     /
 *                         4     7   13
 * Explanation: 8 - 1 = 7
 *
 * Approach:
 * Perform a dfs tree traversal while keeping track of max difference and updating it
 */

#include<iostream>
#include<climits>
#include "LeetCodeDSI/treeStructure.cpp"

using std::max;
using std::cout;
using std::endl;

class MaximalDiffNodeAncestor{
    int diff = INT_MIN;
    void dfs(TreeNode *node, TreeNode *minNode, TreeNode *maxNode){
        if(node == NULL) return;
        if(node->data > maxNode->data) minNode = node;
        if(node->data < minNode->data) maxNode = node;
        diff = max(diff, abs(maxNode->data - minNode->data));
        dfs(node->left, minNode, maxNode);
        dfs(node->right, minNode, maxNode);
    }
    int maxAncestorDiff(TreeNode *root){
        if(root == NULL) return 0;
        dfs(root, root, root);
        return diff;
    }
};

int main(){
    cout << "hello" << endl;
}
