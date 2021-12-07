//Given a stack remove the middle element

#include<iostream>
#include<stack>

using std::stack;
using std::cout;
using std::endl;

void removeMid(stack<int> &stack, int n, int curr = 0){
    //base case (stack is empty, all elements popped)
    if(stack.empty() || curr == n)
        return;

    //pop current element
    int i = stack.top();
    stack.pop();

    //recursively remove other elements
    removeMid(stack, n, curr+1);

    //add elements back to stack except mid element
    if(curr != n/2)
        stack.push(i);
}

void printStack(stack<int> stack){
    while(!stack.empty()){
        int s = stack.top();
        stack.pop();
        cout << s << " ";
    }
    cout << endl;
}

int main(){
    stack<int> stack;

    for(int i = 0; i < 7; i++)
        stack.push(i);

    printStack(stack);

    removeMid(stack, stack.size());

    printStack(stack);
    return 0;
}
