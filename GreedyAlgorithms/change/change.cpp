#include<iostream>
#include<vector>
using namespace std;

int getChange(int n){
   vector<int> coins;
   while(n > 0){
       if(n >= 1 && n < 5){
           n -= 1;
           coins.push_back(1);
       }
       if(n >= 5 && n < 10){
           n -= 5;
           coins.push_back(5);
       }
       if(n >= 10){
           n -= 10;
           coins.push_back(10);
       }
   }
   for(int i = 0; i < coins.size(); i++){
       cout << coins[i] << " ";
   }
   return 0;
}

int main(){
    int n;
    cin >> n;
    cout << getChange(n) << endl;
    return 0;
}
