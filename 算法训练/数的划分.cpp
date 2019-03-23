//
// Created by syh on 19-3-23.
//


/*
 * 问题描述
　　将整数n分成k份，且每份不能为空，任意两份不能相同(不考虑顺序)。
　　例如：n=7，k=3，下面三种分法被认为是相同的。
　　1，1，5; 1，5，1; 5，1，1;
　　问有多少种不同的分法。
输入格式
　　n，k
        输出格式
　　一个整数，即不同的分法
        样例输入
7 3
样例输出
4 {四种分法为：1，1，5;1，2，4;1，3，3;2，2，3;}
数据规模和约定
　　6<n<=200，2<=k<=6
 */

#include <iostream>

using namespace std;

const int maxk = 9;
const int maxn = 205;

int dp[maxk][maxn]; // dp[k][n] 表示 n 划分为 k 个数字的方案数

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    cin >> n >> k;
    dp[1][1] = 1; // 1 种方法将 1 划分为 1 个数字
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i + j <= n)
                dp[i][j + i] += dp[i][j]; // 增加划分中的一个数字
            dp[i + 1][j + 1] += dp[i][j]; // 其中有数字是 1
        }
    }
    cout << dp[k][n] << endl;
    return 0;
}