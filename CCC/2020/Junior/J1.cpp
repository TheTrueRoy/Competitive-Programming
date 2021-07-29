#include <iostream>

/*	Completion date: 2021/01/24		*
 *	CCC Grader Score: 15/15			*
 *	DMOJ: 15/15, 0.038s, 3.23mb		*/

std::string solve() {
    int a, b, c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    if (a + 2 * b + 3 * c >= 10)
        return "happy";
    return "sad";
}

int main() {
    std::cout << solve();
}