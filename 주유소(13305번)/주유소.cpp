#include <iostream>
using namespace std;

int N;
long long distances[100000];
long long totalDistance = 0;
long long prices[100000];

void input() {
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> distances[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> prices[i];
	}
}

void solve() {
	long long postPrice = prices[0];
	long long minPrice = prices[0] * distances[0];
	for (int i = 1; i < N - 1; i++) {
		if (postPrice > prices[i]) {
			postPrice = prices[i];
		}

		minPrice += postPrice * distances[i];
	}

	cout << minPrice;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}