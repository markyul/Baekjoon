#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[1000000];
int answer[1000000];
vector<int> st;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solve() {
	answer[N - 1] = -1;

	for (int i = N - 1; i > 0; i--) {
		if (arr[i] > arr[i - 1]) {
			// [i-1]���� ������ ���� �� ũ�� stack�� ���� �� ����
			st.push_back(arr[i]);
			answer[i - 1] = arr[i];
		}
		else {
			while (1) {
				// stack�� ��������� -1 ����
				if (st.empty()) {
					answer[i - 1] = -1;
					break;
				}
				// stack�� ���� �� ũ�� ����
				if (st.back() > arr[i - 1]) {
					answer[i - 1] = st.back();
					break;
				}
				else	// arr[i-1]���� �۰ų� ������ stack -> pop
					st.pop_back();
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << answer[i] << " ";
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