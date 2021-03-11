#include <iostream>
#include <queue>
using namespace std;

int TC, N, ans_idx;
queue<int> documents;

int MaxImportance() {
	int max = 0;
	queue<int> copy;

	copy = documents;

	while (!copy.empty()) {
		if (max < copy.front())
			max = copy.front();

		copy.pop();
	}

	return max;
}

void input() {
	int importance;
	cin >> N >> ans_idx;

	for (int i = 0; i < N; i++) {
		cin >> importance;
		documents.push(importance);
	}
}

void solve() {
	int max_importance = 0;
	int doc_count = 0;

	max_importance = MaxImportance();
	while (1) {
		if (documents.front() == max_importance) {
			if (ans_idx == 0) {
				cout << ++doc_count << "\n";
				break;
			}
			else {
				ans_idx--;
				doc_count++;
				documents.pop();
				max_importance = MaxImportance();
			}
		}
		else {
			documents.push(documents.front());
			documents.pop();

			if (ans_idx == 0)
				ans_idx = documents.size() - 1;
			else
				ans_idx--;
		}
	}

	while (!documents.empty()) {
		documents.pop();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;
	
	for (int i = 0; i < TC; i++) {
		input();
		solve();
	}

	return 0;
}