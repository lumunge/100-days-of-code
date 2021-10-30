#include<bits/stdc++.h>

//linked list structure
struct ListNode{
    int data;
    ListNode *next;
};

class LinkedListDeletion{
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

        //print linkd list elements
        void printList(ListNode* head){
            while (head != NULL) {
                std::cout << head->data << " ";
                head = head->next;
            }
            std::cout << std::endl;
        }

        //Using two passes through linked list
        ListNode *removeNthNodeFromEnd(ListNode *head, int n){
            if(!head)
                return head;

            int len = 0;
            ListNode *temp = head;
            while(temp){
                len += 1;
                temp = temp->next;
            }

            int x = len - n;
            ListNode *currNode = head;
            ListNode *prevNode = nullptr;

            while(x > 0){
                prevNode = currNode;
                currNode = currNode->next;
                x -= 1;
            }

            if(!prevNode){
                temp = currNode;
                currNode = currNode->next;
                delete temp;
                head = currNode;
            }else{
                prevNode->next = currNode->next;
                delete currNode;
            }
            return head;
        }
        
        //One pass through the linked list
        ListNode *removeNthNodeFromEndII(ListNode *head, int n){
            ListNode *fast = head, *slow = head;
            for(int i = 0; i < n; i++)
                fast = fast->next;
            if(!fast)
                return head->next;
            while(fast->next){
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = slow->next->next;
            return head;
        }
};

int main(){
    LinkedListDeletion ll;
    ListNode* head = NULL;
    ll.append(&head, 1);
    ll.append(&head, 4);
    ll.append(&head, 7);
    ll.append(&head, 9);
    ll.append(&head, 11);
    std::cout << "Original List" << std::endl;
    ll.printList(head);
    ListNode* newHead1 = ll.removeNthNodeFromEnd(head, 2);
    ListNode* newHead2 = ll.removeNthNodeFromEndII(head, 2);
    std::cout << "Using one pass" << std::endl;
    ll.printList(newHead1);
    std::cout << "Using two pass" << std::endl;
    ll.printList(newHead2);
    return 0;
}
