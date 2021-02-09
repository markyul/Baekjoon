#include <iostream>
using namespace std;

int n;

void input() {
	cin >> n;
}

void solve() {
	int sum = 1;
	int i = 0;

	while (1) {
		sum += 6 * i;
		if (n <= sum) {
			cout << i + 1 << endl;
			break;
		}
		i++;
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