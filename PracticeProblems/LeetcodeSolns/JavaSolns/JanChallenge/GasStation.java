//Leetcode 134

class GasStation{
	static int canCompleteCircuit(int[] gas, int[] cost){
		//accumulate gas, current gas, starting point
		int accGas = 0, currGas = 0, sp = 0;
		for(int i = 0; i < gas.length; i++){
		    int g = gas[i] - cost[i];
		    accGas += g; currGas += g;
		    //if negative reset and increment starting point
		    if(currGas < 0){
			currGas = 0;
			sp = i + 1;
		    }
		}
		//if accumulated is negative, return -1, else return starting point
		return (accGas >= 0) ? sp : -1;
	}

	public static void main(String args[]){
		int[] gas = {1, 2, 3, 4, 5};
		int[] cost = {3, 4, 5, 1, 2};
		System.out.println(canCompleteCircuit(gas, cost));
	}
}
