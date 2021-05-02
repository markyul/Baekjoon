#include <iostream>
using namespace std;

string word;

int croatiaAlpha(char word_char, int index) {
	if (word_char == '=' || word_char == '-') {
		if (index > 1 && word[index - 1] == 'z' && word[index - 2] == 'd')
			return 2;
		else
			return 1;
	}
	else if (word_char == 'j') {
		if (word[index - 1] == 'l' || word[index - 1] == 'n')
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

void input() {
	cin >> word;
}

void solve() {
	int total_alpha = word.size();

	for (int i = 1; i < word.size(); i++) {
		total_alpha -= croatiaAlpha(word[i], i);
	}

	cout << total_alpha;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}