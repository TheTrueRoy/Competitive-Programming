#include <iostream>

/*	Completion date: 2021/02/22		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 0.022s, 3.24mb		*/

using namespace std;

#define loop(s,f) for(int i = s; i < f; i++)

int highBet = 0;
string highName = "";
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int bet;
	string name;
	loop(0, N) {
		cin >> name >> bet;
		if (bet > highBet) {
			highBet = bet;
			highName = name;
		}
	}
	cout << highName;
	return 0;
}