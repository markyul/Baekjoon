#include<iostream>
using namespace std;

int N, M;
int print[9];
bool arr[9] = { false };

void solve(int n) {
	int num;

	if (M == n - 1) {
		for (int i = 1; i <= M; i++) {
			cout << print[i] << " ";
		}
		cout << "\n";
		return;
	}

	// 체크했는지 확인하고 안했으면 출력문에 넣음
	for (int i = 1; i <= N; i++) {
		if (arr[i] == false) {
			num = i;
			arr[i] = true;
			print[n] = num;
			break;
		}
	}

	return solve(n+1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	solve(1);

	return 0;
}