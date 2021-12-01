#include <iostream>
using namespace std;

int N;
int score[301];
int maxSum[301][3] = {0};

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> score[i];
	}
}

void solve() {
	int answer;

	for (int i = 1; i <= N; i++) {
		maxSum[i][0] = maxSum[i - 1][1] > maxSum[i - 1][2] ? maxSum[i - 1][1] : maxSum[i - 1][2];
		maxSum[i][1] = maxSum[i - 1][0] + score[i];
		maxSum[i][2] = maxSum[i - 1][1] + score[i];
	}

	answer = maxSum[N][1] > maxSum[N][2] ? maxSum[N][1] : maxSum[N][2];

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