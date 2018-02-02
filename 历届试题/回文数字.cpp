#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    bool found = false;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (2 * i + 2 * j + k == n) {
                    found = (found) ?: true;
                    cout << 10001 * i + 1010 * j + 100 * k << endl;
                }
                if (2 * i + 2 * j + 2 * k == n) {
                    found = (found) ?: true;
                    v.push_back(100001 * i + 10010 * j + 1100 * k);
                }
            }
        }
    }
    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }

    if (!found) { cout << -1; }
    return 0;
}
