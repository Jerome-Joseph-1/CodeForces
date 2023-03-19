import java.util.Scanner;

public class Main {

    public static String isPalindrome(String s) {
        for(int i = 0, n = s.length(); i < s.length()/ 2; ++i) {
            if(s.charAt(i) != s.charAt(n - i -1)) return "NO";
        }
        return "YES";
    }

    public static boolean longestMatch(String a, String b) {
        for(int i = 1; i < a.length(); i++) {
            if(a.charAt(i) != b.charAt(i-1)) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int n = sc.nextInt();
            String[] lenN = new String[2];
            int i = 0;

            for(int k = 0; k < 2*n - 2; k++) {
                String temp = sc.next();

                if(temp.length() == n-1 && i < 2) lenN[i++] = temp;
            }

            String s = "";
        
            if(longestMatch(lenN[0], lenN[1])) s = lenN[0] + lenN[1].charAt(n-2);
            else s = lenN[1] + lenN[0].charAt(n-2);
        
            // System.out.println(s);
            System.out.println(isPalindrome(s));
        }
    }
}
