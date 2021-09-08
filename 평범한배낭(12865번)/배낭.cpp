/* notion�� �賶 �˰��� */
#include <iostream>
using namespace std;

int N;	// ��ǰ�� ��
int K;	// ��ƿ �� �ִ� ����
int weights[101];	// �� ������ ����
int values[101];	// �� ������ ��ġ
int DP[101][100001];

void input() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> weights[i] >> values[i];
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - weights[i] >= 0) {
				if (DP[i - 1][j] < values[i] + DP[i - 1][j - weights[i]])
					DP[i][j] = values[i] + DP[i - 1][j - weights[i]];	// i��° ������ �ְ� �� ���Ը� ���� ���� �ִ� ��ġ�� ��ħ
				else
					DP[i][j] = DP[i - 1][j];
			}
			else
				DP[i][j] = DP[i - 1][j];
		}
	}

	cout << DP[N][K];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}