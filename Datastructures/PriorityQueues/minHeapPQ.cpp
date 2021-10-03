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
        void siftUp(int i){
            //check if node @ i and parent violate heap property
            if(i && arr[parent(i)] > arr[i]){
                swap(arr[i], arr[parent(i)]);
                siftUp(parent(i));
            }
        }
        //Move down the min binary heap
        void siftDown(int i){
            int left = leftChild(i);
            int right = rightChild(i);
            int min = i;

            if(left < size() && arr[left] < arr[i])
                min = left;
            if(right < size() && arr[right] < arr[i])
                min = right;
            if(min != i){
                swap(arr[i], arr[min]);
                siftDown(min);
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
            siftUp(size() - 1);   //for min heap
        }
        //remove minimum element
        void extractMin(){
            try{
                if(size() == 0){
                    throw out_of_range("Underflow");
                }
                //replace root with last element in arr, remove last element
                //siftDown(root)
                arr[0] = arr.back();
                arr.pop_back();
                siftDown(0);   //for min heap
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
    pq.extractMin();
    cout << pq.top() << " ";
    pq.extractMin();
    pq.push(5);
    pq.push(4);
    pq.push(45);
    cout << endl;
    cout << "Size: " << pq.size() << endl;
    cout << pq.top() << " ";
    pq.extractMin();
    cout << pq.top() << " ";
    pq.extractMin();
    cout << pq.top() << " ";
    pq.extractMin();
    cout << pq.top() << " ";
    pq.extractMin();
    cout << endl << boolalpha << pq.isEmpty();
    pq.top();
    pq.extractMin();
    cout << endl;
    return 0;
}

