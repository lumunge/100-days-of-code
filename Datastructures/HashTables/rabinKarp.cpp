#include<bits/stdc++.h>
#include<math.h>

using std::cout;
using std::endl;
using std::string;

#define d 256

class RabinKarp{
    public:
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
    RabinKarp hashSearch;
    char text[] = "ABCCDDAEFG";
    char pattern[] = "CDD";
    int q = 100000007;
    hashSearch.search(pattern, text, q);
    return 0;
}
