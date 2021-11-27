#include <iostream>
using namespace std;

int N, answer;

void makeOne(int n, int ans) {

	if (n == 1) {
		if (answer > ans)
			answer = ans;
		return;
	}

	if (ans >= answer)
		return;

	if (n % 3 == 0) {
		makeOne(n / 3, ans + 1);
	}
	if (n % 2 == 0) {
		makeOne(n / 2, ans + 1);
	}
	makeOne(n - 1, ans + 1);
}

void solve() {
	cin >> N;
	answer = N;
	int processCount = 0;

	makeOne(N, processCount);

	cout << answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}