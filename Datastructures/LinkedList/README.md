## Linked List

### Operations:
    * Add to front of List --> O(1)
        - Create a new node
        - Assign new data to new node
        - Make next of new node to point to head
        - Make new node head pointer
    * Append to end of List --> O(1)
        - Create a new node
        - Assign last pointer to head pointer
        - Make new node next to NULL --> Its going to be last node
        - Check if linked list is empty, --> make new node to head
        - Traverse till end of list and make last node next to new node
    * Insert node after --> O(1)
        - Check if given node is NULL
        - Create the new node
        - Assign given new data to new node
        - Make next of new node as next of given node
        - Make next of given node as new node
    * Deleting a node
        - Create a temp node and store head node
        - Check if head node contains key to be deleted
        - If true, change next of head to next item
        - Delete old head(temp)
        - Traverse list to find previous node of node to be deleted
        - Search for key, while keeping track of previous node
        - If key not present, return
        - Else change next of previous node to next of temp node
        - Free memory of node to be deleted(delete temp)
