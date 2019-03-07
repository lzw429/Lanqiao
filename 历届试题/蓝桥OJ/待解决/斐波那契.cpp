// 矩阵快速幂求斐波那契数列
#include <iostream>
#include <climits>

using namespace std;
long long n, m, p, fm = LLONG_MAX;

long long longMul(long long a, long long b) {
    long long ret = 0;
    a %= fm;
    while (b) {
        if (b & 1)
            ret = (ret + a) % fm;
        b >>= 1;
        a = (a << 1) % fm;
    }
    return ret;
}

void matMul(long long (&a)[2][2], long long b[2][2]) {
    // 矩阵乘积返回给矩阵a
    long long t[2][2] = {0};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k)
                t[i][j] = (t[i][j] + longMul(a[i][k], b[k][j])) % fm;
        }
    }
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            a[i][j] = t[i][j];
}

int main() {
    long long A[2][2] = {1, 1, 1, 0}, B[2][2] = {1, 0, 0, 1};
    cin >> n >> m >> p;
    // 计算fm
    while (m) {
        if (m & 1)
            matMul(B, A);
        matMul(A, A);
        m >>= 1;
    }
    fm = B[0][1];
    // f(i)前n项和 = (f(n+2) + fm - 1) % fm
    long long C[2][2] = {1, 1, 1, 0}, D[2][2] = {1, 0, 0, 1};
    long long tn = n + 2;
    while (tn) {
        if (tn & 1)
            matMul(D, C);
        matMul(C, C);
        tn >>= 1;
    }
    cout << (D[0][1] + fm - 1) % fm % p;
    return 0;
}
