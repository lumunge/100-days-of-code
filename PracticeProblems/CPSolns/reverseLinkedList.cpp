#include<iostream>
#include "../../Datastructures/LinkedList/linkedList.cpp"
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Given head of a singly linked list, reverse the list and return the head of reverse list 
 *
 * Sample:
 * Input: head = [1, 2, 3, 4, 5]
 * Output: head = [5, 4, 3, 2, 1]
 */

class Solution {
    public:
        //Iterative
        Node* reverseList(Node* head){
            //Declare pointers
            Node* current = head;
            Node *prev = NULL, *next = NULL;
            while(current != NULL){
                //Make next one element after current(head in begining)
                next = current->next;
                //reverse current->next pointer
                current->next = prev;
                //Move pointers one position to right
                prev = current;
                current = next;
            }
            //current becomes null, loop stops to the right
            head = prev;
            return head;
        }

        //Recursive
        Node* reverseListII(Node* head){
            if(head == NULL || head->next == NULL)
                return head;
            Node* rest = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return rest;
        }
};

int main(){
    Solution soln;
    LinkedList l;
    LinkedList reversedList;
    Node* head = NULL;
    l.push(&head, 1);
    l.append(&head, 2);
    l.append(&head, 3);
    l.append(&head, 4);
    l.append(&head, 5);
    l.printList(head);
    Node* reversedHead = soln.reverseList(head);
    reversedList.printList(reversedHead);
    return 0;
}
