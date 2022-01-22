class StoneGameIV{
	static boolean helper(int n){
		if(n <= 0) return false;
		for(int i = 1; i*i <= n; i++)
		    if(!helper(n-(i*i))) return true;
		return false;
	}
    	static boolean winnerSquareGame(int n) {
        	return helper(n);
	}

	public static void main(String[] args){
		System.out.println(winnerSquareGame(1));
		System.out.println(winnerSquareGame(2));
		System.out.println(winnerSquareGame(4));
	}
}
