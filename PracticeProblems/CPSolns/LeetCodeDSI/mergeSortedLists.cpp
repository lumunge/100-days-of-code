#include<iostream>
#include "../../../Datastructures/LinkedList/linkedList.cpp"

using std::cout;
using std::endl;

/* PROBLEM STATEMENT:
 * Given two sortd linked lists, merge them and return a sorted linked list.
 * This should be done by splicing together the nodes of the first two lists
 *
 * Sample:
 * Input: l1Head = [1, 2, 4]
 *        l2Head = [1, 3, 4]
 * Output: [1, 2, 2, 3, 4, 4]
 *
 * Approach 1: in-place merging
 * 1. If either list is empty return the other.
 * 2. Start merging procedure with list which has a lesser head node.
 * 3. If list has one node join make head point to second list.
 * 3. Initialize current node in list1 and list, next pointers in list1 and list2
 * 4. Traverse both lists. 
 * 5. If head of 2nd list is between two nodes of first list, insert it there,
 *    make next of 2nd list head. Repeat until both lists are traversed
 * 6. If 1st list has completed traversal, point last node of 1st list to head of 2nd list.
 *
 */

class Solution{
    private:
        LinkedList ll;
    public:
        Node* mergeTwoLists(Node *l1, Node *l2){
            //either of lists null
            if(l1 == NULL)
                return l1;
            if(l2 == NULL)
                return l1;
            //start with lesser list head
            if(l1->data > l2->data)
                swap(l1, l2);
            //if either list has one item
            if(!l1->next){
                l1->next = l2;
                return l1;
            }
            Node *l1Curr = l1, *l1Next = l1->next;
            Node *l2Curr = l2, *l2Next = l2->next;
            while(l1Next && l2Curr){
                //if node of 2nd list lies between two nodes of first list, insert and shift pointers
                if(l2Curr->data >= l1Curr->data && l2Curr->data <= l1Next->data){
                    l2Next = l2Curr->next;
                    l1Curr->next = l2Curr;
                    l2Curr->next = l1Next;

                    //point to next pointers
                    l1Curr = l2Curr;
                    l2Curr = l2Next;
                }else{
                    //remainder nodes 1st list
                    if(l1Next->next){
                        l1Next = l1Next->next;
                        l1Curr = l1Curr->next;
                    }else{
                        //remainder nodes 2nd list
                        l1Next->next = l2Curr;
                        return l1;
                    }
                }
            }
            return l1;
        }
};

int main(){
    Solution soln;
    LinkedList ll;
    Node *head1 = NULL;
    Node *head2 = NULL;
    ll.append(&head1, 3);
    ll.append(&head1, 5);
    ll.append(&head1, 8);
    ll.append(&head2, 1);
    ll.append(&head2, 2);
    ll.append(&head2, 4);
    ll.printList(head1);
    ll.printList(head2);
    cout << "merged list" << endl;
    Node *mergedHead = soln.mergeTwoLists(head1, head2);
    ll.printList(mergedHead);
    return 0;
}
