//
// Created by syh on 19-3-18.
//


// 本题涉及完全背包问题，使用了扩展欧几里德算法的推论

#include <iostream>

using namespace std;

int n;
int g; // 最大公约数
int len = 0;
const int maxn = 101;
int nums[maxn];
bool f[maxn * maxn]; // 能否凑出，最大的凑不出的数不会超过 maxn * maxn - 2 * maxn

int gcd(int a, int b) {
    if (!b)return a;
    return gcd(b, a % b);
}

int main() {
    f[0] = true;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        if (i == 1)
            g = nums[i];
        else g = gcd(g, nums[i]);

        for (int j = 0; j < maxn * maxn; ++j) {
            if (f[j]) {
                f[j + nums[i]] = true;
            }
        }
    }

    if (g != 1) { // 如果所有数的 gcd 不为1，则有无穷个数凑不出
        cout << "INF" << endl;
        return 0;
    }

    // 统计个数
    for (int i = 0; i < maxn * maxn; i++) {
        if (!f[i])
            len++;
    }
    cout << len << endl;
    return 0;
}