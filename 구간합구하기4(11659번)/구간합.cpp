#include <iostream>
using namespace std;

int N, M;
int arr[100001];
int sum[100001];

void input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
}

void solve(int start, int end) {
	int answer;

	answer = sum[end] - sum[start - 1];

	cout << answer << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		solve(start, end);
	}

	return 0;
}