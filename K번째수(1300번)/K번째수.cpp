#include <iostream>
using namespace std;

int N, k;

void input() {
	cin >> N >> k;
}

void solve() {
	int start = 1;
	int end = k;

	while (start < end) {
		int mid = (start + end) / 2;
		int count = 0;
		// mid ���� �۰ų� ���� ���� ��Ŀ��� ã�� counting(�������� �ذ�)
		for (int i = 1; i <= N; i++) {
			if ((mid / i) < N)
				count += mid / i;
			else
				count += N;
		}

		// count�� k�� ���ϸ� �̺� Ž��
		if (count >= k)
			end = mid;
		else
			start = mid + 1;
	}

	cout << start;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}