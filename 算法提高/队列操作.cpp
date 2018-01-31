#include <iostream>
#include <queue>

using namespace std;
queue<int> q;

int main() {
    int n;
    cin >> n;
    int op;
    for (int i = 0; i < n; i++) {
        cin >> op;
        switch (op) {
            case 1:
                int i;
                cin >> i;
                q.push(i);
                break;
            case 2:
                if (!q.size()) {
                    cout << "no" << endl;
                    return 0;
                } else {
                    cout << q.front() << endl;
                    q.pop();
                }
                break;
            case 3:
                cout << q.size() << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
