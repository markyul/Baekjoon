#include <iostream>
using namespace std;

int x, y;

int reverse(int a) {
	int num = 0;
	for (int i = 1; i <= 3; i++) {
		num = num * 10;
		num = num + (a % 10);
		a = a / 10;
	}

	return num;
}

void input() {
	cin >> x >> y;
}

void solve() {
	int num1, num2;
	num1 = reverse(x);
	num2 = reverse(y);

	if (num1 < num2)
		cout << num2 << endl;
	else
		cout << num1 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}