#include <iostream>

#define MAXN 110
using namespace std;

int a[MAXN][MAXN];
int row, col, step, m, n;
char dir;

void move() { // 上右下左
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
