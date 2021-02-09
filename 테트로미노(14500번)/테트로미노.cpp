#include<iostream>
using namespace std;
#define MAX 501

int paper[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int sum_max = 0;
int N, M;

void DFS(int cnt, int y, int x, int sum) {
	if (cnt == 4) {
		if (sum_max < sum)
			sum_max = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < M && nx >= 0 && ny < N && ny >= 0 && !visit[ny][nx]) {
			visit[ny][nx] = true;
			DFS(cnt + 1, ny, nx, sum + paper[ny][nx]);
			visit[ny][nx] = false;
		}
	}

}

void T(int y, int x, int sum) {
	bool right = false, left = false, bot = false, top = false;
	if (x + 1 < M)
		right = true;
	if (x - 1 >= 0)
		left = true;
	if (y + 1 < N)
		bot = true;
	if (y - 1 >= 0)
		top = true;

	//ㅏ 모양
	if (right && bot && top) {
		if(sum_max < (sum + paper[y][x + 1] + paper[y + 1][x] + paper[y - 1][x]))
			sum_max = sum + paper[y][x + 1] + paper[y + 1][x] + paper[y - 1][x];
	}
	//ㅜ 모양
	if (right && bot && left) {
		if (sum_max < (sum + paper[y][x + 1] + paper[y + 1][x] + paper[y][x - 1]))
			sum_max = sum + paper[y][x + 1] + paper[y + 1][x] + paper[y][x - 1];
	}
	//ㅓ 모양
	if (top && bot && left) {
		if (sum_max < (sum + paper[y - 1][x] + paper[y + 1][x] + paper[y][x - 1]))
			sum_max = sum + paper[y - 1][x] + paper[y + 1][x] + paper[y][x - 1];
	}
	//ㅗ 모양
	if (top && right && left) {
		if (sum_max < (sum + paper[y - 1][x] + paper[y][x + 1] + paper[y][x - 1]))
			sum_max = sum + paper[y - 1][x] + paper[y][x + 1] + paper[y][x - 1];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	//배열 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> paper[i][j];
		}
	}
	//탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = true;
			DFS(1, i, j, paper[i][j]);
			T(i, j, paper[i][j]);
			visit[i][j] = false;
		}
	}

	cout << sum_max;
}