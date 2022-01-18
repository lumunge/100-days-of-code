class CanPlaceFlowers{
	static boolean canPlace(int[] flowerbed, int n){
		if(n == 0) return true;
        	int z = flowerbed.length;
		for(int i = 0; i < z; i++){
		    if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.length - 1 || flowerbed[i+1] == 0)){
			    n--;
			if(n == 0) return true;
			flowerbed[i] = 1;
		    }
		}
		return false;
	}
	public static void main(String[] args){
		int[] fb1 = {1, 0, 0, 0, 1};
		int[] fb2 = {1, 0, 0, 0, 0, 1};
		int[] fb3 = {1, 0, 0, 0, 0, 0, 1};
		System.out.println(canPlace(fb1, 1));
		System.out.println(canPlace(fb2, 2));
		System.out.println(canPlace(fb3, 2));
	}
}
