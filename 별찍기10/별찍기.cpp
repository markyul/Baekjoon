#include <iostream>
using namespace std;

int N;
bool stars[2200][2200];	// false °¡ *, true°¡ " "

void star(int n, int i, int j) {
	if (n / 3 == 0)
		return;

	if ((i / (n / 3)) % 3 == 1 && (j / (n / 3)) % 3 == 1)
		stars[i][j] = true;
	else
		star(n / 3, i, j);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			star(N, i, j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (stars[i][j] == 0)
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}