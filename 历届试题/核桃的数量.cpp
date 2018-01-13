#include <iostream>
#include <climits>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int max;
    max = (a > b) ? a : b;
    max = (c > max) ? c : max;
    while (max <= INT_MAX) {
        max += max;
        if (max % a == 0 && max % b == 0 && max % c == 0) {
            cout << max;
            return 0;
        }
    }
    return 0;
}