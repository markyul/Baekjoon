#include <iostream>
#include <vector>

#define MOD 1000
using namespace std;

int N;
int matrix[5][5];
int answer[5][5];
long long B;

void multiMatrix(int Amatrix[][5], int Bmatrix[][5]) {
	int temp[5][5] = { 0,};

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				temp[i][j] += Amatrix[i][k] * Bmatrix[k][j];
			}
			temp[i][j] %= 1000;
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Amatrix[i][j] = temp[i][j];
		}
	}
}

void input() {
	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
		answer[i][i] = 1;
	}
}

void solve() {
	while (B > 0) {
		// ������ Ȧ���� ����-1 �ϰ� answer�� Amatrix�� ����
		if (B % 2 == 1) {
			B -= 1;
			multiMatrix(answer, matrix);
		}
		// B�� ¦���� �� ���̴ϱ� matrix���� ���ϰ� B / 2
		multiMatrix(matrix, matrix);
		B /= 2;
	}
	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}