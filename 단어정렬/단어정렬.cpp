#include <iostream>
#include <algorithm>
using namespace std;

int N;
string words[20000];

bool compare_size(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else {
		return a.size() < b.size();
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}
}

void solve() {
	sort(words, words + N, compare_size);

	cout << words[0] << endl;
	for (int i = 1; i < N; i++) {
		if (words[i] != words[i - 1]) {
			cout << words[i] << endl;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}