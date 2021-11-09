#include<iostream>
#include<queue>
#include "./treeStructure.cpp"

using std::queue;
using std::max;
using std::cout;
using std::endl;

/* 
 * PROBLEM STATEMENT:
 * Given the root of a binary tree, return its maximum depth.
 *
 * Iterative Approach:
 * Initialize an empty queue nd push root to it
 * Initialize height of tree as 0
 * Take the front element of the queue, pop it and push its children to queue,
 * add 1 to height of tree
 * Each time it pops an element from the queue, its childern are added to queue and
 * height is increased by one.
 * Return height.
 */

class Solution{
    public:
        //recursive approach
        int maxDepthRec(TreeNode* root){
            if(!root) return 0;
            if(!root->right && !root->left) return 1;
            int leftHeight = maxDepthRec(root->left);
            int rightHeight = maxDepthRec(root->right);
            return max(leftHeight, rightHeight) + 1;
        }

        //iterative approach
        int maxDepthIter(TreeNode* root){
            if(!root) return 0;
            int height = 0;
            TreeNode* currNode;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                height++;
                int s = q.size();
                while(s){
                    currNode = q.front();
                    if(currNode->left) q.push(currNode->left);
                    if(currNode->right) q.push(currNode->right);
                    q.pop();
                    s--;
                }
            }
            return height;
        }
};


int main(){
    Solution soln;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << soln.maxDepthRec(root) << endl;
    cout << soln.maxDepthIter(root) << endl;
    return 0;
}
