#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <list>
#include <unordered_map>
#include <array>
#include <cstring>
#include <deque>

/*	Completion Date: 2021/2/22	*
 *	CCC Grader Score: 15/15		*/

using namespace std;

#define pb push_back
#define loop(s,f) for(int i = s; i < f; i++)
#define loopJ(s,f) for(int j = s; j < f; j++)
#define loopK(s,f) for(int k = s; k < f; k++)
#define loopL(s,f) for(int l = s; l < f; l++)
#define ii pair<int,int>
#define iii pair<int, pair<int,int>>
#define ll long long

using namespace std;

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