#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string plus;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> plus;
		cout << (plus[0] - '0') + (plus[2] - '0') << "\n";
	}
}