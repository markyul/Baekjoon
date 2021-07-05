#include <iostream>
using namespace std;

int fibonacci(int n) {
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, answer;
	cin >> N;

	answer = fibonacci(N);
	cout << answer;

	return 0;
}