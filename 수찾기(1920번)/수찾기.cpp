#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr_N[100001];

bool search(int start, int end, int n) {
	int mid;

	if (start > end) {
		return false;
	}

	mid = (start + end) / 2;

	if (n == arr_N[mid]) {
		return true;
	}
	else if (n > arr_N[mid]) {
		start = mid + 1;
		return search(start, end, n);
	}
	else {
		end = mid - 1;
		return search(start, end, n);
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr_N[i];
	}

	cin >> M;
}

void solve() {
	int num;

	// 이분 탐색을 위해 arr_N 배열 정렬
	sort(arr_N, arr_N + N);

	for (int i = 0; i < M; i++) {
		cin >> num;

		cout << search(0, N - 1, num) << "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}