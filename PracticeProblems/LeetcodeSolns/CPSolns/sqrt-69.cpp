class Solution {
    public:
        int mySqrt(int x){
            int l = 0;
            int r = x;
            long long int mid = l + (r - l) / 2; // mid point
            long long int sq = mid * mid;
            int res = 0;
            // binary search
            while(l <= r){
                if(sq > x){
                    r = mid - 1;
                }else if(sq < x){
                    res = mid; // new position
                    l = mid + 1;
                }else{
                    res = mid;
                    break;
                }
                mid = l + (r - l) / 2; // new midpoint
            }
            return res;
        }
};
