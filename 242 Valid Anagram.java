class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length();
        int m = t.length();
        if(m != n)
            return false;

        HashMap<Character, Integer> mp = new HashMap<>();
        for(int i = 0; i < n; i++){
            char ch = s.charAt(i);
            mp.put(ch, mp.getOrDefault(ch, 0)+1);
        }

        for(int i = 0; i < m; i++){
            char ch = t.charAt(i);
            if(mp.getOrDefault(ch,0) == 0){
                return false;
            }
            mp.put(ch, mp.get(ch)-1);
        }
        return true;
    }
}
