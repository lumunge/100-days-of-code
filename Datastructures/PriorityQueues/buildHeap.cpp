#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

/*
 * PROBLEM STATEMENT:
 * Convert an array of given intergers into a heap. Do it by applying a number of swaps
 * to the array using O(n) steps, use a min heap.
 *
 * Sample:
 * Input:
 *      5
 *      5 4 3 2 1
 * Output:
 *      3
 *      1 4
 *      0 1
 *      1 3
 *
 * Exaplanation:
 * Swap(1, 4) --> swap first and fourth element --> 5 1 3 2 4
 * Swap(0, 1) --> swap zero element and first   --> 1 5 3 2 4
 * Swap(1, 3) --> swap first and third elements --> 1 2 3 5 4 --> already forms a heap
 */

class HeapBuilder{
    private:
        vector<int> data_;
        vector< pair<int, int> > swaps_;
        //get parents and children
        int parent(int i){return (i-1) / 2;}
        int leftChild(int i){return (i*2) + 1;}
        int rightChild(int i){return (i*2) + 2;}

        void WriteResponse() const {
            cout << swaps_.size() << "\n";
            for (int i = 0; i < swaps_.size(); ++i){
                cout << swaps_[i].first << " " << swaps_[i].second << "\n";
            }
        }
        void ReadData(){
            int n;
            cin >> n;
            data_.resize(n);
            for(int i = 0; i < n; ++i)
                cin >> data_[i];
        }
        void siftDown(int i){
            int left = leftChild(i);
            int right = rightChild(i);
            int min = i;
            if(left < size() && data_[left] < data_[min])
                min = left;
            if(right < size() && data_[right] < data_[min])
                min = right;
            if(min != i){
                swap(data_[i], data_[min]);
                swaps_.push_back(make_pair(i, min));
                siftDown(min);
            }
        }

      void GenerateSwaps(){
          swaps_.clear();
          int n = data_.size();
          for(int i = n/2; i+1 != 0; i--){
              siftDown(i);
          }
      }
    public:
      int size(){return data_.size();}
      void Solve(){
          ReadData();
          GenerateSwaps();
          WriteResponse();
      }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
