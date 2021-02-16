#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
double sum = 0;
int arr[500001];
int counting[8001];

// ������
void average() {
	double avr;
	double result;

	avr = sum / N;
	// �ݿø��� �ؾ��ؼ� �����Լ��� �̿��� �ݿø� ����
	result = floor(avr + 0.5);
	cout << result << "\n";
}
// �߾Ӱ�
void mid() {
	cout << arr[N / 2] << "\n";
}
// �ֺ�
void mode() {
	int result = 4001;
	int max = 0;
	for (int i = 0; i < 8001; i++) {
		if (counting[i] > max)
			max = counting[i];
	}

	for (int i = 0; i < 8001; i++) {
		if (counting[i] == max) {
			if(result > 4000)
				result = i - 4000;
			else {
				result = i - 4000;
				break;
			}

		}

	}
	cout << result << "\n";
}
// ����
void range() {
	int result;

	result = arr[N - 1] - arr[0];

	cout << result << "\n";
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		counting[arr[i] + 4000]++;
	}
}

void solve() {
	sort(arr, arr + N);

	average();
	mid();
	mode();
	range();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}