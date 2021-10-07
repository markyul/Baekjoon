#include <iostream>
using namespace std;

long long N;
long long matrix[2][2] = { {1, 1}, {1, 0} };
long long answer[2][2] = { {1, 0}, {0, 1} }; // ó���� ���� ��ķ� �ʱ�ȭ

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
		// ������ Ȧ���� ����-1 �ϰ� answer�� Amatrix�� ����
		if (N % 2 == 1) {
			N -= 1;
			multiMatrix(answer, matrix);
		}
		// B�� ¦���� �� ���̴ϱ� matrix���� ���ϰ� B / 2
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