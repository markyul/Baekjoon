#include <iostream>
using namespace std;

int TC;
string OX;

void input() {
	cin >> OX;
}

void solve() {
	int count = 0;
	int sum = 0;

	for (int i = 0; i < OX.size(); i++) {
		if (OX[i] == 'O') {
			count++;
			sum += count;
		}
		else
			count = 0;
	}

	cout << sum << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;

	for (int i = 0; i < TC; i++) {
		input();
		solve();
	}

	return 0;
}