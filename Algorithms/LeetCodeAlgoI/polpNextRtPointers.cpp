#include<iostream>
using namespace std;

/* PROBLEM STATEMENT:
 * Given a perfect binary tree, all leaves are on same level, and parent has 2 children
 * Definition is:
 * Node{
 *      int data;
 *      Node *left, *right, *next;
 *  }
 *
 *  Polpulate next pointer to pint to next right node, if no right node, set to NULL
 *  
 *  Sample
 *  Input: [1, 2, 3, 4, 5, 6, 7];
 *  Output: [1, #, 2, 3, #, 4, 5, 6, 7, #];
 *          1           next of 1 == NULL
 *         / \
 *        2   3         next of 2 == 3 next of 3 == NULL
 *       / \  / \
 *      4   5 6  7      next of 4 == 5 next of 5 == 6 next of 6 == 7 next of 7 == NULL
 */
struct Node{
    Node *left, *right, *next;
    int data;
    Node(int data){
        this->data = data;
        left = right = next = NULL;
    }
};

class Traversal{
    private:
        //height of tree
        int height(Node* node){
            if(node == NULL)
                return 0;
            else{
                int lHeight = height(node->left);
                int rHeight = height(node->right);
                if(lHeight > rHeight)
                    return lHeight + 1;
                return rHeight + 1;
            }
        }
        //print current level nodes
        void currentLevel(Node* root, int level){
            if(root == NULL)
                return;
            if(level == 1)
                cout << root->data << " ";
            else if(level > 1){
                currentLevel(root->left, level - 1);
                currentLevel(root->right, level - 1);
            }
        }
    public:
        //level order traversal
        void levelOrder(Node* root){
            int ht = height(root);
            for(int i = 1; i <= ht; i++){
                currentLevel(root, i);
                cout << root->next << " "; //if next == NULL, returns 0;
            }
        }
};

class Solution{
    public:
        Node* connect(Node* root){
            if(root == NULL)
                return NULL;
            Node* current = root;
            while(current->left != NULL){
                Node* nextLevel = current->left;
                while(current != NULL){
                    current->left->next = current->right;
                    if(current->next == NULL)
                        current->right->next = NULL;
                    else
                        current->right->next = current->next->left;
                    current = current->next;
                }
                current = nextLevel; 
            }
            return root;
        }
};
int main(){
    Solution soln;
    Traversal traverse;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node* connectedRoot = soln.connect(root);
    traverse.levelOrder(connectedRoot);
    cout << endl;
    return 0;
}
