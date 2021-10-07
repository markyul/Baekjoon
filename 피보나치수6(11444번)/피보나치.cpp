#include <iostream>
using namespace std;

long long N;
long long matrix[2][2] = { {1, 1}, {1, 0} };
long long answer[2][2] = { {1, 0}, {0, 1} }; // 처음엔 단위 행렬로 초기화

void multiMatrix(long long Amatrix[][2], long long Bmatrix[][2]) {
	long long temp[2][2] = { 0, };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				temp[i][j] += Amatrix[i][k] * Bmatrix[k][j];
			}
			temp[i][j] %= 1000000007;
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			Amatrix[i][j] = temp[i][j];
		}
	}
}

void solve() {
	while (N > 0) {
		// 지수가 홀수면 지수-1 하고 answer에 Amatrix를 곱함
		if (N % 2 == 1) {
			N -= 1;
			multiMatrix(answer, matrix);
		}
		// B가 짝수가 될 것이니까 matrix끼리 곱하고 B / 2
		multiMatrix(matrix, matrix);
		N /= 2;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	solve();

	cout << answer[0][1];

	return 0;
}