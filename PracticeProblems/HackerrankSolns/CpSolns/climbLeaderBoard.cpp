// Hackerrank Climbing leader borad - https://www.hackerrank.com/challenges/climbing-the-leaderboard/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using std::greater;
using std::set;
using std::vector;
using std::cout;
using std::endl;

class Solution{
    private:
        vector<int> helper(vector<int> vec){
            // remove duplicates, sort, reverse
            set<int> st(vec.begin(), vec.end());
            vector<int> v1;
            v1.assign(st.begin(), st.end());
            sort(v1.begin(), v1.end(), greater<>());
            return v1;
        }
    public:
        vector<int> climbLdBd(vector<int> ranked, vector<int> player){
            vector<int> vec = helper(ranked), res;
            int n = vec.size();
            for(auto n1 : player){
                while(n > 0 && n1 >= vec[n - 1]){
                    vec.pop_back();
                    n--;
                }
                res.push_back(vec.size() + 1);
            }

            return res;
        }

        void printVec(vector<int> vec){
            int n = vec.size();
            for(auto i : vec)
                cout << i << " ";
            cout << endl;
        }
};

int main(){
    Solution soln;
    vector<int> ranked = {100, 90, 90, 80}, player = {70, 80, 105};
    vector<int> res = soln.climbLdBd(ranked, player);
    soln.printVec(res);
    return 0;
}
