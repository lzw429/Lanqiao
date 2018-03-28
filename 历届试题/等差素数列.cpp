/*
等差素数列

2,3,5,7,11,13,....是素数序列。
类似：7,37,67,97,127,157 这样完全由素数组成的等差数列，叫等差素数数列。
上边的数列公差为30，长度为6。

2004年，格林与华人陶哲轩合作证明了：存在任意长度的素数等差数列。
这是数论领域一项惊人的成果！

有这一理论为基础，请你借助手中的计算机，满怀信心地搜索：

长度为10的等差素数列，其公差最小值是多少？

注意：需要提交的是一个整数，不要填写任何多余的内容和说明文字。
 */
#include <iostream>

using namespace std;

bool comp[1000000000]; // false 为质数，true 为合数
int len;

int main() {
    // 埃拉托斯特尼筛法
    for (int i = 2; i <= 1000; i++) {
        if (!comp[i]) {
            for (int j = i * i; j <= 1000000; j += i)
                comp[j] = true;
        }
    }
    bool found = true;
    for (int s = 2; s <= 10000; s++) { // 数列首项
        int step = 0;
        for (int d = 3; d <= 10000; d++) { // 公差
            found = true;
            for (int step = 0; step < 10; step++) {
                if (comp[s + d * step]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                cout << "d:" << d << endl << "Array as follows:" << endl;
                for (int i = 0; i < 10; i++)
                    if (!comp[s + i * d])
                        cout << s + i * d << endl;
            }

        }
    }
    return 0;
}
