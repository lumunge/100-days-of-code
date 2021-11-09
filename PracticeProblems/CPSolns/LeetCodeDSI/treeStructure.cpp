#include<iostream>

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data;
        left, right = NULL;
    }
};

TreeNode* newNode(int data){
    TreeNode* temp = new TreeNode(data);
    return temp;
}
