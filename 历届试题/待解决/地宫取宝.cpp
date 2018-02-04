#include <iostream>

#define MAXN 60
#define MOD 1000000007
using namespace std;

int n, m, k;
int map[MAXN][MAXN];
int dp[MAXN][MAXN][15][15];

int DFS(int x, int y, int sum, int max) {
    // (x, y)是坐标，sum是价值总和，max是最大价值
    // max+1 是因为max初始值为-1
    // 函数返回行动方案数
    if (dp[x][y][sum][max + 1] != -1)
        return dp[x][y][sum][max + 1];
    int ret = 0;
    if (x == n - 1 && y == m - 1) {
        // 到达终点
        if (sum == k || (map[x][y] > max && sum == k - 1))
            ret++;
        return dp[x][y][sum][max + 1];
    }

    // 向右走
    if (x < n - 1) {
        if (map[x][y] > max) {
            ret += DFS(x + 1, y, sum + 1, map[x][y]);
            ret %= MOD;
        }
        ret += DFS(x + 1, y, sum, max);
        ret %= MOD;
    }

    // 向下走
    if (y < m - 1) {
        if (map[x][y] > max) {
            ret += DFS(x, y + 1, sum + 1, map[x][y]);
            ret %= MOD;
        }
        ret += DFS(x, y + 1, sum, max);
        ret %= MOD;
    }

    dp[x][y][sum][max + 1] = ret;
    return ret;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++i)
            cin >> map[i][j];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = dfs(0, 0, 0, -1);
    cout << dp[0][0][0][0];
    return 0;
}