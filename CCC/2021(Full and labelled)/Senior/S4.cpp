﻿#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <climits>

/*	Completion date: 2021/07/22	*
 *	CCC Grader Score: 15/15		*/

using namespace std;

#define loop(n) for(int i = 0; i < n; i++)
#define dLoop(n,m) for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++)
#define ii pair<int,int>
#define iii pair<int, pair<int,int>>
#define sf second.first
#define ss second.second 
#define ll long long
#define pb push_back 
#define mp 

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