#include <iostream>

using namespace std;

int main() {
    int n, cnt = 0, max = 0, res = 0, pre;
    cin >> n;
    if (n <= 0 || n > 20)
        return 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (!i) {
            res = pre = t;
            cnt = 1;
            max = 1;
        } else {
            if (t == pre) {
                cnt++;
                if (cnt > max) {
                    max = cnt;
                    res = t;
                }
            } else {
                cnt = 1;
                pre = t;
            }
        }
    }
    cout << res << endl;
    return 0;
}
