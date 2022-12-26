#include<iostream>
#include<unordered_map>
#include<list>

using std::unordered_map;
using std::string;
using std::list;
using std::pair;
using std::cout;
using std::endl;

class AllOne{
    public:
        //create the structure of a row
        struct row{
            list<string> strings;
            int val;
            row(const string &s, int x) : strings({s}), val(x){}
        };
        
        //initialize hashmap and doubly linked list
        unordered_map<string, pair<list<row>::iterator, list<string>::iterator>> strMap;
        list<row> strList;
        
        //increment procedure
        void inc(string key){
            //the key does not exist in the map
            if(strMap.find(key) == strMap.end()){
                if(strList.empty() || strList.back().val != 1){
                    auto newRow = strList.emplace(strList.end(), key, 1);
                    strMap[key] = make_pair(newRow, newRow->strings.begin());
                }else{
                    auto newRow = --strList.end();
                    newRow->strings.push_front(key);
                    strMap[key] = make_pair(newRow, newRow->strings.begin());
                }
            }else{
                //key exist in the map
                auto row = strMap[key].first;
                auto col = strMap[key].second;
                auto lastRow = row;
                --lastRow;
                if(lastRow == strList.end() || lastRow->val != row->val + 1){
                    auto newRow = strList.emplace(row, key, row->val + 1);
                    strMap[key] = make_pair(newRow, newRow->strings.begin());
                }else{
                    auto newRow = lastRow;
                    newRow->strings.push_front(key);
                    strMap[key] = make_pair(newRow, newRow->strings.begin());
                }
                row->strings.erase(col);
                if(row->strings.empty())
                    strList.erase(row);
            }
        }

        void dec(string key){
            //key does not exist in the map
            if(strMap.find(key) == strMap.end())
                return;
            else{
                //key exists in the map
                auto row = strMap[key].first;
                auto col = strMap[key].second;
                if(row->val == 1){
                    row->strings.erase(col);
                    if(row->strings.empty())
                        strList.erase(row);
                    strMap.erase(key);
                    return;
                }
                auto nextRow = row;
                ++nextRow;
                if(nextRow == strList.end() || nextRow->val != row->val - 1){
                    auto newRow = strList.emplace(nextRow, key, row->val - 1);
                    strMap[key] = make_pair(newRow, newRow->strings.begin());
                }else{
                    auto newRow = nextRow;
                    newRow->strings.push_front(key);
                    strMap[key] = make_pair(newRow, newRow->strings.begin());
                }
                row->strings.erase(col);
                if(row->strings.empty())
                    strList.erase(row);
            }
        }
        //get first key in first row in the map
        string getMax(){
            if(strList.empty())
                return "";
            return strList.front().strings.front();
        }
        
        //get the first key in the last row in the map
        string getMin(){
            if(strList.empty())
                return "";
            return strList.back().strings.front();
        }
};

int main(){
    AllOne obj;
    obj.inc("hello");
    obj.inc("hello");
    obj.inc("hello");
    obj.inc("this");
    obj.inc("that");
    obj.inc("this");
    obj.dec("hello");
    obj.dec("hello");
    string maxRes = obj.getMax();
    string minRes = obj.getMin();
    cout << maxRes << endl;
    cout << minRes << endl;
    return 0;
}
