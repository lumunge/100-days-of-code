#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main(){
    //root creation
    struct Node* root = new Node(1);
    //create nodes
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left - new Node(4);

    /*
     * nl = NULL
     *          1
     *         /  \
     *        2    3
     *       / \  /  \
     *      4  nl nl nl
     *     / \
     *    nl nl
     */
    return 0;
}
