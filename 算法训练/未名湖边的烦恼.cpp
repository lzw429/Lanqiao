#include <iostream>

using namespace std;
int dp[20][20]; // dp[i][j]表示i人还鞋j人租鞋的排列数量
int main() {
    int m, n, i, j;
    cin >> m >> n; // 还鞋和租鞋
    for (i = 1; i <= 18; i++) {
        dp[i][0] = 1;
        for (j = 1; j <= 18; j++) {
            dp[i][j] = (i >= j) ? (dp[i - 1][j] + dp[i][j - 1]) : 0;
        }
    }
    cout << dp[m][n];
    return 0;
}
