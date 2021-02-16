#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

string str;
vector<string> word;
stack<char> text;

bool balance(string c_str) {
	for (int i = 0; i < c_str.size(); i++) {
		if (c_str[i] == '(')
			text.push('(');
		else if (c_str[i] == '[')
			text.push('[');

		if (c_str[i] == ')') {
			if (text.size() == 0)
				return false;

			if (text.top() == '(')
				text.pop();
			else
				return false;
		}
		else if (c_str[i] == ']') {
			if (text.size() == 0)
				return false;

			if (text.top() == '[')
				text.pop();
			else
				return false;
		}
	}
	if (text.empty())
		return true;
	else
		return false;
}

void input() {
	while (1) {
		getline(cin, str, '.');
		if (str == "\n")
			break;
		word.push_back(str);
	}
}

void solve() {
	string copy_str;
	for (int i = 0; i < word.size(); i++) {
		copy_str = word[i];
		if (balance(copy_str))
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
		// stack clear
		while (!text.empty())
			text.pop();
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