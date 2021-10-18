#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Hash{
    private:
        int bucket;
        list<int> *table;

    public:
        Hash(int v);

        int hashFunction(int x){
            return (x % bucket);
        }
        void insertKey(int key);
        void deleteKey(int key);
        void displayTable();
};

Hash::Hash(int b){
    this->bucket = b;
    table = new list<int>[bucket];
}

void Hash::insertKey(int key){
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::displayTable(){
    for(int i = 0; i < bucket; i++){
        cout << i;
        for(auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

vector<int> genRand(int l, int h, int c){
    vector<int> randomNums;
    for(int i = 0; i < c; i++){
        int num = (rand() % (h - l + 1)) + l;
        randomNums.push_back(num);
    }
    return randomNums;
}

void printVector(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}

int main(){
    Hash h(7);
    vector<int> arr = genRand(0, 20, 10);
    for(int i = 0; i < arr.size(); i++)
        h.insertKey(arr[i]);

    h.displayTable();
    cout << endl;
    return 0;
}
