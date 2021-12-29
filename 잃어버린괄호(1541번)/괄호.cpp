#include <iostream>
#include <vector>
using namespace std;

string expression;
vector<int> total;

void solve() {
	int multi_10 = 1;
	int temp = 0;
	int sum = 0;
	int answer = 0;
	int length = expression.length() - 1;
	bool flag = false;

	for (int i = 0; i < expression.length(); i++) {
		char word[1] = { expression[i] };

		if (atoi(word) == 0 && word[0] != '0') {
			if (word[0] == '-')
			{
				if (flag) {
					sum -= temp;
					temp = 0;
				}
				else {
					flag = true;
					sum += temp;
					temp = 0;
				}
			}
			else {
				if (flag) {
					sum -= temp;
					temp = 0;
				}
				else {
					sum += temp;
					temp = 0;
				}
			}
		}
		else {
			temp = temp * 10 + atoi(word);
		}
	}

	if (flag) {
		sum -= temp;
	}
	else {
		sum += temp;
	}

	cout << sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> expression;

	solve();

	return 0;
}