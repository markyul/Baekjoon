#include <iostream>
using namespace std;

int TC, M, N, K, answer;
int field[50][50];

void move(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return;

	if (field[i][j] == 0)
		return;
	else {
		field[i][j] = 0;
		move(i, j + 1);
		move(i + 1, j);
		move(i, j - 1);
		move(i - 1, j);
	}
}

void input() {
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> c >> r;
		field[r][c] = 1;
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 1) {
				answer++;
				field[i][j] = 0;
				move(i, j + 1);
				move(i + 1, j);
				move(i, j - 1);
				move(i - 1, j);
			}
		}
	}

	cout << answer << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;

	for (int i = 0; i < TC; i++) {
		answer = 0;
		input();
		solve();
	}

	return 0;
}