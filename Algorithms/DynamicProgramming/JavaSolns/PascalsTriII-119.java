// Leetcode #119 - Pascal's triangle II

import java.util.ArrayList;
import java.util.List;

class PascalsTriII{
    public static List<Integer> getRow(int rowIdx){
        List<List<Integer>> res = new ArrayList<>();

        for(int i = 0; i <= rowIdx + 1; i++){
            List<Integer> temp = new ArrayList<>();
            res.add(temp); // add row to result list
            for(int j = 0; j <= i; j++){
                if(j == 0 || i == j)
                    temp.add(1);
                else
                    temp.add(res.get(i-1).get(j) + res.get(i-1).get(j-1));
            }
        }
        return res.get(rowIdx);
    }

    public static void main(String[] args){
        System.out.println(getRow(3));
        System.out.println(getRow(4));
        System.out.println(getRow(5));
    }
}
