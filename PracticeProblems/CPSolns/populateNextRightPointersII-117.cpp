class Solution{
    public:
        Node* connect(Node* root) {
            if(!root) return NULL;
            Node* head = root;

            while(head){
                Node* dummy = new Node(0);
                Node* curr = dummy;
                while(head){
                    if(head->left){
                        curr->next = head->left;
                        curr = curr->next;
                    }
                    if(head->right){
                        curr->next = head->right;
                        curr = curr->next;
                    }
                    head = head->next;
                }
                head = dummy->next;
            }
            return root;
        }
};
