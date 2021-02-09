#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	vector<int> arr;
	int n, diff;
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> n;
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i];
	}
	diff = sum - 100;

	for (int i = 0; i < arr.size(); i++) {
		bool end = false;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[i] + arr[j] == diff) {
				arr.erase(arr.begin() + i);
				arr.erase(arr.begin() + j - 1);
				end = true;
				break;
			}
		}
		if (end)
			break;
	}

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}