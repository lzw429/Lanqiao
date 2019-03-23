//
// Created by syh on 19-3-14.
//


#include <stdio.h>

void swap(int a[], int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int partition(int a[], int p, int r) {
    int x = a[p]; // pivot
    int i = p; // pivot 位置，即首个被排序元素的前一位
    int j = r + 1; // 最后一个元素的后一位

    while (1) {
        while (i < r && a[++i] < x);
        while (a[--j] > x); // 隐含 j > p
        if (i >= j) break;
        swap(a, i, j);
    }
    swap(a, p, j); // 此行填空
    return j;
}

void quicksort(int a[], int p, int r) {
    if (p < r) {
        int q = partition(a, p, r); // q 是 pivot
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}


int main() {
    int i;
    int a[] = {5, 13, 6, 24, 2, 8, 19, 27, 6, 12, 1, 17};
    int N = 12;

    quicksort(a, 0, N - 1);

    for (i = 0; i < N; i++) printf("%d ", a[i]);
    printf("\n");


    int b[] = {43, 48, 12, 94, 72};
    N = 5;

    quicksort(b, 0, N - 1);

    for (i = 0; i < N; i++) printf("%d ", b[i]);
    printf("\n");

    return 0;
}