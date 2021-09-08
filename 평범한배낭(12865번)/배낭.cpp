/* notion에 배낭 알고리즘 */
#include <iostream>
using namespace std;

int N;	// 물품의 수
int K;	// 버틸 수 있는 무게
int weights[101];	// 각 물건의 무게
int values[101];	// 각 물건의 가치
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
					DP[i][j] = values[i] + DP[i - 1][j - weights[i]];	// i번째 물건을 넣고 그 무게를 뺐을 때의 최대 가치와 합침
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