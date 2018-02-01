#include <iostream>

#define MAXN 1000010
using namespace std;

int a[MAXN];

int main() {
    int n, k, T;
    long long ans = 0;
    cin >> n >> k >> T;
    a[0] = 1;
    for (int i = 1; i < 2 * k; i++) {
        a[i] = (a[i - 1] + i) % k;
    }
    int i = 0;
    while (T--) {
        ans += a[i];
        i = (i + n) % (2 * k);
    }
    cout << ans;
    return 0;
}
