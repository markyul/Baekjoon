#include<stdio.h>

void mergesort(int arr[], int p, int mid, int r) {
    int fIndex = p;
    int rIndex = mid + 1;
    int sIndex = p;
    int sortarr[30] = { 0 };
    while (fIndex <= mid && rIndex <= r) {
        if (arr[fIndex] < arr[rIndex]) {
            sortarr[sIndex] = arr[fIndex];
            fIndex++;
        }
        else {
            sortarr[sIndex] = arr[rIndex];
            rIndex++;
        }
        sIndex++;
    }
    if (fIndex > mid) {
        for (int i = rIndex; i <= r; i++) {
            sortarr[sIndex] = arr[i];
            sIndex++;
        }
    }
    else {
        for (int i = fIndex; i <= mid; i++) {
            sortarr[sIndex] = arr[i];
            sIndex++;
        }
    }
    for (int i = p; i <= r; i++) {
        arr[i] = sortarr[i];
    }
}


void merge(int arr[], int p, int r) {
    int mid;
    if (p < r) {
        mid = (p + r) / 2;
        merge(arr, p, mid);
        merge(arr, mid + 1, r);
        mergesort(arr, p, mid, r);
    }
}



int main() {
    int C[11], D[15], A[26];
    for (int i = 0; i < sizeof(C) / sizeof(int); i++) {
        scanf_s("%d", &C[i]);
    }
    for (int i = 0; i < sizeof(D) / sizeof(int); i++) {
        scanf_s("%d", &D[i]);
    }
    for (int i = 0; i < sizeof(A) / sizeof(int); i++) {
        if (i < sizeof(C) / sizeof(int)) {
            A[i] = C[i];
        }
        else {
            A[i] = D[i - sizeof(C) / sizeof(int)];
        }
    }
    printf("비정상적인 출력\n");
    merge(A, 5, 15);
    printf("[p=5 r=15]\n");
    for (int i = 0; i < 26; i++) {
        printf("%d ", A[i]);
    }
    puts("");
    merge(A, 2, 6);
    printf("[p=2 r=6]");
    for (int i = 0; i < 26; i++) {
        printf("%d ", A[i]);
    }
    puts("");
    merge(A, 15, 21);
    printf("[p=15 r=21]");
    for (int i = 0; i < 26; i++) {
        printf("%d ", A[i]);
    }
    puts("");
    printf("정상적인 출력\n");
    merge(A, 0, 25);
    printf("[p=0 r=25]");
    for (int i = 0; i < 26; i++) {
        printf("%d ", A[i]);
    }
}