#include<iostream>
#include "../../../Datastructures/LinkedList/linkedList.cpp"

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

class Solution {
    public:
        Node* reverseList(Node* head){
            Node *prevNode = NULL, *next = NULL;
            Node* current = head;
            while(current){
                next = current->next;
                current->next = prevNode;
                prevNode = current;
                current = next;
            }
            return prevNode;
        }
};

int main(){
    LinkedList ll;
    Solution soln;
    Node *head = NULL;
    for(int i = 1; i < 7; i++)
        ll.append(&head, i);
    ll.printList(head);
    Node *reversedHead = soln.reverseList(head);
    ll.printList(reversedHead);
    return 0;
}
