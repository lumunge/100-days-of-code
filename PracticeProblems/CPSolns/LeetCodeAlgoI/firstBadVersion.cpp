#include<iostream>
using namespace std;

/* PROBLEM STATEMENT:
 * Given an API bool isBadVersion(version) that check wheather a version is bad
 * Implement a function to find first bad version while minimizing calls to API
 *
 * Sample:
 * n = 5;
 * bad = 4;
 *
 * isBadVersion(3) --> false
 * isBadVersion(5) --> true
 * isBadVersion(4) --> true
 * 
 * return 4 --> first bad version
 *
 * Implemented using binary search --> runs in O(logn) - fewer calls to API.
 */

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned min = 1;
        unsigned max = n;
        while(min < max){
            int mid = (max + min) / 2;
            if(isBadVersion(mid)){
                max = mid;
            }else{
                min = mid+1;
            }
        }
        return min;
    }
};
