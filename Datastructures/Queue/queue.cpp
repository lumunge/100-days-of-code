#include<iostream>
#include<queue>
using namespace std;

//Print queue
void printQueue(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main(){
    queue<int> q;
    q.push(11);
    q.push(22);
    q.push(33);
    q.push(44);
    q.push(55);
    q.push(66);
    printQueue(q);
        
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    q.pop();
    printQueue(q);
    return 0;
};
