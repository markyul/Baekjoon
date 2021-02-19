#include <iostream>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<int, int> cards;
int find_cards[500001];

void input() {
	int data;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> data;

		if (cards.find(data) == cards.end())
			cards.insert(make_pair(data, 1));
		else
			cards[data]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> find_cards[i];
	}
}

void solve() {
	for (int i = 0; i < M; i++) {
		if (cards.find(find_cards[i]) == cards.end())
			cout << 0 << " ";
		else
			cout << cards[find_cards[i]] << " ";
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