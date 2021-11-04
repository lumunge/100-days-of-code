#include<iostream>

using std::cout;
using std::endl;

/* PROBLEM STATEMENT:
 * Given head of a linked list, reverse the list and return the reversed list.
 *
 * Sample:
 * Input head = [1, 2, 3, 4, 5]
 * Output: [5, 4, 3, 2, 1];
 *
 * Approach
 * Initialize 3 pointers
 * prevNode = NULL
 * nextNode = NULL;
 * currNode = head; //points to head
 * Loop through linked list and do the following while currNode is not NULL,
 * Store next  of currNode in nextNode.
 * make next of currNode to prevNode.
 * move prevNode and currNode one step forward.
 * Finally return the previous node
 */

struct ListNode{
    int data;
    ListNode *next;
};

class Solution {
    public:
        ListNode* reverseList(ListNode* head){
            ListNode *prevNode = NULL, *next = NULL;
            ListNode* current = head;
            while(current){
                next = current->next;
                current->next = prevNode;
                prevNode = current;
                current = next;
            }
            return prevNode;
        }
        //push to end of list
        void append(ListNode **head, int newData){
            ListNode *newNode = new ListNode();
            newNode->data = newData;
            newNode->next = NULL;
            ListNode *last = *head;
            if(*head == NULL){
                *head = newNode;
                return;
            }
            while(last->next != NULL){
                last = last->next;
            }
            last->next = newNode;
            return;
        }
        //print linked list
        void printList(ListNode* head){
            while(head != NULL){
                cout << head->data << " ";
                head = head->next;
            }
            cout << endl;
        }
};

int main(){
    Solution soln;
    ListNode *head = NULL;
    for(int i = 1; i <= 7; i++)
        soln.append(&head, i);
    soln.printList(head);
    ListNode *reversedHead = soln.reverseList(head);
    soln.printList(reversedHead);
    return 0;
}
