#include <climits>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef vector<long long> vec;
typedef vector<vec> mat;

long long n, m, p, MOD;

/**
 * 快速乘法
 * @param a
 * @param b
 * @return a * b
 */
long long mul(long long a, long long b) {
    if (a > b) {
        long long t = a;
        a = b;
        b = t;
    }
    long long ans = 0; // a * b % MOD
    while (b) {
        if (b & 1)
            ans = (ans + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return ans;
}

mat mul(const mat &A, const mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int k = 0; k < B.size(); k++) {
            for (int j = 0; j < B[0].size(); j++) {
                C[i][j] = (C[i][j] + mul(A[i][k], B[k][j])) % MOD;
            }
        }
    }
    return C;
}

mat pow(mat A, long long n) {
    mat An(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++)
        An[i][i] = 1;
    while (n > 0) {
        if (n & 1)
            An = mul(A, An);
        A = mul(A, A);
        n >>= 1;
    }
    return An;
}

mat fibInit() {
    mat Fib(2, vec(2));
    Fib[0][0] = 1;
    Fib[0][1] = 1;
    Fib[1][0] = 1;
    Fib[1][1] = 0;
    return Fib;
}

/**
 * 获得 Fib 数列第n项的值
 * @param n 数列索引
 * @return Fib[n]
 */
long long getFib(long long n) {
    mat fib = fibInit();
    mat ans = pow(fib, n);
    return ans[0][1];
}

int main() {
    cin >> n >> m >> p;
    MOD = p;
    if (m >= n + 2) {
        cout << getFib(n + 2) - 1;
    } else {
        MOD = LLONG_MAX;
        MOD = getFib(m);
        cout << getFib(n + 2) % p - 1;
    }
    return 0;
}

