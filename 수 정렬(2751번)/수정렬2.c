#include <stdio.h>

int arr[1000000];
int sort[1000000];
//배열을 병합
void mergesort(int left, int half, int right, int* arr) {
	int mleft = left;
	int soleft = left;
	int mright = half + 1;
	//한쪽 배열이 비기전까지 반복
	while (mleft <= half && mright <= right) {
		if (arr[mleft] < arr[mright]) {
			sort[soleft] = arr[mleft];
			soleft++;
			mleft++;
		}
		else {
			sort[soleft] = arr[mright];
			soleft++;
			mright++;
		}
	}
	//한쪽 배열만 남았을때
	if (mright > right) {
		for (int i = mleft; i <= half; i++) {
			sort[soleft] = arr[i];
			soleft++;
		}
	}
	else {
		for (int j = mright; j <= right; j++) {
			sort[soleft] = arr[j];
			soleft++;
		}
	}

	for (int k = left; k <= right; k++) {
		arr[k] = sort[k];
	}
}
//배열을 분리
void halfarr(int left, int right, int* arr) {
	int half;

	if (left < right) {
		half = (left + right) / 2;
		halfarr(left, half, arr);
		halfarr(half + 1, right, arr);
		mergesort(left, half, right, arr);
	}
}

int main(void) {
	int n, value;
	int left = 0;

	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &value);
		arr[i] = value;
	}

	halfarr(left, n - 1, arr);

	for (int j = 0; j < n; j++) {
		printf("%d ", arr[j]);
	}

	return 0;
}