#include <iostream>
using namespace std;

int h, w, n;

void input() {
	cin >> h >> w >> n;
}

void solve() {
	int floor, room_num, num;

	floor = n % h;
	num = (n / h) + 1;

	if (floor == 0)
		num--;
	if (floor == 0)
		floor = h;

	room_num = floor * 100 + num;

	cout << room_num << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;

	for (int i = 0; i < TC; i++) {
		input();
		solve();
	}

	return 0;
}