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
    //Delete a node
    void deleteNode(Node** head, int key){
        Node* temp = *head;
        Node* prev = NULL;
        if(temp != NULL && temp->data == key){
            *head = temp->next;
            delete temp;
        }else{
            while(temp != NULL && temp->data != key){
                prev = temp;
                temp = temp->next;
            }
            if(temp == NULL)
                return;
            prev->next = temp->next;
            delete temp;
        }
    }
};

/*
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
    list.deleteNode(&head, 45);
    list.printList(head);
    return 0;
}
*/
