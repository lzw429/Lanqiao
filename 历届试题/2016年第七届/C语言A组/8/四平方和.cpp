//
// Created by syh on 19-3-15.
//

// 本题的总体思路是暴力枚举，优化思路包括：
// 1.减小枚举范围
// 2.减少枚举变量

#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int n;
map<int, int> vis; // 使用 hash 暂存，以空间换时间

int main() {
    cin >> n;
    for (int c = 0; c * c <= n / 2; c++) {
        for (int d = 0; c * c + d * d <= n; d++) {
            if (vis.find(c * c + d * d) == vis.end())
                vis[c * c + d * d] = c;
        }
    }

    for (int a = 0; a * a <= n / 4; a++) {
        for (int b = a; a * a + b * b <= n / 2; b++) {
            if (vis.find(n - a * a - b * b) != vis.end()) {
                int c = vis[n - a * a - b * b];
                int d = int(sqrt(n - a * a - b * b - c * c));
                cout << a << " " << b << " " << c << " " << d << endl;
                return 0;
            }
        }
    }

    return 0;
}