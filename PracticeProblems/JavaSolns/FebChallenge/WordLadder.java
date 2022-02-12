// Leetcode #127 - word ladder

import java.util.List;
import java.util.LinkedList;
import java.util.HashSet;
import java.util.Queue;
import java.util.Arrays;

class WordLadder{
    static int ladderLength(String beginWord, String endWord, List<String> wordList){
        HashSet<String> set = new HashSet<>();
       
        for(String w : wordList)set.add(w);

        if(!set.contains(endWord)) return 0;
        
        int level = 1;
        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);

        while(!queue.isEmpty()){
            int sz = queue.size();
            for(int i = 0; i < sz; i++){
                String curr = queue.poll();
                char[] cArr = curr.toCharArray();
                for(int j = 0; j < cArr.length; j++){
                    char orig = cArr[j];
                    for(char c = 'a'; c <= 'z'; c++){
                        if(cArr[j] == c) continue;
                        cArr[j] = c;
                        String newWord = String.valueOf(cArr);
                        if(newWord.equals(endWord)) return level += 1;
                        if(set.contains(newWord)) queue.offer(newWord);
                        set.remove(newWord);

                    }
                    cArr[j] = orig;
                }
            }
            level++;
        }
        return 0;
    }

    public static void main(String[] args){
        List<String> wordList = Arrays.asList("hot","dot","dog","lot","log","cog");
        List<String> wordList1 = Arrays.asList("hot","dot","dog","lot","log");
        System.out.println(ladderLength("hit", "cog", wordList));
        System.out.println(ladderLength("hit", "cog", wordList1));
    }
}
