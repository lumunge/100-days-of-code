#include<iostream>
using namespace std;

struct Node{
    struct Node *left, *right;
    int data;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

//Inorder traversal --> (left, root, right)
void inorder(struct Node* node){
    //base case
    if(node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
//Preorder traversal --> (root, left, right)
void preorder(struct Node* node){
    if(node == NULL)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}
//Postorder traversal --> (left, right, root)
void postorder(struct Node* node){
    if(node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Inorder Traversal: " << endl;
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal: " << endl;
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal: " << endl;
    postorder(root);
    cout << endl;
    return 0;
}