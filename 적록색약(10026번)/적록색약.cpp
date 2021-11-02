#include <iostream>
using namespace std;

int N;
int common = 0, blind = 0;
char grid[100][100];
bool visit[100][100];
bool visitBlind[100][100];

void visitArea(int row, int col) {
	visit[row][col] = true;
	// ╩С
	if (row - 1 > -1 && visit[row - 1][col] == false && grid[row][col] == grid[row - 1][col])
		visitArea(row - 1, col);
	// ©Л
	if (col + 1 < N && visit[row][col + 1] == false && grid[row][col] == grid[row][col + 1])
		visitArea(row, col + 1);
	// го
	if (row + 1 < N && visit[row + 1][col] == false && grid[row][col] == grid[row + 1][col])
		visitArea(row + 1, col);
	// аб
	if (col - 1 > -1 && visit[row][col - 1] == false && grid[row][col] == grid[row][col - 1])
		visitArea(row, col - 1);
}

void visitBlindArea(int row, int col) {
	visitBlind[row][col] = true;
	// ╩С
	if (row - 1 > -1 && visitBlind[row - 1][col] == false) {
		if(grid[row][col] == grid[row - 1][col])
			visitBlindArea(row - 1, col);
		else if(grid[row][col] == 'R' && grid[row - 1][col] == 'G')
			visitBlindArea(row - 1, col);
		else if (grid[row][col] == 'G' && grid[row - 1][col] == 'R')
			visitBlindArea(row - 1, col);
	}
	// ©Л
	if (col + 1 < N && visitBlind[row][col + 1] == false) {
		if (grid[row][col] == grid[row][col + 1])
			visitBlindArea(row, col + 1);
		else if (grid[row][col] == 'R' && grid[row][col + 1] == 'G')
			visitBlindArea(row, col + 1);
		else if (grid[row][col] == 'G' && grid[row][col + 1] == 'R')
			visitBlindArea(row, col + 1);
	}
	// го
	if (row + 1 < N && visitBlind[row + 1][col] == false) {
		if (grid[row][col] == grid[row + 1][col])
			visitBlindArea(row + 1, col);
		else if (grid[row][col] == 'R' && grid[row + 1][col] == 'G')
			visitBlindArea(row + 1, col);
		else if (grid[row][col] == 'G' && grid[row + 1][col] == 'R')
			visitBlindArea(row + 1, col);
	}
	// аб
	if (col - 1 > -1 && visitBlind[row][col - 1] == false) {
		if (grid[row][col] == grid[row][col - 1])
			visitBlindArea(row, col - 1);
		else if (grid[row][col] == 'R' && grid[row][col - 1] == 'G')
			visitBlindArea(row, col - 1);
		else if (grid[row][col] == 'G' && grid[row][col - 1] == 'R')
			visitBlindArea(row, col - 1);
	}
		
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == false) {
				visitArea(i, j);
				common++;
			}
			if (visitBlind[i][j] == false) {
				visitBlindArea(i, j);
				blind++;
			}
		}
	}

	cout << common << " " << blind;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}