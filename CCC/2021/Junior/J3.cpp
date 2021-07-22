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

vector<bool> N(5000005), M(5000005);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int ins;
	string direction = "left";
	cin >> ins;
	while (ins != 99999) {
		int x = ins / 1000;
		if (x == 0);
		else if ((x % 10 + x / 10) % 2 == 0)
			direction = "right";
		else
			direction = "left";
		cout << direction << ' ' << ins % 1000 << endl;
		cin >> ins;
	}
	return 0;
}