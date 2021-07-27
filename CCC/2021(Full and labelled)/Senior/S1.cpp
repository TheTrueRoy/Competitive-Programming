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

/*	Completion date: 2021/07/22	*
 *	CCC Grader Score: 15/15		*/

using namespace std;

#define loop(n) for(int i = 0; i < n; i++)
#define ii pair<int,int>
#define iii pair<int, pair<int,int>>
#define ll long long
#define pb push_back 
#define mp make_pair
#define sf second.first
#define ss second.second 

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