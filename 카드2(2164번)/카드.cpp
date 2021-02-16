#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> arr;

void input() {
	cin >> N;
	for (int i = 0; i < N + 1; i++) {
		arr.push_back(i);
	}
}

void solve() {
	int result = arr[1];
	int front = 2;
	int rear = arr.size();

	while (front < rear) {
		result = arr[front];
		arr.push_back(arr[front]);
		rear++;
		front += 2;
	}

	cout << result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}