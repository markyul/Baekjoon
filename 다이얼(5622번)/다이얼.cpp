#include <iostream>
using namespace std;

string word;

int dialNum(char dial) {
	if ((int)dial < 68 && (int)dial > 64) // A,B,C
		return 2;
	else if ((int)dial < 71) // D,E,F
		return 3;
	else if ((int)dial < 74) // G,H,I
		return 4;
	else if ((int)dial < 77) // J,K,L
		return 5;
	else if ((int)dial < 80) // M,N,O
		return 6;
	else if ((int)dial < 84) // P,Q,R,S
		return 7;
	else if ((int)dial < 87) // T,U,V
		return 8;
	else if ((int)dial < 91) // W,X,Y,Z
		return 9;
	else
		return 0;
}

void input() {
	cin >> word;
}

void solve() {
	int sum = 0;

	for (int i = 0; i < word.size(); i++) {
		sum += dialNum(word[i]);
	}
	sum += word.size();
	cout << sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}