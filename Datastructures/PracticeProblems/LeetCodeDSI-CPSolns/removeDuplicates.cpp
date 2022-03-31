#include<iostream>
#include "../../../Datastructures/LinkedList/linkedList.cpp"

using std::cout;
using std::endl;

/*
 * PROBLEM STATEMENT:
 * Given the head of a sorted linked list, delete duplicate elements.
 * Return sorted list.
 *
 * Sample:
 * Input: head = [1, 1, 2, 3, 3]
 * Output: [1, 2, 3]
 *
 *  Approach 1:
 *  Initialize currNode to be head,
 *  Traverse the sorted list, 
 *  if current node data is equal to next node data,
 *  make next pointer to current node point to next next.
 *  
 *  Approach 2:
 *  Initialize currNode to bea head and nextPointer null,
 *  Traverse the list, if current node is equal to next node, assign next pointer to next next
 *  delete the current node next
 *  make next of current node to next pointer
 *  return head
 */

class Solution {
    private:
        LinkedList ll;
    public:
        Node* deleteDuplicates(Node *head){
            Node *currNode = head;
            while(currNode != NULL && currNode->next != NULL){
                if(currNode->data == currNode->next->data){
                    currNode->next = currNode->next->next;
                }else{
                    currNode = currNode->next;
                }
            }
            return head;
        }
        Node* deleteDuplicatesII(Node *head){
            Node *currNode = head;
            Node *nextPointer = NULL;
            while(currNode != NULL && currNode->next != NULL){
                if(currNode->data == currNode->next->data){
                    nextPointer = currNode->next->next;
                    delete(currNode->next);
                    currNode->next = nextPointer;
                }else{
                    currNode = currNode->next;
                }
            }
            return head;
        }

};

int main(){
    LinkedList ll;
    Solution soln;
    Node *head = NULL;
    ll.append(&head, 3); 
    ll.append(&head, 3); 
    ll.append(&head, 2); 
    ll.append(&head, 1); 
    ll.append(&head, 1);
    ll.printList(head);
    Node *newHead = soln.deleteDuplicatesII(head);
    ll.printList(newHead);
    return 0;
};
