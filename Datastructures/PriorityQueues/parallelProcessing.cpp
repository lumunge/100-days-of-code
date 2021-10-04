#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::pair;
using std::make_pair;
using std::swap;

struct Threads{
    long long int startTime = 0;
    int threadId;
};

class ParallelProcessing{
    private:
        int leftChild(int i){return (i*2) + 1;}
        int rightChild(int i){return (i*2) + 2;}

        //Move down the min binary heap
        void siftDown(int i, vector<Threads> &threads){
            int left = leftChild(i);
            int right = rightChild(i);
            int min = i;

            if(left < threads.size() && threads[left].startTime == threads[min].startTime){
                int tempOriginalId = threads[min].threadId;
                int tempLeftId = threads[left].threadId;
                if(tempOriginalId > tempLeftId)
                    min = left;
            }else if(left < threads.size() && threads[left].startTime < threads[min].startTime)
                min = left;
            
            if(right < threads.size() && threads[right].startTime == threads[min].startTime){
                int leftId = threads[min].threadId;
                int rightId = threads[right].threadId;
                if(leftId > rightId)
                    min = right;
            }else if(right < threads.size() && threads[right].startTime < threads[min].startTime)
                min = right;
            if(min != i){
                swap(threads[i], threads[min]);
                siftDown(min, threads);
            }
        }
        void changePriority(int i, long long int p, vector<Threads> &threads){
            threads[0].startTime = p;
            siftDown(0, threads);
        }
    public:
        void startProcessing(vector<long long int> &jobs, vector<Threads> &threads){
            vector<pair<int, long long int>> results;
            results.resize(jobs.size());
            for(int i = 0; i < jobs.size(); i++){
                results[i] = make_pair(threads[0].threadId, threads[0].startTime);
                if(jobs[i] != 0)
                    changePriority((int)0, threads[0].startTime + jobs[i], threads);
            }
            for(int i = 0; i < results.size(); i++)
                cout << results[i].first << " " << results[i].second << std::endl;
        }
};

int main(){
    ParallelProcessing pp;
    int n, m;
    cin >> n >> m;
    vector<long long int> jobs;
    jobs.resize(m);
    vector<Threads> threads;
    threads.resize(n);

    for(int i = 0; i < m; i++)
        cin >> jobs[i];
    
    for(int i = 0; i < n; i++)
        threads[i].threadId = i;

    pp.startProcessing(jobs, threads);
    return 0;
}
