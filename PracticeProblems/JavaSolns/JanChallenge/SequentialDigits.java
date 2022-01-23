//Leetcode 1291

import java.util.List;
import java.util.ArrayList;

class SequentialDigits{
	static digits(int low, int high){
		String digits = "123456789";
	        List<Integer> res = new ArrayList();
       		int l = String.valueOf(low).length();
		int r = String.valueOf(high).length();
		
		for(int i = l; i <= r; i++){
		    for(int j = 0; j < 10-i; j++){
			int n = Integer.parseInt(digits.substring(j, j+i));
			if(n >= low && n <= high)
			    res.add(n);
		    }
		}
		return res;
	}
}
