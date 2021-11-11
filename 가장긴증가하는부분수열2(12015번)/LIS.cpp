#include <iostream>
using namespace std;

int N;
int answer = 0;
int arr[1000001], lis[1000001];

// 찾는 수가 중복되면 가장 앞의 인덱스, 없으면 찾는 수보다 큰 수 중 가장 작은 수의 인덱스 반환
int lowerBound(int length, int target)
{
	int start = 0;
	int end = length;    // 값이 배열의 최대 값보다 크면 배열보다 큰 인덱스를 가르켜야 함
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