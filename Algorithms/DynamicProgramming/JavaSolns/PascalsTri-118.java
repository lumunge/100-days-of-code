// Leetcode #118 - Pascal's triangle

import java.util.List;
import java.util.ArrayList;

class PascalsTri{
    public static List<List<Integer>> generate(int n){
        List<List<Integer>> res = new ArrayList<>();

        for(int i = 0; i < n; i++){
            List<Integer> temp = new ArrayList<>();
            res.add(temp); // add row to result list
            for(int j = 0; j <= i; j++){
                if(j == 0 || i == j)
                    temp.add(1);
                else
                    temp.add(res.get(i-1).get(j) + res.get(i-1).get(j-1));
            }
        }
        
        return res;
    }

    public static void main(String[] args){
        System.out.println(generate(5));
        System.out.println(generate(1));
        System.out.println(generate(10));
    }
}
