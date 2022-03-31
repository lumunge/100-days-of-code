#include<iostream>
#include "../../../Datastructures/LinkedList/linkedList.cpp"

using std::cout;
using std::endl;

/* 
 * PROBLEM STATEMENT:
 * Given head of linked list, determin if there is a cycle.
 * A cycle occurs when there is a node in the list that can be reached again by 
 * continuously following the next pointer.
 * Return true is there exists otherwise false.
 *
 * Approach: 
 * Use two pointers fast and slow
 *
 */

class Solution{
    public:
        bool hasCycle(Node *head){
            if(head == NULL) return false;
            Node *fast = head, *slow = head;
            while(fast != NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow)
                    return true;
            }
            return false;
        }
};

int main(){
    return 0;
}
