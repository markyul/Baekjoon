#include <iostream>
using namespace std;

int N, k;

void input() {
	cin >> N >> k;
}

void solve() {
	int start = 1;
	int end = k;

	while (start < end) {
		int mid = (start + end) / 2;
		int count = 0;
		// mid 보다 작거나 같은 수를 행렬에서 찾아 counting(수식으로 해결)
		for (int i = 1; i <= N; i++) {
			if ((mid / i) < N)
				count += mid / i;
			else
				count += N;
		}

		// count와 k를 비교하며 이분 탐색
		if (count >= k)
			end = mid;
		else
			start = mid + 1;
	}

	cout << start;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}