#include<bits/stdc++.h>
#include<math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

#define d 256

class PatternSearching{
    public:
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

        /* 
         * NAIVE HASHING
         */
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

        int hashSearch(string text, string pattern){
            int count = 0;
            int t = text.length();
            int p = pattern.length();
            
            int hashedPattern = hashFunc(pattern, p, t);

            for(int i = 0; i <= t-p; i++){
                int j;
                string window = "";
                for(j = 0; j < p; j++){
                    window += text[i+j];
                }
                // hash values are equal, check equality of the two strings
                if(hashedPattern == hashFunc(window, p, t)){
                    if(pattern  ==  window){
                        count++;
                        //cout << "@ " << i << endl;
                    }
                }else
                    continue;
            }
            return count;
        }
};
/*
int main() {
    PatternSearching search;
    string text, pattern;
    cin >>  pattern;
    cin >> text;
    cout << search.hashSearch(text, pattern) << " occurences" << endl;
    return 0;
}
*/
