#include <iostream>

#define N 1300000
using namespace std;
bool comp[N]; // 合数为true，质数为false

int main() {
    for (int i = 2; i < N / 2; i++) {
        for (int j = 2; i * j <= N; j++)
            comp[i * j] = true;
    }
    int n;
    cin >> n;
    int res = 1;
    int cnt = 0;
    for (int i = 2; i <= N, cnt < n; i++) {
        if (!comp[i]) {
            cnt++;
            res = (res * i) % 50000;
        }
    }
    cout << res << endl;
    return 0;
}
