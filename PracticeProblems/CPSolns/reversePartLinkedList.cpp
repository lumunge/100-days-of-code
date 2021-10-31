#include<bits/stdc++.h>

struct ListNode{
    int data;
    ListNode *next;
};

class LinkedListReversal{
    private:
        //reverse a linked list
        ListNode* reverse(ListNode *head){
            ListNode* prevNode = NULL;
            ListNode* currNode = head;
            while(currNode){
                ListNode* next = currNode->next;
                currNode->next = prevNode;
                prevNode = currNode;
                currNode = next;
            }
            return prevNode;
        }

    public:
        //append to end of linked list
        void append(ListNode** head, int newData){
            ListNode* newNode = new ListNode();
            ListNode *last = *head;
            newNode->data = newData;
            newNode->next = NULL;
            if (*head == NULL){
                *head = newNode;
                return;
            }
            while (last->next != NULL){
                last = last->next;
            }
            last->next = newNode;
            return;
        }

        //print linked list elements
        void printList(ListNode* head){
            while (head != NULL) {
                std::cout << head->data << " ";
                head = head->next;
            }
            std::cout << std::endl;
        }
        
        //reversing part of linked list
        ListNode* reversePart(ListNode* head, int m, int n){
            // single element in selected part
            if(m == n)
                return head;
            
            // Initialize pointers
            ListNode* revStart = NULL;
            ListNode* revEnd = NULL;
            ListNode* revPrev = NULL;
            ListNode* revNext = NULL;
            ListNode* currNode = head;
            int i = 1;

            // place all pointers in their respective positions
            while(currNode && i <= n){
                if( i < m)
                    revPrev = currNode;
                if(i == m)
                    revStart = currNode;
                if(i == n){
                    revEnd = currNode;
                    revNext = currNode->next;
                }
                currNode = currNode->next;
                i++;
            }
            revEnd->next = NULL;
            
            // reverse selected part
            revEnd = reverse(revStart);
            
            //rejoin the reversed part back to original list by shifting pointers
            if(revPrev)
                revPrev->next = revEnd;
            else
                head = revEnd;

            revStart->next = revNext;

            return head;
        }

        ListNode* reversePartII(ListNode* head, int m, int n){
            //start cannot be smaller than end position
            if(m > n)
                return head;
            
            ListNode* prevNode = NULL;
            ListNode* currNode = NULL;

           // skip the first m nodes
            for(int i = 1; currNode != NULL && i < m; i++){
                prevNode = currNode;
                currNode = currNode->next;
            }

            // assign pointers to start and end of selected part
            ListNode* revStart = currNode;
            ListNode* revEnd = NULL;
            
            // reverse the selected part
            for(int i = 1; currNode != NULL && i <= n-m+1; i++){
                ListNode* next = currNode->next;
                currNode->next = revEnd;
                revEnd = currNode;
            }

            // reassign pointers and rejoin to main list
            if(revStart != NULL){
                revStart->next = currNode;
                if(prevNode != NULL)
                    prevNode->next = revEnd;
                else
                    head = revEnd;
            }

            return head;
        }
};

int main(){
    LinkedListReversal ll;
    ListNode* head = NULL;
    for(int i = 1; i <= 7; i++){
        ll.append(&head, i);
    }
    std::cout << "Original List" << std::endl;
    ll.printList(head);
    std::cout << "Reversed Lists" << std::endl;
    ListNode* reversedHead = ll.reversePart(head, 3, 5);
    ll.printList(reversedHead);
    ListNode* reversedHeadII = ll.reversePartII(head, 3, 5);
    ll.printList(reversedHeadII);
    return 0;
}
