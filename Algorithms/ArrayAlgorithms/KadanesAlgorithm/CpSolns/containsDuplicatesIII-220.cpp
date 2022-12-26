// Contains duplicates III - 220


class Solution{
    public:
        bool containsDuplicate(vector<int>& nums, int k, int t){
            int n = nums.size();
            set<long> set;

            for(int i = 0; i < n; i++){
                long x = nums[i];

                if(i > k) set.erase(nums[i-k-1]);

                auto idx = set.lower_bound(x - t);
                if(idx != set.end() && (*idx - x) <= t) return true;
                set.insert(x);
            }
            return false;
        }
}
