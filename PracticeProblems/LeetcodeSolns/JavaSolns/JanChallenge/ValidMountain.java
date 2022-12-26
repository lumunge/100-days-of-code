//Leetcode 941

class ValidMountain{
	static boolean validMountainArray(int[] arr) {
		int n = arr.length;
		int i = 0;
		
		//up the mountain
		while(i+1 < n && arr[i] < arr[i+1])
		    i++;
		//peak should be between
		if(i == 0 || i == n-1) return false;
		//down the mountain
		while(i+1 < n && arr[i] > arr[i+1])
		    i++;

		return i==n-1;
    }
}
