#include<iostream>
#include<stack>

using std::stack;
using std::cout;
using std::endl;

/*
 * PROBLEM STATEMENT:
 * Implement a FIFO queue using two stacks. It shoudl support the following operations,
 * push -> pushes element to back of queue
 * pop -> remove element from front of queue and returns it
 * peek -> returns element at front of queue
 * empty() -> returns true if queue is empty, else false
 *
 * Approach:
 * push(x): move all elements from stack1 to stack2
 *          push x to stack1
 *          move all elements from stack2 back to stack 1
 */

class StackQueue{
    public:
        stack<int> stk1;
        stack<int> stk2;
        
        void push(int x){
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
            stk1.push(x);
            while(!stk2.empty()){
                stk1.push(stk2.top());
                stk2.pop();
            }
        }
        int pop(){
            int temp = stk1.top();
            stk1.pop();
            return temp;
        }
        int peek(){
            return stk1.top();
        }
        bool empty(){
            return stk1.empty();
        }
};

int main(){
    StackQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;
    return 0;
}
