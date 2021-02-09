#include<iostream>
#define endl "\n"
using namespace std;

int arr[2][41] = { {1, 0, },{0, 1, } };

void fibo(int n) {
	arr[0][n] = arr[0][n - 1] + arr[0][n - 2];
	arr[1][n] = arr[1][n - 1] + arr[1][n - 2];
}


void solve() {
	int test;

	cin >> test;

	cout << arr[0][test] << " " << arr[1][test] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;

	for (int i = 2; i < 41; i++) {
		fibo(i);
	}

	for (int i = 0; i < TC; i++) {
		solve();
	}

	return 0;
}