#include <iostream>
#include <vector>
#include <array>

/*	Completion date: 2021/02/22		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 0.970s, 22.61mb	*/

using namespace std;

#define fori(l,n) for(int i = l; i < n; i++)
#define forj(l,n) for(int j = l; j < n; j++)
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return (a / gcd(a, b)) * b;
}

const int MAXN = 150010, MAXM = 150010, MAXZ = 26;
int diff[MAXN][MAXZ], d[MAXZ], nums[MAXN], st[MAXN*4];
array<int, 3> ins[MAXM];

int check(int l, int h, int index = 1, int low = 1, int high = MAXN) {
	if (h < l)
		return 0;
	if (l == low && h == high)
		return st[index];
	int mid = (low + high) / 2;
	return gcd(check(l, min(mid,h), index * 2, low, mid), check(max(l,mid+1), h, index * 2 + 1, mid + 1, high));
}

void createTree(int index = 1, int low = 1, int high = MAXN) {
	if (low == high)
		st[index] = nums[low];
	else {
		int mid = (low + high) / 2;
		createTree(index * 2, low, mid);
		createTree(index * 2 + 1, mid + 1, high);
		st[index] = gcd(st[index * 2], st[index * 2 + 1]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int start, end, mag;
	fori(0,M) {
		cin >> start >> end >> mag;
		diff[start][mag]++;
		diff[end + 1][mag]--;
		ins[i] = {start, end, mag};
	}
	fori(1,N+1) {
		nums[i] = 1;
		forj(1,17) {
			d[j] += diff[i][j];
			if (d[j] > 0) {
				nums[i] = lcm(nums[i], j);
			}
		}
	}

	createTree();

	fori(0,M) {
		auto I = ins[i];
		if (check(I[0], I[1]) != I[2]) {
			cout << "Impossible" << endl;
			return 0;
		}
	}
	fori(1,N+1)
		cout << nums[i] << ' ';
	cout << endl;
};