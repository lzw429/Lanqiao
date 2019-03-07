/*
颠倒的价牌
    小李的店里专卖其它店中下架的样品电视机，可称为：样品电视专卖店。
    其标价都是4位数字（即千元不等）。
    小李为了标价清晰、方便，使用了预制的类似数码管的标价签，只要用颜色笔涂数字就可以了（参见p1.jpg）。
    这种价牌有个特点，对一些数字，倒过来看也是合理的数字。如：1 2 5 6 8 9 0 都可以。这样一来，如果牌子挂倒了，有可能完全变成了另一个价格，比如：1958 倒着挂就是：8561，差了几千元啊!!
    当然，多数情况不能倒读，比如，1110 就不能倒过来，因为0不能作为开始数字。
    有一天，悲剧终于发生了。某个店员不小心把店里的某两个价格牌给挂倒了。并且这两个价格牌的电视机都卖出去了!
    庆幸的是价格出入不大，其中一个价牌赔了2百多，另一个价牌却赚了8百多，综合起来，反而多赚了558元。
    请根据这些信息计算：赔钱的那个价牌正确的价格应该是多少？

答案是一个4位的整数，请通过浏览器直接提交该数字。
注意：不要提交解答过程，或其它辅助说明类的内容。
 */

#include <iostream>
#include <cmath>

using namespace std;

int reverse_digit(int x) {
    switch (x) {
        case 1:
            return 1;
        case 2:
            return 2;
        case 5:
            return 5;
        case 6:
            return 9;
        case 8:
            return 8;
        case 9:
            return 6;
        case 0:
            return 0;
    }
}

int reverse(int x) {
    int ret = 0;
    int t = 1000;
    while (x > 0) {
        ret += t * reverse_digit(x % 10);
        x /= 10;
        t /= 10;
    }
    return ret;
}

int main() {
    for (int i = 1000; i <= 9999; i++) {
        for (int j = i + 1; j <= 9999; j++) {
            int delta_i = reverse(i) - i;
            int delta_j = reverse(j) - j;
            int abs_delta_i = abs(delta_i);
            int abs_delta_j = abs(delta_j);
            if (delta_i + delta_j == 558 &&
                (200 <= abs_delta_i && abs_delta_i <= 299 && 800 <= abs_delta_j && abs_delta_j <= 899 ||
                 200 <= abs_delta_j && abs_delta_j <= 299 && 800 <= abs_delta_i && abs_delta_i <= 899))
                cout << i << " " << j << endl;
        }
    }
    return 0;
}
