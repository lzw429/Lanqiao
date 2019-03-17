//
// Created by syh on 19-3-15.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int ans;

bool vis[11][11];
char vis[11][11] = {
        {"UDDLUULRUL"},
        {"UURLLLRRRU"},
        {"RRUURLDLRD"},
        {"RUDDDDUUUU"},
        {"URUDLLRRUU"},
        {"DURLRLDLRL"},
        {"ULLURLLRDU"},
        {"RDLULLRDDD"},
        {"UUDDUDUDLL"},
        {"ULRDLUURRR"}
};

bool check(int x, int y) {
    if (vis[x][y]) return false;
    if (x == 0 && vis[x][y] == 'U')
        return true;
    else if (y == 0 && vis[x][y] == 'L')
        return true;
    else if (x == 9 && vis[x][y] == 'D')
        return true;
    else if (y == 9 && vis[x][y] == 'R')
        return true;
    vis[x][y] = true;
    if (vis[x][y] == 'U')
        return check(x - 1, y);
    else if (vis[x][y] == 'L')
        return check(x, y - 1);
    else if (vis[x][y] == 'D')
        return check(x + 1, y);
    else if (vis[x][y] == 'R')
        return check(x, y + 1);
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            memset(vis, false, sizeof(vis));
            bool flag = check(i, j);
            printf("(%d, %d): %s\n", i, j, (flag ? "true" : "false"));
            if (flag) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}