//
// Created by syh on 19-3-15.
//

#include <iostream>

using namespace std;

int ans;

bool vis[11][11];
char mp[11][11] = {
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
    if (x == 0 && mp[x][y] == 'U')
        return true;
    else if (y == 0 && mp[x][y] == 'L')
        return true;
    else if (x == 9 && mp[x][y] == 'D')
        return true;
    else if (y == 9 && mp[x][y] == 'R')
        return true;
    else if (x == 0 || x == 9 || y == 0 || y == 9) return false;
    vis[x][y] = true;
    if (mp[x][y] == 'U')
        return check(x - 1, y);
    else if (mp[x][y] == 'L')
        return check(x, y - 1);
    else if (mp[x][y] == 'D')
        return check(x + 1, y);
    else if (mp[x][y] == 'R')
        return check(x, y + 1);
    vis[x][y] = false;
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (check(i, j)) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}