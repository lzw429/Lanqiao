#include <iostream>

using namespace std;

bool judgeEqual(int a[], int n) {
    int num = a[n / 2];
    for (int i = 0; i != n; i++)
        if (a[i] != num)
            return false;
    return true;
}

int main() {
    int n, res = 0;
    cin >> n;
    int a[n + 5];
    for (int i = 0; i != n; i++) {
        cin >> a[i];
    }

    while (!judgeEqual(a, n)) {
        int a0 = a[0];
        for (int i = 0; i < n - 1; i++) {
            a[i] = a[i] / 2 + a[i + 1] / 2;
        }
        a[n - 1] = a[n - 1] / 2 + a0 / 2;
        for (int i = 0; i != n; i++) {
            if (a[i] % 2 == 1) {
                a[i]++;
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
