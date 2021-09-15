#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> stack;
    int n;
    cout << "Operations: ", cin >> n;
    for(int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int x;
            cin >> x;
            if(!stack.empty() && stack.top() > x)
                x = stack.top();
            stack.push(x);
        }else if(cmd == "pop")
            stack.pop();
        else if(cmd == "max")
            cout << stack.top() << endl;
    }
    return 0;
}
