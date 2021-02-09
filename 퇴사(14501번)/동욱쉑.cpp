#include<iostream>
#include <algorithm>
using namespace std;

int n;
int meet[2][16];
int dp[16];

int meeting(int date) {
	if (date > n) return 0;

	int& ret = dp[date];
	if (ret != -1) return ret;


	int& T = meet[0][date];
	int& P = meet[1][date];

	int cost = 0;
	if (date + 1 <= n + 1) 
		cost = max(cost, meeting(date + 1));
	if (date + T <= n + 1)
		cost = max(cost, meeting(date + T) + P);

	return ret = cost;
}

int main(void) {
	ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	meet[0][0] = 1;
	meet[1][0] = 0;
	for (int i = 0; i <= n; i++) 
		dp[i] = -1;

	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < 2; j++) 
			cin >> meet[j][i];

	cout << meeting(0);

	return 0;
}