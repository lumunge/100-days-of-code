#include<iostream>
#include "./tree.cpp"
using namespace std;

//LEVEL ORDER TREE TRAVERSAL

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
            for(int i = 1; i <= ht; i++)
                currentLevel(root, i);
        }
};

int main(){
    Traversal traverse;
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    traverse.levelOrder(root);
    cout << endl;
    return 0;
}
