#include <iostream>
using namespace std;

int N;
int arr[1001];
int LISDP[1001], reverseDP[1001];

void setLISDP() {
	for (int i = 1; i <= N; i++) {
		int max = 0;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && LISDP[j] > max)
				max = LISDP[j];
		}
		LISDP[i] = max + 1;
	}
}

void setReverseDP() {
	for (int i = N; i > 0; i--) {
		int max = 0;
		for (int j = N; j > i; j--) {
			if (arr[j] < arr[i] && reverseDP[j] > max)
				max = reverseDP[j];
		}
		reverseDP[i] = max + 1;
	}
}

int bitonic() {
	int max = 0;

	for (int i = 1; i <= N; i++) {
		if (LISDP[i] + reverseDP[i] > max)
			max = LISDP[i] + reverseDP[i];
	}

	return max;
}

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void solve() {
	int answer;

	setLISDP();
	setReverseDP();
	
	answer = bitonic() - 1;

	cout << answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}