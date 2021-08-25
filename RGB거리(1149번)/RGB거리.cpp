#include <iostream>
using namespace std;

int houseN;
int house[1001][3];

void insertDP(int N, int color) {
	int sum = -1;

	for (int i = 0; i < 3; i++) {
		if (i == color)
			continue;
		else {
			if (sum == -1)
				sum = house[N - 1][i] + house[N][color];
			else if (sum > house[N - 1][i] + house[N][color])
				sum = house[N - 1][i] + house[N][color];
		}
	}
	house[N][color] = sum;
}

void DP(int N) {
	for (int i = 0; i < 3; i++) {
		insertDP(N, i);
	}
}

void input() {
	cin >> houseN;


	for (int i = 1; i <= houseN; i++) {
		cin >> house[i][0] >> house[i][1] >> house[i][2];

		DP(i);
	}
}

void solve() {
	int min = -1;

	for (int i = 0; i < 3; i++) {
		if (min == -1)
			min = house[houseN][i];
		else if (min > house[houseN][i])
			min = house[houseN][i];
	}

	cout << min;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}