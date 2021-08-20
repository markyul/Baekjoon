#include <iostream>
using namespace std;

int DP[1000001];

int fibo(int num) {
	if (num < 2) {
		if (DP[num] == 0)
			DP[num] = 1;
		return DP[num];
	}
	else {
		if (DP[num] == 0)
			DP[num] = (fibo(num - 1) + fibo(num - 2)) % 15746;
		return DP[num];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int result = 0;

	cin >> N;

	result = fibo(N);
	//result = result % 15746;

	cout << result;

	return 0;
}