#include<iostream>
#include<unordered_map>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Implement a phonebook manager that can process the queries:
 * -> add number name - user can add a name and number, if there exists a user, it overwrites
 * -> del number - erase a person with the number, if no user in book, ignore query
 * -> find number - book manager responds with appropriate name if there is user else "not found"
 * 
 * Sample:
 * Input:
 *        10
 *        add 700 john
 *        add 500 doe
 *        find 700
 *        del 910
 *        del 700
 *        add 200 kary
 *        find john
 *        find 200
 *        add 500 del
 *        find 500
 *
 *        Output:
 *                john
 *                not found
 *                kary
 *                del
 */      

int main(){
    unordered_map<int, string> phonebook;
    int n;
    cin >> n;
    string cmd, name;
    int number;
    for(int i = 0; i < n; i++){
        cin >> cmd;
        if(cmd == "add"){
            cin >> number >> name;
            phonebook[number] = name;
        }else if(cmd == "find"){
            cin >> number;
            if(phonebook.find(number) == phonebook.end())
                cout << "not found" << endl;
            else
                cout << phonebook.at(number) << endl;
        }else if(cmd == "del"){
            cin >> number;
            phonebook.erase(number);
        }else{
            cout << "not a command";
        }
    }
    return 0;
}
