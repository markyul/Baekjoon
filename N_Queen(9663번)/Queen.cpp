#include <iostream>
using namespace std;

int N;
int caseCount = 0;
bool board[14][14];

// 잡히는 자리면 true
bool isKill(int x, int y) {
	int copyX, copyY;

	for (int i = 0; i < x; i++) {
		if (board[i][y] == true) {
			return true;
		}
	}

	copyX = x-1;
	copyY = y-1;
	while (copyX >= 0 && copyY >= 0) {
		if (board[copyX][copyY] == true)
			return true;
		copyX--;
		copyY--;
	}

	copyX = x - 1;
	copyY = y + 1;
	while (copyX >= 0 && copyY < N) {
		if (board[copyX][copyY] == true)
			return true;
		copyX--;
		copyY++;
	}

	return false;
}

void solve(int x, int y) {
	if (x >= N) {
		caseCount++;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (isKill(x, i) == false) {
				board[x][i] = true;
				solve(x + 1, 0);
				board[x][i] = false;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	solve(0, 0);

	cout << caseCount;

	return 0;
}