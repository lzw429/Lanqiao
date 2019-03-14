#include <iostream>

using namespace std;

int ans = 0;
void f (int level, int cnt) {
    if (level > 13 || cnt > 13) return;
    if (cnt == 13 && level == 13) {
        ans++;
        return;
    } 
    for (int i = 0; i <= 4; i++) {
        f(level + 1, cnt + i);
    }
}

int main() { 
    f(0, 0);
    cout << ans << endl;
    return 0;
}
