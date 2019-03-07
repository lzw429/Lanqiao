/*
方格分割

6x6的方格，沿着格子的边线剪开成两部分。
要求这两部分的形状完全相同。

如图：p1.png, p2.png, p3.png 就是可行的分割法。

试计算：
包括这3种分法在内，一共有多少种不同的分割方法。
注意：旋转对称的属于同一种分割法。

请提交该整数，不要填写任何多余的内容或说明文字。
 */

#include <iostream>

#define N 6
using namespace std;

int ans = 0;
bool map[N + 1][N + 1];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}; // 方向

void DFS(int x, int y) {
    if (x == 0 || y == 0 || x == N || y == N) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (map[tx][ty])continue;
        map[tx][ty] = true;
        map[N - tx][N - ty] = true;
        DFS(tx, ty);
        map[tx][ty] = false;
        map[N - tx][N - ty] = false;
    }
}

int main() {
    map[N / 2][N / 2] = true;
    DFS(N / 2, N / 2);
    cout << ans / 4;
    return 0;
}