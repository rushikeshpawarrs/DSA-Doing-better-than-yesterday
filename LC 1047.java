//1047 remove adjacent duplicates from the string
class Solution {
    public String removeDuplicates(String s) {
        int n = s.length();
        Stack<Character> st = new Stack<>();
        int i = 0;
        while(i<n){
            if(!st.empty() && st.peek() == s.charAt(i)){
                st.pop();
            }
            else{
                st.push(s.charAt(i));
            }
            i++;
        }
        StringBuilder sb = new StringBuilder();
        while(!st.empty()){
            char ch = st.peek();
            st.pop();
            sb.append(ch);
        }
        return sb.reverse().toString();
    }
}
