#include<iostream>
#include<queue>
#include<vector>
using namespace std;


struct Request{
    Request(int arrivalTime, int processTime):
        arrivalTime(arrivalTime),
        processTime(processTime)
    {}
    int arrivalTime;
    int processTime;
};

struct Response{
    Response(bool dropped, int startTime):
        dropped(dropped),
        startTime(startTime)
    {}
    bool dropped;
    int startTime;
};

class Buffer{
public:
    Buffer(int size):
        size(size),
        finishTime()
    {}

    Response Process(const Request &request){
        while(!finishTime.empty() && finishTime.front() <= request.arrivalTime){
            finishTime.pop_front();
        }
        bool dropped = ((this->finishTime.size() == this->size) && (request.arrivalTime < this->finishTime.back()));
        int startTime = -1;
        if(!dropped){
            if(finishTime.empty())
                startTime = request.arrivalTime;
            else
                startTime = max(finishTime.back(), request.arrivalTime);
            finishTime.push_back(startTime + request.processTime);
        }
        return Response(dropped, startTime);
    }
private:
    int size;
    deque<int> finishTime;
};

vector<Request> ReadRequests(){
    vector<Request> requests;
    int count;
    cin >> count;
    for(int i = 0; i < count; ++i){
        int arrivalTime, processTime;
        cin >> arrivalTime >> processTime;
        requests.push_back(Request(arrivalTime, processTime));
    }
    return requests;
}

vector<Response> ProcessRequests(const vector<Request> &requests, Buffer *buffer){
    vector<Response> responses;
    for(int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

void printResponses(const vector<Response> &responses){
    for(int i = 0; i < responses.size(); ++i)
        cout << (responses[i].dropped ? -1 : responses[i].startTime) << endl;
}

int main(){
    int size;
    cin >> size;
    vector<Request> requests = ReadRequests();
    Buffer buffer(size);
    vector<Response> responses = ProcessRequests(requests, &buffer);
    printResponses(responses);
    return 0;
}




