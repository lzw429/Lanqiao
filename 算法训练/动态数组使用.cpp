#include <iostream>

using namespace std;

int main() {
    int n, i, sum = 0, ave;
    cin >> n;
    int *a = new int[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ave = sum / n;
    cout << sum << " " << ave;
    return 0;
}
