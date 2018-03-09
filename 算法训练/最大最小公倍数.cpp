#include <iostream>

using namespace std;

int main() {
    // 两相邻的非零自然数互质
    // 两相邻奇数互质
    // 两相邻偶数不互质
    long long res, N; // 如果N是int类型，所有res的计算结果需要强制类型转换
    cin >> N;
    if (N <= 2)
        cout << N;
    else if (N % 2 == 1) { // N是奇数
        res = N * (N - 1) * (N - 2);
        cout << res;
    } else { // N是偶数
        if (N % 3 == 0) {
            res = (N - 1) * (N - 2) * (N - 3);
        } else res = N * (N - 1) * (N - 3);
        cout << res;
    }
    return 0;
}
