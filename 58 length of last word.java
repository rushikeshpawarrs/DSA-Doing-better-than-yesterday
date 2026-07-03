class Solution {
    public int lengthOfLastWord(String s) {
        int i = s.length()-1;
        while(s.charAt(i) == ' '){
            i--;
        }

        int count = 0;
        while( i >= 0 && s.charAt(i) != ' '){
            count++;
            i--;
        }
        return count;


        // String arr[] = s.trim().split("\\s+");
        // int n = arr.length - 1;
        // return arr[n].length();
    }
}
