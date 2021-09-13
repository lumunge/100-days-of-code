#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node* top = NULL;

void push(int n){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = n;
    newNode->next = top;
    top = newNode;
}

void pop(){
    if(top == NULL){
        cout << "Stack Underflow" << endl;
    }else{
        cout << top->data << " popped" << endl;
        top = top->next;
    }
}

void printStack(){
    struct Node* ptr;
    if(top == NULL){
        cout << "Empty Stack" << endl;
    }else{
        ptr = top;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    cout << endl;
}

int main(){
    int n, choice;
    cout << "1: Push to stack \n2: Pop from stack \n3: Print stack \n4: Exit " << endl;
    do{
        cout << "Choose operation \n";
        cin >> choice;
        switch(choice){
            case 1:{
                       cout << "Value: ", cin >> n;
                       push(n);
                       break;
                   }
            case 2: {
                        pop();
                        break;
                    }
            case 3:{
                       printStack();
                       break;
                   }
            case 4:{
                       cout << "Exited" << endl;
                       break;
                   }
            default:{
                        cout << "Invalid choice" << endl;
                    }
        }
    }while(choice != 4);
    return 0;
}



