#include <iostream>
using namespace std;

int N;
int totalScore = 0;
int minScore = -1;
int board[21][21] = { 0, };
bool team[21];

void compareScore(int startScore, int linkScore) {
	int compareScore = startScore - linkScore;

	if (compareScore < 0)
		compareScore = compareScore * -1;

	if (compareScore < minScore || minScore == -1) {
		minScore = compareScore;
	}
}

void totalSum() {
	int startScore = 0, linkScore = 0;
	int startTeam[11] = { 0,};
	int linkTeam[11] = { 0, };
	int startCount = 1, linkCount = 1;

	for (int i = 1; i <= N; i++) {
		if (team[i] == true) {
			startTeam[startCount] = i;
			startCount++;
		}
		else {
			linkTeam[linkCount] = i;
			linkCount++;
		}
	}

	for (int i = 1; i <= N / 2; i++) {
		for (int j = 1; j <= N / 2; j++) {
			startScore += board[startTeam[i]][startTeam[j]];
			linkScore += board[linkTeam[i]][linkTeam[j]];
		}
	}

	compareScore(startScore, linkScore);
}

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			totalScore += board[i][j];
		}
	}
}

void solve(int index, int member) {
	if (index > N / 2) {
		totalSum();
	}
	else {
		for (int i = member; i <= N; i++) {
			team[i] = true;
			solve(index + 1, i + 1);
			team[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	team[1] = 1;

	input();
	solve(2, 2);

	cout << minScore;

	return 0;
}