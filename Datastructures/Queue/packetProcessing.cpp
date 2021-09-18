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
    int bufferSize, packets;
    cin >> bufferSize >> packets;
    int t;
    int arrival, procTime;
    queue<pair<int, pair<int, int>>> q;
    vector<pair<int, pair<int, int>>> v(packets);
    vector<int> result(packets);
    for(int i = 0; i < packets; i++){
        cin >> arrival >> procTime;
        v[i] = make_pair(i, make_pair(arrival, procTime));
    }
    arrival = 0;
    while(arrival < packets && arrival < bufferSize){
        q.push(v[arrival]);
        arrival++;
    }
    t = 0;
    while(!q.empty()){
        int st = max(t, q.front().second.first);
        t = st + q.front().second.second;
        result[q.front().first] = st;
        q.pop();
        while(q.size() < bufferSize && arrival < packets){
            if(v[arrival].second.first < t){
                result[arrival++] -= 1;
            }else{
                q.push(v[arrival++]);
            }
        }
    }
    for(int i = 0; i < packets; i++){
        cout << result[i] << endl;
    }
    return 0;
}
