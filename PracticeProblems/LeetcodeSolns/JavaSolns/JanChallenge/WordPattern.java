import java.util.HashMap;

class WordPattern{
	static boolean match(String pattern, String s){
		//convert sentence to an array of strings
		String[] words = s.split(" ");
		HashMap<Character, String> map = new HashMap<Character, String>();
		if(words.length != pattern.length()) return false;
		for(int i = 0; i < words.length; i++){
			char c = pattern.charAt(i);
			if(map.containsKey(c)){
				if(!map.get(c).equals(words[i]))
					return false;
			}else{
				if(map.containsValue(words[i]))
					return false;
				map.put(c, words[i]);
			}
		}
		return true;
	}
	public static void main(String[] args){
		System.out.println(match("abba", "dog cat cat dog"));
		System.out.println(match("abba", "dog cat cat fish"));
		System.out.println(match("aaaa", "dog cat cat dog"));
	}
}
