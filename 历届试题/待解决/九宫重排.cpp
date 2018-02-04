#include <iostream>
#include <queue>
#include <map>
using namespace std;

string init, fin;
int ans,empty;
queue <string> que;
map <string, bool> vis;

int getEmpty(const string &s) {
    // 返回空缺的索引
    for (int i = 0; i < 9; ++i) {
        if (s[i] == '.')
            return i;
    }
}

void push(string s, const int &empty, const int &x) {
    int t= empty+x;
    if (0 <= t && t < 9) {
        swap(s[empty], s[t]);
        if (!vis[s]) {
            que.push(s);
            vis[s] = true;
        }
    }
}

int BFS() {
    que.push(init);
    vis[init] = true;
    que.push("n");
    while (!que.empty()) {
        string cur = que.front();
        que.pop();
        if (cur == "n") { // 本层结束
            ans++;
            if(que.size()>0)
                que.push("n");
        } else if (cur == fin) // BFS终止
            return ans;
        else{
            empty = getEmpty(cur);
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
    cout<< BFS();
    return 0;
}
