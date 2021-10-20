#include<bits/stdc++.h>
#include<math.h>

using std::cout;
using std::endl;
using std::string;

#define d 256

/*
 * NAIVE ALGORITHM
 *
void search(char* text, char* pattern){
    int tLen = strlen(text);
    int pLen = strlen(pattern);

    for(int i = 0; i < tLen - pLen; i++){
        int j;
        for(j = 0; j < pLen; j++)
            if(text[i+j] != pattern[j])
                break;
        if(j == pLen)
            cout << "@ " << i << endl;
    }
}
*/

/* NAIVE HASHING
 *
int hashFunc(string str, int n, int m){
    int code = 0;
    //big prime for mod-ing to avoid spurious hits and reduce large numbers
    int bigP = 1000000007;
    //convert each char to ascii for hashing calculations
    int j = n-1;
    for(int i = 0; i < n; i++){
        code += (int)str[i] * pow(m, j);
        j--;
    }
    //mod-ing reduces time-complexity
    int hashValue = code % bigP;
    return hashValue;
}

void hashSearch(string text, string pattern){
    int t = text.length();
    int p = pattern.length();
    
    int hashedPattern = hashFunc(pattern, p, t);

    for(int i = 0; i <= t-p; i++){
        int j;
        string window = "";
        for(j = 0; j < p; j++){
            window += text[i+j];
            //cout << text[i+j];
        }
        //cout << window << "<-" << hashFunc(window, p, t);
        if(hashedPattern == hashFunc(window, p, t))
            cout << i << endl;
        else
            continue;
    }
}
*/


class PatternSearching{
    
    void search(char pattern[], char text[], int bigP){
        int m = strlen(pattern);
        int n = strlen(text);
        int i, j;
        int p = 0;
        int t = 0;
        int h = 1;

        for(i = 0; i < m-1; i++
    }
};


int main(){
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";
    hashSearch(text, pattern);
    return 0;
}


