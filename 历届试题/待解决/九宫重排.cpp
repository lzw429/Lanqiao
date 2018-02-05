#include <iostream>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

string init, fin;
int ans, empty;
queue <string> que;
set <string> vis;

void push(string s, const int &empty, const int &x) {
    int t = empty + x;
    if (0 <= t && t < 9) {
        swap(s[empty], s[t]);
        if (vis.find(s) == vis.end()) {
            que.push(s);
            vis.insert(s);
        }
    }
}

int BFS() {
    que.push(init);
    vis.insert(init);
    que.push("n");
    while (!que.empty()) {
        string cur = que.front();
        que.pop();
        if (cur == "n") { // 本层结束
            ans++;
            if (que.size() > 0)
                que.push("n");
        } else if (cur == fin) // BFS终止
            return ans;
        else {
            empty = cur.find('.');
            push(cur, empty, -1);
            push(cur, empty, -3);
            push(cur, empty, +1);
            push(cur, empty, +3);
        }
    }
    return -1;
}

int main() {
    cin >> init >> fin;
    cout << BFS();
    return 0;
}
