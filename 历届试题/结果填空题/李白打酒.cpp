/*
李白打酒

    话说大诗人李白，一生好饮。幸好他从不开车。

    一天，他提着酒壶，从家里出来，酒壶中有酒2斗。他边走边唱：

    无事街上走，提壶去打酒。
    逢店加一倍，遇花喝一斗。

    这一路上，他一共遇到店5次，遇到花10次，已知最后一次遇到的是花，他正好把酒喝光了。

    请你计算李白遇到店和花的次序，可以把遇店记为a，遇花记为b。则：babaabbabbabbbb 就是合理的次序。像这样的答案一共有多少呢？请你计算出所有可能方案的个数（包含题目给出的）。

 */

#include <iostream>

using namespace std;

int cnt = 0;

void DFS(int &a, int step, int &wine) {
    if (step == 15) {
        if (wine == 0 && a == 5)
            cnt++;
        return;
    } else {
        if (wine <= 0)
            return;
        int w = wine;
        if (a < 5) {
            wine *= 2;
            a++;
            DFS(a, step + 1, wine);
            wine = w;
            a--;
        }
        wine--;
        DFS(a, step + 1, wine);
        wine = w;
    }
}

int main() {
    int a = 0; // 遇店次数
    int wine = 2;
    DFS(a, 0, wine);
    cout << cnt;
    return 0;
}
