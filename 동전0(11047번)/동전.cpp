#include <iostream>
using namespace std;

int N, K;
int coins[10];

void input() {
	cin >> N >> K;

	for (int i = N - 1; i >= 0; i--) {
		cin >> coins[i];
	}
}

void solve() {
	int answer = 0;

	for (int i = 0; i < N; i++) {
		answer += K / coins[i];
		K = K % coins[i];
	}

	cout << answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}