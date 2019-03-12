#include<iostream>
#include<cstring>

#define MAXN 60
#define MOD 1000000007
using namespace std;

int n, m, k; // ��ͼn��m�У����k������
int map[MAXN][MAXN];
int dp[MAXN][MAXN][15][15];

// ���仯DFS
int DFS(int x, int y, int sum, int max) {
    // (x, y)��ʾ���ꣻsum�����б���������max�����б�������ֵ
    // �����ж�������
    int ret = 0;
    if (dp[x][y][sum][max + 1] != -1) // max+1 ����Ϊmax��ʼֵΪ-1����ͬ
    {
        return dp[x][y][sum][max + 1];
    }
    
    int cur = map[x][y];
    if (x == n - 1 && y == m - 1) {
        // ���ѵ��յ�
        if (sum == k || (cur > max && sum == k - 1))
            ret++;
        ret %= MOD; 
        return ret;
    }
    
    // ������
    if (x < n - 1) {
        if (cur > max) {
            // �˵ر�����ֵ�����������ⱦ����ֵ�����Ի�øñ�����Ҳ�ɷ���
            ret += DFS(x + 1, y, sum + 1, cur);
            ret %= MOD;
        }
        ret += DFS(x + 1, y, sum, max);
        ret %= MOD;
    }

    // ������
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
    memset(dp, -1, sizeof(dp)); // �ⲽ���ɺ��� 
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) { // x��Χ[0, n-1]
        for (int j = 0; j < m; ++j) { // y��Χ[0, m-1]
            cin >> map[i][j];
        }
    }
    cout << DFS(0, 0, 0, -1);
    return 0;
}
