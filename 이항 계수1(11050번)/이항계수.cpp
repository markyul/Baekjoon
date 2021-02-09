#include <iostream>
using namespace std;


int N, K;
int pascal[11][11] = { 0 };

void input() {
	cin >> N >> K;
}

void solve() {

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j == 0 || j == i)
				pascal[i][j] = 1;
			else {
				pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
			}
		}
	}

	cout << pascal[N][K] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}