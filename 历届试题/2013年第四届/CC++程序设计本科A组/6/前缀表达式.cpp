//
// Created by syh on 19-3-19.
//


#include <iostream>

using namespace std;
struct EV {
    int result;  //计算结果
    int n;       //消耗掉的字符数
};

struct EV evaluate(char *x) {
    struct EV ev = {0, 0};
    struct EV v1; // 操作数1
    struct EV v2; // 操作数2

    if (*x == 0) return ev;

    if (x[0] >= '0' && x[0] <= '9') { // 如果 x[0] 是数字
        ev.result = x[0] - '0';
        ev.n = 1;
        return ev;
    }

    // 如果 x[0] 是运算符

    //- + 3 * 5 + 2 6 1
    v1 = evaluate(x + 1);
//    v2 = _____________________________;  //填空位置
    v2 = evaluate(x + 1 + v1.n);

    if (x[0] == '+') ev.result = v1.result + v2.result;
    if (x[0] == '*') ev.result = v1.result * v2.result;
    if (x[0] == '-') ev.result = v1.result - v2.result;
    ev.n = 1 + v1.n + v2.n;

    return ev;
}

int main() {
    char str[64] = "-+3*5+261"; // 值为42
    struct EV ev = evaluate(str);
    cout << ev.result << endl;
    return 0;
}
