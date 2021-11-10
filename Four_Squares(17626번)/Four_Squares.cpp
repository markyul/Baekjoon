#include <iostream>
#include <cmath>
using namespace std;

int dp[50001];
int n, answer;

void solve() {
	for (int i = 1; i <= n; i++) {
		int sqr = sqrt(i);
		if (sqr * sqr == i) {
			dp[i] = 1;
			continue;
		}

		int min = 5;

		for (int j = 1; j * j < i; j++) {
			if (min > dp[i - (j * j)] + 1)
				min = dp[i - (j * j)] + 1;
		}
		dp[i] = min;
	}

	cout << dp[n];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	solve();

	return 0;
}