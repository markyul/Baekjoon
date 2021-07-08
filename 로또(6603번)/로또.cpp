#include <iostream>
using namespace std;

int K = 1;
int S[13], lottoNum[6];

void lotto(int lottoIndex, int SIndex) {
	if (lottoIndex >= 6) {
		for (int i = 0; i < 6; i++) {
			cout << lottoNum[i] << " ";
		}
		cout << "\n";
	}
	else {
		lottoNum[lottoIndex] = S[SIndex];
		while (SIndex < K) {
			lotto(lottoIndex + 1, SIndex + 1);
			SIndex++;
			if (SIndex < K)
				lottoNum[lottoIndex] = S[SIndex];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (K != 0) {
		cin >> K;

		if (K != 0) {
			for (int i = 0; i < K; i++) {
				cin >> S[i];
			}
			lotto(0, 0);
			cout << "\n";
		}
		else
			break;
	}

	return 0;
}