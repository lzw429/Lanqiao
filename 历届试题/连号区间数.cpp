#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    int cnt = 0;
    int a[n + 5];
    for (int i = 0; i < n; ++i)
        cin >> a[i]; // 输入是N个不同的数字
    int min, max;
    for (int i = 0; i < n; ++i) {
        min = max = a[i];
        for (int j = i; j < n; ++j) {
            if (min > a[j])
                min = a[j];
            if (max < a[j])
                max = a[j];
            if (max - min == j - i)
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}
