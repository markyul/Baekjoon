#include <iostream>
using namespace std;

int M, N;
int arr[1000001];

void input() {
	cin >> M >> N;
	fill_n(arr, N + 1, 1);
}

void solve() {
	for (int num = 2; num <= N; num++) {
		if (arr[num] == false)
			continue;
		for(int count = 2; num*count <= N; count++) {
			arr[num * count] = false;
		}
	}

	for (int i = M; i <= N; i++) {
		if (i == 1)
			continue;
		if (arr[i] == true)
			cout << i << "\n";
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