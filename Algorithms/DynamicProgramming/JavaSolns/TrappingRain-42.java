// Leetcode #42 - Trapping rain water

class TrappingRain{
    public int trap(int[] height) {
        int rain = 0, n = height.length;
        // cannot hold water
        if(n <= 2) return 0;
        int maxLeft = height[0], maxRight = height[n-1];
        int left = 1, right = n-2;

        // traverse the map
        while(left <= right){
            //
            if(maxLeft < maxRight){
                if(height[left] < maxLeft)
                    // add rain
                    rain += maxLeft - height[left];
                else
                    maxLeft = height[left];
                left++;
            }else{ // maxRight < maxLeft
                if(height[right] < maxRight)
                    // add rain
                    rain += maxRight - height[right];
                else
                    maxRight = height[right];
                right--;
            }
        }
        return rain;
    }
}
