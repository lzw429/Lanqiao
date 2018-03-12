#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            int delta = abs(i - j);
            cout << (char) ('A' + delta);
        }
        cout << endl;
    }
    return 0;
}
