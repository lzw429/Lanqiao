//
// Created by syh on 19-3-19.
//

#include <iostream>

using namespace std;

/**
 * 打印 Hanoi塔移动过程
 * @param n 塔的层数
 * @param from 塔的开始位置
 * @param to 塔的结束位置
 * @param help 中介
 */
void printHanoiTower(const int n, const string &from, const string &to, const string &help) {
    if (n == 1) // 递归终止
        cout << "move " << n << " from " << from << " to " << to << endl;
    else {
        printHanoiTower(n - 1, from, help, to); // 移动上面的 n - 1 层
        cout << "move " << n << " from " << from << " to " << to << endl; // 移动最下面一层
        printHanoiTower(n - 1, help, to, from); // 将上面的 n - 1 层移回
    }
}

int main() {
    int n;
    cin >> n;
    string from = "A";
    string to = "B";
    string help = "C";
    printHanoiTower(n, from, to, help);
    return 0;
}