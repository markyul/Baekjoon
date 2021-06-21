#include <iostream>
using namespace std;

void solve() {
	int N;
	int left, right;	//����, �и�
	int diff;
	int sum = 0;
	int count = 0;

	cin >> N;

	// N�� ���° �밢���� �ִ°�?
	while (sum < N) {
		count++;
		sum += count;
	}

	diff = sum - N;

	if (count % 2 == 0) {
		left = count - diff;
		right = 1 + diff;
	}
	else {
		left = 1 + diff;
		right = count - diff;
	}

	cout << left << "/" << right;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}