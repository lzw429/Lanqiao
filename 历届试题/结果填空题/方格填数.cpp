#include <iostream>
#include <cstring>

using namespace std;

int map[4][5];
int ans;
bool used[12];

void DFS(int x, int y) {
    if (x == 2 && y == 3) {
        // 搜索终点
        ans++;
        return;
    }
    for (int i = 0; i <= 9; ++i) {
        if (used[i])
            continue;
        if (x - 1 >= 0 && (map[x - 1][y] == i - 1 || map[x - 1][y] == i + 1))continue;
        if (x + 1 <= 2 && (map[x + 1][y] == i - 1 || map[x + 1][y] == i + 1))continue;
        if (y - 1 >= 0 && (map[x][y - 1] == i - 1 || map[x][y - 1] == i + 1))continue;
        if (y + 1 <= 3 && (map[x][y + 1] == i - 1 || map[x][y + 1] == i + 1))continue;
        if (x - 1 >= 0 && y - 1 >= 0 && (map[x - 1][y - 1] == i - 1 || map[x - 1][y - 1] == i + 1))continue;
        if (x + 1 <= 2 && y - 1 >= 0 && (map[x + 1][y - 1] == i - 1 || map[x + 1][y - 1] == i + 1)) continue;
        if (x - 1 >= 0 && y + 1 <= 3 && (map[x - 1][y + 1] == i - 1 || map[x - 1][y + 1] == i + 1))continue;
        if (x + 1 <= 2 && y + 1 <= 3 && (map[x + 1][y + 1] == i - 1 || map[x + 1][y + 1] == i + 1)) continue;
        used[i] = true;
        map[x][y] = i;
        if (y == 3)
            DFS(x + 1, 0);
        else DFS(x, y + 1);
        used[i] = false;
        map[x][y] = -0x3f3f3f3f;
    }
}

int main() {
    memset(map, -0x3f3f3f3f, sizeof(map));
    DFS(0, 1);
    cout << ans;
    return 0;
}
