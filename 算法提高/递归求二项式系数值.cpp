#include <iostream>

using namespace std;

int com(int k, int n) {
    if (k == 0 || k == n)
        return 1;
    else return com(k, n - 1) + com(k - 1, n - 1);
}

int main() {
    int k, n;
    cin >> k >> n;
    cout << com(k, n);
    return 0;
}