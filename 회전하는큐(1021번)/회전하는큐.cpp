#include <iostream>
using namespace std;

int qu[51];

void solve(int N, int M) {
	int num;
	int totalSum = 0;
	int front = 1;
	int sizeOfN = N;

	for (int i = 0; i < M; i++) {
		int count = 0;
		cin >> num;
		// 뽑을려는 수가 큐 맨 앞의 수보다 크면
		if (front < num) {
			// 뽑을려는 수와 큐 맨 앞의 거리
			for (int j = front + 1; j <= num; j++) {
				if (qu[j] > 0)
					count++;
			}

			if (count > sizeOfN / 2) {
				totalSum += sizeOfN - count;
			}
			else {
				totalSum += count;
			}

		}
		else if (front > num) {
			// 뽑을려는 수와 큐 맨 앞의 거리
			for (int j = num + 1; j <= front; j++) {
				if (qu[j] > 0)
					count++;
			}

			if (count > sizeOfN / 2) {
				totalSum += sizeOfN - count;
			}
			else {
				totalSum += count;
			}
		}

		if (i + 1 == M)
			continue;

		front = num;
		qu[front] = 0;
		sizeOfN--;
		while (qu[front] == 0) {
			front++;
			if (front > N)
				front = 1;
		}
	}

	cout << totalSum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		qu[i] = i;
	}

	solve(N, M);

	return 0;
}