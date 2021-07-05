#include <iostream>
using namespace std;

int factorial(int n) {
	if (n <= 1)
		return 1;

	return n * factorial(n - 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int answer;
	cin >> N;

	answer = factorial(N);
	cout << answer;

	return 0;
}