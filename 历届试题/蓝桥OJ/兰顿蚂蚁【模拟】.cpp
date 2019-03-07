/*
   兰顿蚂蚁，是于1986年，由克里斯·兰顿提出来的，属于细胞自动机的一种。

　　平面上的正方形格子被填上黑色或白色。在其中一格正方形内有一只“蚂蚁”。
　　蚂蚁的头部朝向为：上下左右其中一方。

　　蚂蚁的移动规则十分简单：
　　若蚂蚁在黑格，右转90度，将该格改为白格，并向前移一格；
　　若蚂蚁在白格，左转90度，将该格改为黑格，并向前移一格。

 */

#include <iostream>

#define MAXN 110
using namespace std;

int a[MAXN][MAXN];
int row, col, step, m, n;
char dir;

void move() { // dir 0上 1右 2下 3左
    if (dir == 0) row--;
    else if (dir == 1) col++;
    else if (dir == 2) row++;
    else if (dir == 3) col--;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    cin >> row >> col >> dir >> step;
    switch (dir) {
        case 'U':
            dir = 0;
            break;
        case 'R':
            dir = 1;
            break;
        case 'D':
            dir = 2;
            break;
        case 'L':
            dir = 3;
            break;
        default:
            break;
    }
    while (step--) {
        if (a[row][col]) {
            // 黑格，右转90度
            a[row][col] = 0;
            dir = (dir + 1) % 4;
        } else {
            // 白格，左转90度
            a[row][col] = 1;
            dir = (dir + 3) % 4;
        }
        move();
    }
    cout << row << " " << col;
    return 0;
}
