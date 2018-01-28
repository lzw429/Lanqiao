#include <iostream>
#include <queue>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        priority_queue<int> a;
        priority_queue<int, vector<int>, greater<int> > b; // 两个“>”之间有空格，否则在蓝桥网上编译出错
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            a.push(t);
        }
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            b.push(t);
        }
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += a.top() * b.top();
            a.pop();
            b.pop();
        }
        cout << sum << endl;
    }
    return 0;
}
