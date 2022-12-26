#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

long long fibSumSquares(int n){
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
    for(int i = 1; i < nums.size() - 1; i++)
        total += pow(nums[i], 2);
    return total % 10;
}


int main(){
    int n;
    cin >> n;
    cout << fibSumSquares(n) << endl;
    return 0;
}

