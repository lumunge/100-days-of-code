/* 
 * PROBLEM STATEMENT:
 * A car with empty seats drives east to west.
 * Given ain integer capacity and an array trips where trip[i] = [numPassengers, from, to] indicates the the ith
 * trip has numPassengers and pick up is 'from' and drop off is 'to'.
 * Return true if it is possible to pick up and drop off all passengers for all ggiven tripe, return false otherwise.
 *
 * Sample;
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 4
 * Output: false
 * 
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 5
 * Output: true
 *
 * Approach(priority queue and loops) O(logn) PQ for N array = O(NlogN)
 * Create a priority queue based in the sorted order of stops by;
 * Traverse the trip array do the following;
 *      add source stop with the no. of passengers picked up to PQ
 *      add target stop with the dropped passengers(-ve) to PQ
 * 
 * Traverse the PQ and do the following;
 *      keep a count of capacity adding and subtracting
 *      If stop numbers are same for previous and next stop, get the local sum
 *      if total capacity > capacity return false
 * If the loop finishes return true.
 */

import java.util.PriorityQueue;

class CarPooling{
    static boolean pool(int[][] trips, int capacity){
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b)->a[0]-b[0]);

        //creating priority queue
        for(int i = 0; i < trips.length; i++){
            pq.add(new int[]{trips[i][1], trips[i][0]});
            pq.add(new int[]{trips[i][2], -1 * trips[i][0]});
        }

        int totalCap = 0;
        while(!pq.isEmpty()){
            int stop = pq.peek()[0];
            totalCap += pq.poll()[1];
            //local sum
            while(!pq.isEmpty() && stop == pq.peek()[0])
                totalCap += pq.poll()[1];
            if(totalCap > capacity)
                return false;
        }
        return true;

    }
    public static void main(String args[]){
        int trips[][] = {{2, 1, 5}, {3, 3, 7}};
        int capacity = 4;
        System.out.println(pool(trips, capacity));
        System.out.println(pool(trips, 5));
    }
}
