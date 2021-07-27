#include <iostream>
#include <vector>
#include <algorithm>

/*	Completion date: 2021/07/27	*
 *	CCC Grader Score: 15/15		*/

using namespace std;

#define fori(l,n) for(int i = l; i < n; i++)
#define pb push_back 

vector<int> measurements;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, in;
	cin >> N;
	fori(0, N) {
		cin >> in;
		measurements.pb(in);
	}
	sort(measurements.begin(), measurements.end());
	int first = (N - 1) / 2;
	int gap = 0;
	cout << measurements[first] << ' ';
	first--;
	for (int i = first; i >= 0; i--) {
		gap += 2;
		cout << measurements[i + gap] << ' ';
		cout << measurements[i] << ' ';
	}
	if (N % 2 == 0) {
		cout << measurements[N - 1] << ' ';
	}
}