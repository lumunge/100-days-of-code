#include<iostream>
#include<vector>
using namespace std;

/* 
 * PROBLEM STATEMENT:
 * Given head of a singly linked list, return middle node of linked list
 * If there are two nodes return second and middle node
 * Sample:
 * Input: head = [1, 2, 3, 4, 5];
 * Output: [3, 4, 5];
 * Middle node = 3;
 */

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    public:
        //Print linked list
        void printList(Node* n){
            while(n != NULL){
                cout << n->data << " ";
                n = n->next;
            }
            cout << endl;
        }
        //Add nodes to font of list
        void push(Node** head, int newData){
            Node* newNode = new Node();
            newNode->data = newData;
            newNode->next = *head;
            *head = newNode;
        }
        //Append elements to back of list
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
        //get mid nodes
        Node* midNode(Node* head){
            vector<Node*> arr = {head};
            while(arr.back()->next != NULL)
                arr.push_back(arr.back()->next);
            return arr[arr.size() /  2];
        }
};

int main(){
    Node* head = NULL;
    LinkedList list;
    list.push(&head, 1);
    list.append(&head, 2);
    list.append(&head, 3);
    list.append(&head, 4);
    list.append(&head, 5);
    Node* midNodes = list.midNode(head);
    list.printList(midNodes);
    return 0;
}
