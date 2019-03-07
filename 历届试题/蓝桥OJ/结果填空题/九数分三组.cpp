/*
九数分三组

1~9的数字可以组成3个3位数，设为：A,B,C,  现在要求满足如下关系：
B = 2 * A
C = 3 * A

请你写出A的所有可能答案，数字间用空格分开，数字按升序排列。

注意：只提交A的值，严格按照格式要求输出。
 */

#include <iostream>

using namespace std;

void DFS(int nums[], int step) {
    if (step == 9) {
        int A = nums[0] * 100 + nums[1] * 10 + nums[2];
        int B = nums[3] * 100 + nums[4] * 10 + nums[5];
        int C = nums[6] * 100 + nums[7] * 10 + nums[8];
        if (B == 2 * A && C == 3 * A)
            cout << A << endl;
    }
    for (int j = step; j <= 8; j++) {
        swap(nums[step], nums[j]);
        DFS(nums, step + 1);
        swap(nums[step], nums[j]);
    }
}

int main() {
    int nums[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    DFS(nums, 0);
    return 0;
}
