#include <iostream>
using namespace std;

int N;
int arr[1000][2];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i][0];
	}
}

void solve() {
	int maxCount = 1;

	for (int i = N - 1; i >= 0; i--) {
		int max = 0;
		int index = i;

		arr[index][1] = 1;

		for (int j = i + 1; j < N; j++) {
			if (arr[index][0] < arr[j][0] && arr[j][1] > max) {
				max = arr[j][1];
				arr[index][1] = max + 1;
			}
			if (maxCount < arr[index][1])
				maxCount = arr[index][1];
		}
	}

	cout << maxCount;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}