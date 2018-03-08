#include <iostream>
#include <cmath> // sqrt
#include <sstream> // stringstream

using namespace std;

int main() {
    int n;
    string res;
    cin >> n;
    // 筛出[2, n]之间的素数
    int m = sqrt(n + 0.5);
    bool vis[n + 5] = {}; // false是素数
    for (int i = 2; i <= m; i++)
        if (!vis[i]) // 如果i是素数
            for (int j = i * i; j <= n; j += i)
                vis[j] = true;

    while (n != 1) {
        for (int i = 2; i <= n; i++) {
            if (!vis[i] && n % i == 0) {
                n /= i;
                string num;
                stringstream ss;
                ss << i;
                ss >> num;
                res += num + "*"; // to_string 是 C++ 11 函数，蓝桥杯不支持
                break;
            }
        }
    }
    res = res.substr(0, res.size() - 1); // pop_back 是 C++ 11 函数，蓝桥杯不支持
    cout << res;
    return 0;
}
