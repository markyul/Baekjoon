#include <iostream>
using namespace std;

int N, K;
int yosep[1001];

void input() {
	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		yosep[i] = i;
	}
}

void solve() {
	int idx = 1;
	int count = 1;	// 처음엔 첫번째를 가리키고 있으므로

	cout << "<";
	for (int i = 0; i < N; i++) {
		while (count < K) {
			idx++;
			if (idx != N)
				idx = idx % N;

			if (yosep[idx] > 0)
				count++;
		}
		count = 0;

		if (i > 0)
			cout << ", ";
		cout << yosep[idx];
		yosep[idx] = -1;
	}
	cout << ">";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}