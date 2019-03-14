/*
「样例输入」
2 1
1 2

「样例输出」
544
*/

#include <iostream>
#include <vector>

using namespace std;

typedef vector<long long> vec;
typedef vector<vec> mat;

const int MOD = 1000000000 + 7;
int n, m;
long long ans;
int op[7];
mat conflict(6, vec(6, 1));

void init() {
    op[1] = 4;
    op[4] = 1;
    op[2] = 5;
    op[5] = 2;
    op[3] = 6;
    op[6] = 3;
}

mat mul(mat a, mat b) {
    mat c(a.size(), vec(b[0].size())); // as result

    for (int i = 0; i < a.size(); i++) {
        for (int k = 0; k < b.size(); k++) { // a[0].size() must equal to b.size()
            for (int j = 0; j < b[0].size(); j++) {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
    return c;
}

mat pow(mat a, long long n) {
    int size = a.size();
    mat res(size, vec(size));
    for (int i = 0; i < size; i++) {
        res[i][i] = 1;
    }

    while (n) {
        if (n & 1)
            res = mul(a, res);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

long long pow(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    init();

    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        conflict[op[x] - 1][y - 1] = 0;
        conflict[op[y] - 1][x - 1] = 0;
    }
    conflict = pow(conflict, n - 1); // n - 1 次方，而不是 n 次方
    mat dp(6, vec(1, 1));
    mat res = mul(conflict, dp);

    for (int j = 0; j < 6; j++) {
        ans = (ans + res[j][0]) % MOD;
    }

    long long t = pow(4, n);
    ans = (ans * t) % MOD;
    cout << ans << endl;

    return 0;
} 
