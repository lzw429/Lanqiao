#include <iostream>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

string init, fin;
int ans;
queue <string> que;
const int mod = 999983;
bool vis[10000010];
int dir[5] = {-1, -3, +1, +3};

long long getHash(string s) {
    long long hashVal = 0;
    for (int i = 0; i != s.size(); i++)
        hashVal += (hashVal * 100000 + s[i]) % mod;
    return hashVal;
}

void push(string s, const int &empty) {
    string ori_s = s;
    for (int i = 0; i <= 3; i++) {
        int t = dir[i] + empty;
        s = ori_s;
        if (0 <= t && t < 9) {
            swap(s[empty], s[t]);
            int has = getHash(s);
            if (!vis[has]) {
                que.push(s);
                vis[has] = true;
            }
        }
    }
}

int BFS() {
    int empty;
    que.push(init);
    vis[getHash(init)] = true;
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
            push(cur, empty);
        }
    }
    return -1;
}

int main() {
    cin >> init >> fin;
    cout << BFS();
    return 0;
}
