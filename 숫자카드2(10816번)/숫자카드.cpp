/*
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int cards[500001];
int find_cards[500001];

int lower_bound(int find_card) {
	int start = -1;
	int end = N;
	int mid;

	while (start + 1 < end) {
		mid = (start + end) / 2;
		if (cards[mid] < find_card) {
			start = mid;
		}
		else
			end = mid;
	}

	return end;
}

int upper_bound(int find_card) {
	int start = -1;
	int end = N;
	int mid;

	while (start + 1 < end) {
		mid = (start + end) / 2;
		if (cards[mid] <= find_card)
			start = mid;
		else
			end = mid;
	}

	return end;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> find_cards[i];
	}
}

void solve() {
	int upper, lower, count;
	sort(cards, cards + N);

	for (int i = 0; i < M; i++) {
		upper = upper_bound(find_cards[i]);
		lower = lower_bound(find_cards[i]);
		count = upper - lower;

		cout << count << " ";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}
*/