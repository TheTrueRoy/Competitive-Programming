#include <iostream>
#include <vector>
#include <queue>

/*	Completion date: 2021/02/22		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 1.804s, 51.07mb	*/

#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;
typedef vector<pair<int, int>> vpii;

const int mn = 1005;
int arr[mn][mn];
bool vis[mn][mn];
vector<vpii> help(1e6 + 5);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            arr[i][j] = x;
            help[x].push_back({ i + 1, j + 1 });
        }
    }
    queue<pair<int, int>> q;
    q.push({ n, m });
    vis[n][m] = true;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        int r = u.first;
        int c = u.second;
        for (auto v : help[r * c]) {
            if (v.first == 1 && v.second == 1) {
                cout << "yes\n";
                return 0;
            } if (!vis[v.first][v.second]) {
                vis[v.first][v.second] = true;
                q.push(v);
            }
        }
    }
    cout << "no\n";
    return 0;
}