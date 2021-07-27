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

using namespace std;

/*	Completion date: 2021/07/22	*
 *	CCC Grader Score: 15/15		*/

#define loop(n) for(int i = 0; i < n; i++)
#define dLoop(n,m) for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++)
#define ii pair<int,int>
#define iii pair<int, pair<int,int>>
#define ll long long
#define pb push_back 
#define mp make_pair
#define sf second.first
#define ss second.second 

int N, M, K;
vector<bool> m(5000000);
vector<bool> n(5000000);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M >> N >> K;
	char d; int p;
	loop(K) {
		cin >> d >> p; p--;
		if (d == 'R')
			m[p] = !m[p];
		else
			n[p] = !n[p];
	}
	int out = 0;
	dLoop(M, N) {
			out += m[i] ^ n[j];
		}
	}
	cout << out;
}