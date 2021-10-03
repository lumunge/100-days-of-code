#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue{
    private:
        vector<int> arr;

        //get parents and children
        int parent(int i){return (i-1) / 2;}
        int leftChild(int i){return (i*2) + 1;}
        int rightChild(int i){return (i*2) + 2;}

        //move up the max binary heap
        void siftUpMax(int i){
            //check if node @ i and parent violate heap property
            if(i && arr[parent(i)] < arr[i]){
                swap(arr[i], arr[parent(i)]);
                siftUpMax(parent(i));
            }
        }

        //move up the max binary heap
        void siftUpMin(int i){
            //check if node @ i and parent violate heap property
            if(i && arr[parent(i)] > arr[i]){
                swap(arr[i], arr[parent(i)]);
                siftUpMin(parent(i));
            }
        }

        //Move down the max binary heap
        void siftDownMax(int i){
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
                siftDownMax(max);
            }
        }
    
        //Move down the min binary heap
        void siftDownMin(int i){
            int left = leftChild(i);
            int right = rightChild(i);
            int min = i;

            if(left < size() && arr[left] < arr[i])
                min = left;
            if(right < size() && arr[right] < arr[i])
                min = right;
            if(min != i){
                swap(arr[i], arr[min]);
                //siftDownMax(min);
                siftDownMin(min);
            }
        }

    public:
        //check if arr is empty
        bool isEmpty(){return arr.size() == 0;}
        //return size of arr
        int size(){return arr.size();}

        //add elements to back of arr
        void push(int k){
            //pushed to back of arr and get index of element and siftUp(index)
            arr.push_back(k);
            siftUpMax(size() - 1); //for max heap
            //siftUpMin(size() - 1);   //for min heap
        }
        //remove elements from front of arr
        void pop(){
            try{
                if(size() == 0){
                    throw out_of_range("Underflow");
                }
                //replace root with last element in arr, remove last element
                //siftDown(root)
                arr[0] = arr.back();
                arr.pop_back();
                siftDownMax(0); //for max heap
                //siftDownMin(0);   //for min heap
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
};


int main(){
    PriorityQueue pq;
    pq.push(3);
    pq.push(2);
    pq.push(15);
    cout << "Size: " << pq.size() << endl;
    cout << pq.top() << " ";
    pq.pop();
    cout << pq.top() << " ";
    pq.pop();
    pq.push(5);
    pq.push(4);
    pq.push(45);
    cout << endl;
    cout << "Size: " << pq.size() << endl;
    cout << pq.top() << " ";
    pq.pop();
    cout << pq.top() << " ";
    pq.pop();
    cout << pq.top() << " ";
    pq.pop();
    cout << pq.top() << " ";
    pq.pop();
    cout << endl << boolalpha << pq.isEmpty();
    pq.top();
    pq.pop();
    cout << endl;
    return 0;
}
