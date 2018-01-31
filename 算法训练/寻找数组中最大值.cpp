#include <iostream>
#include <climits>

using namespace std;

int main() {
    int max = INT_MIN;
    int n;
    cin >> n;
    int sub, t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t > max) {
            sub = i;
            max = t;
        }
    }
    cout << max << " " << sub << endl;
    return 0;
}