#include <iostream>
using namespace std;

int K, N;
int lans[10000];

int max_lan() {
	int max = 0;
	for (int i = 0; i < K; i++) {
		if (max < lans[i])
			max = lans[i];
	}

	return max;
}

int divided_sum(long long length) {
	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += lans[i] / length;
	}

	return sum;
}

void input() {
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> lans[i];
	}
}

void solve() {
	long long start = 0;
	long long mid, end;
	int sum = 0;

	end = max_lan();

	while (start < end) {
		if (start == 0)
			start = 1;
		mid = (start + end) / 2;

		if (start == mid)
			break;

		sum = divided_sum(mid);
		if (sum < N)
			end = mid;
		else
			start = mid;
	}

	if (divided_sum(end) == N)
		start = end;

	cout << start;
}

int main(void) {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}