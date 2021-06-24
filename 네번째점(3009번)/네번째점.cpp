#include <iostream>

#define POINT 3
using namespace std;

int x[POINT], y[POINT];

void input() {
	for (int i = 0; i < POINT; i++) {
		cin >> x[i] >> y[i];
	}
}

void solve() {
	// index1Àº ÁÂÇ¥, 2´Â count
	int pointX[2][2] = { 0 };
	int	pointY[2][2] = { 0 };
	int answer[2];

	for (int i = 0; i < POINT; i++) {
		for (int j = 0; j < 2; j++) {
			if (pointX[j][0] == 0) {
				pointX[j][0] = x[i];
				pointX[j][1]++;
				break;
			}
			if (x[i] == pointX[j][0]) {
				pointX[j][1]++;
				break;
			}
		}

	}
	for (int i = 0; i < POINT; i++) {
		for (int j = 0; j < 2; j++) {
			if (pointY[j][0] == 0) {
				pointY[j][0] = y[i];
				pointY[j][1]++;
				break;
			}
			if (y[i] == pointY[j][0]) {
				pointY[j][1]++;
				break;
			}
		}

	}

	pointX[0][1] == 1 ? answer[0] = pointX[0][0] : answer[0] = pointX[1][0];
	pointY[0][1] == 1 ? answer[1] = pointY[0][0] : answer[1] = pointY[1][0];

	cout << answer[0] << " " << answer[1];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}