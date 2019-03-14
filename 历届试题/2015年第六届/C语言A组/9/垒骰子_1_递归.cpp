#include <iostream>

using namespace std;

const int MOD = 1000000007;
int n, m;
int op[7];
bool conflict[7][7];

void init() {
    op[1] = 4;
    op[4] = 1;
    op[2] = 5;
    op[5] = 2;
    op[3] = 6;
    op[6] = 3;
}

long long f(int up, int level) {
    if (level == 0)
        return 1;
    long long ans = 0;
    for (int upp = 1; upp <= 6; ++upp) {
        if (conflict[op[up]][upp] == true) continue;
        ans = (ans + 4 * f(upp, level - 1)) % MOD;
    }
    return ans;
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

    long long ans = 0;
    for (int up = 1; up <= 6; up++) {
        ans = (ans + 4 * f(up, n - 1)) % MOD;
    }

    cout << ans << endl;
    return 0;
} 
