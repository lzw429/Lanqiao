//
// Created by syh on 19-3-18.
//


// 本题可直接暴力枚举
// 由于时限，必须使用二分搜索优化
#include <iostream>

using namespace std;

const int maxn = 100010;
int N, K;
int H[maxn], W[maxn];
int len;
int ans;

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> H[i] >> W[i]; // 高度和宽度
    }

    // 二分搜索
    int right = maxn; // 注意，并不是每块原有的巧克力都必须被切分
    int left = 1;

    while (left <= right) { // 二分搜索可以取等
        len = (left + right) / 2;
        int cnt = 0;
        // 判断 如果 len == mid 时能否满足 K 块的要求
        for (int i = 0; i < N; i++) {
            cnt += (H[i] / len) * (W[i] / len);
        }
        if (cnt >= K) { // 分割过多，len 可以更大
            ans = len;
            left = len + 1;
        } else
            right = len - 1;
    }

    cout << ans << endl;
    return 0;
}