/* 
 * PROBLEM STATEMENT:
 * In a town there are n people.
 * If a town judge exists
 * 1. The twon judge trusts nobody
 * 2. Everybody except the town judge trusts the town judge
 * 3. There is exactly one person satisfying 1 and 2
 *
 * Given trust[] array trust[i] = [ai, bi] represents person ai trusts person bi
 * Return town judge label if there exists otherwise return -1.
 *
 * Sample:
 * Input: n = 3, trust = [[1,3],[2,3]]
 * Output: 3 
 * Explanation: The twon judge is 3, everybody trust 3 and 3 trusts nobody
 *
 * Input: n = 3, trust = [[1,3],[2,3],[3,1]]
 * Output: -1
 * Explanation: 1, 2, and 3, all trust another number.
 *
 * Approach.
 * Create trusted array to store all people from 1 - n
 * Increment value of number in array if it is trusted.
 * Decrement value if it trusts
 * Return the number with n-1 trusts.
 */

class TownJudge{
    int[] arr = new int[n+1];
        for(int[] t : trust){
            arr[t[0]]--;
            arr[t[1]]++;
        }
        for(int i = 1; i <= arr.length; i++){
            if(arr[i] == n-1)
                return i;
        }
        return -1;
    }
}
