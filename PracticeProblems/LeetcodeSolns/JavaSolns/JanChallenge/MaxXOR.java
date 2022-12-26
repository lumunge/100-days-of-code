//Leetcode 421

class MaxXOR{
    //BRUTE FORCE(quadratic) 
    // public int findMaximumXOR(int[] nums) {
    //     int max = 0;
    //     for(int i = 0; i < nums.length; i++){
    //         for(int j = i+1; j < nums.length; j++){
    //             max = Math.max((nums[i] ^ nums[j]), max);
    //         }
    //     }
    //     return max;
    // }
    
    // OPTIMIZED(linear)
    class Trie{
        Trie[] children;
        public Trie(){
            children = new Trie[2];
        }
    }

    private Trie root;

    private void buildTrie(int[] nums){
        for(int n : nums){
            Trie currNode = root;
            for(int i = 31; i >= 0; i--){
                int currBit = (n >>> i) & 1;
                if(currNode.children[currBit] == null)
                    currNode.children[currBit] = new Trie();
                currNode = currNode.children[currBit];
            }
        }
    }

    private int findCurrentMaxXOR(int num){
        Trie currNode = root;
        int currSum = 0;
        for(int i = 31; i >= 0; i--){
            int currBit = (num >>> i) & 1;
            int targetBit = currBit == 0 ? 1 : 0;
            if(currNode.children[targetBit] != null){
                currSum += (1 << i);
                currNode = currNode.children[targetBit];
            }else
                currNode = currNode.children[currBit];
        }
        return currSum;
    }

    public int findMaximumXOR(int[] nums) {
        if(nums == null || nums.length == 0) return 0;
        // Build trie
        root = new Trie();
        buildTrie(nums);

        int max = Integer.MIN_VALUE;
        for(int n : nums){
            int maxXOR = findCurrentMaxXOR(n);
            max = Math.max(max, maxXOR);
        }
        return max;
    }
}
