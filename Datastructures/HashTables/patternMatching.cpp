#include<bits/stdc++.h>
#include<math.h>

using std::cout;
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
                }
                // hash values are equal, check equaliy of the two
                if(hashedPattern == hashFunc(window, p, t)){
                    if(pattern  ==  window)
                        cout << i << endl;
                }else
                    continue;
            }
        }
        */
    
        // RABIN KARPS ALGORITHM
        void search(char pattern[], char text[], int bigP){
            int m = strlen(pattern);
            int n = strlen(text);
            int i, j;
            int p = 0;
            int t = 0;
            int h = 1;

            for(i = 0; i < m-1; i++)
                h = (h * d) % bigP;
            
            //pattern and text hash value
            for(i = 0; i < m; i++){
                p = (d * p + pattern[i]) % bigP;
                t = (d * t + text[i]) % bigP;
            }

            //Find match in hash value
            for(i = 0; i <= n-m; i++){
                if(p == t){
                    //equal hash values, compare text by text
                    for(j = 0; j < m; j++){
                        if(text[i+j] != pattern[j])
                            break;
                    }
                    if(j == m)
                        cout << i+1 << endl;
                }
                //Shift to next window
                if(i < n - m){
                    t = (d * (t - text[i] * h) + text[i + m]) % bigP;
                    //avoid -ves
                    if(t < 0)
                        t = (t + bigP);
                }
            }
        }
};

int main() {
    PatternSearching hashSearch;
    char text[] = "ABCCDDAEFG";
    char pattern[] = "CDD";
    int q = 100000007;
    hashSearch.search(pattern, text, q);
    return 0;
}
