#include <iostream>

using namespace std;

int main() {
    int line;
    cin >> line; // 行数范围[1, 100]
    int a[line + 5][line + 5] = {}; // 三角形中的数字范围[0, 99]
    for (int i = 0; i < line; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    int dp[line + 5][line + 5] = {};
    dp[0][0] = a[0][0];
    for (int i = 1; i < line; i++) {
        dp[i][0] = a[i][0] + dp[i - 1][0]; // 每行第一个数的上一步一定是上一行第一个数
        dp[i][i] = a[i][i] + dp[i - 1][i - 1]; // 每行最后一个数的上一步一定是上一行最后一个数
        for (int j = 1; j <= i - 1; j++) {
            dp[i][j] = a[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    int max = -1;
    for (int j = 0; j < line; j++) {
        if (dp[line - 1][j] > max)
            max = dp[line - 1][j];
    }
    cout << max;
    return 0;
}
