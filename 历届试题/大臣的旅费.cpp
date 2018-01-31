/*
 * 实际上是要求树中最远的两个点，可以使用两遍深度优先遍历解决。
 * 第一遍从1号点开始，找到距1号点最远的点a，如果有多个任取一个即可。
 * 第二遍从2号点开始，找到距a最远的点b，则a和b就是最远的两个点。
 */

#include <iostream>
#include <vector>
#include <cstring>

#define N 100000
using namespace std;

struct Node {
    int v, weight;
};
vector <Node> ver[N];
int ans_node, ans_dis;
bool vis[N];

void DFS(int u, int d) {
    if (d > ans_dis) {
        ans_dis = d;
        ans_node = u;
    }
    for (int i = 0; i < ver[u].size(); i++) {
        if (vis[ver[u][i].v])
            continue;
        vis[ver[u][i].v] = true;
        DFS(ver[u][i].v, d + ver[u][i].weight);
        vis[ver[u][i].v] = false;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ver[u].push_back(Node{v, w}); // 构造邻接表
        ver[v].push_back(Node{u, w});
    }
    ans_dis = -1;
    vis[1] = true;
    DFS(1, 0); // 第一次DFS以1为起点，结果返回到ans_node
    ans_dis = -1;
    memset(vis, false, sizeof(vis));
    vis[ans_node] = true;
    DFS(ans_node, 0); // 第二次DFS
    ans_dis = ans_dis * 11 + (ans_dis * (ans_dis - 1)) / 2; // 由最远距离计算旅费
    cout << ans_dis;
    return 0;
}
