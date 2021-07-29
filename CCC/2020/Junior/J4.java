import java.util.*;

/*	Completion date: 2021/02/22		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 2.903s, 50.50mb	*/

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        String key = scan.nextLine();
        String o = "no";
        for (int i = 0; i < key.length(); i++) {
            for(int x = 0; x < str.length()-key.length()+1; x++) {
                if(str.substring(x,x+key.length()).equals(key)) {
                    o = "yes";
                    break;
                }
            }
            key = key.charAt(key.length()-1)+key.substring(0, key.length()-1);
        }
        System.out.println(o);
    }
}