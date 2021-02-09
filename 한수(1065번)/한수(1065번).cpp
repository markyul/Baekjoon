#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

int solve(string n) {
	int count = 99;
	int n_all = atoi(n.c_str());

	if (n_all < 100)
		return n_all;
	else {
		while (n_all > 99) {
			n = to_string(n_all);

			int n_first = n[0] - '0';
			int n_second = n[1] - '0';
			int n_third = n[2] - '0';

			if (n_first - n_second == n_second - n_third)
				count++;

			n_all--;
		}
		return count;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	int answer;

	cin >> N;

	answer = solve(N);

	cout << answer << endl;
}