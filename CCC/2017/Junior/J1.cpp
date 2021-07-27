#include <iostream>

using namespace std;

/*	Completion date: 2021/01/24	*
 *	CCC Grader Score: 15/15		*/

int main() {
    int x, y;
    cin >> x >> y;
    if (x < 0) {
        if (y < 0)
            cout << "3";
        else
            cout << "2";
    } else {
        if (y < 0)
            cout << "4";
        else
            cout << "1";
    }
}