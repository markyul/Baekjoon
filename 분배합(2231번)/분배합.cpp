#include <iostream>
using namespace std;

int n;

int distribution(int num) {
	int sum = num;

	while (num != 0) {
		sum += num % 10;
		num = num / 10;
	}

	return sum;
}

void input() {
	cin >> n;
}

void solve() {
	int sum = 1;

	while (1) {
		if (distribution(sum) == n) {
			cout << sum << endl;
			break;
		}
		if (sum == n) {
			cout << 0 << endl;
			break;
		}
		sum++;
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