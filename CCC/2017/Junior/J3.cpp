#include <iostream>

/*	Completion date: 2021/01/27	*
 *	CCC Grader Score: 15/15		*/

using namespace std;
int N = 0, x, sx, y, sy, o;

int main() {
	cin >> x >> y;
	cin >> sx >> sy;
	cin >> o;
	if (abs(sx - x) + abs(sy - y) > o || (abs(sx - x) + abs(sy - y)) % 2 != o % 2)
		cout << "N";
	else
		cout << "Y";
}