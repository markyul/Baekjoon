#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int N, M;
map<string, int> collection;
string monsters[100001];

void answerNumber(string monster) {
	cout << collection.find(monster) -> second << "\n";
}

void answerMonster(int num) {
	cout << monsters[num] << "\n";
}

void input() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string monster;
		cin >> monster;
		
		collection.insert({ monster, i });
		monsters[i] = monster;
	}
}

void solve() {
	for (int i = 0; i < M; i++) {
		string question;
		int num = 0;
		
		cin >> question;

		// 숫자면 true, 문자면 false
		if (isdigit(question[0])) {
			num = stoi(question);
			answerMonster(num);
		}
		else {
			answerNumber(question);
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