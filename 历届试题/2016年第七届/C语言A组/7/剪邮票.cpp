//
// Created by syh on 19-3-14.
//

#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
bool vis[4][5];


void dfs(int x, int y, int cnt, vector<int> path) {
    if (cnt == 5) {

        ans++;

        return;
    }

    vis[x][y] = true;
    if (x > 0 && !vis[x - 1][y]) dfs(x - 1, y, cnt + 1);
    if (y > 0 && !vis[x][y - 1]) dfs(x, y - 1, cnt + 1);
    if (x < 3 && !vis[x + 1][y]) dfs(x + 1, y, cnt + 1);
    if (y < 4 && !vis[x][y + 1]) dfs(x, y + 1, cnt + 1);
    vis[x][y] = false;
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            dfs(i, j, 0);
        }
    }
    cout << ans << endl;
    return 0;
}