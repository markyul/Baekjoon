#include <iostream>
#include <vector>
using namespace std;

int N, M;
long long max_height = 0;
vector<long long> trees;

long long sumOfTrees(long long height) {
	long long sum = 0;

	for (int i = 0; i < trees.size(); i++) {
		if (trees[i] > height)
			sum += trees[i] - height;
	}
	return sum;
}

long long upperBound() {
	long long start = 0;
	long long end = max_height;
	long long mid;
	long long sum;

	while (start <= end) {
		mid = (start + end) / 2;
		sum = sumOfTrees(mid);

		if (sum >= M)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return start;
}

void input() {
	int num;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num;
		trees.push_back(num);
		if (max_height < num)
			max_height = num;
	}
}

void solve() {
	long long answer;

	answer = upperBound() - 1;

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