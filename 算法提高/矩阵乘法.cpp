#include <iostream>
#include <cstring>
#include <climits>

#define  MAXN 1010
using namespace std;

long long a[MAXN]; // 题目的“数据规模和约定”是假的
long long dp[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
        dp[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) // 区间长度
    {
        for (int i = 1; i <= n - len + 1; i++)   // 区间起点
        {
            int j = i + len - 1; // 区间终点
            long long t_min = dp[i + 1][j] + a[i - 1] * a[i] * a[j];
            for (int k = i + 1; k < j; k++) {
                // dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j])
                t_min = min(dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j], t_min);
            }
            dp[i][j] = t_min;
        }
    }
    cout << dp[1][n];
    return 0;
}
