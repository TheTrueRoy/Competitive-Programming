#include <iostream>

/*	Completion date: 2021/02/22		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 8.829s, 14.91mb	*/

using namespace std;

#define pb push_back
#define loop(n) for(int k = 0; k < n; k++)

using namespace std;

int burgers[1000005], last[500005];
double memo[1000005];

double solve() {
	int N;
	cin >> N;
	loop(N) {
		cin >> burgers[k];
		last[burgers[k]] = k;
	}
	int coach = burgers[0], josh = burgers[N - 1];
	if (coach == josh)
		return 1.0;
	double total = 1.0;
	memo[coach] = 1.0;
	for (int i = N - 1; i >= 1; i--) {
		if (last[burgers[i]] == i && burgers[i] != coach && burgers[i] != josh)
			memo[burgers[i]] += total / (N - i);
		total += memo[burgers[i]];
	}
	return total / N;
}

int main() {
	cout << solve();
}