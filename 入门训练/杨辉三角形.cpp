#include <iostream>

using namespace std;
int tri[50][50] = {0};

int main() {
    int n;
    cin >> n;
    int i;
    int j;

    tri[0][0] = 1;
    for (i = 0; i < n; i++) {
        tri[i][0] = 1;
        tri[i][i] = 1;
        for (j = 1; j <= i - 1; j++)
            tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++)
            cout << tri[i][j] << " ";
        cout << endl;
    }
    return 0;
}
