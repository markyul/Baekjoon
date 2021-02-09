#include <iostream>
using namespace std;

string board1 = "WBWBWBWB";
string board2 = "BWBWBWBW";

string big_board[50];
int N, M;

int compare(int row, int col ,string board_1, string board_2) {
	int sum = 0;
	int start_row = row;
	int start_col = col;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j++) {
				if (big_board[start_row][start_col] != board_1[j])
					sum++;
				start_col++;
			}
			start_col = col;
		}
		else {
			for (int j = 0; j < 8; j++) {
				if (big_board[start_row][start_col] != board_2[j])
					sum++;
				start_col++;
			}
			start_col = col;
		}
		start_row++;
	}

	return sum;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> big_board[i];
	}
}

void solve() {
	int sum = 0;
	int sum1 = 64;
	int sum2 = 64;

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			sum = compare(i, j, board1, board2);
			if (sum1 > sum)
				sum1 = sum;
		}
	}

	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			sum = compare(i, j, board2, board1);
			if (sum2 > sum)
				sum2 = sum;
		}
	}

	if (sum1 < sum2)
		sum = sum1;
	else
		sum = sum2;

	cout << sum << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}