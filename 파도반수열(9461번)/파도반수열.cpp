#include <iostream>
using namespace std;

int TC;
long long arr[101] = {0, 1, 1, 1, 2};

long long solve(int n) {
	if (n == 0)
		return 0;

	if (arr[n] != 0) {
		return arr[n];
	}
	else {
		arr[n] = solve(n-5) + solve(n-1);
		return arr[n];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long result = 0;

	cin >> TC;

	for (int i = 0; i < TC; i++) {
		int n;
		cin >> n;

		result = solve(n);
		cout << result << "\n";
	}

	return 0;
}