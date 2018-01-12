#include <climits>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 5];
    int target;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> target;
    for (int i = 0; i < n; i++)
        if (target == a[i]) {
            cout << i + 1;
            return 0;
        }
    cout << -1;
    return 0;
}
