#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string notHear[500000], notSee[500000];
vector<string> answer;
int N, M;
int answerCount = 0;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> notHear[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> notSee[i];
	}
}

void solve() {
	int next = 0;
	sort(notHear, notHear + N);
	sort(notSee, notSee + M);

	for (int i = 0; i < N; i++) {
		for (int j = next; j < M; j++) {
			if (notHear[i].compare(notSee[j]) == 0) {
				next = j;
				answerCount++;
				answer.push_back(notHear[i]);
				break;
			}
			else if (notHear[i].compare(notSee[j]) < 0) {
				break;
			}
			else {
				next = j;
			}
		}
	}

	cout << answerCount << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
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