#include <cstdio>

using namespace std;

int main() {
    freopen("DATA.txt", "r", stdin); // 重定向输入流
    double ans = 0, price, discount;
    char buf[110];
    while (scanf("%s%lf%lf", buf, &price, &discount) != EOF) {
        ans += price * discount / 100;
    }
    cout << ans;
    return 0;
}