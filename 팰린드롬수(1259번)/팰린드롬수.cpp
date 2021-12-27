/*
#include <iostream>
using namespace std;

string n;

void input() {
	cin >> n;
}

void solve() {
	int start = 0;
	int end = n.size() - 1;
	string answer;

	while (1) {
		if (start >= end) {
			answer = "yes";
			break;
		}
		if (n[start] != n[end]) {
			answer = "no";
			break;
		}
		start++;
		end--;
	}

	cout << answer << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	while (n != "0") {
		solve();
		input();
	}

	return 0;
}
*/

#include <iostream>
using namespace std;

void input(char* arr) {
	cin >> arr;
}

void solve(char* arr, int length) {
	int start = 0;
	int end = length - 1;
	int flag = 0;
	while (start < end) {
		if (arr[start] != arr[end]) {
			flag = 1;
			break;
		}
		start++;
		end--;
	}

	if (flag == 0)
		cout << "yes" << "\n";
	else
		cout << "no" << "\n";
}

int getLength(char* arr) {
	for (int i = 0; i < 6; i++) {
		if (arr[i] == '\0')
			return i;
	}
	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int length = 0;
	 
	while (1) {
		char arr[6];
		input(arr);

		if (arr[0] == '0')
			break;

		length = getLength(arr);
		solve(arr, length);
	}

	return 0;
}