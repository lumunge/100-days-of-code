//Given a stack remove the middle element

#include<iostream>
#include<stack>

using std::stack;
using std::cout;
using std::endl;

class RemoveMid{
    public:
        //iterative approach
        void removeMidIter(stack<int> &stk){
            //temporary stack
            stack<int> temp;
            int n = stk.size(), curr = 0;
            //pop from main stack and push to temp stack except where curr = n/2
            while(!stk.empty()){
                int i = stk.top();
                stk.pop();
                if(curr != n/2){
                    temp.push(i);
                }
                curr += 1;
            }
            //pop from temp and push to main stack, no mid element
            while(!temp.empty()){
                int t = temp.top();
                stk.push(t);
                temp.pop();
            }
        }

        //recursive approach
        void removeMidRec(stack<int> &stk, int n, int curr = 0){
            //base case (stack is empty, all elements popped)
            if(stk.empty() || curr == n)
                return;

            //pop current element
            int i = stk.top();
            stk.pop();

            //recursively remove other elements
            removeMidRec(stk, n, curr+1);

            //add elements back to stack except mid element
            if(curr != n/2)
                stk.push(i);
        }

        void printStack(stack<int> stack){
            while(!stack.empty()){
                int s = stack.top();
                stack.pop();
                cout << s << " ";
            }
            cout << endl;
        }
};

int main(){
    RemoveMid rm;
    stack<int> stack;

    for(int i = 1; i <= 6; i++)
        stack.push(i);

    rm.printStack(stack);

    rm.removeMidRec(stack, stack.size());
    //rm.removeMidIter(stack);

    rm.printStack(stack);
    return 0;
}
