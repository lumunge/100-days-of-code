//leetcode 875
class KokoEatingBananas{
	static int minSpeed(int[] piles, int h){
		int l = 1, r = 1;
		for(int p : piles)
		    r = Math.max(r, p);

		while(l < r){
		    int mid = (l + r) / 2;
		    int hrs = 0;
		    for(int p : piles)
			hrs += Math.ceil((double) p / mid);
		    if(hrs <= h) r = mid;
		    else l = mid + 1;
		}
		return r;
	}
}
