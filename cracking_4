public class ArraysStrings {
    // 1.5 write a method to replace all spaces in a string with '%20'
    static String replaceSpaces(String s){
        /*    Test cases:
        1. no spaces: string
        2. 1 space: str str
        3, 2 spaces: s tr sing
        4. null & " " & ""*/

        if (s == null || s == "") {
            System.out.println("Input is not as expected!");
            return null;
        }

        int numberOfSpaces = 0;
        for (int i = 0; i < s.length(); i ++){
            if (s.charAt(i) == ' ')
                numberOfSpaces ++;
        }

        int newStringLen = s.length() + 2 * numberOfSpaces;
        char[] ou = new char[newStringLen];
        int newStringIndex = newStringLen - 1;

        for (int i = s.length() - 1; i > -1; i --){
            if (s.charAt(i) == ' ') {
                ou[newStringIndex --] = '0';
                ou[newStringIndex --] = '2';
                ou[newStringIndex --] = '%';
            }
            else
                ou[newStringIndex --] = s.charAt(i);
        }

        return new String(ou);
    }

    //1.6 Rotate N*N by 90 degrees

  /*  int[][] arr = new int[4][4];
    int count = 0;
    for(int i = 0; i < 4; i ++){
        for (int j = 0; j < 4; j ++) {
            count ++;
            arr[i][j] = count;
        }
    }
    printArray(arr);
    rotate90(arr);
    printArray(arr);*/
    public static void rotate90(int[][] arr){
        int row = arr.length;
        int column = arr[0].length;

        if(row != column) return;
        int N = row;

        for (int i = 0; i <= row / 2; i ++){
            //for each circle, move N - (2i+1)
            for (int j = 0; j < N-2*i-1;j ++){
                int temp = arr[i][i + j];
                arr[i][i+j] = arr[N-i-1-j][i];
                arr[N-i-1-j][i] = arr[N-i-1][N-i-1-j];
                arr[N-i-1][N-i-1-j] = arr[i+j][N-i-1];
                arr[i+j][N-i-1] = temp;
            }
        }
    }

    public static void printArray(int[][] arr){
        int row = arr.length;
        int column = arr[0].length;

        for (int i = 0; i <row; i ++){
            for (int j = 0; j < column; j ++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }

    //1.7 if an element of an M*N matrix is 0, its entire row and column is set to 0
    public static void updateMatrix(int[][] arr){
        int M = arr.length;
        int N = arr[0].length;

        int[] row = new int[M];
        int[] column = new int[N];

        //Collect information
        for (int i = 0 ; i < M; i ++){
            for (int j = 0; j < N; j ++){
                if (arr[i][j] == 0){
                    row[i] = 1;
                    column[j] = 1;
                }
            }
        }

        //Update Matrix
        for (int i = 0; i < M; i ++){
            for (int j = 0; i < N; j ++){
                if (row[i] == 0 || column[j] == 0)
                    arr[i][j] = 0;
            }
        }
    }

    //1.8 use isSubstring() once to check whether s1 is a rotation of s2
    public static boolean checkRotation(String s1, String s2){
        if (s1.length() != s2.length()) return false;
        String newString = s1 + s1;
        if (newString.contains(s2))
            return true;

        return false;
    }

//    public static void main(String[] args) {
//        System.out.println(checkRotation("world", "ldwor"));
//    }

}
