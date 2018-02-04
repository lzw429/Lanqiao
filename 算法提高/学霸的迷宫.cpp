#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>

#define MAXN 250010
using namespace std;

int map[MAXN];
bool vis[MAXN];
int dis[MAXN];
int pre[MAXN];
int n, m;
int min_dis;
vector<char> sp; // shortest path
queue<int> que;

vector<int> getNeighbor(int i) {
    vector<int> ret; // 按上下左右的顺序
    if (i >= m && map[i - m] == 0)
        ret.push_back(i - m); // 向上
    if (i < (n - 1) * m && map[i + m] == 0)
        ret.push_back(i + m); // 向下
    if (i % m > 0 && map[i - 1] == 0)
        ret.push_back(i - 1); // 向左
    if (i % m < m - 1 && map[i + 1] == 0) {
        ret.push_back(i + 1); // 向右
    }
    return ret;
}

void shortestPath() {
    // 更新vector<char> sp
    sp.clear();
    int cur = n * m - 1;
    while (cur != 0) {
        if (pre[cur] - 1 == cur)
            sp.push_back('L');
        else if (pre[cur] + 1 == cur)
            sp.push_back('R');
        else if (pre[cur] + m == cur)
            sp.push_back('D');
        else if (pre[cur] - m == cur)
            sp.push_back('U');
        cur = pre[cur];
    }
    reverse(sp.begin(), sp.end());
}

void BFS() {
    // index = m * i + j
    que.push(0);
    vis[0] = true;
    dis[0] = 0;
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        vis[cur] = false;
        vector<int> nei = getNeighbor(cur);
        for (vector<int>::iterator i = nei.begin(); i != nei.end(); ++i) {
            if (dis[cur] + 1 < dis[*i]) {
                dis[*i] = dis[cur] + 1;
                pre[*i] = cur;
                if (*i == n * m - 1) {
                    min_dis = dis[*i];
                    shortestPath();
                    return; // 第一次找到的解即最优
                }
                if (!vis[*i]) {
                    que.push(*i);
                    vis[*i] = true;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m; // 长、宽
    for (int i = 0; i < n * m; i++) {
        scanf("%1d", &map[i]);
    }
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    BFS();
    cout << dis[n * m - 1] << endl;;
    for (vector<char>::iterator i = sp.begin(); i != sp.end(); ++i)
        cout << *i;
    return 0;
}
