#include<iostream>
#include "../../Datastructures/LinkedList/linkedList.cpp"
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Given two sorted linked lists, merge and return sorted merged linked list
 *
 * Sample:
 * Input: head1 = [1, 2, 4], head2 = [1, 3, 4]
 * Output: mergedHead = [1, 1, 2, 3, 4, 4]
 */

class Solution {
    public:
        Node* mergeTwoLists(Node* l1, Node* l2){
            Node* merged = NULL;
            if(l1 == NULL)
                return l2;
            if(l2 == NULL)
                return l1;
            if(l1->data <= l2->data){//l1 has least element
                merged = l1; //assign smaller element(l1->data) to merged Node
                merged->next = mergeTwoLists(l1->next, l2); //recurr with next element in l1 and first element in l2
            }else{//l2 has smaller element
                merged = l2; //assign smaller element(l2->data) to merged Node
                merged->next = mergeTwoLists(l1, l2->next); //recurr with first element of l1 and second element in l2
            }
            return merged;
        }
};

int main(){
    LinkedList l1;
    LinkedList l2;
    LinkedList merged;
    Solution soln;
    Node* l1Head = NULL;
    Node* l2Head = NULL;
    l1.push(&l1Head, 1);
    l1.append(&l1Head, 2);
    l1.append(&l1Head, 4);
    l1.printList(l1Head);
    l2.push(&l2Head, 1);
    l2.append(&l2Head, 3);
    l2.append(&l2Head, 4);
    l2.printList(l2Head);
    //sorted merged list
    Node* mergedHead = soln.mergeTwoLists(l1Head, l2Head);
    merged.printList(mergedHead); 
    return 0;
}
