#include <iostream>
using namespace std;

long long x, y;

void input() {
	cin >> x >> y;
}

void solve() {
	long long distance = y - x;
	long long sum = 0;
	long long count = 0;
	long long iterationCount = 1;

	while (1) {

		count += 2;
		sum += iterationCount * 2;

		if (sum >= distance)
			break;

		iterationCount++;
	}

	if (sum - distance >= iterationCount)
		count = count - 1;

	cout << count << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;

	for (int i = 0; i < TC; i++) {
		input();
		solve();
	}

	return 0;
}