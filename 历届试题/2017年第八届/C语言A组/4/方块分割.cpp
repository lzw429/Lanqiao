//
// Created by syh on 19-3-17.
//

#include <iostream>

using namespace std;

int len;
int dir[][2] = {{-1, 0},
                {1,  0},
                {0,  -1},
                {0,  1}};

bool vis[7][7]; // 访问数组

void dfs(int x, int y) {
    if (!x || !y || x == 6 || y == 6) { // 访问到边界
        len++;
        return;
    }

    vis[x][y] = vis[6 - x][6 - y] = true;
    for (int i = 0; i < 4; i++) { // 尝试4个方向
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx < 0 || ny < 0 || nx > 6 || ny > 6) continue;
        if (!vis[nx][ny]) // 如果再次访问，将无法分割方块
            dfs(nx, ny);
    }
    vis[x][y] = vis[6 - x][6 - y] = false; // 回溯
}

int main() {
    dfs(3, 3);
    cout << len / 4 << endl; // 找到的剪法在旋转之后重复
    return 0;
}