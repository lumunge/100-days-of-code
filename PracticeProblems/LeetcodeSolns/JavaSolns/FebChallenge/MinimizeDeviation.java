// Leetcode #1675 - Minimize deviation array

import java.util.TreeSet;

class MinimizeDeviation{
    static int minDev(int[] nums){
        TreeSet<Integer> ts = new TreeSet();
        
        for(int i : nums){
            // make odd even and add to tree set
            if(i % 2 != 0) i *= 2;
            ts.add(i);
        }
        
        int diff = Integer.MAX_VALUE;
        
        while(true){
            // set is sorted
            int min = ts.first();
            int max = ts.last();
            
            diff = Math.min(diff, max - min);
            // if even remove and add max/2 to tree set otherwise break
            if(max % 2 == 0){
                ts.remove(max);
                ts.add(max / 2);
            }else break;
        }
        return diff;
    }

    public static void main(String[] args){
        int[] nums = {4, 1, 5, 20, 3};
        System.out.println(minDev(nums));
    }
}

