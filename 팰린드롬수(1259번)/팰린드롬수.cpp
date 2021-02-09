#include <iostream>
using namespace std;

string n;

void input() {
	cin >> n;
}

void solve() {
	int start = 0;
	int end = n.size() - 1;
	string answer;

	while (1) {
		if (start >= end) {
			answer = "yes";
			break;
		}
		if (n[start] != n[end]) {
			answer = "no";
			break;
		}
		start++;
		end--;
	}

	cout << answer << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	while (n != "0") {
		solve();
		input();
	}

	return 0;
}