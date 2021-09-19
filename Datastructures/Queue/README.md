### QUEUE

Works on First In First Out technique
Rear --> element at last position
Front --> element at the first position
Insertions occur at the rear of the queue
Deletions take place at front of the queue

#### Array Implementation

Enqueue * --> Addition of an element to the queue at the back
        * --> Check wheather the queue is full, If rear < n, 
        * --> Store element at rear, increase rear by 1, arr[rear] = newElement, rear++;
        * --> Else if rear == n(size of array) - Queue Overflow, the array is full.

Dequeue --> Removal of element from queue from the front
        --> Check wheather the queue is empty. rear > 0
        --> Delete arr[front], shift elements to left by one position

Front   --> Return front element from queue, if queue is not empty

Display --> Print out elements fron queue


# Operations
    * empty -> check if queue is empty
    * Size -> return size of queue
    * front -> Access front element
    * back -> Access rear element of queue

