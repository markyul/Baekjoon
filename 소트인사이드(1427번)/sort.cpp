#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> answer;

bool compare(int a, int b) {
	return a > b;
}

void solve(int N) {
	while (N != 0) {
		answer.push_back(N % 10);
		N = N / 10;
	}

	sort(answer.begin(), answer.end(), compare);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	solve(N);

	return 0;
}