#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <climits>

/*	Completion date: 2021/07/21	*
 *	CCC Grader Score: 15/15		*/

using namespace std;

#define loop(n) for(int i = 0; i < n; i++)
#define ii pair<int,int>
#define iii pair<int, pair<int,int>>
#define ll long long
#define pb push_back 
#define mp make_pair
#define sf second.first
#define ss second.second 

int N;

vector<pair<int,pair<ll, ll>>> WPD(201000);
ll l, r, c;

ll score(int pos) {
	ll s = 0;
	for (auto person : WPD) {
		ll dist = abs(person.sf - pos) - person.ss;
		if (dist > 0)
			s += dist * person.first;
	}
	return s;
}

int main() {
	cin >> N;
	int W, P, D;
	ll low = LLONG_MAX, high = 0, mid;
	loop(N) {
		cin >> P; cin >> W; cin >> D;
		WPD.pb(mp(W, mp(P, D)));
		if (P > high)
			high = P;
		if (P < low)
			low = P;
	}
	while (low <= high) {
		mid = (low + high) / 2;
		l = score(mid - 1);
		r = score(mid + 1);
		c = score(mid);
		if (l == c || r == c || (l > c && c < r))
			break;
		if (l > c)
			low = mid + 1;
		if (r > c)
			high = mid - 1;
	}
	cout << c;
}