#include <iostream>
#include <climits>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int Max;
    Max = max(a, b);
    Max = max(Max, c);
    while (Max <= INT_MAX) {
        Max *= 2;
        if (Max % a == 0 && Max % b == 0 && Max % c == 0) {
            cout << Max;
            return 0;
        }
    }
    return 0;
}
