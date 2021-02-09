#include <iostream>
using namespace std;

int scale[9] = { 0 };

void input() {
	for (int i = 1; i < 9; i++) {
		cin >> scale[i];
	}
}

void solve() {
	int count = 1;
	string answer;

	if (scale[1] == 1 && scale[8] == 8)
		answer = "ascending";
	if (scale[1] == 8 && scale[8] == 1)
		answer = "descending";

	while (count < 8) {
		int distance = scale[count] - scale[count + 1];
		if(distance > 1 || distance < -1){
			answer = "mixed";
			break;
		}
		count++;
	}

	cout << answer << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}