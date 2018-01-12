#include <iostream>
#include <climits>

using namespace std;

int main() {
    int max = INT_MIN, min = INT_MAX;
    int n;
    cin >> n;
    for (int i = 0; i != n; i++) {
        int t;
        cin >> t;
        if (t > max)
            max = t;
        if (t < min)
            min = t;
    }
    cout << max << " " << min;
    return 0;
}
