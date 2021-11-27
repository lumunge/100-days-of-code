/*
 * PROBLEM STATEMENT:
 * Given root of a binary tree, determine if it is a valid binary search tree
 *
 * Sample:
 * Input: root = [2, 1, 3]
 * Output: true;
 *
 * Input: root = [5, 1, 4, null, null, 3, 6]
 * Output: false -> 3 is placed to the right of tree, less than the root
 */

#include<iostream>
#include "./treeStructure.cpp"
#include<stack>

using std::stack;
using std::cout;
using std::endl;

/*
 * Approach.
 * We use a stack to store parent nodes to the left
 * Push all left nodes to stack using inner while loop
 * store top node of stack in root before popping the stack
 * if root data is less than left child data, return false
 * if the loop completes successfully
 * return true.
 */

class ValidBST{
    public:
        bool isValid(TreeNode* root){
            if(!root) return false;
            stack<TreeNode*> stack;
            TreeNode* prevNode = nullptr;
            while(!stack.empty() || root){
                while(root){
                    stack.push(root);
                    root = root->left;
                }
                root = stack.top();
                stack.pop();
                if(prevNode && root->data <= prevNode->data) return false;
                prevNode = root;
                root = root->right;
            }
            return true;
        }
};

int main(){
    ValidBST vb;
    TreeNode* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);
    TreeNode* root2 = newNode(5);
    root2->left = newNode(1);
    root2->right = newNode(4);
    root2->right->left = newNode(3);
    root2->right->right = newNode(6);
    cout << vb.isValid(root) << endl;
    cout << vb.isValid(root2) << endl;
    return 0;
}
