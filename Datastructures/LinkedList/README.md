## Linked List

### Operations:
    * Add to front of List
        - Create a new node
        - Assign new data to new node
        - Make next of new node to point to head
        - Make new node head pointer
    * Append to end of List
        - Create a new node
        - Assign last pointer to head pointer
        - Make new node next to NULL --> Its going to be last node
        - Check if linked list is empty, --> make new node to head
        - Traverse till end of list and make last node next to new node
    * Insert in middle of List after node
        - Check if given node is NULL
        - Create the new node
        - Assign given new data to new node
        - Make next of new node as next of given node
        - Make next of given node as new node
