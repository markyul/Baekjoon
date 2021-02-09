#include <iostream>
#include <cmath>
#define ASCII 96
#define MOD 1234567891
using namespace std;

int length;
string word;

long long my_pow(int num) {
	long long result = 1;
	for (int i = 0; i < num; i++) {
		result = (result * 31) % MOD;
	}
	return result;
}

void input() {
	cin >> length;
	cin >> word;
}

void solve() {
	long long hash = 0;

	for (int i = 0; i < length; i++) {
		hash += (word[i] - ASCII) * my_pow(i);
	}
	hash = hash % MOD;
	
	cout << hash << endl;
	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}