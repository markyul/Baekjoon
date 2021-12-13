#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int TC, N, answer;
string costumes[30];
map<string, int> kinds;


bool check(string kind) {
	map<string, int>::iterator it;

	for (it = kinds.begin(); it != kinds.end(); it++) {
		if (it -> first == kind) {
			it -> second++;
			return false;
		}
	}

	return true;
}

void input() {
	string name, kind;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> name >> kind;

		costumes[i] = kind;

		if (check(kind)) {
			kinds.insert(make_pair(kind, 1));
		}	
	}
}

void solve() {

	map<string, int>::iterator it;

	for (it = kinds.begin(); it != kinds.end(); it++) {
		answer *= (it->second + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;

	for (int i = 0; i < TC; i++) {
		answer = 1;

		input();
		solve();
		kinds.clear();
		cout << answer - 1 << "\n";
	}

	return 0;
}