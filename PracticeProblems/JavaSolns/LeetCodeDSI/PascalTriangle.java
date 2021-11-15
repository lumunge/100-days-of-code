//Leet code 118

import java.util.ArrayList;
import java.util.List;

class PascalTraingle{
    public static List<List<Integer>> generate(int numRows){
        List<List<Integer>> result = new ArrayList<>();

        for(int i = 0; i < numRows; i++){
            List<Integer> temp = new ArrayList<>();
            result.add(temp);
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i)
                    temp.add(1);
                else
                    temp.add(result.get(i-1).get(j) + result.get(i-1).get(j-1));
            }
        }
        return result;
    }
    public static void main(String[] args){
        List<List<Integer>> pascals = generate(5);
        System.out.print(pascals);
    }
}
