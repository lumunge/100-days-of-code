#include<iostream>

struct Node{
    struct Node *left, *right;
    int data;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
