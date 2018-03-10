/*
取球博弈

两个人玩取球的游戏。
一共有N个球，每人轮流取球，每次可取集合{n1,n2,n3}中的任何一个数目。
如果无法继续取球，则游戏结束。
此时，持有奇数个球的一方获胜。
如果两人都是奇数，则为平局。

假设双方都采用最聪明的取法，
第一个取球的人一定能赢吗？
试编程解决这个问题。

输入格式：
第一行3个正整数n1 n2 n3，空格分开，表示每次可取的数目 (0<n1,n2,n3<100)
第二行5个正整数x1 x2 ... x5，空格分开，表示5局的初始球数(0<xi<1000)

输出格式：
一行5个字符，空格分开。分别表示每局先取球的人能否获胜。
能获胜则输出+，
次之，如有办法逼平对手，输出0，
无论如何都会输，则输出-

例如，输入：
1 2 3
1 2 3 4 5

程序应该输出：
+ 0 + 0 -

再例如，输入：
1 4 5
10 11 12 13 15

程序应该输出：
0 - 0 + +

再例如，输入：
2 3 5
7 8 9 10 11

程序应该输出：
+ 0 0 0 0


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 3000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
 */

#include <iostream>

using namespace std;

int minBalls; // 最少取球数
int n[5]; // 可取球个数
int x[10]; // 5堆球

string nim(int rest, int owe, int other) {
    if (rest < minBalls) {
        if (owe % 2 != 0 && other % 2 == 0) // 先手奇，后手偶，赢
            return "+";
        if (owe % 2 != 0 && other % 2 != 0) // 先手奇，后手奇，平
            return "0";
        if (owe % 2 == 0 && other % 2 == 0) // 先手偶，后手偶，平
            return "0";
        return "-"; // 其余情况，输
    }
    bool draw = false; // 最坏情况是否能平局
    for (int i = 0; i <= 2; i++) {
        if (rest < n[i]) // 剩下的球不足取n[i]
            continue;
        string res = nim(rest - n[i], other, owe + n[i]);
        if (res == "-") // 对方输，我方赢
            return "+";
        if (res == "0") // 对方平，我方最坏情况能平
            draw = true;
    }
    if (draw)
        return "0"; // 无法赢，但存在方法平局
    else return "-";
}

int main() {
    for (int i = 0; i < 3; i++)
        cin >> n[i];
    for (int i = 0; i < 5; i++)
        cin >> x[i];

    minBalls = min(n[0], min(n[1], n[2])); // 最少取球数
    for (int i = 0; i < 5; i++) {
        cout << nim(x[i], 0, 0) << " ";
    }
    return 0;
}
