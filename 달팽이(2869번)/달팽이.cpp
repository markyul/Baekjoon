#include <iostream>
using namespace std;

int a, b, v;

void input() {
	cin >> a >> b >> v;
}

void solve() {
	int day = 1;
	int diff = a - b;
	v = v - a;
	
	if (v % diff == 0)
		day += v / diff;
	else
		day += (v / diff) + 1;

	cout << day << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}