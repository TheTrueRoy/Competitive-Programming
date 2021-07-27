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
#include <unordered_map>

/*	Completion date: 2021/07/24	*
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

unordered_map <ll, ll> memo;

ll sv(int n) {
	if (n == 1 || n == 2)
		return 1;
	if (memo[n])
		return memo[n];
	ll ans = 0;
	for (int k = n, nw, j; k > 1; k = j) {
		nw = n / k, j = n / (nw + 1); // j shows the next value for nw where sv(nw) gives a new value
		ans += sv(nw) * (k - j);
	}
	memo[n] = ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	cout << sv(N);
}