#include <iostream>
#include <map>
using namespace std;

int N, M;
map<string, string> info;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string id, pw;
		cin >> id >> pw;
		info.insert({ id, pw });
	}
}

void solve() {
	for (int i = 0; i < M; i++) {
		string id;
		cin >> id;
		cout << info.find(id)->second << "\n";
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