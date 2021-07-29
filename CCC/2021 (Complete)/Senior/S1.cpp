#include <iostream>
#include <iomanip>
#include <vector>

/*	Completion date: 2021/07/22		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 0.027s, 3.67mb		*/

using namespace std;

#define loop(n) for(int i = 0; i < n; i++)
#define pb push_back 

int N;
vector<double> wood;

int main() {
	cin >> N;
	int f, s, w;
	double sum = 0.0;
	cin >> f;
	loop(N) {
		cin >> s;
		wood.pb((s + f) / 2.0);
		f = s;
	}
	for (auto i : wood) {
		cin >> w;
		sum += w * i;
	}
	cout << fixed << setprecision(5) << sum;
}