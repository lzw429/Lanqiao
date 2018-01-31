#include <iostream>

#define  MAXN 1000010
using namespace std;
bool dp[MAXN];

int main() {
    int a, b, ans = 0;
    cin >> a >> b;

    dp[a] = dp[b] = true;
    for (int i = 1; i < MAXN; i++) {
        if ((i - a) > 0 && dp[i - a])dp[i] = true;
        if ((i - b) > 0 && dp[i - b])dp[i] = true;
        if (!dp[i]) ans = i;
    }
    cout << ans;
    return 0;
}
