#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int edge[m + 5][n + 5] = {};
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        edge[s - 1][i] = 1;
        edge[e - 1][i] = -1;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << edge[i][j] << " ";
        }
        if (i != m - 1)
            cout << endl;
    }
}
