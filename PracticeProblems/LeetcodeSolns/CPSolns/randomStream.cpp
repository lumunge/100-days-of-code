#include<iostream>

using std::cout;
using std::endl;

//selecting a random number from stream using reservoir sampling

int random(int x){
    //random number generated
    static int randN;
    //keeps count of visted number of the stream
    static int count = 0;
    count++;
    
    // if its is the first element in the stream
    if(count == 1){
        // we return it as the random number
        randN = x;
    }else{
        // generate random number from 0 - count -1
        int r = rand() % count;
        // replace previous random number with new number with 1/count probability
        if(r == count - 1)
            randN = x;
    }
    //return random number
    return randN;
}

int main(){
    int stream[] = {3, 11, 23, 1, 7, 4, 8, 12, 6, 5, 9};
    int n = sizeof(stream) / sizeof(stream[0]);
    
    //generate new seed
    srand(time(NULL));

    for(int i = 0; i < n; i++)
        cout << i + 1 << " " << random(stream[i]) << endl;
    return 0;
}
