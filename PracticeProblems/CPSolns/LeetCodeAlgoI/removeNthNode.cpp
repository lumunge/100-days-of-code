#include<iostream>
#include<assert.h>
#include "../../Datastructures/LinkedList/linkedlist.cpp"
using namespace std;

/* 
 * PROBLEM STATEMENT:
 * Given the head of a linked list, remove the nth node from the end of list
 * and return head of linked list
 *
 * Sample:
 * Input: [1, 2, 3, 4, 5], n = 2; --> remove 2nd element from last = 4
 * Output: [1, 2, 3, 5];
 *
 * Input: [1], n = 1;
 * Output: []
 */

class Solution{
    private:
        int getNthNode(Node* head, int index){
            Node* current = head;
            int count = 0;
            while(current != NULL){
                if(count == index)
                    return current->data;
                count++;
                current = current->next;
            }
            assert(0);
        }

        int count(Node* n){
            int count = 0;
            while(n != NULL){
                count++;
                n = n->next;
            }
            return count;
        }
    public:
        Node* head; //head of list

        int deleteNthNode(Node** head, int key){
            int index = count(*head);
            int nodeDelete = getNthNode(*head, index - key);
            return nodeDelete;
        }
        Node* deleteNthNodeII(Node* head, int key){
            Node *fast = head;
            Node *slow = head;
            for(int i = 0; i < key; i++)//fast pointer a head start by (key) nodes before start slow pointer
                fast = fast->next;      //When slow is at key node, fast is at the end
            if(fast == NULL)            //first node == key, return 
                return head->next;       
            while(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = slow->next->next;//make next of slow to be node after key
            return head;
        }
};

int main(){
    Node* head = NULL;
    LinkedList list;
    Solution soln;
    list.push(&head, 1);
    list.append(&head, 2);
    list.append(&head, 3);
    list.append(&head, 4);
    list.append(&head, 5);
    list.printList(head);
    /*
     * first soln execution
    int nodeDelete = soln.deleteNthNode(&head, 2);
    list.deleteNode(&head, nodeDelete);
    */
    //2nd solution execution
    head = soln.deleteNthNodeII(head, 2);
    list.printList(head);
    return 0;
}



