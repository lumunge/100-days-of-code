#include<iostream>
#include<map>
#include<vector>
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

struct Query{
    string cmd, name;
    int number;
};

vector<Query> readQueries(){
    int n;
    cin >> n;
    vector<Query> queries(n);
    for(int i = 0; i < n; i++){
        cin >> queries[i].cmd;
        if(queries[i].cmd == "add")
            cin >> queries[i].number >> queries[i].name;
        else
            cin >> queries[i].number;
    }
    return queries;
}

vector<string> processQueries(const vector<Query>& queries){
    map<int, string> phonebook;
    vector<string> results;
    for(size_t i = 0; i < queries.size(); ++i){
        if(queries[i].cmd == "add")
            phonebook[queries[i].number] = queries[i].name;
        else if(queries[i].cmd == "del")
            phonebook.erase(queries[i].number);
        else{
            string response = "not found";
            map<int, string>::iterator it = phonebook.find(queries[i].number);
            if(it != phonebook.end())
                response = it->second;
            results.push_back(response);
        }
    }
    return results;
}

void writeResponses(const vector<string>& result){
    for(size_t i = 0; i < result.size(); ++i)
        cout << result[i] << "\n";
}

int main(){
    writeResponses(processQueries(readQueries()));
    return 0;
}
