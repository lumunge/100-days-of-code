//Leetcode 211

//Trie implementation
class AddSearchWord{
    private WordDictionary[] children;
    boolean isLeaf;

    public WordDictionary(){
        children = new WordDictionary[26];
        isLeaf = false;
    }

    public void addWord(String word){
        WordDictionary curr = this;
        for(char c : word.toCharArray()){
            if(curr.children[c - 'a'] == null)
                curr.children[c - 'a'] = new WordDictionary();
            curr = curr.children[c - 'a'];
        }
        curr.isLeaf = true;
    }

    public boolean search(String word){
        WordDictionary curr = this;
        for(int i = 0; i < word.length(); i++){
            char c = word.charAt(i);
            if(c == '.'){
                for(WordDictionary ch : curr.children)
                    if(ch != null && ch.search(word.substring(i+1)))
                        return true;
                return false;
            }
            if(curr.children[c - 'a'] == null) return false;
            curr = curr.children[c - 'a'];
        }
        return curr != null && curr.isLeaf;
    }
}
