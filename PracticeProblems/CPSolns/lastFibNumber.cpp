//Print the last digit of a fibaonacci number

#include <iostream>
#include <vector>
using namespace std;

long long int lastFib(int n){
    vector<long long int> nums;
    nums.push_back(0);
    nums.push_back(1);
    if(n == 0)
        return nums[0];
    if(n == 1)
        return nums[1];
    for(int i = 2; i <= n+1; i++)
        nums.push_back(nums[i-1] + nums[i-2]);
    return nums[n] % 10;
}

int main(){
    int n;
    cin >> n;
    int res = lastFib(n);
    cout << res << endl;
    return 0;
}

