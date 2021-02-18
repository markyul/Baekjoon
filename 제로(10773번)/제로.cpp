#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int N;

void input() {
	int n;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n;
		if (n == 0)
			st.pop();
		else
			st.push(n);
	}
}

void solve() {
	int sum = 0;

	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}

	cout << sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}