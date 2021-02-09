#include <iostream>
using namespace std;

struct person {
	int weight;
	int height;
	int rank = 1;
};

int N;
person body[50];


void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> body[i].weight >> body[i].height;
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			
			if (body[i].weight < body[j].weight && body[i].height < body[j].height) {
				body[i].rank++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << body[i].rank << " ";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}