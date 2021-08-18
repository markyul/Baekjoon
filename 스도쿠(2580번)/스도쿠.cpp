#include <iostream>
using namespace std;

int board[9][9];
bool flag = false;

// 행에 중복된 숫자가 없다면 true 반환
bool searchRow(int row, int num) {
	for (int i = 0; i < 9; i++) {
		if (board[row][i] == num)
			return false;
	}

	return true;
}

// 열에 중복된 숫자가 없다면 true 반환
bool searchCol(int col, int num) {
	for (int i = 0; i < 9; i++) {
		if (board[i][col] == num)
			return false;
	}

	return true;
}

// 사각형에 중복된 숫자가 없다면 true 반환
bool searchSquare(int row, int col, int num) {
	for (int i = 0, rowStart = row - (row % 3); i < 3; i++, rowStart++) {
		for (int j = 0, colStart = col - (col % 3); j < 3; j++, colStart++) {
			if (board[rowStart][colStart] == num)
				return false;
		}
	}

	return true;
}

bool threeMethod(int row, int col, int num) {

	if (searchRow(row, num) && searchCol(col, num) && searchSquare(row, col, num)) {
		board[row][col] = num;
		return true;
	}

	return false;
}

void input() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
		}
	}
}

void solve(int index) {
	for (index; index < 81; index++) {
		int row = index / 9;
		int col = index % 9;

		if (board[row][col] == 0) {
			for (int i = 1; i <= 9; i++) {
				if (threeMethod(row, col, i)) {
					solve(index + 1);
					if (flag)
						return;
				}
				// 중복으로 인해 공백에 넣을 숫자가 없으면 빠져나간다.	
			}
			board[row][col] = 0;
			return;
		}
	}
	flag = true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}