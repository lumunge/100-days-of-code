#include <iostream>
#include<vector>

using namespace std;

long long fibLastSum(int m, int n){
    long long total = 0;
    vector <long long> nums;
    nums.push_back(0);
    nums.push_back(1);
    if(n == 0)
        return nums[0];
    if(n == 1)
        return nums[1];
    for(int i = 2; i <= n+1; i++)
        nums.push_back(nums[i-1] + nums[i-2]);
    for(auto i = m; i <= n; i++)
        total += nums[i];
    return total % 10;
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << fibLastSum(n, m) << endl;
    return 0;
}
