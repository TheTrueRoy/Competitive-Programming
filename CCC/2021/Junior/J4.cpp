#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <list>
#include <unordered_map>
#include <array>
#include <cstring>
#include <deque>

/*	Completion Date: 2021/2/22	*
 *	CCC Grader Score: 15/15		*/

using namespace std;

#define pb push_back
#define loop(s,f) for(int i = s; i < f; i++)
#define loopJ(s,f) for(int j = s; j < f; j++)
#define loopK(s,f) for(int k = s; k < f; k++)
#define loopL(s,f) for(int l = s; l < f; l++)
#define ii pair<int,int>
#define iii pair<int, pair<int,int>>
#define ll long long

using namespace std;

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