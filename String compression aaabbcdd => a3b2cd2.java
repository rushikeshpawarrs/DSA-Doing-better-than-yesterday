    //String compression aaabbcdd => a3b2cd2
public static String cmp(String str){
        StringBuilder res = new StringBuilder("");
        int i = 0;
        while( i < str.length()){
            Integer count = 1;
            char ch = str.charAt(i);
            while( i < str.length() - 1 && ch == str.charAt(i+1)  ) {
                count++;
                i++;
            }
            res.append(ch);
            if(count > 1)
                res.append(count.toString());
            i++;
        }
        return res.toString();
    }
