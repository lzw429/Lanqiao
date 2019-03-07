/*
神奇算式

    由4个不同的数字，组成的一个乘法算式，它们的乘积仍然由这4个数字组成。

    比如：

210 x 6 = 1260
8 x 473 = 3784
27 x 81 = 2187

    都符合要求。

    如果满足乘法交换律的算式算作同一种情况，那么，包含上边已列出的3种情况，一共有多少种满足要求的算式。

    请填写该数字，通过浏览器提交答案，不要填写多余内容（例如：列出所有算式）。
 */

#include <iostream>
#include <algorithm>

using namespace std;

int comb(int a, int b, int c, int d) {
    return 1000 * a + 100 * b + 10 * c + d;
}

int comb(int a, int b, int c) {
    return 100 * a + 10 * b + c;
}

int comb(int a, int b) {
    return 10 * a + b;
}

bool check(int num, int a, int b, int c, int d) {
    bool digit[12] = {};
    digit[a] = digit[b] = digit[c] = digit[d] = true;
    for (int i = 1; i <= 4; i++) {
        int last = num % 10;
        num /= 10;
        if (digit[last]) { digit[last] = false; }
        else return false;
    }
    return true;
}

int main() {
    // 10个数字中选4个数字
    int cnt = 0;
    for (int i = 0; i <= 6; i++) {
        for (int j = i + 1; j <= 7; j++) {
            for (int k = j + 1; k <= 8; k++) {
                for (int l = k + 1; l <= 9; l++) {
                    int nums[6] = {i, j, k, l};
                    do {
                        int product1 = nums[0] * comb(nums[1], nums[2], nums[3]); // 一位数乘三位数
                        if (check(product1, i, j, k, l) && nums[0] != 0 && product1 > 999) {
                            cnt++;
                            cout << nums[0] << " * " << nums[1] << nums[2] << nums[3] << " = " << product1 << endl;
                        }
                        int frontTwo = comb(nums[0], nums[1]);
                        int backTwo = comb(nums[2], nums[3]);
                        int product2 = frontTwo * backTwo; // 两位数乘两位数，确保被乘数小于等于乘数
                        if (frontTwo <= backTwo && check(product2, i, j, k, l) && frontTwo > 9 && backTwo > 9 &&
                            product2 > 999) {
                            cnt++;
                            cout << nums[0] << nums[1] << " * " << nums[2] << nums[3] << " = " << product2 << endl;
                        }
                    } while (next_permutation(nums, nums + 4)); // [nums, nums+4)
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
