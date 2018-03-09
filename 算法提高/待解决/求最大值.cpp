#include <iostream>

using namespace std;
int a[110], b[110];

int dp(int x, int y, int i) {
    if (i == 0) {
        if (x + a[0] >= 0 && y + b[0] >= 0)
            return a[0] + b[0];
        else
            return 0;
    } else if (x + a[i] >= 0 && y + b[i] >= 0) {
        return a[i] + b[i] + dp(x + a[i], y + b[i], i - 1);
    } else
        return dp(x, y, i - 1);
}

int main() {
    int n;
    cin >> n;
    int j = 0;
    for (int i = 0; i != n; i++) {
        int ai, bi;
        cin >> ai >> bi;
        if (ai + bi > 0) {
            a[j] = ai;
            b[j] = bi;
            j++;
        }
    }
    cout << dp(0, 0, j - 1);
    return 0;
}
