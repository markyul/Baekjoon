#include<iostream>

using namespace std;

int Gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return Gcd(b, a % b);
	}
}

int Lcm(int a, int b) {
	int gcd = Gcd(a, b);

	return a * b / gcd;
}

int main(void) {
	int x, y;
	int gcd_ans, lcm_ans;

	cin >> x >> y;

	gcd_ans = Gcd(x, y);
	lcm_ans = Lcm(x, y);

	cout << gcd_ans << "\n";
	cout << lcm_ans;
}