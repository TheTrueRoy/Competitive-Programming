#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <string>

using namespace std;

#define pb push_back
#define loop(n) for(int i = 0; i < n; i++)
#define ii pair<int,int>
#define ipii pair<int, pair<int,int>>
int daysM[2][12] = {{ 0,31,59,90,120,151,181,212,243,273,304,334 },{ 0,31,60,91,121,152,182,213,244,275,305,335}};
int dayS[4] = { 2,3,4,5 };
static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
string days[9] = { "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

int main() {
	string S;
	int Y, M, D, N;
	cin >> N;
	loop(N) {
		Y = 1, M = 1, D = 1;
		cin >> S;
		if (S.at(0) == '-') {
			Y *= -1;
			S.erase(0, 1);
		}
		Y *= stoi(S.substr(0, S.find("-")));
		S.erase(0, S.find("-") + 1);
		M *= stoi(S.substr(0, S.find("-")));
		S.erase(0, S.find("-") + 1);
		D *= stoi(S.substr(0, S.find("-")));
		S.erase(0, S.find("-") + 1);
		if (Y < 1752 || (Y == 1752 && (M < 9 || (M == 9 && D <= 2)))) {
			if (Y > 0) {
				Y -= M < 3;
				cout << days[(Y + Y / 4 + t[M - 1] + D) % 7] << endl;
			} else {
				Y = -Y;
				D += Y / 4 * 2; //Don't combine (/4 needs to be casted before multiplication)
				D -= dayS[Y%4];
				D += daysM[0][M - 1];
				if (D < 0)
					D += 7;
				D %= 7;
				cout << days[D+1] << endl;
			}
		} else {
			Y -= M < 3;
			cout << days[(Y+Y/4-Y/100+Y/400+t[M-1]+D) % 7+2] << endl;
		}
	}
}