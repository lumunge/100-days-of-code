#include<iostream>
using namespace std;

int main(){
    int x[3][3] = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr, sc = 1;
    int newColor = 2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "[" << i << "][" << j << "]";
            cout << x[i][j] << endl;
        }
    }
    return 0;
}
