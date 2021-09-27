#include<iostream>
#include "../../Datastructures/LinkedList/linkedList.cpp"
using namespace std;

class Solution {
    public:
        Node* mergeTwoLists(Node* l1, Node* l2){
            Node* merged = NULL;
            if(l1 == NULL)
                return l2;
            if(l2 == NULL)
                return l1;
            if(l1->data <= l2->data){
                merged = l1;
                merged->next = mergeTwoLists(l1->next, l2);
            }else{
                merged = l2;
                merged->next = mergeTwoLists(l1, l2->next);
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
