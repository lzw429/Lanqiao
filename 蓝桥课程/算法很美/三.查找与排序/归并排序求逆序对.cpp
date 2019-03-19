//
// Created by syh on 19-3-19.
//

/*
Sample Input

4
4 2 8 0 3
10 0 1 2 3 4 5 6 7 8 9
6 -42 23 6 28 -100 65537
5 0 0 0 0 0
Sample Output

Scenario #1:
3

Scenario #2:
0

Scenario #3:
5

Scenario #4:
0

 */

// POJ 1804
#include <iostream>
#include <vector>

using namespace std;

const int maxm = 1005;
int cnt; // 逆序对计数

/**
 * 归并arr的两个子数组
 * 第一个子数组是 arr[l...mid]
 * 第二个子数组是 arr[mid+1...r]
 */
void merge(int nums[], int left, int mid, int right) {
    int i, j, k;
    int len1 = mid - left + 1;
    int len2 = right - mid;

    // 创建临时数组
    int L[maxm], R[maxm];

    // 将数组复制到临时数组
    for (i = 0; i < len1; i++)
        L[i] = nums[left + i];
    for (j = 0; j < len2; j++)
        R[j] = nums[mid + 1 + j];

    // 将临时数组归并到 nums[l..r]
    i = j = 0;
    k = left;
    while (i < len1 && j < len2) {
        if (L[i] <= R[j]) nums[k++] = L[i++];
        else {
            nums[k++] = R[j++];
            cnt += (len1 - i); // 逆序对计数
        }
    }

    while (i < len1) nums[k++] = L[i++];
    while (j < len2) nums[k++] = R[j++];
}

void mergeSort(int nums[], int left, int right) {
    if (left < right) { // 切记条件
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    for (int s = 1; s <= n; s++) {
        cnt = 0;
        int m;
        cin >> m;
        int nums[maxm] = {};
        for (int i = 0; i < m; i++) {
            cin >> nums[i];
        }
        mergeSort(nums, 0, m - 1);
        cout << "Scenario #" << s << ":" << endl;
        cout << cnt << endl << endl; // 当心 Presentation Error
    }
}
