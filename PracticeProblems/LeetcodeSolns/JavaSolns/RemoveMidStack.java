//Given a stack remove the middle element

import java.util.Stack;

class RemoveMidStack{
    static void removeMid(Stack<Integer> stack, int n, int current){
        //base case
        if(stack.empty() || current == n)
            return;

        //store referece of top element then pop stack
        int x = stack.pop();
        
        //recursive call
        removeMid(stack, n, current+1);

        if(current != n/2)
            stack.push(x);
    }

    static void printStack(Stack<Integer> stack){
        while(!stack.empty()){
            int s = stack.pop();
            System.out.print(s + " ");
        }
        System.out.println();
    }

    public static void main(String[] args){
        Stack<Integer> stack = new Stack<>();

        for(int i = 1; i < 7; i++)
            stack.push(i);
        
        removeMid(stack, stack.size(), 0);
        printStack(stack);
    }
}
