#include <iostream>
using namespace std;

int N;
int minNum = 1000000001;
int maxNum = -1000000001;
int numbers[11];
int operators[4];

// 최소 값과 최대 값을 구분하는 함수
void minAndMax(int result) {
	if (result > maxNum)
		maxNum = result;
	if (result < minNum)
		minNum = result;
}

// 연산자에 따라 계산
int calculation(int i, int count, int result) {
	switch (i) {
		case 0:
			result = result + numbers[count + 1];
			break;
		case 1:
			result = result - numbers[count + 1];
			break;
		case 2:
			result = result * numbers[count + 1];
			break;
		case 3:
			result = result / numbers[count + 1];
			break;
		default:
			break;
	}

	return result;
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}
}

void solve(int count, int result) {
	if (count == N - 1) {
		minAndMax(result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i] > 0) {
			operators[i]--;
			solve(count + 1, calculation(i, count, result));
			operators[i]++;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve(0, numbers[0]);

	cout << maxNum << "\n" << minNum;

	return 0;
}