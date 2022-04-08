// Leetcode #264 - Ugly number II

class UglyNumII{
    public int nthUglyNumber(int n) {
        int[] ugly = new int[n];
        ugly[0] = 1;
        int counter = 1;
        int idx2 = 0, idx3 = 0, idx5 = 0;
        while(counter < n){
            int temp2 = ugly[idx2] * 2, temp3 = ugly[idx3] * 3, temp5 = ugly[idx5] * 5;
            int next = Math.min(Math.min(temp2, temp3), temp5);
            if(next == temp2) idx2++;
            if(next == temp3) idx3++;
            if(next == temp5) idx5++;
            ugly[counter++] = next;
        }
        return ugly[n-1];
    }
}
