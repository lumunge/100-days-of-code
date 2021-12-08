//Given a queue remove the middle element

#include<iostream>
#include<queue>

using std::queue;
using std::cout;
using std::endl;

class RemoveMid{
    public:
        //iterative approach
        void removeMidIter(queue<int> &q){
            //temporary queue
            queue<int> temp;
            int n = q.size(), curr = 0;
            int x = ((n % 2) == 0) ? (n/2-1) : (n/2);
            //pop from main queue and push to temp queue except where curr = n/2
            while(!q.empty()){
                int i = q.front();
                q.pop();
                if(curr != x){
                    temp.push(i);
                }
                curr += 1;
            }
            //pop from temp and push to main queue, no mid element
            while(!temp.empty()){
                int t = temp.front();
                q.push(t);
                temp.pop();
            }
        }

        //recursive approach
        void removeMidRec(queue<int> &q, int n, int curr = 0){
            //base case (queue is empty, all elements popped)
            if(q.empty() || curr == n)
                return;
            
            //if queue size is even remove the first mid element else remove mid element
            int x = ((n % 2) == 0) ? (n/2-1) : (n/2);

            //remove from front element
            int i = q.front();
            q.pop();

            //add elements back to front of queue except mid element
            if(curr != x)
                q.push(i);
            
            removeMidRec(q, n, curr + 1);
        }
        //helper to print queue
        void printQueue(queue<int> q){
            while(!q.empty()){
                int s = q.front();
                q.pop();
                cout << s << " ";
            }
            cout << endl;
        }
};

int main(){
    RemoveMid rm;
    queue<int> q;
    
    for(int i = 1; i <= 8; i++)
        q.push(i);

    rm.printQueue(q);
    //rm.removeMidRec(q, q.size());
    rm.removeMidIter(q);
    rm.printQueue(q);
    return 0;
}
