#include <iostream>

/*	Completion date: 2021/02/22		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 0.032s, 3.25mb		*/

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ins;
	string direction = "left";
	cin >> ins;
	while (ins != 99999) {
		int x = ins / 1000;
		if (x == 0);
		else if ((x % 10 + x / 10) % 2 == 0)
			direction = "right";
		else
			direction = "left";
		cout << direction << ' ' << ins % 1000 << endl;
		cin >> ins;
	}
	return 0;
}