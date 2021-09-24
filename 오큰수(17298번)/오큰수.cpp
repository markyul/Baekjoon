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
			// [i-1]기준 오른쪽 수가 더 크면 stack에 저장 후 리턴
			st.push_back(arr[i]);
			answer[i - 1] = arr[i];
		}
		else {
			while (1) {
				// stack이 비어있으면 -1 리턴
				if (st.empty()) {
					answer[i - 1] = -1;
					break;
				}
				// stack의 수가 더 크면 리턴
				if (st.back() > arr[i - 1]) {
					answer[i - 1] = st.back();
					break;
				}
				else	// arr[i-1]보다 작거나 같으면 stack -> pop
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