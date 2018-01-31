#include <iostream>

using namespace std;

int lcm(int a, int b) {
    int big = max(a, b);
    int small = min(a, b);
    for (int i = 1;; i++) {
        int c = i * big;
        if (c % small == 0)
            return c;
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b);
    return 0;
}
