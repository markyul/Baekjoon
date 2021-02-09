#include <iostream>
#include <cmath>
using namespace std;

int a, b, c;

void input() {
	cin >> a >> b >> c;
}

void solve() {
	int long_side, side1, side2;

	// 가장 긴 변 찾기
	if (a > b) {
		side1 = b;
		if (a > c) {
			long_side = a;
			side2 = c;
		}
		else {
			long_side = c;
			side2 = a;
		}
	}
	else if (a < b) {
		side1 = a;
		if (b > c) {
			long_side = b;
			side2 = c;
		}
		else {
			long_side = c;
			side2 = b;
		}
	}

	// 직각삼각형 구분
	if (pow(long_side, 2) == pow(side1, 2) + pow(side2, 2))
		cout << "right" << endl;
	else
		cout << "wrong" << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	while (a != 0) {
		solve();
		input();
	}

	return 0;
}