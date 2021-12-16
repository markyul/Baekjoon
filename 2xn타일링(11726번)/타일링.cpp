#include <iostream>
using namespace std;

int N;
int dp[1001];

int solve(int n) {
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	return dp[n];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer;

	cin >> N;
	dp[1] = 1;
	dp[2] = 2;

	answer = solve(N);

	cout << answer;

	return 0;
}