#include<iostream>
#include<cmath>
using namespace std;

void hanoi(int n, int start, int arrive, int waypoint) {
	if (n == 1)
		cout << start << " " << arrive << "\n";
	else {
		hanoi(n - 1, start, waypoint, arrive);
		cout << start << " " << arrive << "\n";
		hanoi(n - 1, waypoint, arrive, start);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	cout << (int)(pow(2, N) - 1) << "\n";
	hanoi(N, 1, 3, 2);

	return 0;
}