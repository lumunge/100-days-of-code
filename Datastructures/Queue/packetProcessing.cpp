#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Given a series of incoming network packets, simulate their processing,
 * There is only one processor and it processes incoming packets inorder of their arrival
 * If processor starts to process a packets it doesnt stop until its finished.
 * The machine has a buffer size that stores packets when they arrive, however if a 
 * packets arrives and buffer is full, packets are dropped otherwise the buffer idles
 * waiting for packets.
 * Return for each packet the moment it was processed or -1 if it was dropped.
 *
 * Sample:
 * 1, 2 --> BufferSize, Packets
 * 0 1 --> 1 - processed at time 0
 * 0 1 --> -1 - dropped because buffer was full with first packet
 *
 * Sample 2:
 * 1, 2
 * 0 1 --> 0
 * 1 1 --> 1
 */

int main(){
    int bufferSize, packets, arrival, procTime, time;
    //Get inputs
    cin >> bufferSize >> packets;
    vector<pair<int, pair<int, int>>> v(packets);
    queue<pair<int, pair<int, int>>> q;
    vector<int> results(packets); 
    for(int i = 0; i < packets; i++){
        cin >> arrival >> procTime;
        v[i] = make_pair(i, make_pair(arrival, procTime));
    }
    //Process packets
    arrival = 0;
    while(arrival < bufferSize && arrival < packets){
        q.push(v[arrival]); //pushing packet to queue for processing
        arrival++;
    }
    time = 0;
    while(!q.empty()){
        int startTime = (time, q.front().second.first);
        time = startTime + q.front().second.second;
        results[q.front().first] = startTime; //time each packet was processed
        q.pop(); //Remove packet from queue after being processed
        while(q.size() < bufferSize && arrival < packets){ 
            if(v[arrival].second.first < time){
                results[arrival++] -= 1;
            }else{
                q.push(v[arrival++]);
            }
        }
    }
    for(int i = 0; i < packets; i++){
        cout << results[i] << endl;
    }
    return 0;
}
