#include <iostream>

/*	Completion date: 2021/02/22		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 0.042s, 3.72mb		*/

using namespace std;

#define loop(s,f) for(int i = s; i < f; i++)

string N;
int l = 0, m = 0, s = 0;
int lm = 0, ls = 0, ms = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int total = 0;
	loop(0, N.length()) {
		if (N.at(i) == 'L')
			l++;
		else if (N.at(i) == 'M')
			m++;
		else if (N.at(i) == 'S')
			s++;
	}
	loop(0, l) {
		if (N.at(i) == 'M')
			lm++;
		if (N.at(i) == 'S')
			ls++;
	}
	loop(l, l + m) {
		if (N.at(i) == 'L' && lm > 0)
			lm--, total++;
		if (N.at(i) == 'S')
			ms++;
	}
	loop(l + m, l + m + s) {
		if (N.at(i) == 'L' && ls > 0)
			ls--, total++;
		if (N.at(i) == 'M' && ms > 0)
			ms--, total++;
	}
	total += (lm + ls) * 2;
	cout << total;
	return 0;
}