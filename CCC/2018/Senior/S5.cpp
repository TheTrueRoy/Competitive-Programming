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
#include <array>
#include <tuple>

/*	Completion date: 2021/07/23	*
 *	CCC Grader Score: 15/15		*/

using namespace std;

#define fori(l,n) for(int i = l; i < n; i++)
#define forj(l,n) for(int j = l; j < n; j++)
#define ii pair<int,int>
#define iii pair<int, pair<int,int>>
#define sf second.first
#define ss second.second 
#define ll long long
#define pb push_back 

typedef tuple<int, int, int, bool> ins; //cost, start, end, isPortal

vector<ins> instructions;

struct dsu {
	int gaps;
	vector<int> parents, sz;

	dsu(int in) {
		gaps = in;
		parents = vector<int>(in);
		fori(0, in) {
			parents[i] = i;
		}
		sz = vector<int>(in, 0);
	}

	int find(int child) {
		if (parents[child] != child)
			parents[child] = find(parents[child]);
		return parents[child];
	}

	bool merge(int a, int b) {
		int pa = find(a), pb = find(b);
		if (pa == pb) return false;
		if (sz[pa] > sz[pb]) {
			parents[pb] = pa;
		}
		else if (sz[pa] < sz[pb]) {
			parents[pa] = pb;
		}
		else {
			parents[pb] = pa;
			sz[pb]++;
		}
		gaps--;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, P, Q;
	cin >> N >> M >> P >> Q;
	ll cost, start, end;
	ll total = 0;
	fori(0, P) {
		cin >> start >> end >> cost;
		total += N * cost;
		instructions.pb(make_tuple(cost, start - 1, end - 1, false));
	}
	fori(0, Q) {
		cin >> start >> end >> cost;
		total += M * cost;
		instructions.pb(make_tuple(cost, start - 1, end - 1, true));
	}

	sort(instructions.begin(), instructions.end());

	dsu planets(N), cities(M);
	ll best = 0;
	bool isPortal;
	for (ins i : instructions) {
		tie(cost, start, end, isPortal) = i;
		if (isPortal && planets.merge(start, end))
			best += cost * cities.gaps;
		else if (!isPortal && cities.merge(start, end))
			best += cost * planets.gaps;
	}
	cout << total - best << endl;
};