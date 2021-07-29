#include <iostream>
#include <vector>

/*	Completion date: 2021/01/28	*
 *	CCC Grader Score: 15/15		*/

using namespace std;

#define fori(l,n) for(int i = l; i < n; i++)
#define ii pair<int,int>
#define pb push_back 
#define mp make_pair

const int MAXN = 150010;
int lines[MAXN];
vector<ii> dt(MAXN);
ii blocks[510][150010];
int blockValue[510];
vector<int> stationIndex[150010];

int N, M, Q, in;

void blockUpdate(int line) {
	fori(0, N / 500 + 1) {
		if (blocks[i][line].first == 0)
			continue;
		int index = (blocks[i][line].second - 1 - lines[line] + stationIndex[line].size()) % stationIndex[line].size();
		blockValue[i] -= stationIndex[line][index];
		index = (blocks[i][line].first - 1 - lines[line] - 1 + 2 * stationIndex[line].size()) % stationIndex[line].size();
		blockValue[i] += stationIndex[line][index];
	}
	lines[line]++;
	lines[line] %= stationIndex[line].size();
}

int search(int x, int y) {
	int bx = x / 500 + 1;
	int by = y / 500;
	int sum = 0;
	fori(x, min(500 * bx, y + 1)) {
		int index = (dt[i].second - 1 - lines[dt[i].first] + stationIndex[dt[i].first].size()) % stationIndex[dt[i].first].size();
		sum += stationIndex[dt[i].first][index];
	}
	fori(max(bx, by) * 500, y + 1) {
		int index = (dt[i].second - 1 - lines[dt[i].first] + stationIndex[dt[i].first].size()) % stationIndex[dt[i].first].size();
		sum += stationIndex[dt[i].first][index];
	}
	fori(bx, by) {
		sum += blockValue[i];
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> Q;
	fori(0, N) {
		int b = i / 500;
		cin >> in;
		if (blocks[b][in].first == 0)
			blocks[b][in].first = lines[in] + 1;
		blocks[b][in].second = lines[in] + 1;
		dt[i] = mp(in, lines[in] + 1);
		lines[in]++;
	}
	fori(0, N) {
		int b = i / 500;
		cin >> in;
		stationIndex[dt[i].first].pb(in);
		blockValue[b] += in;
	}
	fori(0, M) {
		lines[M] = 0;
	}
	int a, b;
	fori(0, Q) {
		cin >> in;
		if (in == 1) {
			cin >> a >> b; a--; b--;
			cout << search(a, b) << endl;
		}
		else {
			cin >> a;
			blockUpdate(a);
		}
	}
}