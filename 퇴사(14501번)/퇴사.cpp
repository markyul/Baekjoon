#include<iostream>
#include<vector>
using namespace std;

vector<int> T, P, maxi;
int N;
int maximum = 0;

void read() {
	int t, p;

	cin >> N;
	maxi.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> t >> p;
		T.push_back(t);
		P.push_back(p);
	}
}

int solve() {
	int index = N - 1;
	while (index >= 0) {
		if (index + T[index] > N) {
			maxi[index] = 0;
			if (index != N - 1) {
				if (maxi[index] > maximum)
					maximum = maxi[index];
				else
					maxi[index] = maximum;
			}
		}
		else if(index + T[index] == N) {
			maxi[index] = P[index];
			if (maxi[index] > maximum)
				maximum = maxi[index];
			else
				maxi[index] = maximum;
		}
		else {
			maxi[index] = P[index] + maxi[index + T[index]];
			if (maxi[index] > maximum)
				maximum = maxi[index];
			else
				maxi[index] = maximum;
		}

		index--;
	}


	return maximum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int answer;

	read();
	answer = solve();

	cout << answer << endl;
}