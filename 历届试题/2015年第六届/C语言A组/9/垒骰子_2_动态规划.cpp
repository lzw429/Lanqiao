#include <iostream>

using namespace std;

const int MOD = 1000000000 + 7;
int dp[2][7]; // dp[i][j]��ʾ��i�㣬��������Ϊj���ȶ�����ɸ�ӷ����� 
// n���ܴܺ󣬲���Ҫ����֮ǰ���е���ʱ���� 
int op[7]; // �෴�� 
bool conflict[7][7];
int cnt[7];
int n, m;
long long ans;

void init() {
    op[1] = 4;
    op[4] = 1;
    op[2] = 5;
    op[5] = 2;
    op[3] = 6;
    op[6] = 3;
    for (int i = 1; i <= 6; i++)
        dp[0][i] = 1;
}

long long pow(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1)
            res = a * res % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    init();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        conflict[x][y] = true;
        conflict[y][x] = true;
    }

    int k = 0;
    for (int i = 0; i < n - 1; i++) { // dp[0][i] �Ѿ��洢��1�㣬ʣ�� n - 1 �ε��� 
        k = 1 - k;
        for (int a = 1; a <= 6; a++) {
            dp[k][a] = 0;
        }
        for (int j = 1; j <= 6; j++) {
            for (int a = 1; a <= 6; a++) {
                if (conflict[op[j]][a] == false) {
                    dp[k][a] = (dp[k][a] + dp[1 - k][j]) % MOD;
                }
            }
        }
    }

    for (int j = 1; j <= 6; j++) {
        ans = (ans + dp[k][j]) % MOD;
    }

    // ʹ�ÿ����ݽ��𰸳��� 4^n

    long long t = pow(4, n);
    ans = (ans * t) % MOD;
    cout << ans << endl;
    return 0;
} 
