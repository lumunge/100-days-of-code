#include<iostream>
#include "../../../Datastructures/LinkedList/linkedList.cpp"

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

class Solution{
    public:
        Node* deleteNode(Node *head, int key){
            Node *tempHead = head;
            Node *iter = head;
            Node *prev = head;
            
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
};

int main(){
    Solution soln;
    LinkedList ll;
    Node *head = NULL;
    int arr[] = {1,2,6,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(auto i:arr)
        ll.push(&head, i);

    ll.printList(head);
    Node *newHead = soln.deleteNode(head, 6);
    ll.printList(newHead);
    return 0;
}
