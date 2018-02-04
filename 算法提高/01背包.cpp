#include <iostream>

using namespace std;

int weight[210];
int value[210];
int dp[5010]; // dp[j]表示载重j内的最大价值

int main() {
    int n, m; // 物品个数和背包载重
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= weight[i]; j--)
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
    cout << dp[m];
    return 0;
}
