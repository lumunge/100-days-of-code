#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class LinkedList{
public:
    //Helper function to print list
    void printList(Node* n){
        while(n != NULL){
            cout << n->data << " ";
            n = n->next;
        }
        cout << endl;
    }
    //Insert at the begining of list
    void push(Node** head, int newData){
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->next = *head;
        *head = newNode;
    }
    //Append to end of list
    void append(Node** head, int newData){
        Node* newNode = new Node();
        Node *last = *head;
        newNode->data = newData;
        newNode->next = NULL;
        if(*head == NULL)
            *head = newNode;
        while(last->next != NULL)
            last = last->next;
        last->next = newNode;
    }
    //Insert Before a Node in list
    void insertBefore(Node* prevNode, int newData){
        if(prevNode == NULL)
            return;
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
};

int main(){
    //Init linked list
    LinkedList list;
    //Init head of list
    Node* head = NULL;
    list.push(&head, 99);
    list.push(&head, 45);
    list.append(&head, 77);
    list.append(&head, 90);
    list.insertBefore(head->next->next, 80);
    list.insertBefore(head->next, 66);
    list.printList(head);
    return 0;
}
