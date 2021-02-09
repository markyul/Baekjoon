#include <iostream>
using namespace std;

int arr[1000000];
int num;

void input() {
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
}

void solve() {
	int min = arr[0];
	int max = arr[0];

	for (int i = 1; i < num; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	cout << min << " " << max << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}