#include <iostream>
#include <vector>
using namespace std;

vector<string> words;

void input() {
	int N;
	string word;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> word;
		words.push_back(word);
	}
}

void solve() {
	vector<char> alphabet;
	string word;
	int count = 0;

	for (int i = 0; i < words.size(); i++) {
		word = words[i];
		bool endFlag = false;
		alphabet.clear();
		for (int j = 0; j < word.size(); j++) {
			// 첫 알파벳은 바로 저장
			if (j == 0) {
				alphabet.push_back(word[j]);
				continue;
			}
			// 앞 알파벳과 현재 알파벳이 같으면 다음 알파벳으로
			if (word[j] == word[j - 1])
				continue;
			else {	// 스택에서 같은 알파벳 찾기
				for (int k = 0; k < alphabet.size(); k++) {
					if (alphabet[k] == word[j]) {
						endFlag = true;
						break;
					}
				}
				// endflag가 true이면 다음 단어
				if (endFlag)
					break;
				else {
					alphabet.push_back(word[j]);
					continue;
				}
			}
		}
		// endFlag가 false이면 그룹단어
		if (!endFlag)
			count++;
	}

	cout << count;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}