/*
猜年龄

小明带两个妹妹参加元宵灯会。别人问她们多大了，她们调皮地说：“我们俩的年龄之积是年龄之和的6倍”。小明又补充说：“她们可不是双胞胎，年龄差肯定也不超过8岁啊。”

请你写出：小明的较小的妹妹的年龄。
 */

#include <iostream>

using namespace std;

int main() {
    int a, b;
    for (a = 1; a <= 100; a++)
        for (b = 1; b <= 100; b++)
            if (a * b == 6 * (a + b) && abs(a - b) <= 8)
                cout << a << " " << b << endl;
    return 0;
}
