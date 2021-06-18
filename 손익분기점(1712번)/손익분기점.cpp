#include <iostream>
using namespace std;

int A, B, C;

void input() {
	cin >> A >> B >> C;
}

void solve() {
	int answer = 0;

	if (B < C) {
		answer = A / (C - B) + 1;
	}
	else
		answer = -1;

	cout << answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}