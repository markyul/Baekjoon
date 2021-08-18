#include <iostream>
using namespace std;

int DP[21][21][21];
bool flag = true; // false가 되면 반복 탈출

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20) {
		if (DP[20][20][20] != 0)
			return DP[20][20][20];
		else {
			DP[20][20][20] = w(20, 20, 20);
			return DP[20][20][20];
		}
	}
	else if (a < b && b < c) {
		if (DP[a][b][c] != 0)
			return DP[a][b][c];
		else {
			DP[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
			return DP[a][b][c];
		}
	}
	else {
		if (DP[a][b][c] != 0)
			return DP[a][b][c];
		else {
			DP[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
			return DP[a][b][c];
		} 
	}
}

void input() {
	int a, b, c;
	int result;

	cin >> a >> b >> c;

	if (a == -1 && b == -1 && c == -1)
	{
		flag = false;
		return;
	}

	result = w(a, b, c);

	cout << "w(" << a << ", " << b << ", " << c <<") = " << result << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (flag) {
		input();
	}

	return 0;
}