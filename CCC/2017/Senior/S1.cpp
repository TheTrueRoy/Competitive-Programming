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

/*	Completion date: 2021/07/26	*
 *	CCC Grader Score: 15/15		*/

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, in;
	cin >> N;
	int t1[100010], t2[100010], c = 0;
	fori(0, N) {
		cin >> in;
		c += in;
		t1[i] = c;
	}
	c = 0;
	fori(0, N) {
		cin >> in;
		c += in;
		t2[i] = c;
	}
	for (int i = N - 1; i >= 0; i--) {
		if (t1[i] == t2[i]) {
			cout << i + 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}