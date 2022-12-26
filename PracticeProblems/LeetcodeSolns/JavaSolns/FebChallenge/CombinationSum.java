// Leetcode #39 - Combination sum

class CombinationSum{
    private void helper(int[] arr, int idx, int target, List<List<Integer>> res, List<Integer> store){
        // base case
        if(idx == arr.length){
            if(target == 0)
                res.add(new ArrayList<>(store));
            return;
        }
        if(arr[idx] <= target){
            store.add(arr[idx]);
            // recur with target minus array value
            helper(arr, idx, target - arr[idx], res, store);
            store.remove(store.size() - 1);
        }
        // increment array index
        helper(arr, idx+1, target, res, store);
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList();
        helper(candidates, 0, target, res, new ArrayList<>());
        return res;
    }
}
