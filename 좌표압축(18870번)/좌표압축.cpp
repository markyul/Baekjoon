#include <iostream>
#include <algorithm>
using namespace std;

int N, location[1000000], copyLocation[1000000], pressure[1000000];
int index = 0;

// 좌표 압축시키는 함수
void pressLocation() {
	
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			pressure[index] = copyLocation[i];
			index++;
		}
		else if (copyLocation[i - 1] != copyLocation[i]) {
			pressure[index] = copyLocation[i];
			index++;
		}
	}
}

void output() {
	for (int i = 0; i < N; i++) {
		int start = 0;
		int mid = index / 2;
		int end = index - 1;
		while (1) {
			if (location[i] == pressure[mid]) {
				cout << mid << " ";
				break;
			}
			else if (location[i] < pressure[mid]) {
				end = mid - 1;
				mid = (start + mid) / 2;
			}
			else {
				start = mid + 1;
				mid = (mid + end) / 2 + 1;
			}
		}
		
	}
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> location[i];
		copyLocation[i] = location[i];
	}
}

void solve() {
	sort(copyLocation, copyLocation + N);

	pressLocation();
	output();
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}