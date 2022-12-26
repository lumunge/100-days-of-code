#include<iostream>

using std::cout;
using std::endl;

struct Node{
    int data = -1;
    Node* next = NULL;
};

class LinkedList{
    public:

        int nodes;
        Node* head = NULL;
        Node* tail = NULL;

        // get value of node
        int get(int idx){
            int debug = nodes;
            if(idx < 0 || idx >= nodes) return -1;
            
            // pointer
            Node* cursor = head;
            int c = 0;
            while(c < idx){
                cursor = cursor->next;
                c++;
            }
            return cursor->data;
        }


        /* Add node after node - prev
         * -> initialize new node - newNode
         * -> link next of newNode to prev's next node
         * -> link next of prev to newNode
         */
        void addAtIndex(int idx, int data){
            if(idx == nodes){
                addAtTail(data);
                return;
            }
            if(idx == 0){
                addAtHead(data);
                return;
            }
            if(idx < 0 || idx > nodes) return;

            int c = 0;
            Node* cursor = head;
            while(c < idx - 1){
                cursor = cursor->next;
                c++;
            }

            Node* next = cursor->next;
            Node* newNode = new Node;
            newNode->data = data;
            
            cursor->next = newNode;
            newNode->next = next;
            nodes++;
            
        }

        /* Add node at front of list
         * -> create new node - newNode
         * -> link newNode to head.
         * -> make newNode head
         */
        void addAtHead(Node** head, int data){
            Node* newNode = new Node;
            newNode->data = data;
            if(*head){
                newNode->next = *head;
                *head = newNode;
            }else{
                *head = newNode;
                tail = newNode;
            }
        }

        // Add to end of list
        void addAtTail(int data){
            Node* newNode = new Node;
            newNode->data = data;
            if(tail){
                tail->next = newNode;
                tail = newNode;
            }else{
                tail = newNode;
                head = newNode;
            }
            nodes++;
        }


       /* Add node after node - prev
         * -> initialize new node - newNode
         * -> link next of newNode to prev's next node
         * -> link next of prev to newNode
         */
        void addAtIndex(int idx, int data){
            if(idx == nodes){
                addAtTail(data);
                return;
            }
            if(idx == 0){
                addAtHead(data);
                return;
            }
            if(idx < 0 || idx > nodes) return;

            int c = 0;
            Node* cursor = head;
            while(c < idx - 1){
                cursor = cursor->next;
                c++;
            }

            Node* next = cursor->next;
            Node* newNode = new Node;
            newNode->data = data;
            
            cursor->next = newNode;
            newNode->next = next;
            nodes++;
            
        }

        /* Delete node - delNode
         * -> find prev and next of delNode
         * -> link prev to next node of delNode
         */
        void deleteAtIndex(int idx){}

        /* Delete first node - delNode
         * -> link next pointer of delNode to head of list
         */

        void printList(Node* head){
            while(head != NULL){
                cout << head->data << " ";
                head = head->next;
            }
            cout << endl;
        }
};

int main(){
    LinkedList ll;
    Node* head = NULL;
    ll.addAtHead(&head, 90);
    ll.printList(head);
    return 0;
}







