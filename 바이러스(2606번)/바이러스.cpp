#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
bool visit[101];
int answer = 0;

void input() {
	int com, pair;

	cin >> com >> pair;

	for (int i = 0; i <= com; i++) {
		vector<int> temp;
		temp.push_back(i);
		graph.push_back(temp);
	}

	for (int i = 0; i < pair; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void solve(int n) {
	visit[n] = true;
	if (n != 1)
		answer++;

	for (int i = 1; i < graph[n].size(); i++) {
		if (visit[graph[n][i]] == false)
			solve(graph[n][i]);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve(1);

	cout << answer;

	return 0;
}