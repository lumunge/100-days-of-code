#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};


void printList(Node* n){
    while(n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

//Insert at begining
void push(Node** head, int newData){
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

//Insert to end
void append(Node** head, int newData){
    Node* newNode = new Node();
    Node *last = *head;
    newNode->data = newData;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(last->next != NULL)
        last = last->next;
    last->next = newNode;
    return;
}

//Insert before a node
void insert(Node* prevNode, int newData){
    if(prevNode == NULL)
        cout << "NULL Node" << endl;
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node;
    second = new Node;
    third = new Node;

    head->data = 1;
    second->data = 2;
    third->data = 3;

    head->next = second;
    second->next = third;
    third->next = NULL;
    printList(head);
    push(&head, 56);
    printList(head);
    append(&head, 100);
    printList(head);
    insert(head->next->next->next, 99);
    printList(head);
    return 0;
}
