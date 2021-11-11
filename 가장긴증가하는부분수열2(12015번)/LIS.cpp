#include <iostream>
using namespace std;

int N;
int answer = 0;
int arr[1000001], lis[1000001];

// ã�� ���� �ߺ��Ǹ� ���� ���� �ε���, ������ ã�� ������ ū �� �� ���� ���� ���� �ε��� ��ȯ
int lowerBound(int length, int target)
{
	int start = 0;
	int end = length;    // ���� �迭�� �ִ� ������ ũ�� �迭���� ū �ε����� �����Ѿ� ��
	int mid = 0;

	while (start < end)
	{
		mid = (start + end) / 2;

		if (lis[mid] >= target)
			end = mid;
		else 
			start = mid + 1;
	}
	return start;
}

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		int idx = 0;
		idx = lowerBound(answer, arr[i]);

		if (lis[idx] >= arr[i]) {
			lis[idx] = arr[i];
		}
		else {
			lis[idx + 1] = arr[i];
			answer++;
		}	
	}

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