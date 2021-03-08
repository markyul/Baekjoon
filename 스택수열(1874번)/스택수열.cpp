#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;
int sequence_arr[100000];
vector<char> answer_arr;
stack<int> stack_arr;
stack<int> copy_arr;

void input() {
	int n;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> n;
		sequence_arr[i] = n;
	}
}

void solve() {
	int count = 1;
	int sequence_idx = 0;
	int answer_idx = 0;

	while (count <= N) {
		if (stack_arr.empty()) {
			stack_arr.push(count);
			answer_arr.push_back('+');
			count++;
		}
		else if (stack_arr.top() == sequence_arr[sequence_idx]) {
			copy_arr.push(stack_arr.top());
			stack_arr.pop();
			sequence_idx++;
			answer_arr.push_back('-');
		}
		else {
			stack_arr.push(count);
			answer_arr.push_back('+');
			count++;
		}
	}

	while (!stack_arr.empty()) {
		if (stack_arr.top() == sequence_arr[sequence_idx]) {
			copy_arr.push(stack_arr.top());
			stack_arr.pop();
			sequence_idx++;
			answer_arr.push_back('-');
		}
		else {
			break;
		}
	}

	if (stack_arr.empty()) {
		for (int i = 0; i < answer_arr.size(); i++) {
			cout << answer_arr[i] << "\n";
		}
	}
	else {
		cout << "NO";
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