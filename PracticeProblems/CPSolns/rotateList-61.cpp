class Solution {
    private:
        ListNode* rotate(ListNode* head){
            if(head == NULL) return NULL;
            
            if(head->next == NULL) return head;

            ListNode* curr = head;
            ListNode* prev = NULL;
            
            while(curr->next){
                prev = curr;
                curr = curr->next;
            }
            
            curr->next = head;
            prev->next = NULL;
            return curr;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* newList = head;
        int sz = 0;
        
        ListNode* temp = head;
        
        while(temp){
            temp = temp->next;
            sz++;
        }

        if(k > sz && sz > 0){
            k = k % sz;
        }

        for(int i = 0; i< k; i++){
            newList = rotate(newList);
        }
        return newList;
    }
};
