/*
 * PROBLEM STATEMENT
 * Given a root node of BST and value. Return root node of BST after inserting the value
 *
 * Sample:
 * Input: root = [4, 2, 7, 1, 3] val = 5
 * Output: root = 4, 2, 7, 1, 3, 5]
 */

#include<iostream>
#include "./levelOrder.cpp"
#include<vector>

using std::vector;
using std::cout;
using std::endl;

/*
 * Approach.
 * Initialize new node, and return it if root is null.
 * Initialize currNode pointing to root and a null parent which we use to place new node.
 * Traverse the tree to find position for new node.
 * If value is less than root, traverse left to find position else traverse right
 */

class InsertBST{
    public:
        TreeNode* insert(TreeNode* root, int data){
            TreeNode* newNode = new TreeNode(data);
            if(!root) return newNode;
            TreeNode* currNode = root;
            TreeNode* parent = nullptr;
            while(currNode){
                parent = currNode;
                if(currNode->data >= data)
                    currNode = currNode->left;
                else
                    currNode = currNode->right;
            }
            if(parent->data >= data)
                parent->left = newNode;
            else
                parent->right = newNode;
            return root;
        }
};

int main(){
    InsertBST ib;
    TraverseTree tt;
    TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    vector<vector<int>> oldTree = tt.levelOrder(root);
    tt.printVec(oldTree);
    TreeNode* newTreeNode = ib.insert(root, 5);
    vector<vector<int>> newTree = tt.levelOrder(newTreeNode);
    cout << "new tree" << endl;
    tt.printVec(newTree);
    return 0;
}

