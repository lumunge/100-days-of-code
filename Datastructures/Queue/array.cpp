#include<iostream>
using namespace std;

class Queue{
public:
    int queue[100], n = 100, front = -1, rear = -1;

    //Enqueue - Insert to the back
    void Enqueue(int val){
        if(rear == n - 1) //is queue full?
            cout << "Overflow!" << endl;
        else{
            if(front == -1)
            front = 0;
            rear++;
            queue[rear] = val;
        }
    }
    //Dequeue - Remove from front
    void Dequeue(){
       if(front == -1 || front > rear) // is queue empty?
           cout << "Underflow" << endl;
       else{
           cout << "Deleted " << queue[front] << endl; //Not really deleted, index increased
           front++;
       }
    }
    //Print queue items
    void Display(){
        if(front == -1)
            cout << "Empty Queue! " << endl;
        else{
            //cout << "Elements: ";
            for(int i = front; i <= rear; i++)
                cout << queue[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    Queue q;
    cout << "1: Enqueue \n2: Dequeue \n3: Display \n4: Exit" << endl;
    int choice;
    int val;
    do{
        cout << "Choose: ", cin >> choice;
        switch(choice){
            case 1:
                cout << "Value: ", cin >> val;
                q.Enqueue(val);
                break;
            case 2: q.Dequeue(); break;
            case 3: q.Display(); break;
            case 4: cout << "Exited" << endl; break;
            default: cout << "Invalid Choice" << endl;
        }
    }while(choice != 4);
    return 0;
}
