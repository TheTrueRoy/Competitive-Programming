#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

#define pb push_back
#define loop(n) for(int i = 0; i < n; i++)
#define ii pair<int,int>
#define ipii pair<int, pair<int,int>>

string stems[10] = { "甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸" };
string branches[12] = { "子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥" };

int main() {
	int N, M, O, P;
	cin >> N;
	loop(N) {
		cin >> M; M -= 4;
		if (M < 0) {
			M %= 60;
			M += 60;
		}
		O = M % 10;
		P = M % 12;
		cout << stems[O] << branches[P] << endl;
	}
}