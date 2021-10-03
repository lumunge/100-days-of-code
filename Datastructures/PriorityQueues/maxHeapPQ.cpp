#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class PriorityQueue{
    private:
        vector<int> arr;

        //get parents and children
        int parent(int i){return (i-1) / 2;}
        int leftChild(int i){return (i*2) + 1;}
        int rightChild(int i){return (i*2) + 2;}

        //move up the max binary heap
        void siftUp(int i){
            //check if node @ i and parent violate heap property
            if(i && arr[parent(i)] < arr[i]){
                swap(arr[i], arr[parent(i)]);
                siftUp(parent(i));
            }
        }

        //Move down the max binary heap
        void siftDown(int i){
            //get children of node @ i
            int left = leftChild(i);
            int right = rightChild(i);
            int max = i;
            
            //compare node @ i with left and right to find maximum value
            if(left < size() && arr[left] > arr[i])
                max = left;
            if(right < size() && arr[right] > arr[i])
                max = right;
            //swap with child having greater value and siftdown(child)
            if(max != i){
                swap(arr[i], arr[max]);
                siftDown(max);
            }
        }
    
    public:
        //check if arr is empty
        bool isEmpty(){return arr.size() == 0;}
        //return size of arr
        int size(){return arr.size();}

        //add elements to back of arr
        void push(int k){
            //push to back of arr and get index of element and siftUp(index)
            arr.push_back(k);
            siftUp(size() - 1);
        }
        //remove the maximum or minimum element
        void extractMax(){
            try{
                if(size() == 0){
                    throw out_of_range("Underflow");
                }
                //replace root with last element in arr, remove last element
                //siftDown(root)
                arr[0] = arr.back();
                arr.pop_back();
                siftDown(0);
            }
            catch(const out_of_range &oor){
                cout << endl << oor.what();
            }
        }
        //get first element in arr
        int top(){
            try{
                if(size() == 0){
                    throw out_of_range("Underflow");
                }
                //return first element
                return arr.at(0);
            }
            catch(const out_of_range &oor){
                cout << endl << oor.what();
            }
            return -1;
        }

        void changePriority(int i, int p){
            if(i > size()){
                cout << "Overflow, cannot change priority";
                return;
            }
            int oldP = arr[i];
            arr[i] = p;
            if(p > oldP)
                siftUp(i);
            else
                siftDown(i);
        }
        /*
        void remove(int i){
            if(i > size()){
                cout << "Large";
                return;
            }
            siftUp(i);
            extractMax();
        }
        */
};

int main(){
    PriorityQueue pq;
    pq.push(3);
    pq.push(2);
    pq.push(15);
    cout << "Size: " << pq.size() << endl;
    cout << pq.top() << " ";
    pq.extractMax();
    cout << pq.top() << " ";
    pq.extractMax();
    pq.push(5);
    pq.push(4);
    pq.push(45);
    pq.changePriority(3, 7);
    //pq.remove(3);
    cout << endl;
    cout << "Size: " << pq.size() << endl;
    cout << pq.top() << " ";
    pq.extractMax();
    cout << pq.top() << " ";
    pq.extractMax();
    cout << pq.top() << " ";
    pq.extractMax();
    cout << pq.top() << " ";
    pq.extractMax();
    cout << endl << boolalpha << pq.isEmpty();
    pq.top();
    pq.extractMax();
    cout << endl;
    return 0;
}
