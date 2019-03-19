#include <iostream>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

string init, fin;
int ans;
queue<string> que;
const int mod = 999983;
bool vis[10000010];
int dir[5] = {-1, -3, +1, +3};

/**
 * 字符串 Hash 索引计算
 * 使用 STL map 速度可能过慢
 * @param s 字符串
 * @return 索引
 */
long long getHash(string s) {
    long long hashVal = 0;
    for (int i = 0; i != s.size(); i++)
        hashVal += (hashVal * 100000 % mod + s[i]) % mod;
    return hashVal;
}

/**
 * 将后续状态放入队列
 * @param s 当前状态
 * @param empty 空位索引
 */
void push(string s, const int &empty) {
    string ori_s = s;
    for (int i = 0; i <= 3; i++) {
        int t = dir[i] + empty;
        if (t < 0 || t >= 9)continue;
        if ((empty == 0 || empty == 3 || empty == 6) && dir[i] == -1)continue;
        if ((empty == 2 || empty == 5 || empty == 8) && dir[i] == 1)continue;
        s = ori_s;
        swap(s[empty], s[t]);
        int has = getHash(s);
        if (!vis[has]) {
            que.push(s);
            vis[has] = true;
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
            if (!que.empty())
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
    cin >> init >> fin; // 初始状态和最终状态
    cout << BFS();
    return 0;
}
