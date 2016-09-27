import java.util.List;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.IOException;

public class Sorter{

    public static void main(String[] args){    

        String str = getLine();
    
        String delimiters = new String(" ");
        StringTokenizer token = new StringTokenizer(str, delimiters, false);
        List<String> allWords = new ArrayList<String>();
        List<Integer> numbers = new ArrayList<Integer>();
        List<String> words = new ArrayList<String>();    

        int i=0;
        while (token.hasMoreTokens()) {    
            String s = token.nextToken();
            if(isNum(s)){
                numbers.add(Integer.parseInt(s));
            }else{
                words.add(s);
            }   
                allWords.add(s);
        }   

        Collections.sort(numbers);

        Collections.sort(words);
        int x=0 ,y=0;
        for(i=0; i < allWords.size(); i++){
            if(isNum(allWords.get(i))){
                allWords.set(i, numbers.get(x++).toString());
            }else{
                allWords.set(i, words.get(y++));
            }
        }

        for(i=0; i < allWords.size(); i++){
            if(i != allWords.size()){
                System.out.print(allWords.get(i)+" ");
            }else{
                System.out.print(allWords.get(i));
            }
        }
        System.out.println();
    }

    private static String getLine() {
        String mystr = "";
        BufferedReader bufferRead = new BufferedReader(new InputStreamReader(System.in));
        try{
            mystr = bufferRead.readLine();
        }catch(IOException err)
        {
            err.printStackTrace();
        }

        return mystr;
    }

    private static boolean isNum(String str){
        try{
            Integer.parseInt(str);
            return true;
        }catch(NumberFormatException ex){
            return false;
        }
    }
}
