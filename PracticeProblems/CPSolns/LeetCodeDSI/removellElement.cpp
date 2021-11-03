#include<iostream>

using std::cout;
using std::endl;

/* PROBLEM STATEMENT:
 * Given head of a linked list and an integer key, remove all node of linked list that
 * have the key and return new head.
 *
 * Sample:
 * Input: head = [1, 2, 6, 3, 4, 5, 6], key = 6
 * Output: [1, 2, 3, 4, 5];
 *
 * Approach: O(n) time
 * Initialize three pointers all pointing to head node.
 * Traverse the linked list
 * If key is head, shift head pointer to next element
 * If key is in the tail, make prev node next point to null
 * If key is in middle, make prev next point to next element after key node
 * return head.
 */

struct ListNode{
    int data;
    ListNode *next;
};

class Solution{
    public:
        ListNode* deleteNode(ListNode *head, int key){
            ListNode *tempHead = head;
            ListNode *iter = head;
            ListNode *prev = head;
            
            while(iter != NULL){
                if(iter->data == key){
                    //if key is head
                    if(iter == tempHead){
                        tempHead = iter->next;
                        prev = tempHead;
                    }else if(iter->next == NULL){
                        //if key is tail
                        prev->next = NULL;
                    }else{
                        //if key is middle element
                        prev->next = iter->next;
                    }
                    iter = iter->next;
                }else{
                    prev = iter;
                    iter = iter->next;
                }
            }
            return tempHead;
        }
        //push to front of linked list
        void push(ListNode **head, int newData){
            ListNode *newNode = new ListNode();
            newNode->data = newData;
            newNode->next = *head;
            *head = newNode;
        }
        //print linked list elements
        void printList(ListNode *head){
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
    int arr[] = {1,2,6,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < n; i++)
        soln.push(&head, arr[i]);

    soln.printList(head);
    ListNode *newHead = soln.deleteNode(head, 6);
    soln.printList(newHead);
    return 0;
}
