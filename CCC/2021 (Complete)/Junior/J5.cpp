#include <iostream>
#include <vector>

/*	Completion date: 2021/02/22		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 0.368s, 4.21mb		*/

using namespace std;

#define loop(n) for(int i = 0; i < n; i++)
#define dLoop(n,m) for(int i = 0; i < n; i++) { for(int j = 0; j < m; j++)

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