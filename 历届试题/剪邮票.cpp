#include <iostream>
#include <cstring>
using namespace std;

bool vis[15];
int ans = 0;

int DFS(int pos) {
    // 检查pos所在连通分量的邮票个数是否为5
    if (vis[pos]) {
        vis[pos] = false;
        int ret = 0;
        if (pos % 4 < 3)
            ret += DFS(pos + 1); // 向右
        if (pos / 4 < 2)
            ret += DFS(pos + 4); // 向下
        if (pos % 4 > 0)
            ret += DFS(pos - 1); // 向左
        if (pos / 4 > 0)
            ret += DFS(pos - 4); // 向上
        return 1+ret;
    } vis[pos] = false;
   return 0;
}

int main() {
    for (int a = 0; a < 8; a++) {
        for (int b = a + 1; b < 9; b++) {
            for (int c = b + 1; c < 10; c++) {
                for (int d = c + 1; d < 11; d++) {
                    for (int e = d + 1; e < 12; e++) {
                        vis[a] = true;
                        vis[b] = true;
                        vis[c] = true;
                        vis[d] = true;
                        vis[e] = true;
                        if (DFS(a) == 5)
                            ans++;
                        memset(vis,false,sizeof(vis));
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
