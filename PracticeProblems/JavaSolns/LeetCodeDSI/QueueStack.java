// Implement a queue using two stack
// Leet code 232

import java.util.Stack;

class QueueStack{
    Stack<Integer> stk1 = new Stack<>();
    Stack<Integer> stk2 = new Stack<>();
    
    public void push(int x) {
        while(!stk1.empty()){
            stk2.push(stk1.peek());
            stk1.pop();
        }
        stk1.push(x);
        while(!stk2.empty()){
            stk1.push(stk2.peek());
            stk2.pop();
        }
    }
    
    public int pop() {
        int temp = stk1.peek();
        stk1.pop();
        return temp;
    }
    
    public int peek() {
        return stk1.peek();
    }
    
    public boolean empty() {
        return stk1.empty();
    }

    public static void main(String[] args){
        QueueStack q = new QueueStack();
        q.push(1);
        q.push(2);
        System.out.println(q.peek());
        System.out.println(q.pop());
        System.out.println(q.empty());
    }
}
