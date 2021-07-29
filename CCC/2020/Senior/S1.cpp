#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

/*	Completion date: 2021/07/29		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 0.244s, 4.26mb		*/

using namespace std;

#define fori(l, n) for(int i = l; i < n; i++)
#define ii pair<int,int>
#define pb push_back
#define mp make_pair 

int N;
vector<ii> ms;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int x, y;
	fori(0, N) {
		cin >> x >> y;
		ms.pb(mp(x, y));
	}
	sort(ms.begin(), ms.end());
	double vel;
	fori(0, N - 1)
		vel = max(vel, abs(1.0 * (ms[i].second - ms[i + 1].second) / (ms[i].first - ms[i + 1].first)));
	cout << vel;
}