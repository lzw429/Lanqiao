#include <iostream>

using namespace std;

int main() {
    int N, K; // 共N个数，其中安排K个乘号和N-K-1个加号
    cin >> N >> K;
    long long dp[N + 5][K + 5] = {}; // dp[i][j]表示前i个数之间分配j个乘号时取得的最大值
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        dp[i][0] = dp[i - 1][0] + num; // dp[i][0]即前i个数之和
    }

    for (int i = 2; i <= N; i++) {
        int t = min(i - 1, K); // 前i个数允许的乘号个数
        for (int j = 1; j <= t; j++) {
            for (int k = 2; k <= i; k++) { // 乘号位置，k表示乘号前有k-1个数
                dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] * (dp[i][0] - dp[k - 1][0]));
            }
        }
    }
    cout << dp[N][K];
    return 0;
}