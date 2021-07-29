import java.util.*;

/*	Completion date: 2021/02/22		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 1.413s, 41.63mb	*/

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in).useDelimiter("\\D");
        int N = scan.nextInt();
        int mx = 0;
        int my = 0;
        int mnx = 100;
        int mny = 100;
        for (int i = 0; i < N; i++) {
            int x = scan.nextInt();
            scan.skip(",");
            int y = scan.nextInt();
            if (x < mnx)
                mnx = x;
            if (x > mx)
                mx = x;
            if (y < mny)
                mny = y;
            if (y > my)
                my = y;
        }
        System.out.println((mnx-1)+","+(mny-1)+"\n"+(mx+1)+","+(my+1));
    }
}