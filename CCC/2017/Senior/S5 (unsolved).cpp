#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <stack>
#include <climits>
#include <array>
#include <tuple>
#include <unordered_map>

using namespace std;

#define fori(l,n) for(int i = l; i < n; i++)
#define forj(l,n) for(int j = l; j < n; j++)
#define fork(l,n) for(int k = l; k < n; k++)
#define rofi(l,n) for(int i = l; i > n; i--)
#define rofj(l,n) for(int j = l; j > n; j--)
#define rofk(l,n) for(int k = l; k > n; k--)
#define ii pair<int,int>
#define iii pair<int, pair<int,int>>
#define sf second.first
#define ss second.second 
#define ll long long
#define pb push_back 
#define pf push_front 
#define mp make_pair

const int MAXN = 150010;

int getNext(int n) {
	return n + (n & -n);
}

int getParent(int n) {
	return n - (n & -n);
}

int N, M, Q;
vector<vector<int>> ft(MAXN);
vector<int> lastStationIndex[MAXN];
vector<ii> stationLineIndex;
vector<int> shift;

void update(int diff, int index, int ln) {
	while (index < ft[ln].size()) {
		ft[ln][index] += diff;
		index = getNext(index);
	}
}

int su;
int queryLine(int index, int ln) {
	su = 0;
	while (index > 0) {
		su += ft[ln][index];
		index = getParent(index);
	}
	return su;
}

int queryLineRange(int start, int end, int ln) {
	if (start == 0 || end == 0)
		return 0;
	start += ft[ln].size() - shift[ln] - 2; end += ft[ln].size() - shift[ln] - 2;
	start %= ft[ln].size() - 1; end %= ft[ln].size() - 1; start++; end++;
	if (start > end) {
		return queryLine(end, ln) + queryLine(lastStationIndex[ln].size(), ln) - queryLine(start - 1, ln);
	}
	return queryLine(end, ln) - queryLine(start - 1, ln);
}

int queryRange(int start, int end) {
	int sum = 0;
	fori(1, M + 1) {
		int op, ed;
		forj(0, lastStationIndex[i].size()) {
			if (lastStationIndex[i][j] >= start) {
				op = j + 1;
				break;
			}
		}
		for (int j = lastStationIndex[i].size() - 1; j >= 0; j--) {
			if (lastStationIndex[i][j] <= end) {
				ed = j + 1;
				break;
			}
		}
		sum += queryLineRange(op, ed, i);
	}
	return sum;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> Q;
	shift = vector<int>(M + 1, 0);
	int m, p;
	lastStationIndex[0] = vector<int>(M + 1, 0);
	fori(1, N + 1) {
		cin >> m;
		stationLineIndex.pb(mp(m, lastStationIndex[m].size()));
		lastStationIndex[m].pb(i);
	}
	fori(1, M + 1) {
		ft[i] = vector<int>(lastStationIndex[i].size() + 1, 0);
	}
	pair<int, int> c;
	fori(0, N) {
		cin >> p;
		c = stationLineIndex[i];
		update(p, c.second + 1, c.first);
	}
	int ins, l, r;
	fori(0, Q) {
		cin >> ins;
		if (ins == 1) {
			cin >> l >> r;
			cout << queryRange(l, r) << endl;
		}
		else {
			cin >> l;
			shift[l]++;
			shift[l] %= ft[l].size() - 1;
		}
	}
}