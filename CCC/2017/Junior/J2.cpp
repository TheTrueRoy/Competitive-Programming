#include <iostream>
#include <string>

/*	Completion date: 2021/01/27	*
 *	CCC Grader Score: 15/15		*/

using namespace std;
int N, x;

int main() {
	cin >> x >> N;
	string str = "";
	for (int i = 0; i <= N; i++)
		str += '1';
	cout << x * stoi(str);
}