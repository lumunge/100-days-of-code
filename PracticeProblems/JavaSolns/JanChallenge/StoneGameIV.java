//Leetcode 1510

import java.util.HashMap;

class StoneGameIV{
	static boolean helper(int n, HashMap<Integer, Boolean> memo){
		if(n <= 0) return false;
		if(memo.containsKey(n)) return memo.get(n);
		for(int i = 1; i*i <= n; i++)
		    if(!helper(n-(i*i), memo)){
			    memo.put(n, true);
			    return true;
		    }
		memo.put(n, false);
		return false;
	}
    	static boolean winnerSquareGame(int n){
		HashMap<Integer, Boolean> memo = new HashMap<>();
        	return helper(n, memo);
	}

	public static void main(String[] args){
		System.out.println(winnerSquareGame(1));
		System.out.println(winnerSquareGame(2));
		System.out.println(winnerSquareGame(4));
	}
}
