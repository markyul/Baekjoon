#include <iostream>
using namespace std;

int x, y, w, h;

int distance(int a, int b) {
	if (a <= b / 2)
		return a;
	else
		return b - a;
}

void input() {
	cin >> x >> y >> w >> h;
}

void solve() {
	int distanceX, distanceY;

	distanceX = distance(x, w);
	distanceY = distance(y, h);

	if (distanceX < distanceY)
		cout << distanceX << endl;
	else
		cout << distanceY << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}