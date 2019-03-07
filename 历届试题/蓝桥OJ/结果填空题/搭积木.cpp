/*
搭积木

小明最近喜欢搭数字积木，
一共有10块积木，每个积木上有一个数字，0~9。

搭积木规则：
每个积木放到其它两个积木的上面，并且一定比下面的两个积木数字小。
最后搭成4层的金字塔形，必须用完所有的积木。

下面是两种合格的搭法：

   0
  1 2
 3 4 5
6 7 8 9

   0
  3 1
 7 5 2
9 8 6 4

请你计算这样的搭法一共有多少种？

请填表示总数目的数字。
注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
 */

#include <iostream>

using namespace std;

int main() {
    // 第一排必然是0，剩余九个数字在下面三排; 8和9必然在最后一排，1必然在第二排
    // a b
    // c d e
    // f g h i
    int a, b, c, d, e, f, g, h, i;
    int cnt = 0;
    for (int a = 1; a <= 7; a++) {
        for (int b = 1; b <= 7; b++) {
            for (int c = 2; c <= 7; c++) {
                for (int d = 2; d <= 7; d++) {
                    for (int e = 2; e <= 7; e++) {
                        for (int f = 2; f <= 9; f++) {
                            for (int g = 2; g <= 9; g++) {
                                for (int h = 2; h <= 9; h++) {
                                    for (int i = 2; i <= 9; i++) {
                                        if (a != b && a != c && a != d && a != e && a != f && a != g && a != h &&
                                            a != i && b != c && b != d && b != e && b != f && b != g && b != h &&
                                            b != i && c != d && c != e && c != f && c != g && c != h && c != i &&
                                            d != e && d != f && d != g && d != h && d != i && e != f && e != g &&
                                            e != h && e != i && f != g && f != h && f != i && g != h && g != i &&
                                            h != i && a < c && a < d && b < d && b < e && c < f && c < g && d < g &&
                                            d < h && e < h && e < i) {
                                            cnt++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;
}