import java.util.*;

/*	Completion date: 2021/01/28	*
 *	CCC Grader Score: 15/15		*/

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();
        int o = 0;
        o+=x/720*31;
        x = x%720+720;
        for(int i = 720; i <= x; i++) {
            String t = Integer.toString((i%720)/60);
            if (t.equals("0"))
                t = "12";
            if (i%60 < 10)
                t += "0"+i%60;
            else
                t += i%60;
            int s = t.charAt(1)-t.charAt(0);
            int u = 1;
            for(int j = 1; j < t.length()-1; j++) {
                if (s != t.charAt(j+1)-t.charAt(j)) {
                    u = 0;
                }
            }
            o+=u;
        }
        System.out.println(o);
    }
}