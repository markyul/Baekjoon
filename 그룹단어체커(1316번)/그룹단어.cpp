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
			// ù ���ĺ��� �ٷ� ����
			if (j == 0) {
				alphabet.push_back(word[j]);
				continue;
			}
			// �� ���ĺ��� ���� ���ĺ��� ������ ���� ���ĺ�����
			if (word[j] == word[j - 1])
				continue;
			else {	// ���ÿ��� ���� ���ĺ� ã��
				for (int k = 0; k < alphabet.size(); k++) {
					if (alphabet[k] == word[j]) {
						endFlag = true;
						break;
					}
				}
				// endflag�� true�̸� ���� �ܾ�
				if (endFlag)
					break;
				else {
					alphabet.push_back(word[j]);
					continue;
				}
			}
		}
		// endFlag�� false�̸� �׷�ܾ�
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