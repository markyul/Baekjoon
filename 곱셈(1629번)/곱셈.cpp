#include <iostream>
using namespace std;

long long A;
int B, C;
void input() {
	cin >> A >> B >> C;
}

long long recursion(long long base, int exponent) {
	base = base % C;

	if (exponent == 1)
		return base;

	if (exponent % 2 == 0)
		return (recursion(base * base, exponent / 2)) % C;
	else
		return (recursion(base, exponent / 2) % C) * (recursion(base, exponent - (exponent / 2)) % C);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long answer;

	input();
	answer = recursion(A, B) % C;

	cout << answer;

	return 0;
}