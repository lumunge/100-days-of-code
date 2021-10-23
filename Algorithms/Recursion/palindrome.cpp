#include<iostream>
using namespace std;

string getFirst(string str){
    return str.substr(0, 1);
}

string getLast(string str){
    return str.substr(str.size() - 1);
}

string getMiddle(string str){
    return str.substr(1, str.size() - 2);
}

bool checkPalindrome(string str){
    if(str.size() == 0 || str.size() == 1)
        return true;
    if(getFirst(str) == getLast(str))
        return true;
    else
        return false;
    return checkPalindrome(getMiddle(str));
}

int main(){
    string str;
    cin >> str;
    cout << checkPalindrome(str) << endl;
    return 0;
}
