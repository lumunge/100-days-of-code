class Solution {
    private:
        int nextVal(int n){
            int total = 0;
            while(n > 0){
                int x = n % 10;
                n = n / 10;
                total += x * x;
            }
            return total;
        }
    public:
        bool isHappy(int n){
            set<int> set;
            while(n != 1 && !set.count(n)){
                set.insert(n);
                n = nextVal(n);
            }
            return n == 1;
        }
};
