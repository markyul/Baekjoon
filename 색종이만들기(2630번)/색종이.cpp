#include <iostream>
using namespace std;

int N;
int white = 0;
int blue = 0;
int paper[128][128];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
}

void solve(int row, int col, int n) {
	if (n == 0)
		return;

	int color = paper[row][col];
	bool flag = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[row + i][col + j] != color) {
				flag = true;
				break;
			}
		}
		if (flag == true)
			break;
	}

	if (flag == true) {
		solve(row, col, n / 2);
		solve(row + n / 2, col, n / 2);
		solve(row, col + n / 2, n / 2);
		solve(row + n / 2, col + n / 2, n / 2);
	}
	else {
		if (color == 0)
			white++;
		else
			blue++;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve(0, 0, N);

	cout << white << "\n" << blue;

	return 0;
}