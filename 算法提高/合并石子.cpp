#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int a[1010];
int dp[1010][1010];
int sum[1010][1010];
// dp[i][j]表示[i,j]的最优花费; dp[i][j] = min(dp[i][k], dp[k+1][j]) + sum of [i,j]

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][i] = 0;
        sum[i][i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            sum[i][j] = sum[i][j - 1] + a[j];
    }
    for (int len = 2; len <= n; len++) // 区间长度
    {
        for (int i = 0; i < n - len + 1; i++) // 区间起点
        {
            int j = i + len - 1; // 区间终点
            int tmin = INT_MAX;
            for (int k = i; k < j; k++) {
                int t = dp[i][k] + dp[k + 1][j] + sum[i][j];
                if (t < tmin)
                    tmin = t;
            }
            dp[i][j] = tmin;
        }
    }
    cout << dp[0][n - 1];
    return 0;
}
