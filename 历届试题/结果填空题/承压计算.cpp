#include <iostream>

using namespace std;
double num[35][35];

int main() {
    for (int i = 1; i <= 29; i++)
        for (int j = 1; j <= i; j++)
            scanf("%lf", &num[i][j]); // 输入的是 double 类型
    for (int i = 1; i <= 29; i++) {
        for (int j = 1; j <= i; j++) {
            num[i + 1][j] += num[i][j] / 2;
            num[i + 1][j + 1] += num[i][j] / 2;
        }
    }
    double maxNum = -1;
    double minNum = 0x3f3f3f3f;
    for (int i = 1; i <= 30; i++) {
        maxNum = max(maxNum, num[30][i]);
        minNum = min(minNum, num[30][i]);
    }
    printf("%lf", maxNum * 2086458231 / minNum);
    return 0;
}
