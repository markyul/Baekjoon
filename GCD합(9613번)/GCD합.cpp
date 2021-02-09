#include<iostream>
#include<vector>

using namespace std;

int Gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return Gcd(b, a % b);
	}
}

int main(void) {
	int T, n, num;
	vector<int> arr;

	cin >> T;
	for (int i = 0; i < T; i++) {
		long long sum = 0;
		arr.clear();
		cin >> n;
		//원소 삽입
		for (int j = 0; j < n; j++) {
			cin >> num;
			arr.push_back(num);
		}
		//순서대로 GCD구하고 더하기
		for (int j = 0; j < n - 1; j++) {
			int next = j + 1;
			while (next != n) {
				sum += Gcd(arr[j], arr[next]);
				next++;
			}
		}
		cout << sum << "\n";
	}
}