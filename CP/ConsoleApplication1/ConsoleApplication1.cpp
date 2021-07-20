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
		cout << Y << M << D << endl;
	}
}