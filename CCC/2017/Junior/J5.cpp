#include <iostream>
#include <vector>

/*	Completion date: 2021/07/27	*
 *	CCC Grader Score: 15/15		*/

using namespace std;

#define fori(l,n) for(int i = l; i < n; i++)
#define forj(l,n) for(int j = l; j < n; j++)

vector<int> boards(2010, 0);
vector<int> fenceHeights(4010);
int pHeights;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, in;
	cin >> N;
	fori(0, N) {
		cin >> in;
		boards[in]++;
	}
	fori(0, boards.size()) {
		if (boards[i] != 0) {
			if (boards[i] > 1)
				fenceHeights[i * 2] += boards[i] / 2;
			forj(i + 1, boards.size()) {
				if (boards[j] != 0) {
					fenceHeights[i + j] += min(boards[i], boards[j]);
				}
			}
		}
	}
	int mx = 0;
	fori(0, fenceHeights.size()) {
		if (fenceHeights[i] > mx) {
			pHeights = 0;
			mx = fenceHeights[i];
		}
		if (fenceHeights[i] == mx) {
			pHeights++;
		}
	}
	cout << mx << ' ' << pHeights << endl;
}