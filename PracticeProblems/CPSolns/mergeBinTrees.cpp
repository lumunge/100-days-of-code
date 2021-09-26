#include<iostream>
#include "../../Datastructures/Trees/bfTreeTraversal.cpp"
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Given two binary trees, root1, root2
 * If two nodes overlap, their sum is new node in merged tree
 * return merged tree
 *
 * Sample:
 * Input: root1 = [1, 3, 2, 5];
 *        root2 = [2, 1, 3, null, 4, null, 7]
 *
 * Output: mrgd = [3, 4, 5, 5, 4, null, 7]
 */

class Solution {
    public:
        Node* mergeTrees(Node* root1, Node* root2){
            if(root1 == NULL)
                return root2;
            if(root2 == NULL)
                return root1;
            root1->data += root2->data;
            root1->left = mergeTrees(root1->left, root2->left);
            root1->right = mergeTrees(root1->right, root2->right);
            return root1;
        }
};
int main(){
    Solution soln;
    Traversal traverse;
    //Tree 1
    Node* root1 = new Node(1);
    root1->left = new Node(3);
    root1->right = new Node(2);
    root1->left->left = new Node(5);
    //Tree 2
    Node* root2 = new Node(2);
    root2->left = new Node(1);
    root2->right = new Node(3);
    root2->left->left = new Node(0);
    root2->left->right = new Node(4);
    root2->right->left = new Node(0);
    root2->right->right = new Node(7);
    Node* mergedRoot = soln.mergeTrees(root1, root2);
    traverse.levelOrder(root1);
    cout << endl;
    return 0;
}
