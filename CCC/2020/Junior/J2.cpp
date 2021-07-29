#include <iostream>

/*	Completion date: 2021/01/28		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 0.050s, 3.30mb		*/

using namespace std;
int N = 0, x, sx, y, sy, o;

int d[4]{ 0 };

int main() {
	cin >> x;
	cin >> sx;
	cin >> y;
	o = 0;
	sy = sx;
	while (sy <= x) {
		sx *= y;
		sy += sx;
		o++;
	}
	cout << o;
}