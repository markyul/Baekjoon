#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	vector<int> arr(10);
	vector<int> remainder(10);
	int num = 42;
	int count = 1;
	int dif;

	for (int i = 0; i < arr.size(); i++) {
		cin >> arr[i];
	}
	//나머지 저장
	for (int i = 0; i < remainder.size(); i++) {
		remainder[i] = (arr[i] % num);
	}

	sort(remainder.begin(), remainder.end());

	dif = remainder[0];
	for (int i = 1; i < remainder.size(); i++) {
		if (dif != remainder[i]) {
			count++;
			dif = remainder[i];
		}
	}

	cout << count;
}