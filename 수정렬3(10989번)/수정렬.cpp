#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// counting 정렬 사용
int N;
int counting[10001];

void input() {
	int x;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		counting[x]++;
	}
}

void solve() {
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < counting[i]; j++)
			cout << i << "\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}