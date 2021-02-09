#include<iostream>
#include<vector>
using namespace std;

vector<bool> SetPrime(vector<bool> primeArr, int n) {
	for (int i = 2; i <= n; i++) {
		primeArr[i] = true;
	}

	for (int i = 2; i * i <= n; i++) {
		if (primeArr[i]) {
			for (int j = i * i; j <= n; j += i) {
				primeArr[j] = false;
			}
		}
	}
	return primeArr;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	const int NUM = 1000000;
	int count = 0, index = 0;
	vector<bool> primeArr(NUM + 1, true);

	primeArr = SetPrime(primeArr, NUM);

	while (1) {
		cin >> T;
		int side_left = 3;
		int side_right = T - 3;
		if (T == 0)
			break;

		while (1) {
			if (side_left > T / 2) {
				cout << "Goldbach's conjecture is wrong.\n";
				break;
			}

			if (primeArr[side_left] == true && primeArr[side_right] == true) {
				cout << T << " = " << side_left << " + " << side_right << "\n";
				break;
			}
			else {
				side_left += 2;
				side_right -= 2;
			}
		}
	}
}