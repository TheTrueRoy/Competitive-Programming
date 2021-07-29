#include <iostream>

/*	Completion date: 2021/02/22		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 0.017s, 3.32mb		*/

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int b, p;
	cin >> b;
	p = 5 * b - 400;
	cout << p << endl;
	if (p > 100)
		cout << -1;
	else if (p < 100)
		cout << 1;
	else
		cout << 0;
	return 0;
}