#include <iostream>

using namespace std;

double dp[110][11000];

// dp[i][j]表示选择i个数字，和为j的概率
int main() {
    int n, a, b, x;
    cin >> n >> a >> b >> x;
    for (int i = a; i <= b; i++) {
        dp[1][i] = 1.0 / (b - a + 1); // [a,b]中选取一个数，为i的概率是1/(b-a+1)
    }
    for (int i = 2; i <= n; i++) {
        for (int j = a; j <= b; j++) {
            for (int k = i * a; k <= x; k++) {
                if (k - j > 0)
                    dp[i][k] += dp[i - 1][k - j] * 1.0 / (b - a + 1);
            }
        }
    }
    printf("%.4lf", dp[n][x]);
    return 0;
}
