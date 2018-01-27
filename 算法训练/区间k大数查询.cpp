#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m;
    int l, r, K;
    int i;
    cin >> n;
    int a[n + 5];
    for (i = 0; i != n; ++i)
        cin >> a[i];
    cin >> m;
    for (i = 0; i != m; ++i) {
        priority_queue<int> pq;
        cin >> l >> r >> K;
        for (int j = l; j <= r; ++j) {
            pq.push(a[j - 1]);
        }
        for (int k = 1; k < K; k++)
            pq.pop();
        cout << pq.top() << endl;
    }
    return 0;
}
