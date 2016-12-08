package Strings;

import java.util.Arrays;

public class Ch1_Q3 {
	
	public static boolean isAnagram(String s1, String s2){
		if(s1.length()!=s2.length())
			return false;
		return sort(s1).equals(sort(s2));					
		
	}
	
	public static String sort(String str){		
		char charset[] = str.toCharArray();	
		Arrays.sort(charset);
		return new String(charset);
	}
	
	public static void main(String[] args) {
		System.out.println(isAnagram("partial", "taarlip"));
	}

}
