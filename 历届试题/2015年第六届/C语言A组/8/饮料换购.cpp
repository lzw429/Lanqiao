#include <iostream>

using namespace std;

int n, ans;

int f(int n) {
    while(n >= 3) {
        n -= 3;
        n++;
        ans++;
    }
}

int main() {
    cin >> n;
    ans = n;
    f(n);
    cout << ans << endl;
    return 0;
}
