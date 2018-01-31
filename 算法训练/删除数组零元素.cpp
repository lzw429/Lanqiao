#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            a[j++] = a[i];
    }
    cout << j << endl;
    for (int i = 0; i < j; i++)
        cout << a[i] << " ";
    return 0;
}
