#include<iostream>
#include<cstring>

#define MAXN 60
#define MOD 1000000007
using namespace std;

int n, m, k; // 地图n行m列，最多k件宝贝
int map[MAXN][MAXN];
int dp[MAXN][MAXN][15][15];

// 记忆化DFS
int DFS(int x, int y, int sum, int max) {
    // (x, y)表示坐标；sum是手中宝贝件数，max是手中宝贝最大价值
    // 返回行动方案数
    int ret = 0;
    if (dp[x][y][sum][max + 1] != -1) // max+1 是因为max初始值为-1，下同
    {
        return dp[x][y][sum][max + 1];
    }
    
    int cur = map[x][y];
    if (x == n - 1 && y == m - 1) {
        // 深搜到终点
        if (sum == k || (cur > max && sum == k - 1))
            ret++;
        ret %= MOD; 
        return ret;
    }
    
    // 向右走
    if (x < n - 1) {
        if (cur > max) {
            // 此地宝贝价值大于手中任意宝贝价值，可以获得该宝贝，也可放弃
            ret += DFS(x + 1, y, sum + 1, cur);
            ret %= MOD;
        }
        ret += DFS(x + 1, y, sum, max);
        ret %= MOD;
    }

    // 向下走
    if (y < m - 1) {
        if (cur > max) {
            ret += DFS(x, y + 1, sum + 1, cur);
            ret %= MOD;
        }
        ret += DFS(x, y + 1, sum, max);
        ret %= MOD;
    }
    dp[x][y][sum][max + 1] = ret;
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp)); // 这步不可忽略 
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) { // x范围[0, n-1]
        for (int j = 0; j < m; ++j) { // y范围[0, m-1]
            cin >> map[i][j];
        }
    }
    cout << DFS(0, 0, 0, -1);
    return 0;
}
