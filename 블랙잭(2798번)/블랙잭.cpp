#include <iostream>
using namespace std;

int n, black;
int card[100];

void input() {
	cin >> n >> black;
	
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
}

void solve() {
	int sum = 0;
	int max = 0;
	int sec = 1;
	int thr = 2;

	for (int first = 0; first < n - 2; first++) {
		for ( ; sec < n - 1; sec++) {
			for ( ; thr < n; thr++) {
				sum = card[first] + card[sec] + card[thr];
				if (sum <= black && sum > max)
					max = sum;
			}
			thr = sec + 2;
		}
		sec = first + 2;
		thr = sec + 1;
	}

	cout << max << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}