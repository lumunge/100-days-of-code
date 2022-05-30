class Solution{
    public:
        vector<vector<int>> 3Sum(vector<int> &nums){
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;
            if(n < 3) return res;

            set<vector<int>> set;

            for(int i = 0; i < n - 2; i++){
                int v = nums[i];
                int l = i + 1;
                int r = n - 1;

                while(l < r){
                    if(v + nums[l] + nums[r] == 0){
                        set.insert({v, nums[l], nums[r]});
                        l++; r--;
                    }else if(v + nums[l] + nums[r] < 0) l++;
                    else r--;
                }
            }
            for(auto it : set) res.push_back(it);
            return res;
        }
};
