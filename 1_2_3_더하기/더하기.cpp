#include<iostream>
using namespace std;
#define MAX 11

int case_num[MAX] = { 0 };
int cnt = 0;

void DP() {
	for (int i = 1; i < MAX; i++) {
		if (i <= 3)
			cnt = 1;
		for (int j = 1; j <= 3; j++) {
			if (i - j == 0)
				break;
			cnt += case_num[i - j];
		}
		case_num[i] = cnt;
		cnt = 0;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC, n;

	cin >> TC;

	DP();

	for (int i = 0; i < TC; i++) {
		cin >> n;
		cout << case_num[n] << "\n";
	}
}