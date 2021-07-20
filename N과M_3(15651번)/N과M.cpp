#include <iostream>
using namespace std;

int N, M;
int output[8];

void NandM(int index) {
	if (index > M) {
		for (int i = 1; i <= M; i++) {
			cout << output[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = 1; i <= N; i++) {
			output[index] = i;
			NandM(index + 1);
		}
	}
}

void input() {
	cin >> N >> M;
}

void solve() {
	NandM(1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}