#include<iostream>
#include<sstream>
using namespace std;

int convert(string addr){
    for(int i = 0; i < addr.length(); i++){
        if(addr[i] == '.')
            continue;
        int num = addr[i];
        cout << num;
    }
    /*
    stringstream degree(addr);
    int x = 0;
    degree >> x;
    cout << x << endl;
    */
    return 0;
}

int main(){
    string ip = "172.16.254.1";
    convert(ip);
}
