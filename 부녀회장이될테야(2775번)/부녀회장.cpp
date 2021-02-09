#include <iostream>
using namespace std;

int apart[15][15] = { 0 };
int k, n;

void insert(int floor, int num) {
	for (int i = 1; i <= floor; i++) {
		for (int j = 1; j <= num; j++) {
			apart[i][j] = apart[i - 1][j] + apart[i][j - 1];
		}
	}
}

void input() {
	cin >> k >> n;
}

void solve() {
	for (int i = 0; i < 15; i++) {
		apart[0][i] = i;
	}

	insert(k, n);
	cout << apart[k][n] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;

	for (int i = 0; i < TC; i++) {
		input();
		solve();
	}

	return 0;
}