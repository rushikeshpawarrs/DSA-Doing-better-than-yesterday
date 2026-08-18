package dusrakaam;

import java.util.Arrays;

public class coreJava {
	public static int fact(int n) {
		int fact = 1;
		for(int i = 1; i <= n; i++) {
			fact = fact * i;
		}
		return fact;
	}
	
	public static int combination(int n, int r) {
		return fact(n) / (fact(r) * fact(n - r));
	}
	
	
	
	public static void hello() {
		

		    int ans = 0;

		    int X = 5;
		    int Y = 3;

		    for (int r = 1; r <= Y; r++) {

		        int combination = 1;

		        for (int i = 1; i <= r; i++) {
		            combination = combination * (X - i + 1) / i;
		        }

		        ans += combination;
		    }

		    System.out.println(ans);
		
		
		
//		//distinct combinations count
//		int ans = 0;
////		int X = 5, Y = 3;  // Output is 25
//		int X = 4, Y = 2; // Output is 10
//		for(int i = 2; i <= Y; i++) {
//			
//			for(int j = 1; j <= X; j++) {
//				
//				int k = j + 1;
//				while(k < X) {
//					ans++;
//					k++;
//				}
//			}
//		}
//		System.out.println(ans + X);
		
//		for(int i = 2; i <= Y; i++) {
//			ans += combination(X, i);
//		}
//		System.out.println(ans + X);
		
		
		
//		System.out.println("dusre kaam kr rha hu");
//		String str = "aabcd";
//		int mp[] = new int[26];
//		for(int i = 0; i < str.length(); i++) {
//			char ch = str.charAt(i);
//			mp[ch - 'a']++;  
//		}
//		
//		String rts = "abcda";
//		for(int i = 0; i < str.length(); i++) {
//			char ch = str.charAt(i);
//			mp[ch - 'a']--;  
//		}
//		
//		for(int it:mp) {
//			if(it != 0){
//				System.out.println("False");
//			}
//		}
//		System.out.println("True");
//		System.out.println(Arrays.toString(mp));
		
	}
}
