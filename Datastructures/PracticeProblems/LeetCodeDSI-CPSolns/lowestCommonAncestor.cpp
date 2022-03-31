/*
 * PROBLEM STATEMENT:
 * Given a bst, find lowest common ancestor of two given nodes in bst.
 *
 * Sample:
 * Input: [6, 2, 8, 0, 4, 7, 9] p = 2, q = 8
 * Output: 6
 * 
 * Approach:
 * Traverse the tree checking the following conditions
 * If the root is greater than both nodes we should find ancestor in left subtree
 * Otherwise we should find in in the right subtree if root if lesser
 */

#include<iostream>
#include "./treeStructure.cpp"

using std::cout;
using std::endl;

class LowestCommonAncestor{
    public:
        TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
            if(!p || !q) return root;
            while(root){
                if(root->data > p->data && root->data > q->data)
                    root = root->left;
                else if(root->data < p->data && root->data < q->data)
                    root = root->right;
                else
                    break;
            }
            return root;
        }
};

int main(){
    LowestCommonAncestor lca;
    TreeNode* root = newNode(6);
    root->left = newNode(2);
    root->left->left = newNode(0);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->left->right->right = newNode(5);
    root->right = newNode(8);
    root->right->left = newNode(7);
    root->right->right = newNode(9);
    TreeNode* p = newNode(2); TreeNode* q = newNode(8);
    TreeNode* r = newNode(2); TreeNode* s = newNode(4);
    TreeNode* root1 = lca.lca(root, p, q);
    TreeNode* root2 = lca.lca(root, r, s);
    cout << root1->data << endl;
    cout << root2->data << endl;
    return 0;
}
