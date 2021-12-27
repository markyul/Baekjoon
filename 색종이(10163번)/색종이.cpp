#include <iostream>
using namespace std;

int field[1001][1001];
int area[101];

void solve(int idx, int x, int y, int w, int h) {
	area[idx] = w * h;

	for (int i = y; i < y + h; i++) {
		for (int j = x; j < x + w; j++) {
			if (field[i][j] != 0) {
				area[field[i][j]]--;
			}
			field[i][j] = idx;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, x, y, w, h;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> x >> y >> w >> h;

		solve(i, x, y, w, h);
	}

	for (int i = 1; i <= N; i++) {
		cout << area[i] << "\n";
	}

	return 0;
}