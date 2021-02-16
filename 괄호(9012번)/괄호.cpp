#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int N;
string str;
vector<string> word;
stack<char> text;

bool balance(string c_str) {
	for (int i = 0; i < c_str.size(); i++) {
		if (c_str[i] == '(')
			text.push('(');
		else if (c_str[i] == ')') {
			if (text.empty())
				return false;

			if (text.top() == '(')
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


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		cin >> str;

		if (balance(str))
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
		// stack clear
		while (!text.empty())
			text.pop();
	}

	return 0;
}