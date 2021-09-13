#include<iostream>
using namespace std;

/*
 * ARRAY IMPLEMENTSTION OF STACK DS
 */

class Stack{
public:
    int stack[100], sz = 100, top = -1;

    void push(int n){
        if(top >= sz-1){
            cout << "Stack Overflow" << endl;
        }else{
            top++;
            stack[top] = n;
        }
    }
    void pop(){
        if(top <= -1){
            cout << "Stack Underflow" << endl;
        }else{
            cout << stack[top] << " popped" << endl;
            top--;
        }
    }
    void printStack(){
        if(top >= 0){
            cout << "Elements " << endl;
            for(int i = top; i >= 0; i--){
                cout << stack[i] << " ";
            }
            cout << endl;
        }else{
            cout << "Empty Stack " << endl;
        }
    }        
};


int main(){
    Stack s;
    int n, choice;
    cout << "1: Push to stack \n2: Pop from stack \n3: Print stack \n4: Exit " << endl;
    do{
        cout << "Choose operation \n";
        cin >> choice;
        switch(choice){
            case 1:{
                       cout << "Value: ", cin >> n;
                       s.push(n);
                       break;
                   }
            case 2: {
                        s.pop();
                        break;
                    }
            case 3:{
                       s.printStack();
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
