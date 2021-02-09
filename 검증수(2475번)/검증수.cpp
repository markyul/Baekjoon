#include<iostream>
using namespace std;

int sum = 0;
void input() {
	int num;

	for (int i = 0; i < 5; i++) {
		cin >> num;
		sum += num * num;
	}
}

int solve() {
	return sum % 10;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	cout << solve() << endl;

	return 0;
}