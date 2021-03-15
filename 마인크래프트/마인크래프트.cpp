#include <iostream>
#define DELETE_TIME 2
#define INSERT_TIME 1
using namespace std;

int N, M, B, copy_B, time;
int min_time = -1;
int ans_height = 0;
int min_floor = 256;
int max_floor = 0;
int land[501][501];

void deleteOrInsert(int diff) {
	if (diff >= 0) {
		time += diff * DELETE_TIME;
		copy_B += diff;
	}
	else {
		time += (-diff) * INSERT_TIME;
		copy_B += diff;
	}
}

void minTime(int diff_height) {
	if (min_time == -1 || min_time >= time) {
		if (min_time == time) {
			if (ans_height < diff_height)
				ans_height = diff_height;
		}
		else {
			min_time = time;
			ans_height = diff_height;
		}
	}
}

void input() {
	int height;
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> height;
			land[i][j] = height;
			if (height < min_floor)
				min_floor = height;
			if (height > max_floor)
				max_floor = height;
		}
	}
}

void solve() {
	for (int diff_height = min_floor; diff_height <= max_floor; diff_height++) {
		time = 0;
		copy_B = B;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int diff = land[i][j] - diff_height;
				deleteOrInsert(diff);	// time과 copy_B가 만들어짐
			}
		}
		// copy_B가 음수이면 블록이 없는데 쌓았으므로 오류
		if (copy_B < 0) {
			continue;
		}
		// 시간이 적게 걸렸는가?
		minTime(diff_height);
	}
	cout << min_time << " " << ans_height;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}