#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int answer = 0;

	cin >> N;

	answer = N / 5 + N / 25 + N / 125;

	cout << answer << endl;

	return 0;
}