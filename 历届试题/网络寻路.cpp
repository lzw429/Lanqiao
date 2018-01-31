#include <iostream>
#include <vector>
#include <cstring>

#define MAXN 10010
using namespace std;

vector<int> g[MAXN];
bool vis[MAXN];
int ans, st;

void DFS(int u, int cnt) {
    if (cnt == 3) {
        ans++;
        return;
    }
    for (int i = 0; i != g[u].size(); ++i) {
        if (cnt == 2 && g[u][i] == st) { // 环路
            ans++;
        }
        if (!vis[g[u][i]]) {
            vis[g[u][i]] = true;
            DFS(g[u][i], cnt + 1);
            vis[g[u][i]] = false;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        memset(vis, 0, sizeof(vis));
        vis[i] = true;
        st = i;
        DFS(i, 0);
    }
    cout << ans;
    return 0;
}
