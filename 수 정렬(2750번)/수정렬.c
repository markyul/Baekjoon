#include <stdio.h>

int arr[1000000];
//Äü Á¤·Ä
void sort(int left, int right, int* arr) {
	int pivot = left;
	int mleft = pivot;
	int tmp = 0;
	int mright = left + 1;

	if (right - left <= 0)
		return;

	for (; mright <= right; mright++) {
		if (arr[pivot] > arr[mright]) {
			++mleft;
			tmp = arr[mleft];
			arr[mleft] = arr[mright];
			arr[mright] = tmp;
		}
	}
	tmp = arr[left];
	arr[left] = arr[mleft];
	arr[mleft] = tmp;

	pivot = mleft;

	sort(left, pivot - 1, arr);
	sort(pivot + 1, right, arr);
}

int main(void)
{
	int right;
	int left = 0;

	scanf_s("%d", &right);
	
	for (int i = 0; i < right; i++) {
		scanf_s("%d", &arr[i]);
	}

	sort(left, right - 1, arr);

	for (int j = 0; j < right; j++) {
		printf("%d\n", arr[j]);
	}

	return 0;

}