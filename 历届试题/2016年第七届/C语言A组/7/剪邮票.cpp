//
// Created by syh on 19-3-14.
//

// 使用 DFS 查找路径要先考虑一笔画问题。例如本题中如果邮票是十字型，DFS 无法搜索到。
// 但 DFS 可用于连通性检查。
// 本题的可行思路是任意选择五张邮票，判断它们是否连通。
// 正确答案：116

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int stamp[13] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
bool vis[4][5];
int len;

int dfs(int x, int y) {
    if (!stamp[4 * x + y])
        return 0;
    int res = 1;
    vis[x][y] = true;
    if (x - 1 >= 0 && !vis[x - 1][y]) res += dfs(x - 1, y); // up
    if (y - 1 >= 0 && !vis[x][y - 1]) res += dfs(x, y - 1); // left
    if (x + 1 <= 2 && !vis[x + 1][y]) res += dfs(x + 1, y); // down
    if (y + 1 <= 3 && !vis[x][y + 1]) res += dfs(x, y + 1); // right
    return res;
}

void printStamp() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << stamp[4 * i + j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    do {
        memset(vis, false, sizeof(vis)); // 不可回溯，因此 DFS 中没有重置 vis
        for (int i = 0; i < 3; i++) {
            bool breakFlag = false;
            for (int j = 0; j < 4; j++) {
                if (stamp[4 * i + j]) {
                    printStamp();
                    if (dfs(i, j) == 5) {
                        cout << "true" << endl;
                        len++;
                    } else cout << "false" << endl;
                    breakFlag = true;
                    break;
                }
            }
            if (breakFlag)
                break;
        }
    } while (next_permutation(stamp, stamp + 12));
    cout << len << endl;
    return 0;
}
