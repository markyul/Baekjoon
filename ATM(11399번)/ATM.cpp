#include <iostream>
#include <algorithm>
using namespace std;

int people[1000];
int N;
int answer = 0;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> people[i];
	}
}

void solve() {
	sort(people, people + N);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += people[i];
		answer += sum;
	}

	cout << answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}