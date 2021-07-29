﻿#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <queue>

/*	Completion date: 2021/07/22		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 7.432s, 24.83mb	*/

using namespace std;

#define loop(n) for(int i = 0; i < n; i++)
#define pb push_back 

vector<int> walkways[201000];
int walk[201001];
bool visited[201000];
int loc[201001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, W, D;
	cin >> N >> W >> D;

	for (int a = 0; a < N; a++)
		walk[a] = INT_MAX / 2;

	walk[N] = 0;

	int t, f;
	loop(W) {
		cin >> f >> t;
		walkways[t].pb(f);
	}

	queue<int> check;
	visited[N] = 1;
	check.push(N);
	while (!check.empty()) {
		int cur = check.front(); check.pop();
		for (auto next : walkways[cur]) {
			if (!visited[next]) {
				walk[next] = walk[cur] + 1;
				visited[next] = true;
				check.push(next);
			}
		}
	}

	multiset<int> distances;

	loop(N) {
		cin >> loc[i];
		distances.insert(i + walk[loc[i]]);
	}

	loop(D) {
		int a, b;
		cin >> a >> b; a--; b--;
		distances.erase(distances.find(a + walk[loc[a]]));
		distances.erase(distances.find(b + walk[loc[b]]));
		swap(loc[a], loc[b]);
		distances.insert(a + walk[loc[a]]);
		distances.insert(b + walk[loc[b]]);
		cout << *distances.begin() << endl;
	}
};