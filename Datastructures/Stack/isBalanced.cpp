#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
    int sz = 100;
    char stack[100];
    int top = -1;

    //push
    void push(char c){
        if(top >= sz-1){
            cout << "Stack overflow" << endl;
        }else{
            top++;
            stack[top] = c;
        }
    }
    //pop
    char pop(){
        char poped;
        if(top <= -1){
            cout << "Stack underflow" << endl;
        }else{
            poped = stack[top];
            //cout << stack[top] << " popped" << endl;
            top--;
        }
        return poped;
    }
    //printStack
    void printStack(){
        if(top >= 0){
            for(int i = top; i >= 0; i--){
                cout << stack[i] << " ";
            }
            cout << endl;
        }else{
            cout << "Empty Stack!" << endl;
        }
    }
    //isEmpty
    bool isEmpty(){
        return (top >= 0) ? false : true;
    }

    bool isBalanced(string str){
        char top;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
                push(str[i]);
            }else{
                if(isEmpty())
                    return false;
                else
                    top = pop();
                    if(top == '[' && str[i] != ']' || top == '(' && str[i] != ')' || top == '{' && str[i] != '}')
                        return false;
            }
        }
        if(isEmpty()){
            cout << "Success" << endl;
            return true;
        }else{
            cout << "Failed" << endl;
            return false;
        }
    }
};


int main(){
    Stack s;
    string str;
    int n = str.length();
    cout << "Enter string: ", cin >> str;
    cout << s.isBalanced(str) << endl;
    return 0;
}



