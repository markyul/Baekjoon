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
	int n, prime;
	int NUM = 1000;
	int count = 0, index = 0;
	vector<bool> primeArr(NUM + 1, false);

	primeArr = SetPrime(primeArr, NUM);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> prime;

		if (primeArr[prime])
			count++;
	}

	cout << count;
}