#include <iostream>
#include <algorithm>
using namespace std;
#define ALPHABET 26
#define ASCII_A 65
#define ALPHA_INTERVAL 32

string word;
int alphabet_count[ALPHABET] = { 0, };

bool sorting(int a, int b) {
	return a > b;
}

void input() {
	cin >> word;
}

char solve() {
	int max_index = 0;
	char max_alpha;
	// 소문자 -> 대문자, 알파벳 수 세기
	for (int i = 0; i < word.size(); i++) {
		if ((int)word[i] > (int)'Z') {
			word[i] = word[i] - ALPHA_INTERVAL;
		}

		alphabet_count[(int)word[i] - ASCII_A]++;
	}
	// 가장 많은 알파벳 찾기
	for (int i = 1; i < ALPHABET; i++) {
		if (alphabet_count[i] > alphabet_count[max_index]) {
			max_index = i;
		}
	}
	max_alpha = (char)(ASCII_A + max_index);
	
	sort(alphabet_count, alphabet_count + ALPHABET, sorting);

	if (alphabet_count[0] == alphabet_count[1])
		return '?';
	else
		return max_alpha;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	cout << solve() << endl;

	return 0;
}