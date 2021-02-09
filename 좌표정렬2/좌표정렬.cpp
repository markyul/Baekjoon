#include <iostream>
#include <algorithm>
using namespace std;

struct position {
	int x;
	int y;
};

int N;
position pos[100000];

bool compare(position a, position b) {
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y < b.y;
}

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> pos[i].x >> pos[i].y;
	}
}

void solve() {
	sort(pos, pos + N, compare);

	for (int i = 0; i < N; i++) {
		cout << pos[i].x << " " << pos[i].y << "\n";
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