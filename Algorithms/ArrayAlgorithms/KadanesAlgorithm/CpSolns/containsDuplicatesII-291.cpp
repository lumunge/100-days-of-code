// Leetcode #219 - contains duplicate II


class Solution{
    public:
        bool dup(vector<int>& nums, int k){
            int n = nums.size();
            map<int, int> map;

            for(int i = 0; i < n; i++){
                auto c = map.find(nums[i]);
                    if(c != map.end()){
                        int j = c->second;
                        if(abs(i - j) <= k)
                            return true;
                        else
                            map[nums[i]] = i;
                    }
                    else
                        map[nums[i]] = i;
            }
            return false;
        }
}
