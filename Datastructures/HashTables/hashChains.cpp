#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * PROBLEM STATEMENT:
 * Implement hash table using a list chaining scheme using given buckets and the polynimial
 * hash function.
 * The program should support
 * add string -> insert string into table, if string exists ignore query
 * del string -> remove string from table, if no string exists, ignore query
 * find string -> if exists output "yes" else "no"
 * check i -> output content of i-th list(chain) in table
 *
 * -> Strings are inserted at the begining of the chain
 */

struct Query{
    string type, s;
    size_t ind;
};

class QueryProcessor{
    private:
        //size of each list(bucket)
        int buckets;
        //list of lists
        vector<vector<string>> hashMap = vector<vector<string>>(buckets);

        //hash function to hash the string
        size_t hashFunc(const string& s){
            static const size_t multiplier = 263;
            static const size_t prime = 1000000007;
            unsigned long long hash = 0;
            for(int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
                hash = (hash * multiplier + s[i]) % prime;
            return hash % buckets;
        }
    public:
        explicit QueryProcessor(int buckets) {}

        Query readQuery() const{
            Query query;
            cin >> query.type;
            if(query.type != "check")
                cin >> query.s;
            else
                cin >> query.ind;
            return query;
        }

        void processQuery(const Query& query){
            if(query.type == "check"){
                if(hashMap[query.ind].size() != 0){
                    for(int i = static_cast<int>(hashMap[query.ind].size()) - 1; i >= 0; --i)
                        cout << hashMap[query.ind][i] << " ";
                }
                cout << "\n";
            }else{
                //get hash value of string
                size_t ind = hashFunc(query.s);
                vector<string>::iterator it = std::find(hashMap[ind].begin(), hashMap[ind].end(), query.s);
                if(query.type == "find"){
                    if(it != hashMap[ind].end())
                        cout << "yes" << endl;
                    else
                        cout << "no" << endl;
                }else if(query.type == "add"){
                    if(it == hashMap[ind].end())
                        hashMap[ind].push_back(query.s);
                }else if(query.type == "del"){
                    if(it != hashMap[ind].end())
                        hashMap[ind].erase(it);
                }
            }
        }

        void processQueries(){
            int n;
            cin >> n;
            for(int i = 0; i < n; ++i)
                processQuery(readQuery());
        }
};

int main(){
    std::ios_base::sync_with_stdio(false); // for fast i/o
    int buckets;
    cin >> buckets;
    QueryProcessor proc(buckets);
    proc.processQueries();
    return 0;
};
