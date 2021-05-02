#include <iostream>
using namespace std;

int x, y;

void input() {
	cin >> x >> y;
}

void solve() {
	if (x > 0) {
		if (y > 0)
			cout << 1;
		else
			cout << 4;
	}
	else {
		if (y > 0)
			cout << 2;
		else
			cout << 3;
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